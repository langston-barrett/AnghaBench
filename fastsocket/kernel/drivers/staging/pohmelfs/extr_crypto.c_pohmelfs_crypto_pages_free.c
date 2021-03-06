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
struct pohmelfs_crypto_engine {unsigned int page_num; int /*<<< orphan*/ * pages; } ;

/* Variables and functions */
 int /*<<< orphan*/  __free_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void pohmelfs_crypto_pages_free(struct pohmelfs_crypto_engine *e)
{
	unsigned int i;

	for (i=0; i<e->page_num; ++i)
		__free_page(e->pages[i]);
	kfree(e->pages);
}