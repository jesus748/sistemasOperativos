#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <pthread.h>
#include <unistd.h>

volatile float v=0;
puerta door;

void *division(void *arg) {
    sleep(2);
    int z=25;
    int y=350;
    v=(float)z/y;
    abrir_puerta(door);

    return NULL;
}
void *multiplicacion(void *arg) {
    int x=1250;
    cerrar_puerta(door);
    v=(float)x*v;
    abrir_puerta(door);

    return NULL;
}


int main(int argc, char *argv[]) {

    crear_puerta(door);
    cerrar_puerta(door);
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, division, NULL);
    Pthread_create(&p2, NULL, multiplicacion, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    destruir_puerta(door);
    printf("V=  %f\n", v);

    return 0;
}
