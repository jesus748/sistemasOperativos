#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    struct stat sb;
    int archivo = open("texto.txt", O_CREAT | O_RDWR, S_IRWXU);
    int rc = fork();

    if (rc == 0)
    {
        const char * mensajehijo = "soy el hijo\n";
        write(archivo, mensajehijo , strlen(mensajehijo));
        exit(0);
    }
    else if (rc > 0)
    {
        wait(NULL);
        const char * mensajepadre = "soy el padre\n";
        write(archivo, mensajepadre, strlen(mensajepadre));
    }
    sync();
    fstat(archivo, &sb);
    lseek(archivo, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(archivo, buffer, sb.st_size);

    printf("Contenido del archivo \n%s", buffer);
    close(archivo);
    return 0;
}
