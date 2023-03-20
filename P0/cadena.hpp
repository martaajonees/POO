#ifndef CADENA_HPP_
#define CADENA_HPP_

#include<stdexcept>
#include<iostream>
#include<string.h>
using namespace std;

class Cadena{
    public:
        explicit Cadena(size_t tam =0, char s= ' ');
        Cadena(const Cadena& cad);
        Cadena(const char* c);
        Cadena& operator =(const Cadena& cad);
        int length() const; //Se trata de una función constante, ya que no modifica el estado interno de la clase
        /* Operadores -----------------------------------------------------------*/
        Cadena& operator += (const Cadena&);
        const Cadena operator+ (const Cadena&) const;
        /* Operadores Lógicos ----------------------------------------------------------*/
        friend bool operator == (const Cadena& cad1, const Cadena& cad2);
        //friend bool operator == (const char * cad, const Cadena&);
        friend bool operator != (const Cadena& cad1, const Cadena& cad2);
        friend bool operator > (const Cadena& cad1, const Cadena& cad2);
        friend bool operator < (const Cadena& cad1, const Cadena& cad2);
        friend bool operator >= (const Cadena& cad1, const Cadena& cad2);
        friend bool operator <= (const Cadena& cad1, const Cadena& cad2);
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
/*
bool operator == (const char * s, const Cadena& cad){
    return !strcmp(s, cad.s_);
}
*/

   
#endif