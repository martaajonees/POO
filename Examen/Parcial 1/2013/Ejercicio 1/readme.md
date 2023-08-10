Supongamos una clase en C++ para operar con números complejos
```C++
class Complejo {
public:
  // ...
private:
  double r, i; //parte real, parte imaginaria
};
```
__Apartado A.__ Defina el mínimo de miembros imprescindibles para que las siguientes líneas compilen y se ejecuten. 
Explique por qué no se necesitan otros
1. `Complejo v(1.);`
2. `Complejo w;`
3. `Complejo x(2, -1.2);`
4. `Complejo y(x);`
5. `Complejo z = y`
6. `Complejo i2 = -1`
7. `x = -3.5;`

__Apartado B.__ Complete la clase `Complejo` con las declaraciones y definiciones de las funciones mínimas necesarias, ya sea como miembros de la clase o como funciones externas según convenga para que el siguiente programa se ejecute sin errores.
```C++
int main() {
Complejo i, i2, z, y;
i.real() = 0;
i.imag() = 1;
i2 = i * i;
if ( i2 == Complejo(-1.0)) cout << “OK\n”;
if ( i2 != -1.0) cout << “MAL\n”;
z = y = Complejo(2.5, 1);
y.imag() = -y.imag();
if ( z + y == 2 * z.real()) cout << “OK\n”;
else cout << “MAL\n”;
if ( z + -y != Complejo(0,2 * z.imag())) cout << “MAL\n”;
else cout << “OK\n”;
};
```
