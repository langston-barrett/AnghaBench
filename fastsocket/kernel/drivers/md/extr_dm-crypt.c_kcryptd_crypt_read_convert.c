#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  pending; } ;
struct dm_crypt_io {TYPE_2__ ctx; int /*<<< orphan*/  sector; int /*<<< orphan*/  base_bio; TYPE_1__* target; } ;
struct crypt_config {int dummy; } ;
struct TYPE_4__ {struct crypt_config* private; } ;

/* Variables and functions */
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int crypt_convert (struct crypt_config*,TYPE_2__*) ; 
 int /*<<< orphan*/  crypt_convert_init (struct crypt_config*,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypt_dec_pending (struct dm_crypt_io*) ; 
 int /*<<< orphan*/  crypt_inc_pending (struct dm_crypt_io*) ; 
 int /*<<< orphan*/  kcryptd_crypt_read_done (struct dm_crypt_io*,int) ; 

__attribute__((used)) static void kcryptd_crypt_read_convert(struct dm_crypt_io *io)
{
	struct crypt_config *cc = io->target->private;
	int r = 0;

	crypt_inc_pending(io);

	crypt_convert_init(cc, &io->ctx, io->base_bio, io->base_bio,
			   io->sector);

	r = crypt_convert(cc, &io->ctx);

	if (atomic_dec_and_test(&io->ctx.pending))
		kcryptd_crypt_read_done(io, r);

	crypt_dec_pending(io);
}