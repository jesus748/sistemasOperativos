#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main( int argc, char *argv[]){

	int rc=fork();

    if (rc == 0){ // hijo
        close(STDOUT_FILENO);
        printf("Holaaaaa?\n");
    }
    else if (rc > 0){
        wait(NULL);
        printf("Soy el padre\n");
    }

}
