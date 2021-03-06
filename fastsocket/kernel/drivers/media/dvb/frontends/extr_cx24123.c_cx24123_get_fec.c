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
struct cx24123_state {int dummy; } ;
typedef  int /*<<< orphan*/  fe_code_rate_t ;

/* Variables and functions */
 int /*<<< orphan*/  FEC_1_2 ; 
 int /*<<< orphan*/  FEC_2_3 ; 
 int /*<<< orphan*/  FEC_3_4 ; 
 int /*<<< orphan*/  FEC_4_5 ; 
 int /*<<< orphan*/  FEC_5_6 ; 
 int /*<<< orphan*/  FEC_6_7 ; 
 int /*<<< orphan*/  FEC_7_8 ; 
 int /*<<< orphan*/  FEC_NONE ; 
 int cx24123_readreg (struct cx24123_state*,int) ; 

__attribute__((used)) static int cx24123_get_fec(struct cx24123_state *state, fe_code_rate_t *fec)
{
	int ret;

	ret = cx24123_readreg(state, 0x1b);
	if (ret < 0)
		return ret;
	ret = ret & 0x07;

	switch (ret) {
	case 1:
		*fec = FEC_1_2;
		break;
	case 2:
		*fec = FEC_2_3;
		break;
	case 3:
		*fec = FEC_3_4;
		break;
	case 4:
		*fec = FEC_4_5;
		break;
	case 5:
		*fec = FEC_5_6;
		break;
	case 6:
		*fec = FEC_6_7;
		break;
	case 7:
		*fec = FEC_7_8;
		break;
	default:
		/* this can happen when there's no lock */
		*fec = FEC_NONE;
	}

	return 0;
}