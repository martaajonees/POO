# Ejercicio 1

1. `A a1, a2;` SI. Utiliza el constructor por defecto clase A.
2. `B b1 = 0;` SI. Utiliza el constructor de conversion de int a clase B y utiliza el operador de asignación.
3. `B *p = new B(10);` SI. Utiliza el constructor y la asignación.
4. `B * q = new B [10];` NO. No hay constructor sin parámetros.
5. `B b2 = "examen";` NO. No hay constructor de conversion de string a clase B.
6. `A a3(b1);` NO. No hay constructor de conversión de clase B a clase A.
7. `a2 = a1 = *q;` NO. No hay conversión de clase B a clase A 
8. `B b3 = a2;` NO. No hay constructor de conversión de clase A a clase B.
