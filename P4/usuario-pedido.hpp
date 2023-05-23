

#ifndef _USUARIO_PEDIDO_HPP__
#define _USUARIO_PEDIDO_HPP__

#include<map> //mapa de Usuario y set de Pedido
#include<set> //set de pedido

//Declaración adelantada
class Pedido;
class Usuario;

class Usuario_Pedido{
public:
    typedef std::set<Pedido*> Pedidos;
    void asocia(Usuario&, Pedido&);
    void asocia(Pedido&, Usuario&);
    Pedidos pedidos(const Usuario&)const;
    const Usuario* cliente(const Pedido&)const;
private:
    std::map<Usuario*, Pedidos> user_ped;
    std::map<Pedido*, Usuario*> ped_user;
};

#endif