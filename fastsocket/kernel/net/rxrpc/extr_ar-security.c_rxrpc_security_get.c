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
struct rxrpc_security {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 scalar_t__ try_module_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct rxrpc_security *rxrpc_security_get(struct rxrpc_security *sec)
{
	return try_module_get(sec->owner) ? sec : NULL;
}