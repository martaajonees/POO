Defina una clase de nombre doble con un único atributo, privado y no
estático, de tipo `double` para que el siguiente programa se compile y
ejecute sin errores. 

_No está permitida la sobrecarga de operadores
aritméticos, de asignación, inserción, ni el uso de funciones amigas._
```C++
#include <iostream>

int main(){
double a = 1.5,b = 10.5;
double c = 5.25, d = c;
cout<< c/d * b+b * c-c * c/b + b/c <<endl; // 65
d= a = b += c;
cout << d << ’ ‘ << a << ’ ‘ << b << ’ ‘ << c << endl;
//15,75 15,75 15,75 5,25
}
```
