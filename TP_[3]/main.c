#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "miBiblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int opcionIngresada;
    int banderaTexto;
    int banderaBinario;

    LinkedList* listaEmpleados;

    banderaTexto = 0;
    banderaBinario = 0;

    listaEmpleados = ll_newLinkedList();

    do
    {
        opcionIngresada = MostrarMenu(1, 10);

        switch(opcionIngresada)
        {
        case 1:
            HacerLaLogicaCase1(&banderaTexto, &banderaBinario, "data.csv", listaEmpleados);
            break;

        case 2:
            HacerLaLogicaCase2(&banderaTexto, &banderaBinario, "databin", listaEmpleados);
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            break;

        case 4:
            controller_editEmployee(listaEmpleados);
            break;

        case 5:
            controller_removeEmployee(listaEmpleados);
            break;

        case 6:
            controller_ListEmployee(listaEmpleados);
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            break;

        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;

        case 9:
            controller_saveAsBinary("databin", listaEmpleados);
            break;

        default:
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcionIngresada != 10);
    return 0;
}
