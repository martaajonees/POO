# Ejercicio 1
## Apartado 1
Solo es necesario definir el constructor con valores predeterminados. Los demás métodos son los generados automáticamente por el
compilador. Como no hay punteros ni memoria dinámica se pueden utilizar y nos ahorramos predefinirlos.

El programa quedaría:
```C++
class Complejo {
public:
  Complejo(double r = 0.0, double i= 0.0): r(r), i(i){}
private:
  double r, i; //parte real, parte imaginaria
};
```
## Apartado 2
```C++
class Complejo {
public:
  Complejo(double r_ = 0.0, double i_= 0.0): r(r_), i(i_){}
  double& real() {return r;}
  double real() const {return r;}
  double& imag() {return i;}
  double imag() const {return i;}
  Complejo operator - (){ return Complejo(-r, -i);}
  friend Complejo operator * (const Complejo& c, const Complejo& a);
  friend Complejo operator + (const Complejo& c, const Complejo& a);
  friend bool operator == (const Complejo& c, const Complejo& a);
  friend bool operator != (const Complejo& c, const Complejo& a);
private:
  double r, i; //parte real, parte imaginaria
};

Complejo operator * (const Complejo& c, const Complejo& a){
    return Complejo((c.r * a.r) - (c.i * a.i), (c.i * a.r)-(c.r * a.i));
}

Complejo operator + (const Complejo& c, const Complejo& a){
    return Complejo(c.r + a.r, c.i + a.i);
}

bool operator == (const Complejo& c, const Complejo& a){
    return (c.r == a.r) && (c.i == a.i);
}
bool operator != (const Complejo& c, const Complejo& a){
    return !(c == a);
}
```
