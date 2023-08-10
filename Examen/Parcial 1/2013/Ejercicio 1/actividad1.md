
# Apartado A

Se debe definir el constructor con valores predeterminados para 1, 2 y 3
Para lo demás no hace falta ninguno ya que como no tenemos punteros, se puede
utilizar los métodos por defecto.

```C++
class Complejo {
public:
  Complejo(double r = 0., double i = 0.): r(r), i(i){}
private:
  double r, i; //parte real, parte imaginaria
};
```

# Apartado B

```C++
class Complejo {
public:
  Complejo(double r = 0., double i = 0.): r(r), i(i){}
  double& real(){return r;}
  double& imag(){return i;}
  void mostrar(){ cout << "Real " << r << " Imaginario " << i;}
  friend Complejo operator *(const Complejo& c, const Complejo& c1);
  friend bool operator == (const Complejo& c, const Complejo& c1);
  friend bool operator != (const Complejo& c, const Complejo& c1);
  friend Complejo operator +(const Complejo& c, const Complejo& c1);
  Complejo operator -();
private:
  double r, i; //parte real, parte imaginaria
};

Complejo operator *(const Complejo& c, const Complejo& c1){
    return Complejo(c.r * c1.r - c.i * c1.i, c.r * c1.i + c1.r * c.i);
}

bool operator == (const Complejo& c, const Complejo& c1){
    return (c.i == c1.i) && (c.r == c1.r);
}

bool operator != (const Complejo& c, const Complejo& c1){
    return !(c == c1);
}

Complejo operator +(const Complejo& c, const Complejo& c1){
    return Complejo(c.r + c1.r, c.i + c1.i);
}

Complejo Complejo::operator -(){
    return Complejo(- r, - i);
}
```
