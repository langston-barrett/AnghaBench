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
typedef  int u_int8_t ;
typedef  void* u_int16_t ;
struct smbnode {void* n_rwstate; void* n_fid; TYPE_1__* n_mount; } ;
struct smb_share {int dummy; } ;
struct smb_rq {int dummy; } ;
struct smb_cred {int dummy; } ;
struct mdchain {int dummy; } ;
struct mbchain {int dummy; } ;
struct TYPE_2__ {struct smb_share* sm_share; } ;

/* Variables and functions */
 int EBADRPC ; 
 int /*<<< orphan*/  SMB_COM_OPEN ; 
 int /*<<< orphan*/  SMB_DT_ASCII ; 
 int SMB_FA_HIDDEN ; 
 int SMB_FA_SYSTEM ; 
 int /*<<< orphan*/  SSTOCP (struct smb_share*) ; 
 int /*<<< orphan*/  SSTOVC (struct smb_share*) ; 
 int /*<<< orphan*/  mb_put_uint16le (struct mbchain*,int) ; 
 int /*<<< orphan*/  mb_put_uint8 (struct mbchain*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  md_get_uint16 (struct mdchain*,void**) ; 
 int /*<<< orphan*/  md_get_uint16le (struct mdchain*,void**) ; 
 int /*<<< orphan*/  md_get_uint32 (struct mdchain*,int /*<<< orphan*/ *) ; 
 scalar_t__ md_get_uint8 (struct mdchain*,int*) ; 
 int smb_rq_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct smb_cred*,struct smb_rq**) ; 
 int /*<<< orphan*/  smb_rq_bend (struct smb_rq*) ; 
 int /*<<< orphan*/  smb_rq_bstart (struct smb_rq*) ; 
 int /*<<< orphan*/  smb_rq_done (struct smb_rq*) ; 
 int /*<<< orphan*/  smb_rq_getreply (struct smb_rq*,struct mdchain**) ; 
 int /*<<< orphan*/  smb_rq_getrequest (struct smb_rq*,struct mbchain**) ; 
 int smb_rq_simple (struct smb_rq*) ; 
 int /*<<< orphan*/  smb_rq_wend (struct smb_rq*) ; 
 int /*<<< orphan*/  smb_rq_wstart (struct smb_rq*) ; 
 int smbfs_fullpath (struct mbchain*,int /*<<< orphan*/ ,struct smbnode*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int
smbfs_smb_open(struct smbnode *np, int accmode, struct smb_cred *scred)
{
	struct smb_rq *rqp;
	struct smb_share *ssp = np->n_mount->sm_share;
	struct mbchain *mbp;
	struct mdchain *mdp;
	u_int8_t wc;
	u_int16_t fid, wattr, grantedmode;
	int error;

	error = smb_rq_alloc(SSTOCP(ssp), SMB_COM_OPEN, scred, &rqp);
	if (error)
		return (error);
	smb_rq_getrequest(rqp, &mbp);
	smb_rq_wstart(rqp);
	mb_put_uint16le(mbp, accmode);
	mb_put_uint16le(mbp, SMB_FA_SYSTEM | SMB_FA_HIDDEN);
	smb_rq_wend(rqp);
	smb_rq_bstart(rqp);
	mb_put_uint8(mbp, SMB_DT_ASCII);
	do {
		error = smbfs_fullpath(mbp, SSTOVC(ssp), np, NULL, 0);
		if (error)
			break;
		smb_rq_bend(rqp);
		error = smb_rq_simple(rqp);
		if (error)
			break;
		smb_rq_getreply(rqp, &mdp);
		if (md_get_uint8(mdp, &wc) != 0 || wc != 7) {
			error = EBADRPC;
			break;
		}
		md_get_uint16(mdp, &fid);
		md_get_uint16le(mdp, &wattr);
		md_get_uint32(mdp, NULL);	/* mtime */
		md_get_uint32(mdp, NULL);	/* fsize */
		md_get_uint16le(mdp, &grantedmode);
		/*
		 * TODO: refresh attributes from this reply
		 */
	} while(0);
	smb_rq_done(rqp);
	if (error)
		return error;
	np->n_fid = fid;
	np->n_rwstate = grantedmode;
	return 0;
}