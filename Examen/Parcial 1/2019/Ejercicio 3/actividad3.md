# Ejercicio 3
__Apartado 1__ 

Es más conveniente ponerlo como miembro si no queremos incluir métodos observadores de los atributos privados, pero, en otros casos
podría resultar un código más limpio y facilitar la ocultación de información sobrecargandolo de manera externa con
el uso de observadores.

```C++
class Fecha {
public:
  //..
  long operator -(const Fecha& f); //Como miembro
private:
  int dia_,mes_,anio_;
};

bool operator < (Fecha f1, Fecha f2); //Externo
```

__Apartado 2__

Partimos de que está ya sobrecargado:
```C++

class Fecha {
public:
  //..
  long operator -(const Fecha& f); //Como miembro
  int dia() const {return dia_;}
  int mes() const {return mes_;}
  int anio() const {return anio_;}
private:
  int dia_,mes_,anio_;
};

bool operator < (Fecha f1, Fecha f2);
```
El operador - quedaría:
```C++
long operator -(Fecha f1, Fecha f2){ //Externo
    long dias = 0;
    const int dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //En f1 siempre el más pequeño
    if(f2 < f1){
        Fecha aux;
        aux = f2;
        f2 = f1;
        f1 = aux;
    }

    dias += abs(f1.dia() - f2.dia());
    dias += abs(f1.mes() - f2.mes()) * dias_por_mes[f1.mes()];
    dias = abs(f1.anio() - f2.anio()) * 365;
    
    //Si el año es bisiesto le sumamos un dia
    if(((f1.anio() +1960) % 4 == 0 && ((f1.anio() + 1960) % 100 != 0 || (f1.anio() + 1960) % 400 == 0))){
        dias ++;
    }

    return dias;
}
```

__Apartado 3__

Sobrecargar el operador '+' para objetos de la clase Fecha puede ser útil si tiene un significado claro 
en el contexto de tu programa, como calcular una fecha futura a partir de una fecha y días. 
Sin embargo, esta sobrecarga puede volverse ambigua 
si no está definida con claridad y puede añadir complejidad si trabajar con fechas es complicado en tu aplicación
