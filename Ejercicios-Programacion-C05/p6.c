#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

        int rc=fork();
        if(rc<0){

                fprintf(stderr,"fork failed\n");
                exit(1);
        }else if (rc==0){

        printf("\nHola, soy el hijo de: %d\n", getppid());

        }else{
        int wait_rc=waitpid(rc,NULL,0);
        printf("\nHola, soy el padre de: %d\n", rc);
        printf("el wait retorna: %d \n", wait_rc);
        }

        return 0;
}

