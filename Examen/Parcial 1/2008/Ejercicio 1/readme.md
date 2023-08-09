# Ejercicio 1
Se desea implementar en C++ una clase para almacenar fragmentos de ADN. Esta clase se denomina ADN y 
su representación interna está basada en dos atributos: un puntero, _c_, y un tamaño, _n_. 

El atributo _c_ apuntará a una zona de memoria dinámica creada con ```new``` que
será destruida con ```delete``` tan pronto como deje de ser necesaria. Dicha zona contendrá la
secuencia de nucleótidos de una de las hélices. El atributo _n_ representará la longitud de la
secuencia y se permitirá la existencia de secuencias vacías, que tendrán longitud 0.

Los nucleótidos se definen mediante un tipo enumerado, _Nucleotido_, formado por las constantes
enumeradas _A_ (adenina), _C_ (citosina), _G_ (guanina) y _T_ (timina), en dicho orden.

1. Defina externamente el constructor predeterminado para crear objetos _ADN: vacíos. No emplee asignaciones.
2. Defina externamente un constructor que cree un objeto _ADN_ a partir de una secuencia de nucleótidos, ya creada con __new__, representada por dos parámetros: un puntero y un tamaño. Utilice para los parámetros idénticos nombres a los indicados para los atributos. No emplee asignaciones. Este constructor será privado.
3. Defina externamente un constructor que cree un objeto _ADN_ con la secuencia de nucleótidos correspondiente
   a una cadena de bajo nivel de caracteres constantes, que recibirá como único parámetro y que sólo
   contendrá caracteres __’A’__, __’C’__, __’G’__ y __’T’__.
4. ¿Es necesario definir un constructor de copia si queremos copiar objetos _ADN_ con la
   semántica habitual que poseen los tipos primitivos? ¿Por qué?
6. Sobrecargue externamente el operador de suma para devolver la concatenación de dos
   objetos _ADN_. Suponga que ha sido declarado como amigo. Utilice el constructor más
   apropiado para crear el objeto temporal que devolverá como resultado, así como la función
   ```memcpy()``` de la biblioteca estándar (recuerde que posee tres parámetros: destino, origen
   y número de bytes). No empleee bucles.
7. Reescriba el siguiente fragmento de código colocando explícitamente las llamadas a los constructores implicados:
   ```C++
   const char∗ const s = "GA";
   ADN a(s), b = a;
   b[0] = C;
   (a + "TTA" + b).mostrar();
   ```
