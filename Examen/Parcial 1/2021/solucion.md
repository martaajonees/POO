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
  bool buscar(size_t fila, size_t colum);
    size_t m, n;
    std::vector<terna> val;
};
```
## Apartado 2
