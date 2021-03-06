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

/* Variables and functions */
 int GFP_HIGHUSER ; 
 int __GFP_ZERO ; 
 struct page* __xip_sparse_page ; 
 struct page* alloc_page (int) ; 

__attribute__((used)) static struct page *xip_sparse_page(void)
{
	if (!__xip_sparse_page) {
		struct page *page = alloc_page(GFP_HIGHUSER | __GFP_ZERO);

		if (page)
			__xip_sparse_page = page;
	}
	return __xip_sparse_page;
}