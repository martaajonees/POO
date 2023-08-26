# Ejercicio 2
La lista inicializadora y la lista de inicialización tienen funciones distintas:

Como ya hemos dicho antes, la lista de inicialización se utiliza para asignar valores a los stributos a la hora de
crear los objetos. La sintaxis es:
```C++
class Ejemplo {
public:
    Ejemplo(int a, int b) : atributo1(a), atributo2(b) {}
private:
    int atributo1;
    int atributo2;
};
```

Por otro lado, la lista inicializadora se utiliza para inicializar un objeto con una lista de valores entre llaves. 
La sintaxis es la siguiente:
```C++
int vector[] = {1, 2, 3, 4, 5};
```

as listas de inicialización y las listas inicializadoras sólo se pueden utilizar en el constructor de una clase. 
No es posible utilizar estas listas en otros métodos de una clase.
