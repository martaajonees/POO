

#include "pedido.hpp"
#include "pedido-articulo.hpp"

//Constructor
Pedido::Pedido(Usuario_Pedido& user_pedido, Pedido_Articulo& pedido_articulo, Usuario& user,const Tarjeta& tar, const Fecha& fecha):
   num_(N_pedido),tarjeta_(&tar),fecha_(fecha), total_(0.0) //Inicialización de atributos
{
   //EXCEPCIONES:

   //Titular no correcto
    if(user.id() != tarjeta_->titular()->id()) throw Pedido::Impostor(user);

    //Tarjeta no activa
    if(!tarjeta_->activa()) throw Tarjeta::Desactivada();

    //Fecha del pedido mal
    //if(Fecha()< fecha_) throw Fecha::Invalida("Fecha no correcta");
    
    //Tarjeta caducada
    if(tarjeta_->caducidad()< fecha_) throw Tarjeta::Caducada(tarjeta_->caducidad());
   
   //Carrito Vacío
    if(user.compra().size() == 0) throw Pedido::Vacio(&user);
    //Sin stock
    for(auto it:user.compra()){ //Recorremos carrito
        if(it.first->stock()<it.second){ //Si el stock que se pide es mayor al que hay
            user.vaciar_carro(); //Vaciar carrito
            throw Pedido::SinStock(*it.first); //lanzamos excepción 
        }
    }

    //Actualizamos carrito
    for(auto& i: user.compra()){
        Articulo& art = *i.first;
        unsigned cant = i.second;

        pedido_articulo.pedir(*this,art, art.precio(),cant);
        pedido_articulo.pedir(art,*this, art.precio(),cant);

        total_ += art.precio() * cant;
        
        i.first->stock() -= i.second; //Actualizamos stock
    }

    //Asociamos pedido y usuario
    user_pedido.asocia(*this,user);
    user_pedido.asocia(user,*this);
    
    user.vaciar_carro();
    N_pedido ++;
}

//Método ostream
ostream& operator <<(ostream& os, const Pedido& ped){
    os<< "Núm. pedido: "<<ped.numero()<<endl;
    os<<"Fecha: \t"<<ped.fecha()<<endl;
    os<<"Pagado con:  "<<ped.tarjeta()->tipo()<<"n.º: "<<ped.tarjeta()->numero()<<endl;
    os<<"Importe: \t"<<fixed<<setprecision(2)<<ped.total()<<" €"<<endl;
return os;
}
