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
struct request {int /*<<< orphan*/  biotail; int /*<<< orphan*/  q; } ;
struct bio {int dummy; } ;

/* Variables and functions */
 int bio_will_gap (int /*<<< orphan*/ ,struct request*,int /*<<< orphan*/ ,struct bio*) ; 

__attribute__((used)) static inline bool req_gap_back_merge(struct request *req, struct bio *bio)
{
	return bio_will_gap(req->q, req, req->biotail, bio);
}