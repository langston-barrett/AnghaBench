#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct page {int dummy; } ;
struct dio_submit {unsigned int cur_page_offset; int cur_page_len; scalar_t__ cur_page_block; int blkbits; int cur_page_fs_offset; int block_in_file; struct page* cur_page; scalar_t__ boundary; } ;
struct dio {int rw; } ;
struct buffer_head {int dummy; } ;
typedef  scalar_t__ sector_t ;

/* Variables and functions */
 int WRITE ; 
 int dio_send_cur_page (struct dio*,struct dio_submit*,struct buffer_head*) ; 
 int /*<<< orphan*/  page_cache_get (struct page*) ; 
 int /*<<< orphan*/  page_cache_release (struct page*) ; 
 int /*<<< orphan*/  task_io_account_write (unsigned int) ; 

__attribute__((used)) static inline int
submit_page_section(struct dio *dio, struct dio_submit *sdio, struct page *page,
		    unsigned offset, unsigned len, sector_t blocknr,
		    struct buffer_head *map_bh)
{
	int ret = 0;

	if (dio->rw & WRITE) {
		/*
		 * Read accounting is performed in submit_bio()
		 */
		task_io_account_write(len);
	}

	/*
	 * Can we just grow the current page's presence in the dio?
	 */
	if (sdio->cur_page == page &&
	    sdio->cur_page_offset + sdio->cur_page_len == offset &&
	    sdio->cur_page_block +
	    (sdio->cur_page_len >> sdio->blkbits) == blocknr) {
		sdio->cur_page_len += len;

		/*
		 * If sdio->boundary then we want to schedule the IO now to
		 * avoid metadata seeks.
		 */
		if (sdio->boundary) {
			ret = dio_send_cur_page(dio, sdio, map_bh);
			page_cache_release(sdio->cur_page);
			sdio->cur_page = NULL;
		}
		goto out;
	}

	/*
	 * If there's a deferred page already there then send it.
	 */
	if (sdio->cur_page) {
		ret = dio_send_cur_page(dio, sdio, map_bh);
		page_cache_release(sdio->cur_page);
		sdio->cur_page = NULL;
		if (ret)
			goto out;
	}

	page_cache_get(page);		/* It is in dio */
	sdio->cur_page = page;
	sdio->cur_page_offset = offset;
	sdio->cur_page_len = len;
	sdio->cur_page_block = blocknr;
	sdio->cur_page_fs_offset = sdio->block_in_file << sdio->blkbits;
out:
	return ret;
}