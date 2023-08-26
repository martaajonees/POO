# Ejercicio 6
```C++
struct B; // Declaración adelantada

struct A {
  A(B);// Constructor de conversión de B a A
};

struct B {
operator A(); // Operador de conversión de B a A
};

void f(const A&); // Recibe por referencia un objeto constante de A

int main() {
   B b; f(b);
}
```
1. Describa el error de compilación que provoca el código anterior.
   ¿Cómo modificaría las clases sin suprimir métodos para solucionarlo?
2. Suponga que el parámetro de `f()` es de entrada y salida y la línea 9 es sustituida por `void f(A&);`.
¿Qué error de compilación se produce? ¿Y cómo se puede resolver sin suprimir métodos?
