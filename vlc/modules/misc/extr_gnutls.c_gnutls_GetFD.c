#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vlc_tls_t ;
struct TYPE_2__ {int /*<<< orphan*/  session; } ;
typedef  TYPE_1__ vlc_tls_gnutls_t ;

/* Variables and functions */
 int /*<<< orphan*/ * gnutls_transport_get_ptr (int /*<<< orphan*/ ) ; 
 int vlc_tls_GetPollFD (int /*<<< orphan*/ *,short*) ; 

__attribute__((used)) static int gnutls_GetFD(vlc_tls_t *tls, short *restrict events)
{
    vlc_tls_gnutls_t *priv = (vlc_tls_gnutls_t *)tls;
    vlc_tls_t *sock = gnutls_transport_get_ptr(priv->session);

    return vlc_tls_GetPollFD(sock, events);
}