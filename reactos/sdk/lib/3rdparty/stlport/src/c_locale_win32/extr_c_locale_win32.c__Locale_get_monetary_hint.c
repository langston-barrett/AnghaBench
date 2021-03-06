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
struct TYPE_3__ {int /*<<< orphan*/  lc; } ;
typedef  TYPE_1__ _Locale_monetary_t ;
typedef  int /*<<< orphan*/  _Locale_lcid_t ;

/* Variables and functions */

_Locale_lcid_t* _Locale_get_monetary_hint(_Locale_monetary_t* lmonetary)
{ return (lmonetary != 0) ? &lmonetary->lc : 0; }