# Clase Binario
## Apartado 1
Es necesario:
1. Constructor:
   ```C++
   Binario(int n = 1);
   ```
2. Constructor de conversion de const char a Binario:
   ```C++
   Binario(const char* c);
   ```
3. Observador n_bits:
   ```C++
   size_t n_bits() const;
   ```
4. Observador unos:
   ```C++
   size_t unos() const;
   ```
La clase con todos estos métodos quedaría:
```C++
class Binario {
public:
    Binario(int n = 1);
    Binario(const char* c);
    size_t n_bits() const;
    size_t unos() const;
    refBit operator[](size_t i );
    bool bit(size_t i) const;
private:
    static const size_t bits_elto = CHAR_BIT * sizeof(unsigned); // CHAR BIT = bits por byte
    const size_t n; // longitud en bits
    const size_t m; // longitud del vector de enteros
    unsigned * bits; // vector de enteros
};
```
## Apartado 2
```C++
Binario::Binario(int n): n(n), m((n+ bits_elto - 1)/bits_elto), bits(new unsigned int [m]){
    for(int i = 0; i < n; i++){ // m representa la cantidad de elementos en el array 
        bits[i] = 0;
    }
}

Binario::Binario(const char* c): n(strlen(c)), m((n + bits_elto - 1)/bits_elto), bits(new unsigned int [m]){
    for(int i = n-1; i >= 0; i--){
        if(c[i] == '1') bits[i] = 1;
        else if(c[i] == '0') bits[i] = 0;
        else throw invalid_argument("Los números deben ser 0 o 1");
    }
}

size_t Binario::n_bits() const {return n;}

size_t Binario::unos() const {
    size_t uno = 0;
    for(int i = n-1; i >= 0; i--){
        if(bits[i] == 1) uno++;
    }
    return uno;
}
```

## Apartado 3
No es válido el constructor de copia por defecto ya que estamos usando un vector de bajo nivel. 
El constructor de copia va copiando miembro a miembro por lo que solo copiaría la referencia del vector no los
elementos en sí. Hay que declarar y definir una sobrecarga a este constructor.
```C++
Binario::Binario(const Binario& b): n(b.n), m(b.m), bits(new unsigned int[m]){
    for(int i = n - 1; i >= 0; i--){
        bits[i] = b.bits[i];
    }
}
```
## Apartado 4
Pueden lanzarse dos tipos de excepciones: `invalid_argument` (constructor por cadena de caracteres) y 
`out_of_range` (funcion bit).

Por lo tanto el programa queda:
```C++
int main(){
    try {
        Binario b2("10v00");
        b2.bit(2);
    } catch(const out_of_range& e){
        cerr << "ERROR. "<< e.what();
    } catch (const invalid_argument& i){
        cerr << "ERROR. "<< i.what();
    } catch (...){
        cerr << "Se ha producido un error";
    }
}
```

## Apartado 5
```C++
ostream& operator <<(ostream& os, const Binario& b){
    os << "El número tiene " << b.unos() << " bits con valor 1 y " << b.n_bits() - b.unos() << " bits con valor 0"<< endl;
    return os;
}
```
## Apartado 6
```C++
Binario Binario::operator & (const Binario& b){
    size_t n1;
    if(n > b.n) n1 = n;
    else n1 = b.n;
    Binario b1(n1);
    
    for(int i = 0; i < b1.n; i++){
        b1.bits[i] = bits[i] & b.bits[i];
    }
    return b1;
}
```
