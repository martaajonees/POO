# Ejercicio 1
## Apartado 1
La clase será de la siguiente forma:
```C++
class Vector{
public:
  explicit Vector(size_t t, double d = 0.0);
  Vector(const initializer_list<double>& t);
private:
  size_t n;
  double* datos;
};
```
Los errores de compilación se generan porque:
1. No existe un constructor sin parámetros.
2. Al tener el exlicit en el constructor no permite que el 3 se convierta implicitamente a clase `Vector`y como
   no hay operador de asignación válido da el error.

## Apartado 2
```C++
Vector::Vector(size_t t, double d): n(t), datos(new double[n]){
    for(int i = 0; i < n; i++){
        datos[i] = d;
    }
}

Vector::Vector(const initializer_list<double>& t): n(t.size()), datos(new double[n]){
    copy(t.begin(), t.end(), datos);
}
```
## Apartado 3
No es válido debido a que se hace uso del operador `new`, donde reserva un espacio de memoria. Para evitar 
errores, hay que liberar el espacio de memoria cuando no nos haga falta. Por eso no nos sirve el destructor por defecto.
La implementación es: 
```C++
Vector::~Vector(){
    delete[] datos; //Libera espacio de memoria
}
```
## Apartado 4
Por mismo motivo que en el apartado 3, hay que definirlo.
```C++
Vector::Vector(const Vector& v): n(v.n), datos(new double[n]){
    for(int i = 0; i < n; i++){
        datos[i] = v.datos[i];
    }
}
```

