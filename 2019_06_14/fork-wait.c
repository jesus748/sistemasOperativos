#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
	pid_t pid;

	pid = fork();
	if(pid==0){
	sleep(3);
	printf("soy el hijo y mi identificador es %d \n", getpid());
	}else{
	pid_t pid2;
	int status;
	printf("Soy el padre, mi identificador es %d y el de mi hijo es %d \n", getpid(), pid);
	pid2=wait(NULL);
	printf("termino el hijo %d \n", pid2);
	}
	
}
