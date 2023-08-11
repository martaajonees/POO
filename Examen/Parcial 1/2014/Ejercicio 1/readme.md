# Ejercicio 1

Supongamos una clase en C++ para operar con números complejos:
```C++
class Complejo {
public:
  // ...
private:
  double r, i; //parte real, parte imaginaria
};
```
1. Defina los mínimos miembros imprescindibles para que las siguientes líneas de código se compilen y ejecuten correctamente y explique por qué no se necesitan otros.
   - `Complejo v(1.);`
   - `Complejo w;`
   - `Complejo x(2, -1.2);`
   - `Complejo y(x);`
   - `Complejo z = y`
   - `Complejo i2 = -1`
   -  `x = -3.5`
