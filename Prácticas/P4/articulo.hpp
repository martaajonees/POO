

#ifndef _ARTICULO_HPP_
#define _ARTICULO_HPP_

#include <iostream>
#include <iomanip>
#include <set>
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

using namespace std;
class Autor;

class Articulo{
public:
    //Enlaces
    typedef std::set<Autor*> Autores;
    //Constructor
    Articulo(const Autores& aut, const Cadena& referencia, const Cadena& titulo, const Fecha& f_publi, double precio);
    const Cadena& referencia() const noexcept{ return referencia_;}
    const Cadena& titulo() const noexcept {return titulo_;}
    const Fecha& f_publi() const noexcept {return f_publi_;}
    double precio() const noexcept {return precio_;};
    const Autores& autores() const noexcept{return autores_;}
    //Métodos modificadores
    double& precio(){return precio_;}
    //ostream
    virtual void impresion_especifica(ostream& os) const = 0;
    virtual ~Articulo(){}
    //Excepción
    class Autores_vacios{};
protected:
    const Cadena referencia_;
    const Cadena titulo_;
    const Fecha f_publi_;
    double precio_;
    const Autores autores_;
};
//Operador ostream
ostream& operator <<(ostream&, const Articulo&);


class Autor{
public:
    Autor(const Cadena& nombre, const Cadena& apellidos, const Cadena& direccion) noexcept: 
    nombre_{nombre},apellidos_{apellidos}, direccion_{direccion} {}
    //Observadores
    const Cadena& nombre()const noexcept {return nombre_; }
    const Cadena& apellidos()const noexcept {return apellidos_; }
    const Cadena& direccion()const noexcept {return direccion_; }
private:
    Cadena nombre_;
    Cadena apellidos_;
    Cadena direccion_;
};


class ArticuloAlmacenable: public Articulo{
    public:
    ArticuloAlmacenable(const Autores& aut, const Cadena& referencia, const Cadena& titulo,const Fecha& f_publi, double precio, size_t stock = 0):
    Articulo(aut, referencia, titulo, f_publi, precio), stock_(stock){}
    size_t stock() const noexcept {return stock_;}
    size_t& stock (){return stock_;}
    protected:
    size_t stock_;
};

class Libro: public ArticuloAlmacenable{
    public:
    Libro(const Autores aut, const Cadena referencia, const Cadena titulo, const Fecha f_publi, double precio, size_t n_pags, size_t stock = 0):
    ArticuloAlmacenable(aut, referencia, titulo, f_publi, precio, stock), n_pag_(n_pags){}
    size_t n_pag()const noexcept{return n_pag_;}
    void impresion_especifica(ostream& os) const;
    protected:
    size_t n_pag_;
};

class Revista: public ArticuloAlmacenable{
public: 
    Revista(const Autores aut, const Cadena referencia, const Cadena titulo, const Fecha f_publi, double precio, unsigned int numrevista,unsigned int periodicidad, size_t stock = 0):
    ArticuloAlmacenable(aut, referencia, titulo, f_publi, precio, stock), numero_(numrevista),periodicidad_(periodicidad){}
    unsigned int numero()const noexcept{return numero_;}
    unsigned int periodicidad()const noexcept{return periodicidad_;}
    void impresion_especifica(ostream& os) const;
private:
    unsigned int numero_;
    unsigned int periodicidad_;
};

class LibroDigital: public Articulo{
public:
    LibroDigital(Autores aut, Cadena referencia,Cadena titulo, Fecha f_publi, double precio, Fecha f_expir):
    Articulo(aut, referencia, titulo, f_publi, precio),f_expir_(f_expir){}
    const Fecha f_expir()const noexcept{return f_expir_;}
    void impresion_especifica(ostream& os) const;
private:
    const Fecha f_expir_;
};
#endif