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
typedef  int /*<<< orphan*/  svn_token_map_t ;
struct TYPE_3__ {int /*<<< orphan*/  db; int /*<<< orphan*/  s3stmt; } ;
typedef  TYPE_1__ svn_sqlite__stmt_t ;
typedef  int /*<<< orphan*/  svn_error_t ;

/* Variables and functions */
 int /*<<< orphan*/  SQLITE_ERR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SQLITE_STATIC ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  sqlite3_bind_text (int /*<<< orphan*/ ,int,char const*,int,int /*<<< orphan*/ ) ; 
 char* svn_token__to_word (int /*<<< orphan*/  const*,int) ; 

svn_error_t *
svn_sqlite__bind_token(svn_sqlite__stmt_t *stmt,
                       int slot,
                       const svn_token_map_t *map,
                       int value)
{
  const char *word = svn_token__to_word(map, value);

  SQLITE_ERR(sqlite3_bind_text(stmt->s3stmt, slot, word, -1, SQLITE_STATIC),
             stmt->db);
  return SVN_NO_ERROR;
}