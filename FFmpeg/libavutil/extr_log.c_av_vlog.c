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
typedef  int /*<<< orphan*/  va_list ;

/* Variables and functions */
 void av_log_callback (void*,int,char const*,int /*<<< orphan*/ ) ; 

void av_vlog(void* avcl, int level, const char *fmt, va_list vl)
{
    void (*log_callback)(void*, int, const char*, va_list) = av_log_callback;
    if (log_callback)
        log_callback(avcl, level, fmt, vl);
}