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
typedef  int /*<<< orphan*/  u8 ;
struct cc770_priv {scalar_t__ reg_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  readb (scalar_t__) ; 

__attribute__((used)) static u8 cc770_isa_mem_read_reg(const struct cc770_priv *priv, int reg)
{
	return readb(priv->reg_base + reg);
}