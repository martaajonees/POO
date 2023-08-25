# Ejercicio 3
¿Hay algún error en el siguiente programa? Si es así, explique por qué y corríjalo.
```C++
#include <iostream> 
class C { 
  public:
    C(int i = 0): n(i) {}
    void mostrar() { std::cout << "i = " << n << std::endl;}
  private:
    int n; 
};  

int main() { const C c; c.mostrar(); }
```
