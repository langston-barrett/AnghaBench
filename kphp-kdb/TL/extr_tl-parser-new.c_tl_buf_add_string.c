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

/* Variables and functions */
 char* buf ; 
 int buf_pos ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int strlen (char*) ; 

void tl_buf_add_string (char *s, int len) {
  if (len < 0) { len = strlen (s); }
  buf[buf_pos ++] = ' ';
  memcpy (buf + buf_pos, s, len); buf_pos += len;
  buf[buf_pos] = 0;
}