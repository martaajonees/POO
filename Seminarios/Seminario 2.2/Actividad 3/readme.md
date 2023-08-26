# Ejercicio 3
```C++
class punto {
  double x,y; 
public:
  punto(double a = 0., double b = 0.) : x{a}, y{b} {}
  punto(const punto& p) : x{p.x}, y{p.y} {}
  punto& operator=(const punto& p){
    x=p.x;
    y=p.y;
    return *this;
  } 
};
```

Diga qué función de la clase punto se llama en cada una de las siguientes líneas. Si alguna depende de una línea anterior que sea incorrecta, corríjala previamente.

1. `punto p;` 
2. `punto q();` 
3. `punto r(2. , );` 
4. `punto s{3.4};` 
5. `punto t{};` 
6. `punto u(q);`
7. `punto v = r`;
8. `t = s;` 
