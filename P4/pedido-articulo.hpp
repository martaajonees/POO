

#ifndef _PEDIDO_ARTICULO_HPP_
#define _PEDIDO_ARTICULO_HPP_

#include<iostream>
#include<iomanip>
#include<map>

#include "pedido.hpp"
#include "articulo.hpp"
using namespace std;
//Declaraciones adelantadas
class Pedido;

class LineaPedido{
public:
    explicit LineaPedido(double pv, unsigned cant = 1): precio_venta_(pv),cantidad_(cant){}
    double precio_venta() const;
    unsigned cantidad() const;
private:
    double precio_venta_;
    unsigned cantidad_;
};
inline double LineaPedido::precio_venta() const {return precio_venta_;}
inline unsigned LineaPedido::cantidad() const {return cantidad_;}

std::ostream& operator <<(std::ostream& os, const LineaPedido& linea);

//Clases definidas
class OrdenaArticulos{
    public:
    bool operator ()(const Articulo* art1, const Articulo* art2)const {return art1->referencia() < art2->referencia();}
};
class OrdenaPedidos{
    public:
    bool operator ()(const Pedido* ped1, const Pedido* ped2)const {return ped1->numero()<ped2->numero();}
};

//PEDIDO_ARTICULOS
class Pedido_Articulo{
    public: 
    //Tipos definidos
    typedef std::map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
    typedef std::map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
    //Métodos de asociación
    void pedir(Pedido& p, Articulo& a, double precio, unsigned cantidad=1);
    void pedir(Articulo& a, Pedido& p, double precio, unsigned cantidad=1);
    //Métodos observadores
    ItemsPedido detalle(const Pedido& ped) const;
    Pedidos ventas(const Articulo& art) const;
    //Métodos mostrar
    void mostrarDetallePedidos(std::ostream& os)const noexcept;
    void mostrarVentasArticulos(std::ostream& os)const noexcept;

    private:
    typedef std::map<Pedido*, ItemsPedido, OrdenaPedidos> Ped_Art;
    typedef std::map<Articulo*, Pedidos, OrdenaArticulos> Art_Ped;//De articulo a pedido
    Ped_Art ped_art;
    Art_Ped art_ped;
};
std::ostream& operator <<(ostream& os, const Pedido_Articulo::ItemsPedido& ped);
std::ostream& operator <<(ostream& os, const Pedido_Articulo::Pedidos& art);
#endif