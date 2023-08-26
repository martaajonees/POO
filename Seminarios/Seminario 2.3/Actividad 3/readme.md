Describa los errores que hay en el siguiente código:
```C++
  matriz A = 3;
  matriz B = matriz(5);
  matriz C(3);
  B=2;
  A = matriz(5);
```
¿Por qué se declara explicit el primer constructor de la clase matriz? 
¿Podría causar algún problema si no se hiciera así? 
Y en caso afirmativo, ¿se podría evitar ese problema definiendo un operador de conversión de int a matriz? 
Razone la respuesta.
