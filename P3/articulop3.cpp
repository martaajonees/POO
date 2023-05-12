

#include "articulo.hpp"

ostream& operator <<(ostream& os, const Articulo& A){
    os<<"["<< A.referencia() << "] \""<< A.titulo()<< "\", "<<A.f_publi().anno()<<". "<<
    setprecision(2)<<fixed << A.precio()<<" €"<<endl;
    return os;
}

