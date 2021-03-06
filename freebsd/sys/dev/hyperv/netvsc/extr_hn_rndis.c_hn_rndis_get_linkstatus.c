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
typedef  int /*<<< orphan*/  uint32_t ;
struct hn_softc {int /*<<< orphan*/  hn_ifp; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  OID_GEN_MEDIA_CONNECT_STATUS ; 
 int hn_rndis_query (struct hn_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  if_printf (int /*<<< orphan*/ ,char*,size_t) ; 

int
hn_rndis_get_linkstatus(struct hn_softc *sc, uint32_t *link_status)
{
	size_t size;
	int error;

	size = sizeof(*link_status);
	error = hn_rndis_query(sc, OID_GEN_MEDIA_CONNECT_STATUS, NULL, 0,
	    link_status, &size);
	if (error)
		return (error);
	if (size != sizeof(uint32_t)) {
		if_printf(sc->hn_ifp, "invalid link status len %zu\n", size);
		return (EINVAL);
	}
	return (0);
}