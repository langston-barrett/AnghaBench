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
struct tls_connection_params {int /*<<< orphan*/  flags; } ;
struct eap_ssl_data {int /*<<< orphan*/ * conn; int /*<<< orphan*/  ssl_ctx; } ;
struct eap_sm {void* ignore; } ;
struct eap_peer_config {int ocsp; int /*<<< orphan*/ * pin; } ;

/* Variables and functions */
 int /*<<< orphan*/  MSG_INFO ; 
 int /*<<< orphan*/  TLS_CONN_REQUEST_OCSP ; 
 int /*<<< orphan*/  TLS_CONN_REQUIRE_OCSP ; 
 int /*<<< orphan*/  TLS_CONN_REQUIRE_OCSP_ALL ; 
 int TLS_SET_PARAMS_ENGINE_PRV_BAD_PIN ; 
 int TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED ; 
 int TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED ; 
 void* TRUE ; 
 int /*<<< orphan*/  eap_sm_request_pin (struct eap_sm*) ; 
 int /*<<< orphan*/  os_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tls_connection_deinit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * tls_connection_init (int /*<<< orphan*/ ) ; 
 int tls_connection_set_params (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct tls_connection_params*) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int eap_tls_init_connection(struct eap_sm *sm,
				   struct eap_ssl_data *data,
				   struct eap_peer_config *config,
				   struct tls_connection_params *params)
{
	int res;

	if (config->ocsp)
		params->flags |= TLS_CONN_REQUEST_OCSP;
	if (config->ocsp >= 2)
		params->flags |= TLS_CONN_REQUIRE_OCSP;
	if (config->ocsp == 3)
		params->flags |= TLS_CONN_REQUIRE_OCSP_ALL;
	data->conn = tls_connection_init(data->ssl_ctx);
	if (data->conn == NULL) {
		wpa_printf(MSG_INFO, "SSL: Failed to initialize new TLS "
			   "connection");
		return -1;
	}

	res = tls_connection_set_params(data->ssl_ctx, data->conn, params);
	if (res == TLS_SET_PARAMS_ENGINE_PRV_BAD_PIN) {
		/*
		 * At this point with the pkcs11 engine the PIN is wrong. We
		 * reset the PIN in the configuration to be sure to not use it
		 * again and the calling function must request a new one.
		 */
		wpa_printf(MSG_INFO,
			   "TLS: Bad PIN provided, requesting a new one");
		os_free(config->pin);
		config->pin = NULL;
		eap_sm_request_pin(sm);
		sm->ignore = TRUE;
	} else if (res == TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED) {
		wpa_printf(MSG_INFO, "TLS: Failed to initialize engine");
	} else if (res == TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED) {
		wpa_printf(MSG_INFO, "TLS: Failed to load private key");
		sm->ignore = TRUE;
	}
	if (res) {
		wpa_printf(MSG_INFO, "TLS: Failed to set TLS connection "
			   "parameters");
		tls_connection_deinit(data->ssl_ctx, data->conn);
		data->conn = NULL;
		return -1;
	}

	return 0;
}