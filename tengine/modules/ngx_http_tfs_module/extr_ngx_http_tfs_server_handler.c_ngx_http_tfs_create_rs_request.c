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
typedef  int /*<<< orphan*/  ngx_int_t ;
struct TYPE_3__ {int /*<<< orphan*/ * request_bufs; int /*<<< orphan*/  pool; } ;
typedef  TYPE_1__ ngx_http_tfs_t ;
typedef  int /*<<< orphan*/  ngx_chain_t ;

/* Variables and functions */
 int /*<<< orphan*/  NGX_ERROR ; 
 int /*<<< orphan*/  NGX_OK ; 
 int /*<<< orphan*/ * ngx_http_tfs_root_server_create_message (int /*<<< orphan*/ ) ; 

ngx_int_t
ngx_http_tfs_create_rs_request(ngx_http_tfs_t *t)
{
    ngx_chain_t  *cl;

    cl = ngx_http_tfs_root_server_create_message(t->pool);
    if (cl == NULL) {
        return NGX_ERROR;
    }

    t->request_bufs = cl;

    return NGX_OK;
}