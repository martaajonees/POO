__Apartado A__
Para que se ejecuten las instrucciones solo es necesario el constructor de esta forma:
```C++
class racional {
public:
  racional(int num= 0, int den=1);
private:
  int n,d;
  static int mcd(int,int);
};
```

__Apartado B__
Solo es necesario definir el constructor debido a que la clase no tiene punteros ni memoria dinámica. Por tanto, 
se pueden utilizar el constructor de copia y operador de asignación por defecto.
```C++
Racional::Racional(int num, int den): n(num), d(den){
    //Excepción
    if(den == 0){
        throw invalid_argument("El denominador no puede ser 0");
    }

    //Buscamos mcd
    int m = mcd(num, den);
    n /= m;
    d /= m;
}
```
