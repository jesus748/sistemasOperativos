# tarea_01_ostep

En este trabajo, se realizaron cambios en los archivos [mem.c](mem.c), [threads.c](threads.c),
[io.c](io.c).

## mem.c

Al ejecutar mem se crea un contador llamado p que ira sumando de 1 en 1 mientras se repita el bucle todo esto
es guardado en un espacio especifico de la memoria que es mostrada al principio. Con esto al correr dos veces 
el programa de manera concurrente se puede observar como cada valor p es guardado en una seccion diferente en 
esa parte de la memoria.

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

Se desarrolla un programa que pide una entrada de texto por consola, para cargar un archivo de texto plano.
El programa toma todos los caracteres que hay en el archivo y retorna al revés todo el contenido de dicho 
archivo. 

Con el uso de FILE se intenta cargar el archivo con el nombre indicado, de no poder cargarse se envia un 
mensaje negativo. 

Si se puede cargar, el contenido del archivo se guarda en la variable file para poder acceder de forma 
individual a cada uno de los caracteres incluidos en él. 

Mediante la función fseek() nos paramos en la parte final del archivo, en cada iteración con la función 
ftell() verificamos en que punto del archivo nos encontramos, cuando se llegue al inicio de este, paramos. 

Al estar ubicados al final del archivo, en cada iteración del ciclo, retornamos el caracter que se encuentra 
en dicha posición y luego nos ubicamos en la posición anterior a la cual acabamos de retornar, repetimos estos
pasos devolviendonos y retorando cada uno de los caracteres contenidos en el archivo desde la parte final, al
inico de este.

Cuando se termina de recorrer el archivo, en la pantalla se muestra el contenido de este totalmente al revés.
