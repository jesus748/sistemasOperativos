Threads.c 

- En el primer caso el tiempo de ejecucion media fueron 
  0.000163
  0.000163
  0.000173
  0.000160
  0.000163
  La media fue de 0.163

- En el segundo caso el tiempo de ejecución media fue de 
  0.000165
  0.000179
  0.000166
  0.000174
  0.000178
  La media fue de 0.0007196

En el primer caso, al cerrar la puerta en el ciclo for, el primer hilo en entrar tiene total libertad y se puede ejecutar hasta el final,
una vez termina de hacer lo que está dentro del for, se abre la puerta y el otro hilo que estaba en espera se puede ejecutar.

En el segundo caso, al cerrar el ciclo for antes de modificar la variable global y cerrarla justo después de modificada hace que si un hilo
llegó primero, modifique la variable global una vez, después de esto, se abre la puerta y el siguiente en ejecutarse puede ser bien sea
el hilo 1 o el 2 en este caso se hace la comprabación si la puerta está abierta en cada uno de los ciclos del For, en caso contrario, se espera
hasta que el otro hilo termine su ciclo y la libere.

El segundo caso se tarda más debido a la cantidad de veces que tiene que comprobar si la puerta está abierta o cerrada.


Pregunta 2

Después de crear la puerta, se cierra inmediatamente, de esta forma se garantiza que 
el hilo 1 sea el primero que sa vaya a ejecutar(division), ya que el segundo va a estar bloqueado,
despues de realizar la operacion 1  se abre la puerta y ahí es el momento en el que se 
ejecuta el hilo 2.(multiplicacion)


