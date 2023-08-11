# Ejercicio 1
## Apartado A
la clase será de la siguiente forma:
```C++
class Vector{
public:
  explicit Vector(size_t t, double d = 0.0);
  Vector(initializer_list<double> t);
  void mostrar();
private:
  size_t n;
  double* datos;
};
```
Los errores de compilación se genera porque:
1. No existe un constructor sin parámetros.
2. Al tener el exlicit en el constructor no permite que el 3 se convierta implicitamente a clase `Vector`y como
   no hay operador de asignación válido da el error.
