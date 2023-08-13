# Apartado 1
```C++
class MatrizDispersa { 
public:
    explicit MatrizDispersa(size_t m = 1, size_t n = 1);
    void asignar(size_t fila, size_t colum, double valor);
    double valor() const;
    size_t filas() const;
    size_t columnas() const;
    int n_valores() const;
private:
  struct terna {
    size_t f, c;
    double v;
  };
  bool buscar(size_t fila, size_t colum, int& indice);
    size_t m, n;
    std::vector<terna> val;
};
```
## Apartado 2
La sobrecarga del operador < hay que hacerla dentro de la estructura terna para poder acceder a sus elementos, de la siguiente manera:
```C++
class MatrizDispersa { 
public:
    typedef vector<terna>::iterator iterator;   
    explicit MatrizDispersa(size_t m = 1, size_t n = 1);
    void asignar(size_t fila, size_t colum, double valor);
    double valor() const;
    size_t filas() const;
    size_t columnas() const;
    int n_valores() const;
private:
  struct terna {
    size_t f, c;
    double v;
    bool operator <(terna& t1); //Sobrecarga operador <
  };
  bool buscar(size_t fila, size_t colum, int& indice);
    size_t m, n;
    std::vector<terna> val;
};

bool MatrizDispersa::terna::operator <(terna& t){
    return (t.f < f)|| ((t.f == f) && (t.c < c));
}
```
Con esto programado, la operación `buscar()` será de la siguiente manera:
```C++
bool MatrizDispersa::buscar(size_t fila, size_t colum, int& indice){
    bool enc = false;
    for(int i = 0; i < val.size() && !enc; i++){
        if(val[i].f == fila && val[i].c == colum){
            enc = true;
            cout << "Elemento encontrado.";
            indice = i;
        }
    }
    //Si no lo hemos encontrado devolvemos el índice del siguiente valor
    if(!enc){
        terna t;
        t.f = fila;
        t.c = colum;
        for(int i = 0; i < val.size() ; i++){
            if(t < val[i]){
                indice = i;
            }
        }   
    }
    //Si no se encuentra un valor menor, devuelve n_valores()
    if(indice == -1){
        indice = n_valores();
    }
    return enc;
}
```
