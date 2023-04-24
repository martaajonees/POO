

#ifndef _ARTICULO_HPP_
#define _ARTICULO_HPP_

#include <iostream>
#include <iomanip>
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

using namespace std;

class Articulo{
public:
    //Constructor
    Articulo(Cadena referencia,Cadena titulo, Fecha f_publi, double precio, size_t stock = 0):
       referencia_(referencia), titulo_(titulo), f_publi_(f_publi), precio_(precio), stock_(stock) {}
    //Métodos observadores
    Cadena referencia() const noexcept{ return referencia_;}
    Cadena titulo() const noexcept {return titulo_;}
    Fecha f_publi() const noexcept {return f_publi_;}
    double precio() const noexcept {return precio_;};
    size_t stock() const noexcept {return stock_;}
    //Métodos modificadores
    double& precio(){return precio_;}
    size_t& stock (){return stock_;}
    
private:
    const Cadena referencia_;
    const Cadena titulo_;
    const Fecha f_publi_;
    double precio_;
    size_t stock_;
};
//Operador ostream
ostream& operator <<(ostream&, const Articulo&);

#endif