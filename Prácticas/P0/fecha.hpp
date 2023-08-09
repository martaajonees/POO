
#ifndef _FECHA_HPP_
#define _FECHA_HPP_
#include<iomanip>
#include<locale>
#include <cstdio>
#include<iostream>
using namespace std;
#include <ctime>

class Fecha{
  public:
    static const int AnnoMinimo = 1902;
    static const int AnnoMaximo = 2037;

    explicit Fecha(int d=0,int m=0, int y=0);
    Fecha(const char* f); /* Constructor de una cadena de caracteres en el formato: "dd/mm/aaa" */
    int dia() const noexcept; 
    int mes() const noexcept;
    int anno() const noexcept;
    
    Fecha& operator += (int d);/*Operadores*/
    Fecha& operator -= (int d);
    Fecha operator +(int i)const;
    Fecha operator -(int i)const;
    Fecha& operator ++();
    Fecha operator ++(int);
    Fecha& operator --();
    Fecha operator --(int);
    operator const char *()const; /* Conversión de Cadena a const char */
    
    class Invalida {
      public:
          Invalida(const char* inf):info_(inf){}
          const char * por_que() const;
      private:
          const char * info_;
    };

  private:
    int dia_, mes_, anno_;
    void es_fecha_valida();
    
};

/* Operadores lógicos*/
  bool operator != (const Fecha& f1,const Fecha& f2 );
  bool operator == (const Fecha& f1,const Fecha& f2);
  bool operator > (const Fecha& f1,const Fecha& f2);
  bool operator < (const Fecha& f1,const Fecha& f2);
  bool operator <= (const Fecha& f1,const Fecha& f2);
  bool operator >= (const Fecha& f1,const Fecha& f2);

  inline bool operator == (const Fecha& f1,const Fecha& f2){
    return ((f1.dia()==f2.dia())&&(f1.mes()==f2.mes())&& (f1.anno()==f2.anno()));
  }

  inline bool operator != (const Fecha& f1,const Fecha& f2 ){
    return !(f1==f2);
  }

  inline bool operator > (const Fecha& f1,const Fecha& f2){
     return (f2<f1);
  }
  inline bool operator < (const Fecha& f1,const Fecha& f2){
      return ((f1.anno() < f2.anno()) || ((f1.anno() == f2.anno()) && (f1.mes() < f2.mes())) || 
     (((f1.anno() == f2.anno()) && (f1.mes() == f2.mes())) && (f1.dia() < f2.dia())));
  }
  inline bool operator <= (const Fecha& f1,const Fecha& f2){
    return !(f2<f1);
  }
  inline bool operator >= (const Fecha& f1,const Fecha& f2){
    return !(f1<f2);
  }

/* Observadores -------------------------------------------------------------------------------------------------- */
  inline int Fecha::dia() const noexcept{
    return dia_;
  }
  inline int Fecha::mes() const noexcept{
    return mes_;
  }
  inline int Fecha::anno() const noexcept{
    return anno_;
  }

inline const char * Fecha::Invalida::por_que() const
{ return (info_); }

#endif
