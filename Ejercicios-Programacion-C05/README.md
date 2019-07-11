#Capitulo 5

1. [p1.c][p1]. El programa se ejecuta, el proceso npadre hacede a una variable y le establece un valor despues se hace una llamado a fork(), la variable es procesada por el porceso npadre y el proceso nhijo imprimiendo cada uno la variable con el valor que establecieron.

2. [p2.c][p2]. El programa abre un archivo usando open() para despues utilizar fork() y crear un nuevo proceso, despues tanto el proceso npadre como el proceso nhijo pueden haceder al archivo y escribir en el pero uno es elegido para funcionar primero.

3. [p3.c][p3]. El programa hace uso de pitPadre para asegurar que el nhijo siempre imprima primero, por lo que se sigue usando wait para que funcione.

4. [p4.c][p4]. El programa hace un llamado a diferentes variantes de exec(), aunque la funcinalidad de estas variables es similar su distincion principal esta en la sintaxis con la que funcionan.

5. [p5.c][p5]. El programa al ejecutarse se crea un proceso nhijo, el proceso npadre es pausado por la funcion wait mientras la funcion nhijo es ejecutada he imprime su valor, despues la funcion npadre se ejecuta he imprime su valor.
Cuando el wait se aplica al nhijo su proceso de detiene y es el proceso npadre quien se ejecuta primero.

6. [p6.c][p6]. waitpid es mas versatil en las opciones para pausar un proceso, funciona mejor cuando varios procesos nhijos se esten ejecutadno permitiendo que se ejecute mas de uno antes que el proceso npadre a diferencia de wait.

7. [p7.c][p7]. El programa se ejecuta se crea un proceso nhijo, se pide la impresion de ambos precesos pero antes se cierra STDOUT_FILENO en el proceso nhijo impidiendo que imprima en pantallam, resultando en una sola imprecion por parte del proceso npadre.



[p1]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p1.c
[p2]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p2.c
[p3]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p3.c
[p4]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p3.c
[p5]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p5.c
[p6]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p6.c
[p7]: https://github.com/jesus748/sistemasOperativos/blob/master/Ejercicios-Programacion-C05/p7.c/


