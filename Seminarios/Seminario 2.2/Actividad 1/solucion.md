# Ejercicio 1
La principal diferencia es que la lista de inicialización se utiliza para asignarles valores a los atributos a 
la hora de crear el objeto.

La sintaxis es :

```C++
  class Ejemplo {
public:
    Ejemplo(int a, int b) : atributo1(a), atributo2(b) {}
private:
    int atributo1;
    int atributo2;
};
```

La asignación en el cuerpo del constructor se usa para modificar los valores de los atributos una vez ya creado el objeto.

La sintaxis es:

```C++
  class Ejemplo {
public:
    Ejemplo(int a, int b){
      atributo1 = a;
      atributo2 = b; 
    }
private:
    int atributo1;
    int atributo2;
};
```
