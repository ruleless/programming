
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void sigAlarm(int signo) {
}
unsigned int sleepex(unsigned int sec) {
	if (0 == sec) {
		return alarm(0);
	}

	struct sigaction newact, oldact;
	newact.sa_handler = sigAlarm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	if (sigaction(SIGALRM, &newact, &oldact) < 0) {
		return sec;
	}

	// 在alarm之前屏蔽SIGALRM的原因是：
	// 避免在alarm和sigsuspend调用之间产生SIGALRM信号
	sigset_t newmask, oldmask, suspmask;
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	suspmask = oldmask;
	sigdelset(&suspmask, SIGALRM);

	alarm(sec);
	sigsuspend(&suspmask);

	// 恢复信号屏蔽字
	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	// 恢复信号动作
	sigaction(SIGALRM, &oldact, NULL);

	return alarm(0);  // alarm(0)不会产生SIGALRM信号
}

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		unsigned int sec = atoi(argv[i]);
		printf("going to sleep %ds\n", sec);
		printf("%ds left\n", sleepex(sec));
	}
	exit(0);
}
