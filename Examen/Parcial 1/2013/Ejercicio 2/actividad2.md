1. `A a1, a2;` SI. Se utiliza el constructor prederminado de la clase A
2. `B b1 = 0;` SI. Se utiliza el constructor de conversión de int a clase B y el constructor de copia
3. `B *p = new B(10);` Si. Utiliza el constructor para crear el objeto B y guarda direccion de memoria. 
4. `B * q = new B[10];` NO. No existe ningún constructor predeterminado para la clase B
5. `B b2 = "examen"` NO. No hay un constructor adecuado para convertir de const char* a clase B
6. `A a3(b1);` NO. No hay ningún constructor de conversión de clase B a clase A.
7. `a2 = a1 = *q` NO. No hay ningún operador de asignación de clase B a clase A.
8. `B b3 = a2` NO. no existe ningún constructor de conversión de clase A a clase B. Solo existe el operador de asignación.
