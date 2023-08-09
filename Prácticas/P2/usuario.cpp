
#include "usuario.hpp"

#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <random>
#include <time.h>
#include "tarjeta.hpp"
#include "articulo.hpp"

using namespace std;

std::unordered_set<Cadena> Usuario::identificador_;

/* CLASE CLAVE*/
Clave::Clave(const char* contr)
{   
    //Comprobamos longitud
    if (strlen(contr)<5) throw Clave::Incorrecta(CORTA);

    //generación de un salt seguro para la encriptaciópn
    //srand(time(nullptr)); //Inicializar semilla
    const char* salt_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";
    char salt[3];
    salt[0] = salt_chars[rand()%strlen(salt_chars)];
    salt[1] = salt_chars[rand()%strlen(salt_chars)];
    salt[2] = '\0';
    //salt aleatorio de 2 caracteres elegidos aleatoriamente  
    if(crypt(contr, salt) == NULL) throw Clave::Incorrecta(ERROR_CRYPT);
        
    clave_ = crypt(contr, salt);
}


bool Clave::verifica(const char* contr) const
{
    const char* cifrado = crypt(contr,(const char*) clave_);
    return cifrado == clave_;
}

std::unordered_set<Cadena> identificador_; //declaracion adelantada

/*CLASE USUARIO-----------------------------------*/
Usuario::Usuario(const Cadena& ident, const Cadena& nombre,const Cadena& apell, const Cadena& dir, const Clave& clave):
id_(ident), nombre_(nombre), apellidos_(apell), direccion_(dir), password_(clave){
    typedef unordered_set<Cadena>::iterator it;
    std::pair<it, bool> res = identificador_.insert(id_);
    if(!res.second) //Inserción fallida
       throw Usuario::Id_duplicado(id_);
}

void Usuario::compra(const Articulo& art, unsigned int cantidad){
    auto it = articulos_.find(const_cast<Articulo*>(&art)); //Miramo si existe
    if (it == articulos_.end()){ //No está
        if(cantidad>0) articulos_.insert(std::make_pair(const_cast<Articulo*>(&art), cantidad));
    }else if(cantidad >0) //Verificamos que esté en el mapa
            it->second = cantidad;
        else articulos_.erase(it);
    
}

//Método ostream
ostream& operator <<(ostream& os, const Usuario& user){
    setlocale(LC_ALL,"");
    os<< user.id()<<" ["<<user.password_.clave()<<"] "<<user.nombre()<<user.apellidos()<<endl;
    os<<user.direccion()<<endl;
    os<<"Tarjetas: "<<endl;
    for(auto& tarjeta: user.tarjetas())
        os<< *tarjeta.second <<endl;
    return os;
}

//Mostrar carro
ostream& mostrar_carro(ostream& os, const Usuario& user){
    os<<"Carrito de compra de "<<user.id()<<" [Artículos: "<<user.n_articulos()<<"]"<<endl;
    os<<"Cant. \tArt."<<endl;
    os<<"==========================================================="<<endl;
    for(auto art: user.compra()){
        os<<"["<<art.second<<"] "<<*art.first<<endl;
    }
    return os;
}


//Destructor
Usuario::~Usuario(){
    for(auto t: tarjetas_) t.second->anular_titular();
    Usuario::identificador_.erase(id_);
    
}



