#ifndef CADENA_HPP_
#define CADENA_HPP_

#include<stdexcept>
#include<iostream>
#include<cstring>
#include<iterator>
using namespace std;

class Cadena{
    public:
        /* Iterador*/
        typedef char* iterator;
        typedef const char* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator; 
        typedef std::reverse_iterator <const_iterator> const_reverse_iterator;
        iterator begin() const;
        iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend()const;
        reverse_iterator rbegin() const;
        reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
        

        explicit Cadena(size_t tam =0, char s= ' ');
        Cadena(const Cadena& cad);
        Cadena(const char* c);
        Cadena(Cadena&& otra) noexcept;
        Cadena& operator =(const Cadena& cad);
        Cadena& operator=(const char* c);
        Cadena& operator=(Cadena&& otra) noexcept;
        size_t length() const noexcept;
        
        /* Operadores ----------------------------------------------------------- */
        Cadena& operator += (const Cadena&);
        
        /* Funciones AT ----------------------------------------------------------------- */
        char& at(size_t indice);
        const char& at(size_t indice) const;
        char& operator [] (size_t indice);
        char& operator [] (size_t indice) const;
        /* Substr --------------------------------------------------------------------- */
        Cadena substr(size_t indice, size_t tam) const;
        /* Conversión de Cadena a const char ---------------------------------------------------- */
        explicit operator const char *()const;
        /* Destructor --------------------------------------------------------------- */
        ~Cadena();
    private:
        char* s_;
        size_t tam_;

};

 /* OPERADOR OSTREAM */
istream& operator >>(istream&, Cadena&);
ostream& operator <<(ostream&, const Cadena&);

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
     if (s_ == nullptr) {
        return "";
    } else {
        return s_;
    }
}


/* ITERATOR */
inline Cadena::iterator Cadena::begin()const {return s_;}
inline Cadena::iterator Cadena::end()const {return s_+tam_;}

inline Cadena::const_iterator Cadena::cbegin() const {return begin();}
inline Cadena::const_iterator Cadena::cend()const {return end();}

inline Cadena::reverse_iterator Cadena::rbegin() const {
    return reverse_iterator(end());
}
inline Cadena::reverse_iterator Cadena::rend() const { 
    return reverse_iterator(begin()); 
}
inline Cadena::const_reverse_iterator Cadena::crbegin() const {
    return const_reverse_iterator(end());
}
inline Cadena::const_reverse_iterator Cadena::crend() const { 
    return const_reverse_iterator(begin()); 
}

   
#endif