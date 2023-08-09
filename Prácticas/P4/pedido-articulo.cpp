

#include "pedido-articulo.hpp"

ostream& operator <<(ostream& os, const LineaPedido& line){
    os << setprecision(2) << fixed << " "<< line.precio_venta() <<" €" << " \t "<<
    line.cantidad()<<" \t";
    return os;
}

//CLASE PEDIDO_ARTÍCULO
//Métodos de asociaciones
void Pedido_Articulo::pedir(Pedido& ped, Articulo& art, double precio, unsigned cantidad){
    //Creamos linea de pedido
   ped_art[&ped].insert(make_pair(&art, LineaPedido(precio, cantidad)));
   art_ped[&art].insert(make_pair(&ped, LineaPedido(precio, cantidad)));
}

void Pedido_Articulo::pedir(Articulo& art, Pedido& ped, double precio, unsigned cantidad){
    pedir(ped, art, precio, cantidad);
}

//Métodos observadores
Pedido_Articulo::ItemsPedido Pedido_Articulo::detalle(const Pedido& ped) const{
    auto it = ped_art.find((Pedido *)&ped); //Buscamos pedido
    if(it != ped_art.end()){ //Si lo hemos encontrado
        return it->second;
    }else return ItemsPedido{};//Devuelve map vacío
}

Pedido_Articulo::Pedidos Pedido_Articulo::ventas(const Articulo& art) const{
    auto it= art_ped.find((Articulo*)&art); //Buscamos artículo
    if(it != art_ped.end())//Existe
        return it->second;
    else return Pedidos{};//Devuelve map vacío
}

//Métodos ostream
ostream& operator <<(ostream& os, const Pedido_Articulo::ItemsPedido& ped){
    double total = 0;
    int nejemplar=0;

    os << std::setfill(' ') << setw(10) << "PVP" << setw(16) << "Cantidad" << setw(20) << "Artículo" << endl;
    os<<std::setfill('=')<<setw(65)<< ""<<endl;

    for(auto const &it: ped){
        //Definimos nombres para más claridad
        const Articulo& a = *it.first;
        const LineaPedido& lp = it.second;

        total += a.precio(); //Para el precio total
        nejemplar += lp.cantidad();

        os << setfill(' ') << lp.precio_venta() << setw(10) << " €"
        <<setw(16)<<lp.cantidad()
        <<"["<<a.referencia() <<"] "<<a.titulo()<<endl;
    }
    os<<std::setfill('=')<<setw(65)<< ""<<endl;
    os<< setfill(' ') << setw(10)<<"Total:" << total <<setw(10)<<" €"<<setw(8)<< nejemplar <<endl;
    return os;
}

ostream& operator <<(ostream& os, const Pedido_Articulo::Pedidos& art){
    double total = 0.0;
    int nejemplar= 0;

    os << " [Pedidos: " << art.size() << "]" << endl;
    os << setfill('=') << setw(65) << " " << endl;
    os << setfill(' ') << setw(10) << " PVP" << setw(16) << "Cantidad" << setw(20) << "Fecha de venta" << endl;
    os << setfill('=') << setw(65) << " " << endl;
    for(auto const &it: art){
        const Pedido& p = *it.first;
        const LineaPedido& l = it.second;

        total += l.precio_venta() * l.cantidad();
        nejemplar += l.cantidad();

        os << l << setw(20) << p.fecha() << endl;
        
    }

    os << setfill('=') << setw(65) << " " << endl;
    os << setfill(' ') << " "<<total<< " €" <<"\t"<<nejemplar<<endl;
    return os;
}

//Métodos mostrar
void Pedido_Articulo::mostrarDetallePedidos(std::ostream& os)const noexcept{
  double total =0.0;

  for(auto& it:ped_art){
    const Pedido& p = *it.first;

    total += p.total();
    os<< "Pedido num. "<<p.numero()<<endl;
    os<< "Cliente: "<< p.tarjeta()->titular()->nombre()<<"\t"
    <<"Fecha: "<<p.fecha()<<endl;

    os<<detalle(p)<<endl;
  }  
  os<<setw(20)<<"TOTAL VENTAS"<<"\t"<<total<<" €"<<endl;
}

void Pedido_Articulo::mostrarVentasArticulos(std::ostream& os)const noexcept{
    for(auto& it:art_ped){
        os<<"Venta de ["<<it.first->referencia()<< "] "<< it.first->titulo() <<endl;
        os << ventas(*it.first) << endl;
    }
}
