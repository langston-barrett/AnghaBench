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
struct TYPE_3__ {char const* body_start; } ;
typedef  TYPE_1__ HttpResponseState ;

/* Variables and functions */

const char *
ts_http_response_state_body_start(HttpResponseState *state)
{
	return state->body_start;
}