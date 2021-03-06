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
typedef  int /*<<< orphan*/  fw_port_cap32_t ;
typedef  enum cc_fec { ____Placeholder_cc_fec } cc_fec ;

/* Variables and functions */
 int FEC_BASER_RS ; 
 int FEC_RS ; 
 int /*<<< orphan*/  FW_PORT_CAP32_FEC_BASER_RS ; 
 int /*<<< orphan*/  FW_PORT_CAP32_FEC_RS ; 

__attribute__((used)) static inline fw_port_cap32_t cc_to_fwcap_fec(enum cc_fec cc_fec)
{
	fw_port_cap32_t fw_fec = 0;

	if (cc_fec & FEC_RS)
		fw_fec |= FW_PORT_CAP32_FEC_RS;
	if (cc_fec & FEC_BASER_RS)
		fw_fec |= FW_PORT_CAP32_FEC_BASER_RS;

	return fw_fec;
}