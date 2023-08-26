# Ejercicio 5

Considere la siguiente clase Libro:
```C++
#include <iostream>
#include <cstring>
using namespace std;
class Libro {
  char* titulo_; int paginas_;
public:
  Libro() : titulo_(new char[1]), paginas_(0) {*titulo_= 0;}
  Libro(const char* t, int p) : paginas_(p) {
    titulo_ = new char[strlen(t) + 1];
    strcpy(titulo_, t);
  }
  ~Libro() { delete[] titulo_; }
  int paginas() const { return paginas_; }
  char* titulo() const { return titulo_; }
};
```

Diga si el siguiente programa funciona correctamente. En caso afirmativo indique lo que imprime. 
En caso negativo haga las modificaciones necesarias para que funcione correctamente.
```C++
void mostrar(Libro l) {
  cout << l.titulo() << " tiene "
      << l.paginas() << " páginas" << endl;
}

int main() {
  Libro l1("Fundamentos de C++", 474), l2;

  l2 = l1;
  mostrar(l2);
}
```
