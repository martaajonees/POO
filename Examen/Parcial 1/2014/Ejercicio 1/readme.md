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
2. Complete la clase complejo con las declaraciones y definiciones de las funciones
mínimas necesarias, ya sea como miembros de la clase o como funciones externas
según convenga para que el siguiente programa se ejecute sin errores:
```C++
int main(){
  Complejo i, i2, z, y;
  i.real() = 0;
  i.imag() = 1;
  i2 = i * i;
  if ( i2 == complejo(-1.0)) cout << “OK\n”;
  if ( i2 != -1.0) cout << “MAL\n”;
  z = y = complejo(2.5, 1);
  y.imag() = -y.imag();
  if ( z + y == 2 * z.real()) cout << “OK\n”;
  else cout << “MAL\n”;
  if ( z + -y != complejo(0,2 * z.imag())) cout << “MAL\n”;
  else cout << “OK\n”;
}
```
