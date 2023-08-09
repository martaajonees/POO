

#include "articulo.hpp"

Articulo::Articulo(const Autores& aut, const Cadena& referencia, const Cadena& titulo, const Fecha& f_publi, double precio):
      referencia_(referencia), titulo_(titulo), f_publi_(f_publi), precio_(precio), autores_(aut){
    if(aut.empty()){
        throw Articulo::Autores_vacios();
    }
}

ostream& operator <<(ostream& os, const Articulo& A){
    os << "[" << A.referencia() << "] \"" << A.titulo() << "\", de ";
    auto i= A.autores().begin();
    os<<(*i)->apellidos();
    i++;
    while( i!= A.autores().end()){
        os<<", "<<(*i)->apellidos();
        i++;
    }
    os <<". "<<A.f_publi().anno()<<". "<<
    setprecision(2)<<fixed << A.precio()<<" €"<<endl;
    os << "\t";
    A.impresion_especifica(os);
    return os;
}

void Libro::impresion_especifica(ostream& os) const{
    os << n_pag_ << " págs., "<< stock_ << " unidades.";
}

void LibroDigital::impresion_especifica(ostream& os) const{
    os << "A la venta hasta el "<< f_expir_<< ".";
}

void Revista::impresion_especifica(ostream& os) const{
    os << "Número: "<< numero_ << ", Periodicidad: "<< periodicidad_ <<" días."<< endl;
    os << "\t" << "Próximo número a partir de: "<< f_publi_ + periodicidad_<< ".";
}