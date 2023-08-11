# Ejercicio 1
Los racionales se guardarán siempre de manera canónica, no esta
permitido denominador 0 y el racional cero será almacenado como:
```C++
class racional {
public:
  //..
private:
  int n,d;
  static int mcd(int,int);
};
```
## Apartado A
Nombre los métodos necesarios para que las siguientes instrucciones muestren las salidas correspondientes.
   
1. `racional r(0,1)` //0
2. `racional s` //0
3. `racional t{4,-8}` //  -1/2
4. `racional u(3)` //  3/1
5. `racional v=5` //  5/1
6. `racional w=v`
7. `racional x{w}`
8. `r=t`
9. `s=racional{9,6}` //  3/2
10. `v=-4 `//  -4/1

## Apartado B
Defina los mínimos miembros imprescindibles para que compilen y
ejecuten las instrucciones del ___Apartado A___ y explique por qué no se
necesitan otros.

Deberá comprobar precondiciones y lanzar las excepciones adecuadas.

## Apartado C
Declare y defina los siguientes operadores y funciones.

- Funcion `inv()` //inverso del racional
- Operadores aritméticos +,-,* y /
- Operadores de signo + y –
- Operadores de comparación ==, !=, <, <=, > y >=

Comprobar precondiciones, lanzar excepciones. Utiliza inline cuando sea factible.
