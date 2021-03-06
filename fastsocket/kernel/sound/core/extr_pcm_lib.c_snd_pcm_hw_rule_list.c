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
struct snd_pcm_hw_rule {int /*<<< orphan*/  var; struct snd_pcm_hw_constraint_list* private; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_pcm_hw_constraint_list {int /*<<< orphan*/  mask; int /*<<< orphan*/  list; int /*<<< orphan*/  count; } ;

/* Variables and functions */
 int /*<<< orphan*/  hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int snd_interval_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_pcm_hw_rule_list(struct snd_pcm_hw_params *params,
				struct snd_pcm_hw_rule *rule)
{
	struct snd_pcm_hw_constraint_list *list = rule->private;
	return snd_interval_list(hw_param_interval(params, rule->var), list->count, list->list, list->mask);
}