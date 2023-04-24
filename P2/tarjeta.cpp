//Añadimos cabeceras
#include "tarjeta.hpp"
#include <locale>
#include "usuario.hpp"

using std::isspace;
using std::isdigit;

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
    os << " ____________________ " << endl;
    os << "/                     \\" << endl;
    os << "| " << setw(20) << left << tar.tipo() << "|" << endl;
    os << "| " << setw(20) << left << tar.numero() << "|" << endl;
    os << "| " << setw(20) << left << tar.titular_facial() << "|" << endl;
    os << "| " << "Caduca: ";
    if (tar.caducidad().mes() < 10) {
        os << "0";
    }
    os << tar.caducidad().mes() << "/" << setw(2) << setfill('0') 
    << (tar.caducidad().anno() % 100) <<"|" << endl;

    os << "\\____________________/" << endl;
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
Numero::Numero(const Cadena& num){
    //Le quitamos los espacios
    Cadena noEspacios;
    for(auto it: num){
        if(!isspace(it)){
            if(!isdigit(it)) throw Numero::Incorrecto(DIGITOS);
            else noEspacios += Cadena(1,it); //Tam = 1, char= it
        }
        
    }
    //Verificamos que sea correcta
    if(noEspacios.length()<13 || noEspacios.length()>19){
        throw Numero::Incorrecto(LONGITUD);
    }
    if(!luhn(noEspacios)){
        throw Numero::Incorrecto(NO_VALIDO);
    }
    
    numero_= noEspacios;  
}

