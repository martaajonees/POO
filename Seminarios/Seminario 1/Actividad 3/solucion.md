# Ejercicio 3
En el `main()` vemos que se ha creado un objeto C de como un const. Como el método mostrar no es `const`, da error.

Para que funcione, debemos poner como `const` el método `mostrar()`

```C++
void mostrar() const { std::cout << "i = " << n << std::endl;}
```
