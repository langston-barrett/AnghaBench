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
typedef  int u_int8_t ;

/* Variables and functions */
#define  PF_BINAT 137 
#define  PF_DROP 136 
#define  PF_NAT 135 
#define  PF_NOBINAT 134 
#define  PF_NONAT 133 
#define  PF_NORDR 132 
#define  PF_NOSCRUB 131 
#define  PF_PASS 130 
#define  PF_RDR 129 
 int PF_RULESET_BINAT ; 
 int PF_RULESET_FILTER ; 
 int PF_RULESET_MAX ; 
 int PF_RULESET_NAT ; 
 int PF_RULESET_RDR ; 
 int PF_RULESET_SCRUB ; 
#define  PF_SCRUB 128 

int
pf_get_ruleset_number(u_int8_t action)
{
	switch (action) {
	case PF_SCRUB:
	case PF_NOSCRUB:
		return (PF_RULESET_SCRUB);
		break;
	case PF_PASS:
	case PF_DROP:
		return (PF_RULESET_FILTER);
		break;
	case PF_NAT:
	case PF_NONAT:
		return (PF_RULESET_NAT);
		break;
	case PF_BINAT:
	case PF_NOBINAT:
		return (PF_RULESET_BINAT);
		break;
	case PF_RDR:
	case PF_NORDR:
		return (PF_RULESET_RDR);
		break;
	default:
		return (PF_RULESET_MAX);
		break;
	}
}