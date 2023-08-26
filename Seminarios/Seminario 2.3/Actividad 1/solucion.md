# Ejercicio 1

## Constructores

1. `explicit matriz(size_t m = 1, size_t n = 1, double y = 0.0)`
2. `matriz(size_t m, size_t n, double f(size_t i, size_t j));` 
3. `matriz(const initializer_list<valarray<double>>& l);`
4. `matriz(const matriz&) = default;` 
5. `matriz(matriz&&) = default;`

## Destructores

## Observadores

1. `size_t filas() const;` 
2. `size_t columnas() const;` 
3. `double operator ()(size_t i, size_t j) const;`  
5. `valarray<double> operator [](size_t i) const;` 
7. `valarray<double> operator ()(size_t j) const;`
   
## Modificadores
4. `double& operator ()(size_t i, size_t j);`
5. `slice_array<double> operator [](size_t i);`
8. `slice_array<double> operator ()(size_t j);`
1. `matriz& operator =(const matriz&) = default;` 
2. `matriz& operator =(matriz&&) = default;` 
3. `matriz& operator +=(const matriz& a);` 
4. `matriz& operator-=(const matriz& a);` 
5. `matriz& operator *=(const matriz& a);` 
6. `matriz& operator *=(double y);`
