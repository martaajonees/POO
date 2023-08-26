# Actividad 6

```C++
class C {
public:
  C(int i): n(i), m(0.0){}
  const C& operator +(const C& other); //Miembro
private:
  int n;
  double m;
};

const C& operator +(const C& c1, const C& c2);  //Externo

int main(){
  C c2(2);
  C c3 (c2 + 1);
}
```
