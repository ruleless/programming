#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

static int _g_signals[] =
{
	SIGINT,
	SIGQUIT,
	SIGSTOP,
	SIGKILL,
	SIGUSR1,
	SIGUSR2,
	SIGCHLD,
};

static const char* _g_signalstr[] =
{
	"SIGINT",
	"SIGQUIT",
	"SIGSTOP",
	"SIGKILL",
	"SIGUSR1",
	"SIGUSR2",
	"SIGCHLD",
};

static int _g_capturedsig = -1;

static void _sig_handler(int signo)
{
	_g_capturedsig = signo;
	for (int i = 0; i < sizeof(_g_signals); ++i)
	{
		if (signo == _g_signals[i])
		{
			printf("we capure signal:%s\n", _g_signalstr[i]);
			break;
		}
	}	
}

int main(int argc, char *argv[])
{
	struct sigaction sa, oldact;
	sa.sa_handler = _sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigset_t new_mask, old_mask, zero_mask;
	sigemptyset(&new_mask);
	sigemptyset(&old_mask);
	sigemptyset(&zero_mask);
	for (int i = 0; i < sizeof(_g_signals)/sizeof(int); ++i)
	{
		sigaddset(&new_mask, _g_signals[i]);
	}
	sigprocmask(SIG_BLOCK, &new_mask, &old_mask);

	for (int i = 0; i < sizeof(_g_signals)/sizeof(int); ++i)
	{
		sigaction(_g_signals[i], &sa, &oldact);
	}

	// suspend
	while (_g_capturedsig != SIGQUIT)
		sigsuspend(&zero_mask);

	// restore
	for (int i = 0; i < sizeof(_g_signals)/sizeof(int); ++i)
	{
		sigaction(_g_signals[i], &oldact, NULL);
	}	
	sigprocmask(SIG_SETMASK, &old_mask, NULL);
	
	exit(0);
}
