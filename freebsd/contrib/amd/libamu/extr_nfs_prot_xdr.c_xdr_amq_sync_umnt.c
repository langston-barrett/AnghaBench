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
typedef  int /*<<< orphan*/  bool_t ;
typedef  int /*<<< orphan*/  amq_sync_umnt ;
typedef  int /*<<< orphan*/  XDR ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  xdr_opaque (int /*<<< orphan*/ *,char*,int) ; 

bool_t
xdr_amq_sync_umnt(XDR *xdrs, amq_sync_umnt *objp)
{

  if (!xdr_opaque(xdrs, (char *) objp, sizeof(*objp))) {
    return (FALSE);
  }
  return (TRUE);
}