#ifndef CADENA_HPP_
#define CADENA_HPP_

#include<stdexcept>
#include<iostream>
#include<cstring>
using namespace std;

class Cadena{
    public:
        explicit Cadena(size_t tam =0, char s= ' ');
        Cadena(const Cadena& cad);
        Cadena(const char* c);
        Cadena& operator =(const Cadena& cad);
        size_t length() const noexcept;
        /* Operadores -----------------------------------------------------------*/
        Cadena& operator += (const Cadena&);
        /* Funciones AT -----------------------------------------------------------------*/
        char& at(size_t indice);
        const char& at(size_t indice) const;
        char& operator [] (size_t indice);
        char& operator [] (size_t indice) const;
        /* Substr --------------------------------------------------------------------- */
        Cadena substr(size_t indice, size_t tam) const;
        /* Conversión de Cadena a const char ----------------------------------------------------*/
        explicit operator const char *()const;
        /* Destructor ---------------------------------------------------------------*/
        ~Cadena();
    private:
        char* s_;
        size_t tam_;

};
inline size_t Cadena::length()const noexcept{
    return tam_;
}
Cadena operator + (const Cadena& cad1, const Cadena& cad2);
 /* Operadores Lógicos ----------------------------------------------------------*/
bool operator == (const Cadena& cad1, const Cadena& cad2);
bool operator != (const Cadena& cad1, const Cadena& cad2);
bool operator > (const Cadena& cad1, const Cadena& cad2);
bool operator < (const Cadena& cad1, const Cadena& cad2);
bool operator >= (const Cadena& cad1, const Cadena& cad2);
bool operator <= (const Cadena& cad1, const Cadena& cad2);

/* Operadores Lógicos ----------------------------------------------------------*/
inline bool operator == (const Cadena& cad1, const Cadena& cad2){
    return !strcmp((const char *)cad1,(const char *) cad2); //Strcmp devuelve 0 si son iguales, para convertirlo en true hay que negarlo
}

inline bool operator != (const Cadena& cad1, const Cadena& cad2){
        return strcmp((const char *)cad1,(const char *) cad2);
}

inline bool operator > (const Cadena& cad1, const Cadena& cad2){
    return (cad2<cad1);
}

inline  bool operator < (const Cadena& cad1, const Cadena& cad2){
    return strcmp((const char *)cad1,(const char *) cad2)< 0;
}

inline  bool operator >= (const Cadena& cad1, const Cadena& cad2){
    return !(cad1<cad2);
}

inline  bool operator <= (const Cadena& cad1, const Cadena& cad2){
    return !(cad1>cad2); 
}
/* Conversión de Cadena a const char ----------------------------------------------------*/

inline Cadena::operator const char *()const{
    return s_;
}

   
#endif