# Ejercicio 3
Dada la clase Fecha siguiente:
```C++
class Fecha{
public:
  //..
private:
  int dia_,mes_,anio_;
};
```
Sobrecargue el operador – para que restando dos fechas devuelva
un long con el número de días que la separan
1. Escriba dos declaraciones de dicho operador, una como miembro
y otra externa. Explique cuál es más conveniente y porque.
2. Asumiendo que ya están sobrecargados los operadores de
pre/post incremento, pre/post decremento y relacionales para
Fecha, escriba la implementación del operador – declarado.
3. ¿Considera conveniente la sobrecarga del operador binario +
para objetos Fecha?. Razone.
