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
struct TYPE_3__ {int rates_len; int /*<<< orphan*/  extra; scalar_t__ mask; scalar_t__ rates; } ;
typedef  TYPE_1__ item_t ;

/* Variables and functions */
 int /*<<< orphan*/  FLAG_DELETED ; 
 int /*<<< orphan*/  zzfree (scalar_t__,int) ; 

__attribute__((used)) static void delete_item_rates (item_t *I) {
  zzfree (I->rates, I->rates_len * 4);
  I->rates = 0;
  I->rates_len = 0;
  I->mask = 0;
  I->extra |= FLAG_DELETED;
}