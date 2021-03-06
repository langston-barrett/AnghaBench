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
typedef  int /*<<< orphan*/  const uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  AV_WB32 (int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static void update_size(uint8_t *size, const uint8_t *end)
{
    AV_WB32(size, end-size);
}