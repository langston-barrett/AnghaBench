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
struct eap_sm {int dummy; } ;
struct eap_peap_data {int /*<<< orphan*/  pending_resp; int /*<<< orphan*/  pending_phase2_req; int /*<<< orphan*/  session_id; int /*<<< orphan*/  ssl; int /*<<< orphan*/  phase2_types; scalar_t__ phase2_priv; TYPE_1__* phase2_method; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* deinit ) (struct eap_sm*,scalar_t__) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  bin_clear_free (struct eap_peap_data*,int) ; 
 int /*<<< orphan*/  eap_peap_free_key (struct eap_peap_data*) ; 
 int /*<<< orphan*/  eap_peer_tls_ssl_deinit (struct eap_sm*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct eap_sm*,scalar_t__) ; 
 int /*<<< orphan*/  wpabuf_clear_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void eap_peap_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_peap_data *data = priv;
	if (data == NULL)
		return;
	if (data->phase2_priv && data->phase2_method)
		data->phase2_method->deinit(sm, data->phase2_priv);
	os_free(data->phase2_types);
	eap_peer_tls_ssl_deinit(sm, &data->ssl);
	eap_peap_free_key(data);
	os_free(data->session_id);
	wpabuf_clear_free(data->pending_phase2_req);
	wpabuf_clear_free(data->pending_resp);
	bin_clear_free(data, sizeof(*data));
}