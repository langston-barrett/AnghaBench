#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lsm_i64 ;
typedef  int /*<<< orphan*/  lsm_file ;
struct TYPE_3__ {int /*<<< orphan*/  (* xRead ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,int) ;} ;
typedef  TYPE_1__ lsm_env ;

/* Variables and functions */
 int IOERR_WRAPPER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,int) ; 

__attribute__((used)) static int lsmEnvRead(
  lsm_env *pEnv, 
  lsm_file *pFile, 
  lsm_i64 iOff, 
  void *pRead, 
  int nRead
){
  return IOERR_WRAPPER( pEnv->xRead(pFile, iOff, pRead, nRead) );
}