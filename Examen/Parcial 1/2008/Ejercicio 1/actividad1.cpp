
#include <iostream>
#include <stdlib.h>
using namespace std;

enum Nucleotido {A, C, G, T};

class ADN {
    public:
    ADN();
    ADN(size_t, Nucleotido*);
    ADN(const char * const);
    ADN(const ADN&);
    void mostrar();
    friend ADN operator + (ADN a, ADN b);
    private:
    size_t n_;
    Nucleotido *c_;
};

//Ejercicio 1
ADN::ADN(): n_(0), c_(nullptr){}

//Ejercicio 2
ADN::ADN(size_t n, Nucleotido* c): n_(n), c_(c){}

//Ejercicio 3
ADN::ADN(const char * const s): n_(strlen(s)){
    c_ = new Nucleotido[n_];//Creo espacio c
    for(int i = 0; i < n_; i++){
        switch (s[i]){
        case 'A': c_[i] = A; 
            break;
        case 'C': c_[i] = C;
            break;
        case 'G': c_[i] = G;
            break;
        case 'T': c_[i] = T;
            break;
        default:
            break;
        }
    }
}

/*
Ejercicio 4:
    Sí, sería necesario. EL constructor de copia generado por el compilador 
    simplemente copia el puntero del objeto que queremos copiar, por lo que el 
    nuevo puntero sigue apuntando a la dirección de memoria del otro.
    Lo que podría causar muchos problemas.
*/
ADN::ADN(const ADN& a): n_(a.n_){
    c_ = new Nucleotido[n_]; //Creo espacio c
    memcpy(c_, a.c_, n_ * sizeof(Nucleotido)); //Copio el puntero
}

//Ejercicio 5
ADN operator + (ADN a, ADN b){
    const size_t n = a.n_ + b.n_;
    ADN c(n, new Nucleotido[n]);
    memcpy(c.c_, a.c_, a.n_ * sizeof(Nucleotido));
    memcpy(c.c_ + a.n_, b.c_, b.n_ * sizeof(Nucleotido));
    return c;
}

//Ejercicio 6
int main() {
    const char * const s = "GA";
    ADN a(s); //Constructor a partir de un const char
    ADN b = ADN(a);
    b[0] = C;
    ADN(ADN(a + ADN("TTA")) + b).mostrar();
}
