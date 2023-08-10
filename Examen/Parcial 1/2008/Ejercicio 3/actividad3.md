
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

   `Falso. la asignación se produce sólo cuando ya se ha creado y existe el objeto.`
9. El único parámetro de un constructor de copia puede ser una referencia const o no const.

   `Falso. El único parámetro debe ser una referencia const puesto que el objeto recibido por el constructor se va a copiar, no a modificar.`
10. El único parámetro de un constructor de copia se puede pasar por valor, aunque a veces es obligatorio pasarlo por referencia.
    
    `Falso. El parámetro formal del constructor debe ser obligatoriamente una referencia al objeto de la misma
    clase. Ya que si se pasara por valor daría lugar a una recursión infinita`
    
11. El único parámetro del operador de asignación se puede pasar siempre por valor.
    
    `Falso. AL igual que en el constructor de copia, siempre se debe pasar el único parámetro por referencia.`
12. La declaración de un constructor con dos o más parámetros, todos con un valor por defecto definido, en realidad declara dos constructores: el predeterminado y uno de conversión.

    `Falso. La declación de un constructor con mas de un parámetro no declara dos constructores, simplemente es una sobrecarga del constructor`
13. C++ permite sobrecargar un operador dándole un significado diferente al que por naturaleza le corresponde.

    `Verdadero. La sobrecarga de operadores proporciona al operador más de un significado.`
14. La sobrecarga externa de un operador para una clase requiere la definición de un operador de conversión.

    `Falso. Para sobrecargar un operador no es necesario del operador de conversión ya que no se trata de convertir a otro tipo, sino de definir cómo se comportará el operador en el contexto de esa clase`
15. No se pueden sobrecargar operadores en la parte privada de una clase.
    
    `Verdadero. Los operadores sobrecargados deben ser una función global o una función miembro no estática. No pueden sobrecargarse en la parte privada. Si se quiere acceder a la parte privada de la clase se deben declarar como friend`
17. Siempre que se defina un constructor para una clase hay que definir al menos un destructor.

    `Falso. Aunque se defina un constructor puede no ser necesario definir un constructor, se puede utilizar el predeterminado`


