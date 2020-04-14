#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid = fork();
	if (pid == 0){
		chdir("/");
		
		setsid();
		printf("starting my demon\n");
		
		close(stdout);
		close(stdin);
		close(stderr);
		
		openlog("myDemon", LOG_PID, LOG_DAEMON);
		syslog(LOG_NOTICE, "demon started");
		usleep(3000000);
		syslog(LOG_NOTICE, "doing some work...");
		usleep(3000000);
		syslog(LOG_NOTICE, "demon finished");
	}
	else printf("demon PID %d\n", pid);
	return 0;
}