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
struct cache_mp_write_session_write_request {int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int /*<<< orphan*/  TRACE_IN (void (*) (struct cache_mp_write_session_write_request*)) ; 
 int /*<<< orphan*/  TRACE_OUT (void (*) (struct cache_mp_write_session_write_request*)) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

void
finalize_cache_mp_write_session_write_request(
	struct cache_mp_write_session_write_request *mp_ws_write_request)
{

	TRACE_IN(finalize_cache_mp_write_session_write_request);
	free(mp_ws_write_request->data);
	TRACE_OUT(finalize_cache_mp_write_session_write_request);
}