# Ejercicio 1
## Apartado A
La clase será de la siguiente forma:
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
Los errores de compilación se generan porque:
1. No existe un constructor sin parámetros.
2. Al tener el exlicit en el constructor no permite que el 3 se convierta implicitamente a clase `Vector`y como
   no hay operador de asignación válido da el error.

## Apartado B
```C++
void Vector::mostrar(){
    for(int i = 0; i < n; i++){
        cout << datos[i] << " ";
    }
}

Vector::Vector(size_t t, double d): n(t), datos(new double[n]){
    for(int i = 0; i < n; i++){
        datos[i] = d;
    }
}

Vector::Vector(initializer_list<double> t): n(t.size()), datos(new double[n]){
    copy(t.begin(), t.end(), datos);
}
```
