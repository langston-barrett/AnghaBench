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

/* Variables and functions */
 int /*<<< orphan*/  SIGPOLL ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int const)) ; 
 int /*<<< orphan*/  sigpoll_cnt ; 

__attribute__((used)) static void sigpoll_handler (const int sig) {
  sigpoll_cnt++;
  signal (SIGPOLL, sigpoll_handler);
}