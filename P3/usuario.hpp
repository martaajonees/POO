

#ifndef _USUARIO_HPP_
#define _USUARIO_HPP_

#include "../P1/cadena.hpp"
#include "tarjeta.hpp"
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>

using std::map;
using std::unordered_map;
using std::unordered_set;
using std::ostream;

class Tarjeta;
class Numero;
class Articulo;


/* CLASE CLAVE ---------------------------------------*/

class Clave{
public:
    //Contructor
    Clave(const char* contr= ""); 
    //Método Observador
    Cadena clave() const;

    //Clase INCORRECTA
    enum Razon {CORTA, ERROR_CRYPT};
    class Incorrecta{
        public:
            Incorrecta(Razon razon): razon_(razon){}
            Razon razon() const noexcept{return razon_;}
        private:
            Razon razon_;
    };
    //Otros métodos
    bool verifica(const char* contr) const;


private:
    Cadena clave_; //clave_ es la contraseña cifrada
};

inline Cadena Clave::clave() const {return clave_;}

/*CLASE USUARIO -------------------------------------------------*/
class Usuario{
public:
    //Asociaciones: Tarjetas y Artículos
    typedef std::unordered_map<Articulo*,unsigned int> Articulos;
    typedef std::map<Numero,Tarjeta*> Tarjetas; //map de tarjetas

    //Constructor
    Usuario(const Cadena& ident, const Cadena& nombre,const Cadena& apell, const Cadena& dir, const Clave& clave);
    //Copia eliminamos
    Usuario(const Usuario&)=delete;
    void operator = (const Usuario&)= delete;

    //Clase duplicado
    class Id_duplicado{
    public:
        Id_duplicado(Cadena dup):id_(dup){}
        Cadena idd() const{return id_;}
    private: 
        Cadena id_;
    };

    //Métodos observadores
    const Cadena& id() const noexcept;
    const Cadena& nombre() const noexcept;
    const Cadena& apellidos() const noexcept;
    const Cadena& direccion() const noexcept;
    const Tarjetas& tarjetas() const noexcept;
    const Articulos& compra() const noexcept;

    //Enlace con Articulos
    void compra(const Articulo& art, unsigned int cantidad = 1);
    void vaciar_carro();
    unsigned int n_articulos() const;

    //Asociaciones
    void es_titular_de(const Tarjeta& tarjeta);
    void no_es_titular_de(const Tarjeta& tarjeta);

    //Método ostream
    friend ostream& operator <<(ostream& os, const Usuario& user);
    //Mostrar carro
    friend ostream& mostrar_carro(ostream& os, const Usuario& user);
    //Destructor
    ~Usuario();
private:
    static std::unordered_set<Cadena> identificador_;
    const Cadena id_, nombre_, apellidos_, direccion_;
    Clave password_;
    Articulos articulos_;
    Tarjetas tarjetas_;
};

//Métodos observadores
inline const Cadena& Usuario::id() const noexcept{return id_;}
inline const Cadena& Usuario::nombre() const noexcept{return nombre_;}
inline const Cadena& Usuario::apellidos() const noexcept{return apellidos_;}
inline const Cadena& Usuario::direccion() const noexcept{return direccion_;}
inline const Usuario::Tarjetas& Usuario::tarjetas() const noexcept{return tarjetas_;}
inline const Usuario::Articulos& Usuario::compra() const noexcept{return articulos_;}

//Asociaciones
inline void Usuario::es_titular_de(const Tarjeta& t){
    if(t.titular() == this) //La tarjeta es del usuario
        tarjetas_[t.numero()]= const_cast<Tarjeta*>(&t); //Añadimos tarjeta
}
//Erase eliminará el valor que corresponda a la clave num(Número de tarjeta)
inline void Usuario::no_es_titular_de(const Tarjeta& t){
    tarjetas_.erase(t.numero()); //Borramos la tarjeta del usuario
}
//Vaciar carro
inline void Usuario::vaciar_carro(){
    articulos_.clear();
}
//Numero de articulos
inline unsigned int Usuario::n_articulos() const{
    return articulos_.size();
}

#endif

