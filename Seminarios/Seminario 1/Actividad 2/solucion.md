La ocultación de datos permite separar el aspecto de un componente, que viene determinado por 
su interfaz con el exterior, de sus detalles internos de implementación. La interfaz del componente 
representa un «_contrato_» de prestación de servicios entre él y los demás componentes del sistema.

Así los clientes de un componente sólo necesitan conocer los servicios que éste ofrece, no cómo están 
realizados internamente.

Esto permite disminuir las interdependencias entre los componentes relacionados del sistema, reduciendo el 
_acoplamiento_ entre ellos.
