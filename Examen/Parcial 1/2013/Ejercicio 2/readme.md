# Ejercicio 2
Considere las siguientes declaraciones, independientes de las definiciones asociadas.
```C++
Class A {};

Class B {
public:
  B(int i, const char* s = “”, int j = 0);
  B& operator = (const B& b):
  B& operator = (const A& a):
};
```
__Apartado A__ Diga si cada línea del siguiente fragmento de código es o no correcta (con un SI o un NO) y explica en una única frase el
porqué. Simplemente debe decir que se ejecuta de cada clase, si es correcto, o qué le faltaría a las clases A y B para que se pudiera
ejecutar, en caso contrario. Suponga que en cada línea se han ejecutado correctamente las anteriores.
1. `A a1, a2;`
2. `B b1 = 0;`
3. `B *p = new B(10);`
4. `B * q = new B [10]`
5. `B b2 = "examen"`
6. `A a3(b1);`
7. `a2 = a1 = *q`
8. `B b3 = a2`
