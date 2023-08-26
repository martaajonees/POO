
# Ejercicio 4
Sean las clases Libro1 y Libro2:
```C++
class Libro1 {
  string titulo_;
  int pags_;
public:
  Libro1(string t = "", int p = 0);
  // ...
};

class Libro2 {
  string titulo_;
  int pags_;
public:
  Libro2(string t, int p = 0); Libro2(const char* c);
  // ...
};
```

Decida si X se puede sustituir por 1, 2 o ambos en los siguientes
items:

1. Se puede definir: `LibroX lib1;`
2. Se tiene un constructor de conversión de `std::string a LibroX`
3. Se puede definir: `LibroX lib2[5];`
4. Se puede definir: `std::vector<LibroX> lib3;`
5. Siendo "El Quijote" una cadena literal de tipo `const char*`; se produce una conversión implícita a `string` al ejecutar: `LibroX* lib4 = new LibroX("El Quijote");`
6. Se puede definir: LibroX lib5 = "El Quijote";
7. Hace falta denir el destructor para LibroX.


