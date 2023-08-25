# Ejercicio 4
Indique los errores que hay en el siguiente código y su causa.

```C++
class C {
public:
  C();
  C(int a, int b, int c, int d);
  int f1(int i) const;
  int f2(int i) const;
  static void f3(){ m=h;}
  static int n;
private:
  int h;
  mutable int i;
  const int j;
  mutable int k;
  static int m;
};

int C::f1(int i) const {
  h = i;
  k = i;
  return 0; 
}

C::C() {
h = i = j = k = 0;
} 

C::C(int a,int b,int c,int d):h(a),i(b),j(c),k(d){} 

int C::f2(int i){
  k = i;
  h = i;
  return 0;
}
```
