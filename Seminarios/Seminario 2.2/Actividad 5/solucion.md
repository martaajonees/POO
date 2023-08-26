# Ejercicio 5

```C++
class Libro {
  char* titulo_; int paginas_;
public:
  Libro() : titulo_(new char(1)), paginas_(0) {*titulo_= 0;}
  Libro(const char* t, int p) : paginas_(p) {
    titulo_ = new char[strlen(t) + 1];
    strcpy(titulo_, t);
  }
  
  Libro& operator = (const Libro& l){
    titulo_ = new char[strlen(l.titulo_)];
    strcpy(titulo_, l.titulo_);
    paginas_ = l.paginas_;
    return *this;
  }

  ~Libro() { delete[] titulo_; }
  int paginas() const { return paginas_; }
  char* titulo() const { return titulo_; }
};

void mostrar(const Libro& l) {
  cout << l.titulo() << " tiene "
      << l.paginas() << " páginas" << endl;
}

int main() {
  Libro l1("Fundamentos de C++", 474), l2;

  l2 = l1;
  mostrar(l2);
}
```
__Errores:__ 
- En la función `mostrar()`, se está pasando un objeto Libro por valor en lugar de por referencia. Esto significa que se llama al constructor de copia de la clase Libro para crear una copia del objeto l1, y cuando esa copia se destruye al final de la función, se llama al destructor. Sin embargo, el destructor elimina la memoria asignada para titulo_, lo que lleva a un problema de doble eliminación (doble free) cuando el destructor de la copia se ejecuta.
- Se necesita un operador de asignación ya que si no se estarían copiando las direcciones de memoria y no el atributo en si.
