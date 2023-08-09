#include "cadena.hpp"
#include <cstdio>

/* Constructores ------------------------------------------------------------------------*/

/* Con 2 parámetros, que serán por este orden: un tamaño inicial 
y un carácter de relleno*/
Cadena::Cadena(size_t tam, char c): s_(new char[tam+1]),tam_(tam){
    for(size_t i=0; i<tam_;i++){
        s_[i]= c;
    }
    s_[tam_]= '\0'; //Añado '\0' al final
}


/* Por copia de otra Cadena.*/
Cadena::Cadena(const Cadena& cad): s_(new char[cad.tam_+1]), tam_(cad.tam_){
    strcpy(s_, cad.s_);
}
/* Una Cadena podrá asignarse a otra. Una cadena de bajo nivel también podrá asignarse directamente a una Cadena. 
La original se destruye.
*/
Cadena& Cadena::operator =(const Cadena& cad)
{
    if(this != &cad) { //Primero miramos que no se ha copiado ya 
        tam_ = cad.tam_; 
        delete[] s_; //Liberamos memoria
        s_= new char[tam_ +1];//Asignamos espacio de memoria
        strcpy(s_, cad.s_); //Copiamos el contenido 
    }
     return *this;
}

/*A partir de una cadena de caracteres de bajo nivel, permitiéndose las conversiones 
desde const char* a Cadena.*/

/* Se calcula la longitud de la cadena y asignamos memoria para almacenar 
los caracteres utilizando new char[tam_+1]*/

Cadena::Cadena(const char* cad)
{
    tam_ = strlen(cad);
    s_ = new char[tam_+1];
    strcpy(s_,cad);
}


/* Operadores ------------------------------------------------------------------------ */

Cadena& Cadena::operator +=(const Cadena& cad)
{
    char* cat = new char[tam_ + cad.tam_ + 1];

    strcpy(cat, s_); // Copia s_ a cat
    strcat(cat, cad.s_); // Concatena cad.s_ a cat

    tam_ += cad.tam_; // Actualiza el tamaño
    delete[] s_; // Libera el espacio de s_
    s_ = new char[tam_ +1]; // Asigna el puntero de cat a s_
    strcpy(s_,cat);
    s_[tam_]= '\0';
    delete [] cat;
    return *this;
}

Cadena operator + (const Cadena& cad1, const Cadena& cad2) {
    Cadena aux(cad1);
    aux += cad2;
    return aux;
}
        


    /* Funciones AT -----------------------------------------------------------------*/
    char& Cadena::at(size_t indice){
        if(indice >= tam_){
            throw out_of_range("Índice fuera de rango");
        }else
        return s_[indice];
    }

    const char& Cadena::at(size_t indice) const{
        if(indice >= tam_){
            throw out_of_range("Índice fuera de rango");
        }else
        return s_[indice];
    }

    char& Cadena::operator [] (size_t indice){
        return s_[indice];
    }

    char& Cadena::operator [] (size_t indice) const{
        return s_[indice];
    }

    /* Substr --------------------------------------------------------------------- */
    /* La función miembro substr recibirá dos parámetros enteros sin signo: 
    un  índice y un tamaño, y devolverá una Cadena formada por tantos caracteres como indique el tamaño 
    a partir del índice. */
    Cadena Cadena::substr(size_t indice, size_t tam)const
    {
        if(tam>tam_ || indice> tam_ ||tam+indice>tam_){
            throw out_of_range("La operación substr() está fuera de rango");
        }else{
            Cadena aux(tam); //Una cadena auxiliar con el tamaño pasado
            strncpy(aux.s_, s_ + indice,tam); //La función strncpy copia los 
            //primeros tam caracteres de la cadena original que comienzan en el índice indice a 
            //la cadena auxiliar.
            aux.s_[tam]='\0'; //último carácter de la cadena auxiliar en '\0'
            return aux;
        }
    }

     /* Destructor ---------------------------------------------------------------*/
    Cadena::~Cadena(){
      delete [] s_;
      tam_=0;
    }