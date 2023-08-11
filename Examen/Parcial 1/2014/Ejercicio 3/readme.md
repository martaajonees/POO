# Ejercicio 3
Se dispone de la clase Fecha siguiente:
```C++
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
int dia () const noexcept;
int mes () const noexcept;
int anno () const noexcept;
// ...
private:
int dia_, mes_, anio_;
};
```
El constructor inicializa una Fecha tomando os parámetros en el orden día, mes,
año. Si un parámetro es 0, se toma el valor correspondiente de la fecha del
sistema. En caso de que el valor de algún parámetro no sea válido el constructor
lanza una excepción `Fecha::Invalida`, cuya razón se puede obtener con el
método `fecha::Invalida::por_que()`.
1. Implementa un constructor de conversión desde cadena de caracteres en el
formato ”dd/mm/aaaa”, siendo dd y mm el día y el mes, respectivamente,
expresados con 1 ó 2 dígitos, y aaaa los 4 dígitos del año. Se lanzara una excepción
`Fecha::Invalida` si la cadena no se ajusta al formato correcto.
