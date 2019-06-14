#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "solucion.h"
#include <stdio.h>

int main(int argc, char** argv) {
  int x=20;

  pid_t pid=fork();

  if(pid==0){
    printf("fibonacci(%d) = ",x);
    x = fibonacci(x);
    printf("%d\n",x);
    guardarEntero("archivo",x);
  }else{
    wait(NULL);
    x=leerEntero("archivo")*100;
    printf("el resultado es: %d \n", x);
  }
  return 0;
}
