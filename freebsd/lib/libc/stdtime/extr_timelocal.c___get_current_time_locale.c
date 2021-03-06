#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct lc_time_T {int dummy; } ;
struct xlocale_time {struct lc_time_T locale; } ;
typedef  TYPE_1__* locale_t ;
struct TYPE_3__ {scalar_t__* components; scalar_t__ using_time_locale; } ;

/* Variables and functions */
 size_t XLC_TIME ; 
 int /*<<< orphan*/  _C_time_locale ; 

struct lc_time_T *
__get_current_time_locale(locale_t loc)
{
	return (loc->using_time_locale
		? &((struct xlocale_time *)loc->components[XLC_TIME])->locale
		: (struct lc_time_T *)&_C_time_locale);
}