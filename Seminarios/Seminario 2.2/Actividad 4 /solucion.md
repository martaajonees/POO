# Ejercicio 4

1. __Se puede definir: `LibroX lib1;`__

   Solo se puede en el Libro1 ya que el Libro2 no permite construir un objeto Libro2 sin argumentos.
3. __Se tiene un constructor de conversión de `std::string a LibroX`__

   Ambas lo permiten.
5. __Se puede definir: `LibroX lib2[5];`__
   
   Solo lo permite `Libro1`. Ya que la línea `Libro1 lib2[5];` crea un array de 5 valores del tipo Libro1 con valores predeterminados.
