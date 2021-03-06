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
struct TYPE_2__ {int status; int /*<<< orphan*/  func_code; } ;
union ccb {int /*<<< orphan*/  cpi; TYPE_1__ ccb_h; } ;
struct ccb_pathinq {int dummy; } ;
struct cam_device {int dummy; } ;

/* Variables and functions */
 int CAM_ARG_VERBOSE ; 
 int /*<<< orphan*/  CAM_EPF_ALL ; 
 int /*<<< orphan*/  CAM_ESF_ALL ; 
 int CAM_REQ_CMP ; 
 int CAM_STATUS_MASK ; 
 int /*<<< orphan*/  CCB_CLEAR_ALL_EXCEPT_HDR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XPT_PATH_INQ ; 
 int arglist ; 
 int /*<<< orphan*/  bcopy (int /*<<< orphan*/ *,struct ccb_pathinq*,int) ; 
 int /*<<< orphan*/  cam_error_print (struct cam_device*,union ccb*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cam_freeccb (union ccb*) ; 
 union ccb* cam_getccb (struct cam_device*) ; 
 scalar_t__ cam_send_ccb (struct cam_device*,union ccb*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  warn (char*) ; 
 int /*<<< orphan*/  warnx (char*) ; 

__attribute__((used)) static int
get_cpi(struct cam_device *device, struct ccb_pathinq *cpi)
{
	union ccb *ccb;
	int retval = 0;

	ccb = cam_getccb(device);
	if (ccb == NULL) {
		warnx("get_cpi: couldn't allocate CCB");
		return (1);
	}
	CCB_CLEAR_ALL_EXCEPT_HDR(&ccb->cpi);
	ccb->ccb_h.func_code = XPT_PATH_INQ;
	if (cam_send_ccb(device, ccb) < 0) {
		warn("get_cpi: error sending Path Inquiry CCB");
		retval = 1;
		goto get_cpi_bailout;
	}
	if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
		if (arglist & CAM_ARG_VERBOSE)
			cam_error_print(device, ccb, CAM_ESF_ALL,
					CAM_EPF_ALL, stderr);
		retval = 1;
		goto get_cpi_bailout;
	}
	bcopy(&ccb->cpi, cpi, sizeof(struct ccb_pathinq));

get_cpi_bailout:
	cam_freeccb(ccb);
	return (retval);
}