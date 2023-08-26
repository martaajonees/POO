# Ejercicio 6

## Apartado 1

El error de compilación que sale es: 

> se aplica más de una conversión definida por el usuario de "B" a "const A":

Por tanto, es necesario modificar el constructor de conversión de B a A para que acepte referencias constantes. 
Así, arreglamos el problema.
```C++
struct B; // Declaración adelantada

struct A {
  A(const B&);// Constructor de conversión de B a A
};

struct B {
operator A(); // Operador de conversión de B a A
};

void f(const A&); // Recibe por referencia un objeto constante de A

int main() {
   B b; 
   f(b);
}
```

## Apartado 2
El error de compilación que sale es: 

> una referencia de tipo "A &" (no calificado constante) no se puede inicializar con un valor de tipo "B"

Para solucionarlo, se puede definir el operador de conversión que acepte un objeto de tipo B y 
devuelva una referencia a un objeto de tipo A.
```C++
struct B; // Declaración adelantada

struct A {
  A(B);// Constructor de conversión de B a A
};

struct B {
operator A&(); // Operador de conversión de B a A
};

void f(A&); // Recibe por referencia un objeto constante de A

int main() {
   B b; 
   f(b);
}
```
