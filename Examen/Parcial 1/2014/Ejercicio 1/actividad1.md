# Ejercicio 1
## Apartado 1
Solo es necesario definir el constructor con valores predeterminados. Los demás métodos son los generados automáticamente por el
compilador. Como no hay punteros ni memoria dinámica se pueden utilizar y nos ahorramos predefinirlos.

El programa quedaría:
```C++
class Complejo {
public:
  Complejo(double r = 0.0, double i= 0.0): r(r), i(i){}
private:
  double r, i; //parte real, parte imaginaria
};
```
