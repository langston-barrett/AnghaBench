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
typedef  int /*<<< orphan*/  u32 ;
struct rt2x00_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSR11 ; 
 int /*<<< orphan*/  CSR11_CWMAX ; 
 int /*<<< orphan*/  CSR11_CWMIN ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  rt2x00mmio_register_read (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00mmio_register_write (struct rt2x00_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rt2400pci_config_cw(struct rt2x00_dev *rt2x00dev,
				const int cw_min, const int cw_max)
{
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, CSR11);
	rt2x00_set_field32(&reg, CSR11_CWMIN, cw_min);
	rt2x00_set_field32(&reg, CSR11_CWMAX, cw_max);
	rt2x00mmio_register_write(rt2x00dev, CSR11, reg);
}