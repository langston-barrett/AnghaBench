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
struct work_struct {int dummy; } ;
struct asd_sas_phy {int /*<<< orphan*/  port_events_pending; } ;
struct asd_sas_event {struct asd_sas_phy* phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PORTE_HARD_RESET ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sas_deform_port (struct asd_sas_phy*,int) ; 
 struct asd_sas_event* to_asd_sas_event (struct work_struct*) ; 

void sas_porte_hard_reset(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;

	clear_bit(PORTE_HARD_RESET, &phy->port_events_pending);

	sas_deform_port(phy, 1);
}