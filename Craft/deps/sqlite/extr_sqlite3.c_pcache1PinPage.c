#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  nRecyclable; TYPE_2__* pGroup; } ;
struct TYPE_6__ {TYPE_1__* pLruTail; TYPE_1__* pLruHead; int /*<<< orphan*/  mutex; } ;
struct TYPE_5__ {TYPE_3__* pCache; struct TYPE_5__* pLruPrev; struct TYPE_5__* pLruNext; } ;
typedef  TYPE_1__ PgHdr1 ;
typedef  TYPE_2__ PGroup ;
typedef  TYPE_3__ PCache1 ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_mutex_held (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pcache1PinPage(PgHdr1 *pPage){
  PCache1 *pCache;
  PGroup *pGroup;

  if( pPage==0 ) return;
  pCache = pPage->pCache;
  pGroup = pCache->pGroup;
  assert( sqlite3_mutex_held(pGroup->mutex) );
  if( pPage->pLruNext || pPage==pGroup->pLruTail ){
    if( pPage->pLruPrev ){
      pPage->pLruPrev->pLruNext = pPage->pLruNext;
    }
    if( pPage->pLruNext ){
      pPage->pLruNext->pLruPrev = pPage->pLruPrev;
    }
    if( pGroup->pLruHead==pPage ){
      pGroup->pLruHead = pPage->pLruNext;
    }
    if( pGroup->pLruTail==pPage ){
      pGroup->pLruTail = pPage->pLruPrev;
    }
    pPage->pLruNext = 0;
    pPage->pLruPrev = 0;
    pPage->pCache->nRecyclable--;
  }
}