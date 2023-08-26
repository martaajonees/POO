# Actividad 4
1. La funcion `f1(int i) const` está puesta como constante, lo que significa que no puede modificar ningún atributo de la clase
   privados (excepto mutable).

   Funcionaría si se pusiera así, o si se pone la variable h como `mutable`.:
   ```C++
   int C::f1(int i) {
     h = i;
     k = i;
     return 0;
   }
   ```

2. En `C()` , se está inicializando todos los valores a 0.
  Aquí no e ha inicializado j, que es una variable miembro constante.
  Las variables miembro constantes deben inicializarse en la lista de inicialización del constructor.
  ```C++
    C::C(): h(0), i(0), j(0), k(0) {}
  ```
3. En la función `static void f3()` se está intentando asignar un valor no estático a un valor estático, lo que no
   es correcto.
