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
typedef  TYPE_1__* esp_transport_handle_t ;
typedef  int /*<<< orphan*/  esp_err_t ;
struct TYPE_3__ {int port; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_FAIL ; 
 int /*<<< orphan*/  ESP_OK ; 

esp_err_t esp_transport_set_default_port(esp_transport_handle_t t, int port)
{
    if (t == NULL) {
        return ESP_FAIL;
    }
    t->port = port;
    return ESP_OK;
}