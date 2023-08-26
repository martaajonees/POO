# Ejercicio 5

Para que el programa se ejecute, hay que inicializar la variable estática de la siguiente forma:
```C++
int C::n = 0;
int C::m = 0;
```
Tras esto, el programa se ejecutará correctamente y se imprimirá `4 4`. 
Debido a que tanto `C::n` como `c1.n` apuntan a el mismo objeto estático.
