## Apartado A
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

## Apartado B
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
## Apartado C
- __Funcion inverso__: Devuelve el inverso del número racional (intercambia el numerador y el denominador).
  ```C++
  inline Racional Racional::inverso(){
    if(n == 0) throw logic_error("El inverso no está disponible");
    return Racional(d, n);
  }
  ```
- __Operadores aritméticos__:
  * __Suma__: Suma dos números racionales:
    ```C++
    inline Racional Racional::operator +(const Racional& r){
    return Racional((n * r.d) + (r.n * d), d * r.d);
    }
    ```
  * __Resta__: Resta dos números racionales.
    ```C++
    inline Racional Racional::operator -(const Racional& r){
    return Racional((n * r.d) - (r.n * d), d * r.d);
    }
    ```
  * __Cociente__: Divide dos números racionales.
    ```C++
    inline Racional Racional::operator /(const Racional& r){
      if(r.n == 0) throw logic_error("División por 0 no permitida");
    return Racional(n * r.d, d * r.n);
    }
    ```
  * __Producto__: Multiplica dos números racionales.
    ```C++
    inline Racional Racional::operator *(const Racional& r){
    return Racional(n * r.n, d * r.d);
    }
    ```
- __Operadores de signo__ :
    * __Positivo__: Devuelve el número racional con signo positivo
      ```C++
      inline Racional Racional::operator +(){return Racional(+n, +d);}
      ```
    * __Negativo__ : Devuelve el número racional con signo negativo.
      ```C++
      inline Racional Racional::operator -(){return Racional(-n, -d);}
      ```
- __Operadores de comparación__
  ```C++
  inline bool Racional::operator == (const Racional& r){
    return (n == r.n) && (d == r.d);
  }
  
  inline bool Racional::operator != (const Racional& r){
      return !(*this == r);
  }
  
  inline bool Racional::operator < (const Racional& r){
      return (n * r.d) > (r.n * d);
  }
  
  inline bool Racional::operator <= (const Racional& r){
      return (*this < r) || *this == r;
  }
  
  inline bool Racional::operator > (const Racional& r){
      return !(*this <= r);
  }
  
  inline bool Racional::operator >= (const Racional& r){
      return (*this > r) || (*this == r);
  }
  ```
