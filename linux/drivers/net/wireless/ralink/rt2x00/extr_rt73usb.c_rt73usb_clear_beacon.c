#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct rt2x00_dev {int dummy; } ;
struct queue_entry {int /*<<< orphan*/  entry_idx; TYPE_1__* queue; } ;
struct TYPE_2__ {struct rt2x00_dev* rt2x00dev; } ;

/* Variables and functions */
 unsigned int HW_BEACON_OFFSET (int /*<<< orphan*/ ) ; 
 unsigned int TXRX_CSR9 ; 
 int /*<<< orphan*/  TXRX_CSR9_BEACON_GEN ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00usb_register_read (struct rt2x00_dev*,unsigned int) ; 
 int /*<<< orphan*/  rt2x00usb_register_write (struct rt2x00_dev*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rt73usb_clear_beacon(struct queue_entry *entry)
{
	struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
	unsigned int beacon_base;
	u32 orig_reg, reg;

	/*
	 * Disable beaconing while we are reloading the beacon data,
	 * otherwise we might be sending out invalid data.
	 */
	orig_reg = rt2x00usb_register_read(rt2x00dev, TXRX_CSR9);
	reg = orig_reg;
	rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 0);
	rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);

	/*
	 * Clear beacon.
	 */
	beacon_base = HW_BEACON_OFFSET(entry->entry_idx);
	rt2x00usb_register_write(rt2x00dev, beacon_base, 0);

	/*
	 * Restore beaconing state.
	 */
	rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, orig_reg);
}