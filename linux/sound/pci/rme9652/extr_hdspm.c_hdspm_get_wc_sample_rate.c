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
struct hdspm {int io_type; } ;

/* Variables and functions */
#define  AES32 130 
#define  AIO 129 
 int HDSPM_AES32_wcFreq_bit ; 
 int /*<<< orphan*/  HDSPM_RD_STATUS_1 ; 
 int /*<<< orphan*/  HDSPM_statusRegister ; 
#define  RayDAT 128 
 int hdspm_read (struct hdspm*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hdspm_get_wc_sample_rate(struct hdspm *hdspm)
{
	int status;

	switch (hdspm->io_type) {
	case RayDAT:
	case AIO:
		status = hdspm_read(hdspm, HDSPM_RD_STATUS_1);
		return (status >> 16) & 0xF;
		break;
	case AES32:
		status = hdspm_read(hdspm, HDSPM_statusRegister);
		return (status >> HDSPM_AES32_wcFreq_bit) & 0xF;
	default:
		break;
	}


	return 0;
}