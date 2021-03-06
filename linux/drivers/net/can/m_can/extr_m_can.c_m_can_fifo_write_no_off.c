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
struct m_can_classdev {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* write_fifo ) (struct m_can_classdev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct m_can_classdev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void m_can_fifo_write_no_off(struct m_can_classdev *cdev,
					   u32 fpi, u32 val)
{
	cdev->ops->write_fifo(cdev, fpi, val);
}