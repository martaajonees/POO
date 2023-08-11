# Ejercicio 1
Sea una clase vector para almacenar secuencias de números de coma flotante
y doble precisión. La longitud de un objeto `Vector` se establecerá en el momento de la
construcción y permanecerá fija hasta el momento de su destrucción.

```C++
class Vector{
public:
  // ....
private:
  size_t n;
  double* datos;
};
```

__Apartado 1__ Complete la clase Vector con la declaración de los métodos necesarios para que
las siguientes instrucciones proporcionen los resultados descritos en los comentarios y
explique por qué se producen los dos errores.
- `Vector v1(5, 1.2);` Resultado: v1 = {1.2, 1.2, 1.2, 1.2, 1.2}
- `Vector v2(4);`  Resultado: v2={0, 0, 0, 0}
- `Vector v3;` Resultado: error de compilación
- `Vector v4=3;` Resultado: error de compilación
- `Vector v5={1,2.5,3};` Resultado: v5={1,2.5,3}

__Apartado 2__ Defina los métodos declarados en el apartado anterior.

__Apartado 3__  ¿Es Válido el comportamiento del destructor por defecto? En caso afirmativo explique por qué, en caso contrario
implemente el método.

__Apartado 4__ Repita el apartado anterior para el constructor de copia.

__Apartado 5__ Repita el apartado anterior para el constructor de movimiento.

__Apartado 6__ Implemente el método `Vector::at( )` para que el siguiente fragmento de código se ejecute correctamente.
```C++
const Vector v6={1,2,3,4,5,6};
Vector v7(6);
try{
  v7.at(0)=v6.at(9);
}catch (std::out_of_range& e){
  std::cout << e.what() << std::endl;
}
```
