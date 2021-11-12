#include "LinkedList.h"
#include "Employee.h"

/*----------------------------------------------------------------------------------------------------*/
/** \brief Muestra el menu principal del programa.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \return int
 *
 */
int MostrarMenu(int opcionMinima, int opcionMaxima);

/** \brief Muestra el listado de empleados.
 *
 * \param pArrayListEmployee LinkedList*
 * \return void
 *
 */
void MostrarListadoEmpleados(LinkedList* pArrayListEmployee);

/** \brief Se encarga de hacer la logica del case 1 del switch del main.
 *
 * \param banderaTexto int*
 * \param banderaBinario int*
 * \param path char*
 * \param listaEmpleados LinkedList*
 * \return void
 *
 */
void HacerLaLogicaCase1(int* banderaTexto, int* banderaBinario, char* path, LinkedList* listaEmpleados);

/** \brief Se encarga de hacer la logica del case 2 del switch del main.
 *
 * \param banderaTexto int*
 * \param banderaBinario int*
 * \param path char*
 * \param listaEmpleados LinkedList*
 * \return void
 *
 */
void HacerLaLogicaCase2(int* banderaTexto, int* banderaBinario, char* path, LinkedList* listaEmpleados);

/** \brief Calcula el ID del empleado a buscar.
 *
 * \param pArrayListEmployee LinkedList*
 * \param minimo int
 * \return int
 *
 */
int CalcularIdEmpleado(LinkedList* pArrayListEmployee, int minimo);

/** \brief Calcula cual el el ID maximo de la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList*
 * \param minimo int
 * \return int
 *
 */
int CalcularIdMaximo(LinkedList* pArrayListEmployee, int minimo);

/** \brief Se encarga de pedirle al usuario una serie de datos.
 *
 * \param pArrayListEmployee LinkedList*
 * \param pElement void*
 * \return int
 *
 */
int PedirDatosDeUnEmpleado(LinkedList* pArrayListEmployee, void* pElement);

/** \brief Se encarga de pedirle al usuario un string.
 *
 * \param cadena[] char
 * \param buffer int
 * \param mensaje[] char. El mensaje para instruir al usuario.
 * \return void
 *
 */
void PedirUnaCadena(char cadena[], int buffer, char mensaje[]);

/** \brief Formaliza el nombre de los empleados.
 *
 * \param nombre[] char
 * \param buffer int
 * \return void
 *
 */
void FormalizarUnNombre(char nombre[], int buffer);

/** \brief Le pide al usuario un numero entero mayor a cero.
 *
 * \param mensaje[] char
 * \return int
 *
 */
int PedirUnNumeroEnteroMayorACero(char mensaje[]);

/** \brief Le pide al usuario un numero entero.
 *
 * \param mensaje[] char
 * \return int
 *
 */
int PedirUnNumeroEntero(char mensaje[]);

/** \brief Le pide al usuario un numero flotante.
 *
 * \param mensaje[] char
 * \return float
 *
 */
float PedirUnNumeroFlotante(char mensaje[]);

/** \brief Le pide al usuario el ID de un empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \param mensaje char*
 * \return int
 *
 */
int PedirIdEmpleado(LinkedList* pArrayListEmployee, char* mensaje);

/** \brief Se encarga de modificar los datos de un empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \param pElement void*
 * \return void
 *
 */
void ModificarEmpleado(LinkedList* pArrayListEmployee, void* pElement);

/** \brief Muestra el menu de modificaciones posibles a un empleados.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \param bandera int
 * \return int
 *
 */
int MenuDeModificaciones(int opcionMinima, int opcionMaxima, int bandera);

/** \brief Muestra el menu de criterios de ordenamiento al usuario.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \return int
 *
 */
int MostrarMenuDeOrdenamiento(int opcionMinima, int opcionMaxima);

/** \brief Muestra el menu de ordenamiento por ID.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \return int
 *
 */
int MostrarMenuDeOrdenamientoId(int opcionMinima, int opcionMaxima);

/** \brief Muestra el menu de ordenamiento por nombre.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \return int
 *
 */
int MostrarMenuDeOrdenamientoNombre(int opcionMinima, int opcionMaxima);

/** \brief Muestra el menu de ordenamiento por horas trabajads.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \return int
 *
 */
int MostrarMenuDeOrdenamientoHorasTrabajadas(int opcionMinima, int opcionMaxima);

/** \brief Muestra el menu de ordenamiento por sueldo.
 *
 * \param opcionMinima int
 * \param opcionMaxima int
 * \return int
 *
 */
int MostrarMenuDeOrdenamientoSueldo(int opcionMinima, int opcionMaxima);
