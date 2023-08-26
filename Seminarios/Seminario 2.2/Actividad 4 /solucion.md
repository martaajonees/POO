# Ejercicio 4

1. __Se puede definir: `LibroX lib1;`__

   Solo se puede en el Libro1 ya que el Libro2 no permite construir un objeto Libro2 sin argumentos.
3. __Se tiene un constructor de conversión de `std::string a LibroX`__

   Ambas lo permiten.
5. __Se puede definir: `LibroX lib2[5];`__
   
   Solo lo permite `Libro1`. Ya que la línea `Libro1 lib2[5];` crea un array de 5 valores del tipo Libro1 con valores predeterminados.

4. __Se puede definir: `std::vector<LibroX> lib3;`__

   Con ambos se puede ya que solo se define un vector de Libro1 y de Libro2 vacío que aún no contiene ninguna instancia de objetos LibroX.

6. __Siendo "El Quijote" una cadena literal de tipo `const char*`; se produce una conversión implícita a `string` al ejecutar: `LibroX* lib4 = new LibroX("El Quijote");`__

   Cuando se ejecuta con `Libro 1`, se produce una conversión implícita de `const char *` a `string` debido a que no tiene un constructor de Libro2 a `const char *`. Para que se pueda crear a partir del constructor `Libro1(string t = "", int p = 0)` , hay que realizar ese cambio.

   Libro2 simplemente utiliza el constructor de conversión.

8. __Se puede definir: LibroX lib5 = "El Quijote";__

   Solo se puede con Libro2, ya que Libro1 no tiene ningún constructor a `const char*`

10. __Hace falta definir el destructor para LibroX.__

    Solo de Libro2
