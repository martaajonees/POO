

#include "usuario-pedido.hpp"
void Usuario_Pedido::asocia(Usuario& user, Pedido& ped){
    user_ped[&user].insert(&ped);
    ped_user[&ped]=&user;
}

void Usuario_Pedido::asocia(Pedido& ped, Usuario& user){
    asocia(user, ped);
}

Usuario_Pedido::Pedidos Usuario_Pedido::pedidos(const Usuario& user)const{
    auto it= user_ped.find((Usuario*)&user);
    if(it != user_ped.end()) //Lo ha encontrado
        return it->second;
    else return Usuario_Pedido::Pedidos();
}

const Usuario* Usuario_Pedido::cliente(const Pedido& ped)const{
    auto it = ped_user.find((Pedido*)&ped);
    if(it != ped_user.end()) //Se ha encontrado
        return it->second;
    else return nullptr;
}