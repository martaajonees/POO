# Ejercicio 1
Sean los operadores `x& operator ++()` y `x operator++(int)`:

__Apartado A__. ¿Cuáles son estos operadores?

Los operadores x& operator ++() y x operator++(int) son los operadores de preincremento y post-incremento respectivamente para una clase x.

__Apartado B__. ¿Cuál es la función del parámetro `int` en el segundo?

El parámetro int en el segundo operador (`x operator++(int)`) es utilizado como una convención para distinguirlo del operador de preincremento (`x& operator++()`). 

El valor del parámetro no se utiliza en el cuerpo del operador; su única función es proporcionar una firma distinta para el compilador para poder diferenciar entre el preincremento y el post-incremento.

__Apartado C__. ¿Por qué el primero es devuelto por referencia y el segundo por valor?

El primer operador devuelve una referencia para permitir la modificación directa del objeto, mientras que el segundo operador devuelve una copia del objeto original antes de la modificación, siguiendo la convención del operador de post-incremento.
