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
union iwreq_data {int mode; } ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct adapter {int /*<<< orphan*/  hw_init_completed; } ;
typedef  enum ndis_802_11_network_infra { ____Placeholder_ndis_802_11_network_infra } ndis_802_11_network_infra ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_88E (char*) ; 
 int EINVAL ; 
 int EPERM ; 
#define  IW_MODE_ADHOC 131 
#define  IW_MODE_AUTO 130 
#define  IW_MODE_INFRA 129 
#define  IW_MODE_MASTER 128 
 int Ndis802_11APMode ; 
 int Ndis802_11AutoUnknown ; 
 int Ndis802_11IBSS ; 
 int Ndis802_11Infrastructure ; 
 int /*<<< orphan*/  RT_TRACE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ _FAIL ; 
 int /*<<< orphan*/  _drv_err_ ; 
 int /*<<< orphan*/  _module_rtl871x_ioctl_os_c ; 
 int /*<<< orphan*/ * iw_operation_mode ; 
 scalar_t__ rtw_netdev_priv (struct net_device*) ; 
 scalar_t__ rtw_pwr_wakeup (struct adapter*) ; 
 int /*<<< orphan*/  rtw_set_802_11_infrastructure_mode (struct adapter*,int) ; 
 int /*<<< orphan*/  rtw_setopmode_cmd (struct adapter*,int) ; 

__attribute__((used)) static int rtw_wx_set_mode(struct net_device *dev, struct iw_request_info *a,
			     union iwreq_data *wrqu, char *b)
{
	struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
	enum ndis_802_11_network_infra networkType;
	int ret = 0;

	if (_FAIL == rtw_pwr_wakeup(padapter)) {
		ret = -EPERM;
		goto exit;
	}

	if (!padapter->hw_init_completed) {
		ret = -EPERM;
		goto exit;
	}

	switch (wrqu->mode) {
	case IW_MODE_AUTO:
		networkType = Ndis802_11AutoUnknown;
		DBG_88E("set_mode = IW_MODE_AUTO\n");
		break;
	case IW_MODE_ADHOC:
		networkType = Ndis802_11IBSS;
		DBG_88E("set_mode = IW_MODE_ADHOC\n");
		break;
	case IW_MODE_MASTER:
		networkType = Ndis802_11APMode;
		DBG_88E("set_mode = IW_MODE_MASTER\n");
		break;
	case IW_MODE_INFRA:
		networkType = Ndis802_11Infrastructure;
		DBG_88E("set_mode = IW_MODE_INFRA\n");
		break;
	default:
		ret = -EINVAL;
		RT_TRACE(_module_rtl871x_ioctl_os_c, _drv_err_, ("\n Mode: %s is not supported\n", iw_operation_mode[wrqu->mode]));
		goto exit;
	}
	if (!rtw_set_802_11_infrastructure_mode(padapter, networkType)) {
		ret = -EPERM;
		goto exit;
	}
	rtw_setopmode_cmd(padapter, networkType);
exit:
	return ret;
}