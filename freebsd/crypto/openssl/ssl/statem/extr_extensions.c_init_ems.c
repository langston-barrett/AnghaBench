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
struct TYPE_5__ {TYPE_1__* s3; int /*<<< orphan*/  server; } ;
struct TYPE_4__ {int /*<<< orphan*/  flags; } ;
typedef  TYPE_2__ SSL ;

/* Variables and functions */
 int /*<<< orphan*/  TLS1_FLAGS_RECEIVED_EXTMS ; 

__attribute__((used)) static int init_ems(SSL *s, unsigned int context)
{
    if (!s->server)
        s->s3->flags &= ~TLS1_FLAGS_RECEIVED_EXTMS;

    return 1;
}