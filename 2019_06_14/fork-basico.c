#include<unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
	pid_t pid;

	pid = fork();
	
	if(pid==0){
	printf("soy el hijo y mi identificador es %d \n", getpid());
	}else{
	printf("Soy el padre, mi identificador es %d y el de mi hijo es %d \n", getpid(), pid);
	}
	
}
