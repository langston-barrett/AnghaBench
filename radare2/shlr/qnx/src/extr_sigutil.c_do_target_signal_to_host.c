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
typedef  enum target_signal { ____Placeholder_target_signal } target_signal ;

/* Variables and functions */
 int EXC_ARITHMETIC ; 
 int EXC_BAD_ACCESS ; 
 int EXC_BAD_INSTRUCTION ; 
 int EXC_BREAKPOINT ; 
 int EXC_EMULATION ; 
 int EXC_SOFTWARE ; 
 int REALTIME_HI ; 
 int REALTIME_LO ; 
 int SIGABRT ; 
 int SIGALRM ; 
 int SIGBUS ; 
 int SIGCANCEL ; 
 int SIGCHLD ; 
 int SIGCLD ; 
 int SIGCONT ; 
 int SIGDANGER ; 
 int SIGEMT ; 
 int SIGFPE ; 
 int SIGGRANT ; 
 int SIGHUP ; 
 int SIGILL ; 
 int SIGINFO ; 
 int SIGINT ; 
 int SIGIO ; 
 int SIGKILL ; 
 int SIGLOST ; 
 int SIGLWP ; 
 int SIGMSG ; 
 int SIGPHONE ; 
 int SIGPIPE ; 
 int SIGPOLL ; 
 int SIGPRIO ; 
 int SIGPROF ; 
 int SIGPWR ; 
 int SIGQUIT ; 
 int SIGRETRACT ; 
 int SIGSAK ; 
 int SIGSEGV ; 
 int SIGSOUND ; 
 int SIGSTOP ; 
 int SIGSYS ; 
 int SIGTERM ; 
 int SIGTRAP ; 
 int SIGTSTP ; 
 int SIGTTIN ; 
 int SIGTTOU ; 
 int SIGURG ; 
 int SIGUSR1 ; 
 int SIGUSR2 ; 
 int SIGVTALRM ; 
 int SIGWAITING ; 
 int SIGWINCH ; 
 int SIGWIND ; 
 int SIGXCPU ; 
 int SIGXFSZ ; 
#define  TARGET_EXC_ARITHMETIC 180 
#define  TARGET_EXC_BAD_ACCESS 179 
#define  TARGET_EXC_BAD_INSTRUCTION 178 
#define  TARGET_EXC_BREAKPOINT 177 
#define  TARGET_EXC_EMULATION 176 
#define  TARGET_EXC_SOFTWARE 175 
#define  TARGET_SIGNAL_0 174 
#define  TARGET_SIGNAL_ABRT 173 
#define  TARGET_SIGNAL_ALRM 172 
#define  TARGET_SIGNAL_BUS 171 
#define  TARGET_SIGNAL_CANCEL 170 
#define  TARGET_SIGNAL_CHLD 169 
#define  TARGET_SIGNAL_CONT 168 
#define  TARGET_SIGNAL_DANGER 167 
#define  TARGET_SIGNAL_EMT 166 
#define  TARGET_SIGNAL_FPE 165 
#define  TARGET_SIGNAL_GRANT 164 
#define  TARGET_SIGNAL_HUP 163 
#define  TARGET_SIGNAL_ILL 162 
#define  TARGET_SIGNAL_INFO 161 
#define  TARGET_SIGNAL_INT 160 
#define  TARGET_SIGNAL_IO 159 
#define  TARGET_SIGNAL_KILL 158 
#define  TARGET_SIGNAL_LOST 157 
#define  TARGET_SIGNAL_LWP 156 
#define  TARGET_SIGNAL_MSG 155 
#define  TARGET_SIGNAL_PHONE 154 
#define  TARGET_SIGNAL_PIPE 153 
#define  TARGET_SIGNAL_POLL 152 
#define  TARGET_SIGNAL_PRIO 151 
#define  TARGET_SIGNAL_PROF 150 
#define  TARGET_SIGNAL_PWR 149 
#define  TARGET_SIGNAL_QUIT 148 
 int TARGET_SIGNAL_REALTIME_127 ; 
 int TARGET_SIGNAL_REALTIME_32 ; 
 int TARGET_SIGNAL_REALTIME_33 ; 
 int TARGET_SIGNAL_REALTIME_63 ; 
 int TARGET_SIGNAL_REALTIME_64 ; 
