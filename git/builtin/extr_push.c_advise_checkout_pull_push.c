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
 int /*<<< orphan*/  _ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  advice_push_non_ff_matching ; 
 int /*<<< orphan*/  advice_push_update_rejected ; 
 int /*<<< orphan*/  advise (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  message_advice_checkout_pull_push ; 

__attribute__((used)) static void advise_checkout_pull_push(void)
{
	if (!advice_push_non_ff_matching || !advice_push_update_rejected)
		return;
	advise(_(message_advice_checkout_pull_push));
}