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
typedef  TYPE_1__* esp_http_client_handle_t ;
typedef  int /*<<< orphan*/  esp_err_t ;
struct TYPE_4__ {int /*<<< orphan*/ * location; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_ERR_INVALID_ARG ; 
 int /*<<< orphan*/  ESP_LOGD (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAG ; 
 int /*<<< orphan*/  esp_http_client_set_url (TYPE_1__*,int /*<<< orphan*/ *) ; 

esp_err_t esp_http_client_set_redirection(esp_http_client_handle_t client)
{
    if (client == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    if (client->location == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    ESP_LOGD(TAG, "Redirect to %s", client->location);
    return esp_http_client_set_url(client, client->location);
}