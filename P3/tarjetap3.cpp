//Añadimos cabeceras
#include "tarjeta.hpp"
#include <locale>
#include "usuario.hpp"
#include<functional>

using std::isspace;
using std::isdigit;
using std::string;

bool luhn(const Cadena& numero);

std::set<Numero> Tarjeta::tarjetas_;

/*CLASE TARJETA ------*/
Tarjeta::Tarjeta(const Numero& num, Usuario& titular, const Fecha& cad):
    numero_(num), titular_(&titular),caducidad_(cad) ,activa_(true){
    
     //Compruebo la tarjeta
    Fecha actual;
    if(caducidad_<actual){
        throw Tarjeta::Caducada(caducidad_);
    }

    //Comprobamos que no existe número 
    if (!tarjetas_.insert(num).second) //Inserción fallida
        throw Num_duplicado{num};
   
   
    //Asociar tarjeta con usuario
    titular_->es_titular_de(*this);
}


Tarjeta::Tipo Tarjeta::tipo()const{
    const char* num= (const char*) numero();
    switch (num[0])
    {
    case '3':
        if(num[1]=='4' || num[1]=='7') return AmericanExpress;
        else return JCB;
        break;
    case '4':
        return VISA;
        break;
    case '5':
        return Mastercard;
        break;
    case '6':
        return Maestro;
    default:
        return Otro;
        break;
    }

}
//Destructor
Tarjeta::~Tarjeta(){
    if(titular_){
        const_cast<Usuario*&>(titular_)->no_es_titular_de(*this);
        const_cast<Usuario*&>(titular_)=nullptr;
    }
    //Borramos tarjeta
    tarjetas_.erase(numero());
}

//Ostreams

ostream& operator <<(ostream& os, const Tarjeta::Tipo& tipo){
    switch (tipo)
    {
        case Tarjeta::Tipo::AmericanExpress:
            os<<"American Express";
            break;
        case Tarjeta::Tipo::JCB:
            os<<"JCB";
            break;
        case Tarjeta::Tipo::Maestro:
            os<<"Maestro";
            break;
        case Tarjeta::Tipo::Mastercard:
            os<<"Mastercard";
            break;
        case Tarjeta::Tipo::VISA:
            os<<"VISA";
            break;
        default:
            os<<"Tipo indeterminado";
        break;
    }
    return os;
}

ostream& operator <<(ostream& os, const Tarjeta& tar){
   
    os << left << tar.tipo() << endl;
    os << tar.numero() <<  endl;
    os  << tar.titular_facial() <<  endl;
    os << "Caduca: ";
    if (tar.caducidad().mes() < 10) {
        os << "0";
    }
    os << tar.caducidad().mes() << "/" << (tar.caducidad().anno() % 100)  << endl;
    return os;
}

//Titular facial
Cadena Tarjeta::titular_facial() const {
    Cadena facial = titular()->nombre() + Cadena(" ") + titular()->apellidos();
    for(auto& c: facial){ //Convertir en mayúsculas
        c = std::toupper(c);
    }
    return facial;
}


/* CLASE NÚMERO----*/
struct EsBlanco{
    public:
    bool operator () (char c)const { return isspace(c);}
    private:
    char c_;
};

struct EsDigito{
    public:
    bool operator () (char c)const { return isdigit(c);}
    private:
    char c_;
};

Numero::Numero(const Cadena& num){

    //Devuelve el iterador al ultimo elemento sin espacios
    auto it = std::remove_if(num.begin(), num.end(), EsBlanco());
    
    if(std::find_if(num.begin(), it, std::not_fn(EsDigito()))!= it) 
    throw Numero::Incorrecto(DIGITOS);

    Cadena noEspacios = num.substr(0, it-num.begin());
 
    //Verificamos que sea correcta
    if(noEspacios.length()<13 || noEspacios.length()>19){
        throw Numero::Incorrecto(LONGITUD);
    }
    
    if(!luhn(noEspacios)){
        throw Numero::Incorrecto(NO_VALIDO);
    }

    numero_ = noEspacios;
}

