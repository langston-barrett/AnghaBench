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
typedef  int /*<<< orphan*/  uv_pipe_t ;

/* Variables and functions */
 int /*<<< orphan*/  getpeername ; 
 int uv__pipe_getsockpeername (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,char*,size_t*) ; 

int uv_pipe_getpeername(const uv_pipe_t* handle, char* buffer, size_t* size) {
  return uv__pipe_getsockpeername(handle, getpeername, buffer, size);
}