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
typedef  scalar_t__ GTypeIP ;

/* Variables and functions */
 char* GeoIP_country_name_by_name (int /*<<< orphan*/ ,char const*) ; 
 char* GeoIP_country_name_by_name_v6 (int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ TYPE_IPV4 ; 
 scalar_t__ TYPE_IPV6 ; 
 int /*<<< orphan*/  geo_location_data ; 

__attribute__((used)) static const char *
geoip_get_country_by_geoid (const char *addr, GTypeIP type_ip)
{
  const char *country = NULL;

  if (TYPE_IPV4 == type_ip)
    country = GeoIP_country_name_by_name (geo_location_data, addr);
  else if (TYPE_IPV6 == type_ip)
    country = GeoIP_country_name_by_name_v6 (geo_location_data, addr);

  return country;
}