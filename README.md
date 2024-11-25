## Planificador de Tareas

### Nombre: Juan Pablo Hernández Tovar  
### Matrícula: A01712073

### Descripción del Proyecto
Este proyecto es un planificador de tareas que permite a los usuarios gestionar sus actividades, asignarles prioridades y fechas de entrega, y organizar las tareas de manera eficiente. Está diseñado para ayudar a estudiantes y profesionales a mantener un seguimiento de sus responsabilidades.

### Funcionalidades Principales
- Agregar Tareas: Permite al usuario ingresar una nueva tarea con una descripción, prioridad (1-3) y fecha de entrega.
- Eliminar Tareas: Las tareas pueden eliminarse utilizando su descripción.
- Buscar Tareas: Los usuarios pueden buscar tareas específicas por descripción o prioridad.
- Ordenar Tareas: Las tareas pueden ordenarse por prioridad o fecha de entrega utilizando el algoritmo Merge Sort.
- Mostrar Tareas: Se puede visualizar una lista de todas las tareas pendientes.
- Contar Tareas de Alta Prioridad: El programa puede contar recursivamente cuántas tareas tienen una prioridad de 1.
- Guardar y Cargar Tareas: Se pueden guardar tareas en un archivo y cargarlas desde un archivo existente para facilitar la gestión a largo plazo.

### Ejemplo de Uso
1. Agregar una tarea con su descripción, prioridad y fecha de entrega.
2. Eliminar una tarea por su descripción.
3. Mostrar todas las tareas pendientes.
4. Ordenar las tareas por prioridad.
5. Contar cuántas tareas de alta prioridad (1) existen de manera recursiva.
6. Guardar las tareas en un archivo para almacenamiento futuro.
7. Cargar tareas desde un archivo ya existente.

----------------------------------------------------------------------------------------------------
### SICT0301: Evalúa los Componentes

 ## Análisis de Complejidad:

- Agregar Tareas:
Complejidad: O(1) en todos los casos.
Explicación: La inserción de una tarea al principio de la lista enlazada es constante, ya que no depende del tamaño de la lista. Solo se necesita actualizar los punteros.

- Eliminar Tareas:
Mejor caso: O(1), cuando la tarea a eliminar es la primera.
Caso promedio y peor caso: O(n), donde n es el número de tareas, ya que podría ser necesario recorrer toda la lista si la tarea está al final o no existe.

- Buscar Tareas:
Mejor caso: O(1), si la tarea buscada es la primera.
Caso promedio y peor caso: O(n), ya que es necesario recorrer la lista hasta encontrar la tarea o alcanzar el final.

- Ordenar Tareas (Merge Sort):
Complejidad: O(n log n) en todos los casos.
Explicación: Merge Sort es un algoritmo eficiente y estable que funciona bien con listas enlazadas, lo que nos asegura un buen rendimiento aunque haya muchas tareas.

- Contar Tareas de Alta Prioridad:
Complejidad: O(n), ya que se tiene recorrer toda la lista para contar las tareas que tienen prioridad 1.

- Complejidad Final del Programa
En un uso de este programa, la operación más "costosa" es el algoritmo de ordenamiento (Merge Sort), que tiene una complejidad de O(n log n). Las otras operaciones (como agregar, buscar o eliminar tareas) tienen complejidades lineales o constantes en función del número de tareas n. Por esto, la complejidad final del programa se puede considerar O(n log n), siendo este el que más afecta al rendimiento del programa.


----------------------------------------------------------------------------------------------------
### SICT0302: Toma decisiones

#### Selección de Estructura Lineal
He elegido una lista enlazada para gestionar las tareas porque permite una inserción y eliminación eficiente en (O(1)), lo que es muy bueno para una colección de datos que cambia de tamaño constantemente. Aunque las búsquedas y eliminaciones específicas son (O(n)), esto no es un gran problema ya que no se realizan con tanta frecuencia. Además, esta estructura es compatible con el algoritmo mergeSort, que ordena las tareas en (O(nlogn)), sin necesidad de usar mucha memoria adicional. La lista enlazada me da flexibilidad, eficiencia y simplicidad, se adapta bien al funcionamiento interactivo de mi  programa.

#### Selección de Algoritmo de Ordenamiento
Para mi proyecto, eligí el Merge Sort como algoritmo de ordenamiento tomando en cuenta su eficiencia, conociendo su complejidad(n log n), y que es estable, mantiene el orden relativo de las tareas con la misma prioridad. Este algoritmo me parece una buena opción para listas enlazadas, permitiendo ordenar las tareas por prioridad(una función importante del programa) y tambien por fecha, lo que hace facil a los usuarios gestionar sus actividades pendientes.

----------------------------------------------------------------------------------------------------
### SICT0303: Implementa acciones científicas

## Consulta de Información:
He implementado métodos que dan la posibilidad a los usuarios de buscar tareas de manera eficiente utilizando descripciones específicas.

## Lectura de Archivos:
El programa ya cuenta con funcionalidades para guardar y cargar tareas desde un archivo, lo cual facilita el almacenamiento de datos a largo plazo y la transferencia de información entre sesiones.
