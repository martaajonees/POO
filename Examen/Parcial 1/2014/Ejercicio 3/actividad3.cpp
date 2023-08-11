class Fecha {
  public:
  class Invalida { //clase de excepción
    public:
      Invalida (const char*);
      const char* por_que() const;
    private:
      const char* razón;
    };

explicit Fecha(int d = 0, int m = 0, int a = 0);
Fecha(const char * c);
int dia () const noexcept;
int mes () const noexcept;
int anno () const noexcept;
// ...
private:
int dia_, mes_, anio_;
};

Fecha::Fecha(const char * c) {
    if(strlen(c) != 10 || c[2] != '/' || c[5] != '/'){
        throw Fecha::Invalida("Formato incorrecto");
    }else{
        if(sscanf(c, "%2d/%2d/%4d", &dia_, &mes_, &anio_) != 3)
            throw Fecha::Invalida("Formato incorrecto");
        if(dia_ < 1 || dia_ > 31 || mes_ < 1 || mes_ > 12 || anio_ < 0){
            throw Fecha::Invalida("Formato incorrecto");
        }
    }
}