#define  TARGET_SIGNAL_RETRACT 147 
#define  TARGET_SIGNAL_SAK 146 
#define  TARGET_SIGNAL_SEGV 145 
#define  TARGET_SIGNAL_SOUND 144 
#define  TARGET_SIGNAL_STOP 143 
#define  TARGET_SIGNAL_SYS 142 
#define  TARGET_SIGNAL_TERM 141 
#define  TARGET_SIGNAL_TRAP 140 
#define  TARGET_SIGNAL_TSTP 139 
#define  TARGET_SIGNAL_TTIN 138 
#define  TARGET_SIGNAL_TTOU 137 
#define  TARGET_SIGNAL_URG 136 
#define  TARGET_SIGNAL_USR1 135 
#define  TARGET_SIGNAL_USR2 134 
#define  TARGET_SIGNAL_VTALRM 133 
#define  TARGET_SIGNAL_WAITING 132 
#define  TARGET_SIGNAL_WINCH 131 
#define  TARGET_SIGNAL_WIND 130 
#define  TARGET_SIGNAL_XCPU 129 
#define  TARGET_SIGNAL_XFSZ 128 
 int _NSIG ; 

__attribute__((used)) static int
do_target_signal_to_host (enum target_signal oursig,
			  int *oursig_ok) {
	int retsig;
	/* Silence the 'not used' warning, for targets that
     do not support signals.  */
	(void)retsig;

	*oursig_ok = 1;
	switch (oursig) {
	case TARGET_SIGNAL_0:
		return 0;

#if defined(SIGHUP)
	case TARGET_SIGNAL_HUP:
		return SIGHUP;
#endif
#if defined(SIGINT)
	case TARGET_SIGNAL_INT:
		return SIGINT;
#endif
#if defined(SIGQUIT)
	case TARGET_SIGNAL_QUIT:
		return SIGQUIT;
#endif
#if defined(SIGILL)
	case TARGET_SIGNAL_ILL:
		return SIGILL;
#endif
#if defined(SIGTRAP)
	case TARGET_SIGNAL_TRAP:
		return SIGTRAP;
#endif
#if defined(SIGABRT)
	case TARGET_SIGNAL_ABRT:
		return SIGABRT;
#endif
#if defined(SIGEMT)
	case TARGET_SIGNAL_EMT:
		return SIGEMT;
#endif
#if defined(SIGFPE)
	case TARGET_SIGNAL_FPE:
		return SIGFPE;
#endif
#if defined(SIGKILL)
	case TARGET_SIGNAL_KILL:
		return SIGKILL;
#endif
#if defined(SIGBUS)
	case TARGET_SIGNAL_BUS:
		return SIGBUS;
#endif
#if defined(SIGSEGV)
	case TARGET_SIGNAL_SEGV:
		return SIGSEGV;
#endif
#if defined(SIGSYS)
	case TARGET_SIGNAL_SYS:
		return SIGSYS;
#endif
#if defined(SIGPIPE)
	case TARGET_SIGNAL_PIPE:
		return SIGPIPE;
#endif
#if defined(SIGALRM)
	case TARGET_SIGNAL_ALRM:
		return SIGALRM;
#endif
#if defined(SIGTERM)
	case TARGET_SIGNAL_TERM:
		return SIGTERM;
#endif
#if defined(SIGUSR1)
	case TARGET_SIGNAL_USR1:
		return SIGUSR1;
#endif
#if defined(SIGUSR2)
	case TARGET_SIGNAL_USR2:
		return SIGUSR2;
#endif
#if defined(SIGCHLD) || defined(SIGCLD)
	case TARGET_SIGNAL_CHLD:
#if defined(SIGCHLD)
		return SIGCHLD;
#else
		return SIGCLD;
#endif
#endif /* SIGCLD or SIGCHLD */
#if defined(SIGPWR)
	case TARGET_SIGNAL_PWR:
		return SIGPWR;
#endif
#if defined(SIGWINCH)
	case TARGET_SIGNAL_WINCH:
		return SIGWINCH;
#endif
#if defined(SIGURG)
	case TARGET_SIGNAL_URG:
		return SIGURG;
#endif
#if defined(SIGIO)
	case TARGET_SIGNAL_IO:
		return SIGIO;
#endif
#if defined(SIGPOLL)
	case TARGET_SIGNAL_POLL:
		return SIGPOLL;
#endif
#if defined(SIGSTOP)
	case TARGET_SIGNAL_STOP:
		return SIGSTOP;
#endif
#if defined(SIGTSTP)
	case TARGET_SIGNAL_TSTP:
		return SIGTSTP;
#endif
#if defined(SIGCONT)
	case TARGET_SIGNAL_CONT:
		return SIGCONT;
#endif
#if defined(SIGTTIN)
	case TARGET_SIGNAL_TTIN:
		return SIGTTIN;
#endif
#if defined(SIGTTOU)
	case TARGET_SIGNAL_TTOU:
		return SIGTTOU;
#endif
#if defined(SIGVTALRM)
	case TARGET_SIGNAL_VTALRM:
		return SIGVTALRM;
#endif
#if defined(SIGPROF)
	case TARGET_SIGNAL_PROF:
		return SIGPROF;
#endif
#if defined(SIGXCPU)
	case TARGET_SIGNAL_XCPU:
		return SIGXCPU;
#endif
#if defined(SIGXFSZ)
	case TARGET_SIGNAL_XFSZ:
		return SIGXFSZ;
#endif
#if defined(SIGWIND)
	case TARGET_SIGNAL_WIND:
		return SIGWIND;
#endif
#if defined(SIGPHONE)
	case TARGET_SIGNAL_PHONE:
		return SIGPHONE;
#endif
#if defined(SIGLOST)
	case TARGET_SIGNAL_LOST:
		return SIGLOST;
#endif
#if defined(SIGWAITING)
	case TARGET_SIGNAL_WAITING:
		return SIGWAITING;
#endif
#if defined(SIGCANCEL)
	case TARGET_SIGNAL_CANCEL:
		return SIGCANCEL;
#endif
#if defined(SIGLWP)
	case TARGET_SIGNAL_LWP:
		return SIGLWP;
#endif
#if defined(SIGDANGER)
	case TARGET_SIGNAL_DANGER:
		return SIGDANGER;
#endif
#if defined(SIGGRANT)
	case TARGET_SIGNAL_GRANT:
		return SIGGRANT;
#endif
#if defined(SIGRETRACT)
	case TARGET_SIGNAL_RETRACT:
		return SIGRETRACT;
#endif
#if defined(SIGMSG)
	case TARGET_SIGNAL_MSG:
		return SIGMSG;
#endif
#if defined(SIGSOUND)
	case TARGET_SIGNAL_SOUND:
		return SIGSOUND;
#endif
#if defined(SIGSAK)
	case TARGET_SIGNAL_SAK:
		return SIGSAK;
#endif
#if defined(SIGPRIO)
	case TARGET_SIGNAL_PRIO:
		return SIGPRIO;
#endif

/* Mach exceptions.  Assumes that the values for EXC_ are positive! */
#if defined(EXC_BAD_ACCESS) && defined(_NSIG)
	case TARGET_EXC_BAD_ACCESS:
		return _NSIG + EXC_BAD_ACCESS;
#endif
#if defined(EXC_BAD_INSTRUCTION) && defined(_NSIG)
	case TARGET_EXC_BAD_INSTRUCTION:
		return _NSIG + EXC_BAD_INSTRUCTION;
#endif
#if defined(EXC_ARITHMETIC) && defined(_NSIG)
	case TARGET_EXC_ARITHMETIC:
		return _NSIG + EXC_ARITHMETIC;
#endif
#if defined(EXC_EMULATION) && defined(_NSIG)
	case TARGET_EXC_EMULATION:
		return _NSIG + EXC_EMULATION;
#endif
#if defined(EXC_SOFTWARE) && defined(_NSIG)
	case TARGET_EXC_SOFTWARE:
		return _NSIG + EXC_SOFTWARE;
#endif
#if defined(EXC_BREAKPOINT) && defined(_NSIG)
	case TARGET_EXC_BREAKPOINT:
		return _NSIG + EXC_BREAKPOINT;
#endif

#if defined(SIGINFO)
	case TARGET_SIGNAL_INFO:
		return SIGINFO;
#endif

	default:
#if defined(REALTIME_LO)
		retsig = 0;

		if (oursig >= TARGET_SIGNAL_REALTIME_33 && oursig <= TARGET_SIGNAL_REALTIME_63) {
			/* This block of signals is continuous, and
             TARGET_SIGNAL_REALTIME_33 is 33 by definition.  */
			retsig = (int)oursig - (int)TARGET_SIGNAL_REALTIME_33 + 33;
		} else if (oursig == TARGET_SIGNAL_REALTIME_32) {
			/* TARGET_SIGNAL_REALTIME_32 isn't contiguous with
             TARGET_SIGNAL_REALTIME_33.  It is 32 by definition.  */
			retsig = 32;
		} else if (oursig >= TARGET_SIGNAL_REALTIME_64 && oursig <= TARGET_SIGNAL_REALTIME_127) {
			/* This block of signals is continuous, and
             TARGET_SIGNAL_REALTIME_64 is 64 by definition.  */
			retsig = (int)oursig - (int)TARGET_SIGNAL_REALTIME_64 + 64;
		}

		if (retsig >= REALTIME_LO && retsig < REALTIME_HI)
			return retsig;
#endif

		*oursig_ok = 0;
		return 0;
	}
}