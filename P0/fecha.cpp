#include "fecha.hpp"

/* Fecha con tres parámetros: el día, el mes y el año */
Fecha::Fecha(int d,int m, int y): dia_(d), mes_(m),anno_(y)
{ 
  if(d == 0 || m==0 || y==0){
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);
    int year_now = tiempo_descompuesto->tm_year + 1900;
    int month_now = tiempo_descompuesto->tm_mon + 1;
    int day_now = tiempo_descompuesto->tm_mday;

    if(y==0) anno_=year_now;
    if(m==0) mes_=month_now;
    if(d==0) dia_=day_now;
  }
  es_fecha_valida();
}

/* A partir de una cadena de caracteres en el formato: "dd/mm/aaa" */
Fecha::Fecha(const char* f){ 
  int dia, mes, anio;
  int date = sscanf(f, "%d/%d/%d", &dia, &mes, &anio);
  if(date!=3){
    throw Fecha::Invalida ("Formato de la cadena incorrecta");
  }else{
   Fecha d(dia,mes,anio);
    dia_ = d.dia();
    mes_ = d.mes();
    anno_ = d.anno();
  }
}


/* 1.2 Comprobar que una fecha sea válida ---------------------------------------------------*/ 
void Fecha::es_fecha_valida(){
  static const int diasMes[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
  bool bisiesto = (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0));
  
  //Verficamos que si es un año bisiesto y es febrero, tenga 29 días
   if (dia_ < 1 || dia_ > diasMes[mes_] || (bisiesto && mes_ == 2 && dia_ > 29) || (!bisiesto && mes_ == 2 && dia_ > 28)) {
    throw Invalida("Fecha incorrecta");
  }
    
    if(anno_ < AnnoMinimo || anno_ > AnnoMaximo){ //Verificamos año
       throw Invalida ("Año incorrecto");
    }

    if(mes_ < 1 || mes_ > 12){ // Verificamos mes
        throw Invalida("Mes incorrecto");
    }
}
 

/* PARTE 2: OPERADORES ---------------------------------------------------------*/

Fecha& Fecha::operator += (int i){
    struct tm f = {};
    f.tm_mday = dia_;
    f.tm_mon = mes_ - 1;
    f.tm_year = anno_ - 1900;
    f.tm_mday += i;
    
    std::mktime(&f);

    this->dia_ = f.tm_mday;
    this->mes_ = f.tm_mon +1;
    this->anno_ = f.tm_year+ 1900;

    es_fecha_valida();
    return *this;
}

Fecha& Fecha::operator -= (int i){
  *this += -i;
  return *this;
}

Fecha Fecha::operator +(int i)const{ //deben ser declaradas como const 
//ya que no modifican el objeto Fecha original
  Fecha f;
  f = *this; //Creamos copia del objeto
  f += i;
  return f;
}

Fecha Fecha::operator -(int i)const{
  Fecha f;
  f = *this; //Creamos copia del objeto
  f += -i;
  return f;
}

Fecha& Fecha::operator ++(){//
  *this += 1;
  return *this;
}

//Operador de postincremento
Fecha& Fecha::operator ++(int){ //f++
  Fecha f;
  f= *this;
  *this += 1;
  return f;
}

Fecha& Fecha::operator --(){
  *this += -1;
  return *this;
}

Fecha& Fecha::operator --(int){ //f++
  Fecha f;
  f= *this;
  *this += -1;
  return f;
}


/* Conversión de Cadena a const char ----------------------------------------------------*/
Fecha::operator const char *() const
{
    setlocale(LC_ALL,"es_ES.UTF-8"); //establece el locale español
    struct tm f{};
    f.tm_year= anno_ - 1900;
    f.tm_mon= mes_ - 1;
    f.tm_mday= dia_;

    mktime(&f);

    static char aux[80];
    strftime(aux,80,"%A %e de %B de %Y",&f );
    return aux;
}


