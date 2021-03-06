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
struct ubi_vid_io_buf {struct ubi_vid_hdr* hdr; } ;
struct ubi_vid_hdr {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct ubi_vid_hdr *ubi_get_vid_hdr(struct ubi_vid_io_buf *vidb)
{
	return vidb->hdr;
}