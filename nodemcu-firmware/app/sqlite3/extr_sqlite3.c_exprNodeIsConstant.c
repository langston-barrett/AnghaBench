#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  iCur; } ;
struct TYPE_8__ {int eCode; TYPE_1__ u; } ;
typedef  TYPE_2__ Walker ;
struct TYPE_9__ {int op; int /*<<< orphan*/  iTable; } ;
typedef  TYPE_3__ Expr ;

/* Variables and functions */
 int /*<<< orphan*/  EP_ConstFunc ; 
 int /*<<< orphan*/  EP_FromJoin ; 
 scalar_t__ ExprHasProperty (TYPE_3__*,int /*<<< orphan*/ ) ; 
#define  TK_AGG_COLUMN 134 
#define  TK_AGG_FUNCTION 133 
#define  TK_COLUMN 132 
 int const TK_EXISTS ; 
#define  TK_FUNCTION 131 
#define  TK_ID 130 
#define  TK_IF_NULL_ROW 129 
 int const TK_NULL ; 
 int const TK_SELECT ; 
#define  TK_VARIABLE 128 
 int WRC_Abort ; 
 int WRC_Continue ; 
 int /*<<< orphan*/  testcase (int) ; 

__attribute__((used)) static int exprNodeIsConstant(Walker *pWalker, Expr *pExpr){

  /* If pWalker->eCode is 2 then any term of the expression that comes from
  ** the ON or USING clauses of a left join disqualifies the expression
  ** from being considered constant. */
  if( pWalker->eCode==2 && ExprHasProperty(pExpr, EP_FromJoin) ){
    pWalker->eCode = 0;
    return WRC_Abort;
  }

  switch( pExpr->op ){
    /* Consider functions to be constant if all their arguments are constant
    ** and either pWalker->eCode==4 or 5 or the function has the
    ** SQLITE_FUNC_CONST flag. */
    case TK_FUNCTION:
      if( pWalker->eCode>=4 || ExprHasProperty(pExpr,EP_ConstFunc) ){
        return WRC_Continue;
      }else{
        pWalker->eCode = 0;
        return WRC_Abort;
      }
    case TK_ID:
    case TK_COLUMN:
    case TK_AGG_FUNCTION:
    case TK_AGG_COLUMN:
      testcase( pExpr->op==TK_ID );
      testcase( pExpr->op==TK_COLUMN );
      testcase( pExpr->op==TK_AGG_FUNCTION );
      testcase( pExpr->op==TK_AGG_COLUMN );
      if( pWalker->eCode==3 && pExpr->iTable==pWalker->u.iCur ){
        return WRC_Continue;
      }
      /* Fall through */
    case TK_IF_NULL_ROW:
      testcase( pExpr->op==TK_IF_NULL_ROW );
      pWalker->eCode = 0;
      return WRC_Abort;
    case TK_VARIABLE:
      if( pWalker->eCode==5 ){
        /* Silently convert bound parameters that appear inside of CREATE
        ** statements into a NULL when parsing the CREATE statement text out
        ** of the sqlite_master table */
        pExpr->op = TK_NULL;
      }else if( pWalker->eCode==4 ){
        /* A bound parameter in a CREATE statement that originates from
        ** sqlite3_prepare() causes an error */
        pWalker->eCode = 0;
        return WRC_Abort;
      }
      /* Fall through */
    default:
      testcase( pExpr->op==TK_SELECT ); /* selectNodeIsConstant will disallow */
      testcase( pExpr->op==TK_EXISTS ); /* selectNodeIsConstant will disallow */
      return WRC_Continue;
  }
}