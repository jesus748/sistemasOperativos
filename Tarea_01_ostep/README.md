# tarea_01_ostep

En este trabajo, se realizaron cambios en los archivos [mem.c](mem.c), [threads.c](threads.c),
[io.c](io.c).

## mem.c

slkadjflksdfjsldñfjsdlfñkjslfdñkjsadlfjñsldfjl

## threads.c

El objetivo de modificar este archivo, era poder administrar la ejecución de los hilos, para que el
programa se comporte siempre de forma correcta, apoyandonos en el concepto de "puertas" evitando que
 los hilos accedan a la variable counter de manera concurrente.

Para esto, se agregó la librería mycommon.h al threads.c en la cual se definieron los metodos de la puerta
(crear, abrir, cerrar, destruir).

Se definió una variable global puerta. Dentro del main, se creó la puerta (se inicializó). dentro del 
método que es usado por los hilos, worker. Específicamente, cuando un hilo entra en el ciclo for, antes 
de realizar el incremento de counter, se manda una señal para cerrar la puerta, de esta manera, 
asegurarse que esto va a ser realizado solo por el primer hilo en llegar, una vez incrementado el 
counter, se envía una señal para que se abra la puerta y así el proximo hilo pueda hacer el incremento
también.

Después que los dos hilos terminan con el ciclo for, antes de salir del main, se destruye la puerta.

## io.c

aslkñdfjsdklfñjsdfklñsjdfñlksdjf
