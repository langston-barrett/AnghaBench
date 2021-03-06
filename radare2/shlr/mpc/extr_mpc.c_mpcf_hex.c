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
typedef  int mpc_val_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (int*) ; 
 int* malloc (int) ; 
 int strtol (int*,int /*<<< orphan*/ *,int) ; 

mpc_val_t *mpcf_hex(mpc_val_t *x) {
  int *y = malloc(sizeof(int));
  *y = strtol(x, NULL, 16);
  free(x);
  return y;
}