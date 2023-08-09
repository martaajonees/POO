
#ifndef _PEDIDO_HPP_
#define _PEDIDO_HPP_

#include <iostream>
#include "tarjeta.hpp" 
#include "usuario-pedido.hpp" 
#include "articulo.hpp"
#include "usuario.hpp"

class Usuario;
class Fecha;
class Articulo;
class Usuario_Pedido;
class Pedido_Articulo;

class Usuario;

class Pedido{
public:
    //Constructor
    Pedido(Usuario_Pedido& user_pedido, Pedido_Articulo& pedido_articulo, Usuario& user,const Tarjeta& tar, const Fecha& fecha = Fecha());
    //Excepciones
    class Impostor{
        public:
        Impostor(const Usuario *user): user_(user){}
        const Usuario& usuario() const noexcept {return *user_;}
        private:
        const Usuario* user_;
    };
    class Vacio{
        public:
        Vacio(const Usuario* user):user_(user){}
        const Usuario& usuario()const {return *user_;}
        private:
        const Usuario* user_;
    };
    class SinStock{
        public:
        SinStock(const Articulo& art): art_(&art){}
        const Articulo& articulo()const {return *art_;}
        private:
        const Articulo* art_;
    };

    //Métodos observadores
    int numero() const{return num_;}
    const Tarjeta* tarjeta() const{return tarjeta_;}
    const Fecha& fecha() const {return fecha_;}
    double total() const{return total_;}
    static int n_total_pedidos(){return N_pedido;}

private:
    static int N_pedido;
    int num_;
    const Tarjeta* tarjeta_;
    Fecha fecha_;
    double total_;

};
inline int Pedido::N_pedido = 1;
ostream& operator <<(ostream& os, const Pedido& ped);



#endif