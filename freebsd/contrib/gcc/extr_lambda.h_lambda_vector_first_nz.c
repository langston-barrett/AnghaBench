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
typedef  scalar_t__* lambda_vector ;

/* Variables and functions */

__attribute__((used)) static inline int
lambda_vector_first_nz (lambda_vector vec1, int n, int start)
{
  int j = start;
  while (j < n && vec1[j] == 0)
    j++;
  return j;
}