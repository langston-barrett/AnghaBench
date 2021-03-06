#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  mutex; } ;
typedef  TYPE_1__ mbedtls_entropy_context ;

/* Variables and functions */
 int /*<<< orphan*/  MBEDTLS_ENTROPY_SOURCE_MANUAL ; 
 int MBEDTLS_ERR_THREADING_MUTEX_ERROR ; 
 int entropy_update (TYPE_1__*,int /*<<< orphan*/ ,unsigned char const*,size_t) ; 
 int mbedtls_mutex_lock (int /*<<< orphan*/ *) ; 
 scalar_t__ mbedtls_mutex_unlock (int /*<<< orphan*/ *) ; 

int mbedtls_entropy_update_manual( mbedtls_entropy_context *ctx,
                           const unsigned char *data, size_t len )
{
    int ret;

#if defined(MBEDTLS_THREADING_C)
    if( ( ret = mbedtls_mutex_lock( &ctx->mutex ) ) != 0 )
        return( ret );
#endif

    ret = entropy_update( ctx, MBEDTLS_ENTROPY_SOURCE_MANUAL, data, len );

#if defined(MBEDTLS_THREADING_C)
    if( mbedtls_mutex_unlock( &ctx->mutex ) != 0 )
        return( MBEDTLS_ERR_THREADING_MUTEX_ERROR );
#endif

    return( ret );
}