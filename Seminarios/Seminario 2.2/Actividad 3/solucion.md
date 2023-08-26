# Ejercicio 3

1. `punto p;`

   __Correcto__. Llama al constructor con los valores predeterminados, en este caso `x = 0.0` y `y = 0.0`.
3. `punto q();`

   __No es correcto__. No se llama a ninguna función, sería la definición de una función que devuelve un tipo `punto`.

   __Corrección__: `punto q;`
5. `punto r(2. , );`

   __No es correcto__. Se debería llamar al constructor con valor `x = 2.0` y valor y predeterminado `y = 0.0` pero no
   es la sintaxis correcta.

   __Corrección__: `punto r(2.);`
7. `punto s{3.4};`
   
   __Correcto__. Llama al constructor con valor `x = 3.4` y valor y predeterminado `y = 0.0`.
9. `punto t{};`

    __Correcto__. Llama al constructor con los valores predeterminados, en este caso `x = 0.0` y `y = 0.0`.
11. `punto u(q);`
    
      __Correcto__. Llama al constructor de copia. Los valores de `u` serán los mismos que los de `q`
13. `punto v = r`;

    __Correcto__. Llama al constructor de copia para crear un objeto v y para asignarle los valores de r.
15. `t = s;`

  __Correcto__. Llama al operador de asignación. 
