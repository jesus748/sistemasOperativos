#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int x;

    x = 100;

    int rc = fork();

    if (rc == 0) // Hijo
    {

        printf("\nHijo\n");
        printf("Valor de X: %d\n", x);
        x = 101;
        printf("X modificado: %d\n", x);

    }
    else if (rc > 0) // Padre
    {
        wait(NULL);
        printf("\npadre\n");
        printf("Valor de x: %d\n", x);
        x = 102;
        printf("X modificado: %d\n", x);
    }
}
