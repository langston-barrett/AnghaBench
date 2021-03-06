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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int lz4_nmatch32 (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline size_t lz4_nmatch64(const uint8_t * a,const uint8_t * b)
{
  size_t n = lz4_nmatch32(a,b);
  return (n == 32)?(32 + lz4_nmatch32(a+32,b+32)):n;
}