# Ejercicio 2
Defina una clase de nombre doble con un único atributo, privado y no
estático, de tipo `double` para que el siguiente programa se compile y se ejecute sin
errores. 

_Para resolver el ejercicio no está permitida la sobrecarga de operadores
aritméticos, de asignación ni de inserción en flujo de salida, así como tampoco el uso de
funciones amigas._

```C++
int main(){
  double a = 1.5, b= 10.5;
  doble c = 5.25,
  d=c;
  std::cout << c / d * b + b * c – c * c / b + b / c << std::endl; //65
  d = a = b += c;
  std::cout << d << ' ' << a << ' ' << b << ' '<< c << std::endl; // 15,75 15,75 15,75 5,25
}
```
