
#ifndef _FECHA_HPP_
#define _FECHA_HPP_
#include <ctime>

class Fecha{
  public:
    static const int AnnoMinimo = 1902;
    static const int AnnoMaximo = 2037;

    explicit Fecha(int d=0,int m=0, int y=0);
    Fecha(const char* f); /* Constructor de una cadena de caracteres en el formato: "dd/mm/aaa" */
    size_t dia() const; 
    size_t mes() const;
    size_t anno() const;
    //Fecha& operator=(const Fecha& f);
    Fecha& operator += (int d);/*Operadores*/
    Fecha& operator -= (int d);
    Fecha operator +(int i)const;
    Fecha operator -(int i)const;
    Fecha& operator ++();
    Fecha& operator ++(int);
    Fecha& operator --();
    Fecha& operator --(int);
    bool operator != (const Fecha&) const;
    bool operator == (const Fecha&) const;
    bool operator > (const Fecha&) const;
    bool operator < (const Fecha&) const;
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

inline const char * Fecha::Invalida::por_que() const
{ return (info_); }

#endif