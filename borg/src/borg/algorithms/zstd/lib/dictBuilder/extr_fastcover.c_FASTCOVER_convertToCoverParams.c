#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  zParams; int /*<<< orphan*/  splitPoint; int /*<<< orphan*/  nbThreads; int /*<<< orphan*/  steps; int /*<<< orphan*/  d; int /*<<< orphan*/  k; } ;
typedef  TYPE_1__ ZDICT_fastCover_params_t ;
struct TYPE_6__ {int /*<<< orphan*/  zParams; int /*<<< orphan*/  splitPoint; int /*<<< orphan*/  nbThreads; int /*<<< orphan*/  steps; int /*<<< orphan*/  d; int /*<<< orphan*/  k; } ;
typedef  TYPE_2__ ZDICT_cover_params_t ;

/* Variables and functions */

__attribute__((used)) static void
FASTCOVER_convertToCoverParams(ZDICT_fastCover_params_t fastCoverParams,
                               ZDICT_cover_params_t* coverParams)
{
    coverParams->k = fastCoverParams.k;
    coverParams->d = fastCoverParams.d;
    coverParams->steps = fastCoverParams.steps;
    coverParams->nbThreads = fastCoverParams.nbThreads;
    coverParams->splitPoint = fastCoverParams.splitPoint;
    coverParams->zParams = fastCoverParams.zParams;
}