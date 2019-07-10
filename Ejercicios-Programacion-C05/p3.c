#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void mensaje() {
    printf("goodbye\n");
    exit(0);
}
int main (int argc, char const *argv[]) {
    int pidPadre = getpid();
    int rc = fork();
    if (rc == 0)
    {
        printf("hello\n");
        kill(pidPadre, SIGCONT);
        exit(0);
    }
    else if (rc > 0)
    {

        signal(SIGCONT, mensaje); // install signal handler
        pause();
    }
}
