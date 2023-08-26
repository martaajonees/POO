# Ejercicio 2

## Constructor predeterminado 
El constructor predeterminado es: 
```C++
matriz(size_t m = 1, size_t n = 1, double y = 0.0);
```
__Programa de prueba__ :
```C++
int main(){
    matriz m;
}
```
## Constructor de copia 
El constructor de copia es: 
```C++
matriz(const matriz&);
```
__Programa de prueba__ :
```C++
int main(){
    matriz m, n(m);
}
```
## Constructor de movimiento
El constructor de movimiento es: 
```C++
matriz(matriz&&);
```
__Programa de prueba__ :
```C++
int main(){
    matriz m;
    matriz A = std::move(m);
}
```
## Constructor de conversión
El constructor de movimiento es: 
```C++
matriz(matriz&&);
```
__Programa de prueba__ :
```C++
int main(){
    matriz m;
    matriz A = std::move(m);
}
```
