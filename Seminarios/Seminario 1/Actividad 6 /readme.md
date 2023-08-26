# Ejercicio 6
Considere la siguiente clase:
```C++
class C {
public:
  C(int i): n(i), m(0.0){}
  //..
private:
  int n;
  double m;
};
```
Escriba las declaraciones correspondientes a la sobrecarga del operador + para objetos de tipo C como miembro y como función externa. A continuación escriba a modo de ejemplo un trozo de código 
que provoque un error de compilación con el operador miembro, pero no con el externo.
