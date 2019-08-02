#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <pthread.h>
#include <time.h>

volatile int counter = 0;
int loops;
puerta door;

void *worker(void *arg) {
    int i;
	cerrar_puerta(door); //descomentar para caso 1
    for (i = 0; i < loops; i++) {
        //cerrar_puerta(door); //descomentar para caso 2
        counter++;
        //abrir_puerta(door); //descomentar para caso 2
    }
	abrir_puerta(door); //descomentar para caso 1

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "usage: threads <loops>\n");
	exit(1);
    }
    crear_puerta(door);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    clock_t initTime, endTime;
    double tTotal;
    initTime=clock();
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    destruir_puerta(door);
    printf("Final value   : %d\n", counter);
    printf("tiempo total: %f/n", (double) (clock()-initTime)/CLOCKS_PER_SEC);

    return 0;
}
