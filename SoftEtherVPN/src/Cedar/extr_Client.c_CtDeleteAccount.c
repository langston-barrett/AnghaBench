#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_19__ {int /*<<< orphan*/  AccountName; } ;
struct TYPE_18__ {int /*<<< orphan*/  lock; int /*<<< orphan*/ * ClientSession; TYPE_4__* ClientOption; } ;
struct TYPE_17__ {int /*<<< orphan*/  AccountList; scalar_t__ Halt; } ;
struct TYPE_16__ {int /*<<< orphan*/  AccountName; } ;
typedef  TYPE_1__ RPC_CLIENT_DELETE_ACCOUNT ;
typedef  int /*<<< orphan*/  CLIENT_OPTION ;
typedef  TYPE_2__ CLIENT ;
typedef  TYPE_3__ ACCOUNT ;

/* Variables and functions */
 int /*<<< orphan*/  CLog (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CiFreeAccount (TYPE_3__*) ; 
 int /*<<< orphan*/  CiNotify (TYPE_2__*) ; 
 int /*<<< orphan*/  CiSaveConfigurationFile (TYPE_2__*) ; 
 int /*<<< orphan*/  CiSetError (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Delete (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  ERR_ACCOUNT_ACTIVE ; 
 int /*<<< orphan*/  ERR_ACCOUNT_NOT_FOUND ; 
 int /*<<< orphan*/  ERR_INTERNAL_ERROR ; 
 int /*<<< orphan*/  Free (TYPE_4__*) ; 
 int /*<<< orphan*/  Lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LockList (int /*<<< orphan*/ ) ; 
 TYPE_3__* Search (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  UniStrCpy (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UnlockList (int /*<<< orphan*/ ) ; 
 TYPE_4__* ZeroMalloc (int) ; 

bool CtDeleteAccount(CLIENT *c, RPC_CLIENT_DELETE_ACCOUNT *a, bool inner)
{
	bool ret;
	// Validate arguments
	if (c == NULL || a == NULL)
	{
		return false;
	}

	ret = false;

	if (c->Halt)
	{
		// Don't allow the removal of the account in the process of stopping
		CiSetError(c, ERR_INTERNAL_ERROR);
		return false;
	}

	LockList(c->AccountList);
	{
		ACCOUNT t, *r;
		// Search for an Account

		t.ClientOption = ZeroMalloc(sizeof(CLIENT_OPTION));
		UniStrCpy(t.ClientOption->AccountName, sizeof(t.ClientOption->AccountName), a->AccountName);

		r = Search(c->AccountList, &t);
		if (r == NULL)
		{
			// Specified account can not be found
			UnlockList(c->AccountList);

			Free(t.ClientOption);
			CiSetError(c, ERR_ACCOUNT_NOT_FOUND);
			return false;
		}

		Free(t.ClientOption);

		Lock(r->lock);
		{
			// Check the operating state of the account
			if (r->ClientSession != NULL)
			{
				// The account is active
				Unlock(r->lock);
				UnlockList(c->AccountList);
				CiSetError(c, ERR_ACCOUNT_ACTIVE);

				return false;
			}

			// Remove this account from the list
			Delete(c->AccountList, r);
		}
		Unlock(r->lock);

		// Free the memory of this account
		CiFreeAccount(r);

		CLog(c, "LC_DELETE_ACCOUNT", a->AccountName);
		ret = true;

	}
	UnlockList(c->AccountList);

	if (ret)
	{
		CiSaveConfigurationFile(c);
		CiNotify(c);
	}

	return ret;
}