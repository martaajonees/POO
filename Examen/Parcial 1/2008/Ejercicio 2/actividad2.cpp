
#include <iostream>
#include <cmath>
using namespace std;

class Complejo {
  double real, imag;
public:
  explicit Complejo (double r = 0., double i = 0.): real(r), imag(i) // i(imag) {}
  Complejo(const Complejo& c){}
  //static void print() { cout << "(" << real << "," << imag << ")"; }
  void print() { cout << "(" << real << "," << imag << ")"; }
  operator double() const { return sqrt(real * real + imag * imag); }

  friend Complejo operator +(const Complejo& c1, const Complejo& c2);
  friend Complejo operator -(Complejo c1, Complejo c2);
  friend const Complejo operator *(Complejo& c1, Complejo& c2);
};

Complejo operator +(const Complejo& c1, const Complejo& c2) {
//c1.real += c2.real, c1.imag += c2.imag;
return Complejo(c1.real + c2.real, c1.imag + c2.imag);
}

//Le quito & en Complejo&
Complejo operator -(Complejo c1, Complejo c2) {
c1.real -= c2.real, c1.imag -= c2.imag;
return Complejo(c1.real, c1.imag);
}

const Complejo operator *(Complejo& c1, Complejo& c2) {
return Complejo(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c2.real * c1.imag);
}

int main() {
Complejo a(3.), b(2., 2.), c = a + b; //d = b + 3.;
double e = 3. + b;
//cout << "a * b = ", (a * b).print();
cout << "a * b = ", Complejo(a * b).print();
}
