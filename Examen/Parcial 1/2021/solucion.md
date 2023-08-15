# Apartado 1
```C++
class MatrizDispersa { 
public:
    explicit MatrizDispersa(size_t m = 1, size_t n = 1);
    void asignar(size_t fila, size_t colum, double valor);
    double valor(size_t fila, size_t colum) const;
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
    double valor(size_t fila, size_t colum) const;
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
## Apartado 3
```C++
void MatrizDispersa::asignar(size_t fila, size_t colum, double valor){
    if(fila > m || colum > n){
        throw out_of_range("la fila y la columna está fuera del rango");
    } 
    bool enc = false;
    terna t;
    t.f = fila;
    t.c = colum;
    t.v = valor;
    for(auto it = val.begin(); it != val.end() && !enc; it++){
        if(*it < t && t.v != 0){ //Orden creciente
            val.insert(it, t); //Inserto en el inicio
            enc = true;
        }
    }
    // Si el valor es igual a 0 no lo inserto
    if(!enc && valor != 0){ //Si no lo he encontrado, inserto al final
        val.insert(val.end(), t); 
    }
}


double MatrizDispersa::valor(size_t fila, size_t colum) const {
    if(fila > m || colum > n){
        throw out_of_range("la fila y la columna está fuera del rango");
    }
    bool enc = false;
    double res = 0; //Si no lo encuentra devuelve 0 
    for(int i = 0; i < val.size() && !enc; i++){
        if(val[i].f == fila && val[i].c == colum){
            enc = true;
            res = val[i].v;
        }
    }
    return res;
}

size_t MatrizDispersa::filas() const { return m; }

size_t MatrizDispersa::columnas() const { return n; }

int MatrizDispersa::n_valores() const { return val.size(); }
```
## Apartado 4
La clase quedaría:
```C++
class MatrizDispersa { 
public:  
    MatrizDispersa(initializer_list<terna>);
    explicit MatrizDispersa(size_t m = 1, size_t n = 1): m(m), n(n){}
    void asignar(size_t fila, size_t colum, double valor);
    double valor(size_t fila, size_t colum) const;
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

MatrizDispersa::MatrizDispersa(initializer_list<terna> l){
    vector<terna> aux(l);
    terna last = aux.back();
    m = last.f;
    n = last.c;
    //Recorremos la lista y vamos insertando si son distintas de 0
    for(const auto& elem: aux){
        if(elem.v != 0.0){
            asignar(elem.f, elem.c, elem.v);
        }
    }
}
```
## Apartado 5
```C++
int main() {
    MatrizDispersa A{{0, 1 , 7.5}, {2, 0, 18.2}, {2, 2, 86.37}, {3, 3, 10.25}, {4, 2, 61.05}, {4, 3, 0.0}};
    try {
        A.asignar(8, 6, 0.0);
    } catch(const out_of_range& e){
        cerr << "Error: " << e.what() << ". No se pudo actualizar el valor";
    }
    return 0;
}

```
## Apartado 6
No hace falta definir un destructor para la clase `MatrizDispersa` ya que no se utiliza memoria dinámica ni recursos externos. En nuestro caso, el `std::vector` se encarga de liberar la memoria ocupada automáticamente sin necesidad de definirlo.

## Apartado 7
Para hacer un intercambio evitando la copia de objetos, lo hacemos mediante el movimiento de objetos. Para ello declaramos y definimos el constructor de movimiento y el operador de asignación por movimiento de esta manera.
```C++
class MatrizDispersa { 
public:  
    MatrizDispersa(initializer_list<terna>);
    explicit MatrizDispersa(size_t m = 1, size_t n = 1): m(m), n(n){}
    MatrizDispersa(MatrizDispersa&&);
    MatrizDispersa& operator=(MatrizDispersa && o);
    void asignar(size_t fila, size_t colum, double valor);
    double valor(size_t fila, size_t colum) const;
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

MatrizDispersa::MatrizDispersa(MatrizDispersa&& o): m(o.m), n(o.n), val(o.val){
    o.m = 0;
    o.n = 0;
    o.val.clear();
}

MatrizDispersa& MatrizDispersa::operator=(MatrizDispersa && o){
    if(this != &o){ //evitar autoasignación
        n = o.n;
        m = o.m;
        val = o.val;
        //Dejamos o vacío
        o.n = 0;
        o.m = 0;
        o.val.clear();
    }

    return *this;
}
```
Tras esto, podemos definir la función externa de intercambio:
```C++
void intercambiar(MatrizDispersa& A, MatrizDispersa& B){
    MatrizDispersa C (std::move(A));
    A = std::move(B);
    B = std::move(C);
}
```

## Apartado 8
```C++
double& MatrizDispersa::valor(size_t fila, size_t colum){
    if(fila > m || colum > n){
        throw out_of_range("la fila y la columna está fuera del rango");
    }
    int indice;
    bool enc = buscar(fila, colum, indice);
    if(enc){
        return val[indice].v;
    } else{
        asignar(fila, colum, 1.0);
        buscar(fila, colum, indice);
        return val[indice].v;
    }
}

Un inconveniente en esta sobrecarga es que se estaría permitiendo cambiar valores en la matriz dispersa sin un mecanismo claro para manejar la dispersión y mantener la coherencia de los datos.

Por ejemplo, en una matriz 3x3 de la siguiente manera:
```
3.0  0.0  0.0
0.0  2.0  0.0
0.0  1.0  0.0

```
Y le asignamos el `valor(1,1) = 0.0` tendríamos un valor 0.0 en nuestro vector `val`y no podríamos
controlar la propiedad de dispersión de nuestra matriz.

