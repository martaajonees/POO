
Contesta verdadero (V) o falso (F) a las siguientes afirmaciones. Un acierto suma 0,1 y un fallo resta un acierto.

1. Un método const puede modificar un atributo mutable solamente si el objeto al que pertenecen no es constante.

   ` Falso. Un método calificado con const puede modificar siempre un atributo mutable indiferentemente de si su objeto es o no constante.
   `
   > Mutable: esta palabra reservada indica que el miembro de datos nunca será constante, ni aunque el objeto al
   > que pertenece lo sea.
  
3. Un método observador que devuelva una referencia no constante a un atributo privado permite violar el principio de ocultación de información.
   
   ` Verdadero. El problema surge cuando un método observador devuelve una referencia no constante de un atributo
   privado lo que permitiría que cualquier usuario que haga uso de ese método pueda modificar dicho atributo
   privado.`

   `El principio de ocultación de informacion se refiere a la forma en que se exponen y manipulan los detalles de implementación internos de una clase.`

   `Por lo que este problema iría en contra de este principio.`

3. Una función amiga de una clase C sólo tiene acceso a los miembros privados de C.
   
   `Falso. Una función amiga de una clase C tiene acceso a todos los miembros: a los privados(por ser amigas) y a
   los públicos (como cualquier otra función).`

4. Una función amiga de una clase C no tiene acceso al puntero this.

   `Falso. Debido a que no es una función miembro no tienen acceso al puntero this.`

7. El puntero this no es modificable.
  
   `Verdadero. Aunque si se habilita se pueden hacer asignaciones a this.`

10. Se pueden definir clases sin escribir ningún constructor.
    
    `Verdadero. Se utilizaría el constructor por defecto que crea el compilador.`

7. Al inicializar un objeto se llama al constructor de copia, si existe, y si no, al operador de asignación.
El único parámetro de un constructor de copia puede ser una referencia const o no const.
El único parámetro de un constructor de copia se puede pasar por valor, aunque a veces es obligatorio pasarlo por referencia.
El único parámetro del operador de asignación se puede pasar siempre por valor.
La declaración de un constructor con dos o más parámetros, todos con un valor por defecto definido, en realidad declara dos constructores: el predeterminado y uno de conversión.
C++ permite sobrecargar un operador dándole un significado diferente al que por naturaleza le corresponde.
La sobrecarga externa de un operador para una clase requiere la definición de un operador de conversión.
No se pueden sobrecargar operadores en la parte privada de una clase.
Siempre que se defina un constructor para una clase hay que definir al menos un destructor.
