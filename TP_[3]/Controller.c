#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "miBiblioteca.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int resultado;
    FILE* pArchivo;

    resultado = 0;
    pArchivo = fopen(path, "r");

    if(pArchivo != NULL)
    {
        resultado = parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    }

    fclose(pArchivo);

    return resultado;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int resultado;
    FILE* pArchivo;

    resultado = 0;
    pArchivo = fopen(path, "rb");

    if(pArchivo != NULL)
    {
        resultado = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
    }

    fclose(pArchivo);

    return resultado;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int resultado;
    int bandera;
    Employee* empleado;

    resultado = 0;
    empleado = employee_new();
    bandera = PedirDatosDeUnEmpleado(pArrayListEmployee, empleado);

    if(bandera == 0)
    {
        ll_add(pArrayListEmployee, empleado);
        resultado = 1;
    }

    return resultado;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int resultado;
    int indice;
    Employee* empleadoAuxiliar;

    resultado = 0;

    if(pArrayListEmployee != NULL)
    {
        indice = PedirIdEmpleado(pArrayListEmployee, "\nIngrese el ID del empleado que quiera modificar: ");
        empleadoAuxiliar = (Employee*) ll_get(pArrayListEmployee, indice);
        ModificarEmpleado(pArrayListEmployee, empleadoAuxiliar);
        ll_set(pArrayListEmployee, indice, empleadoAuxiliar);
        resultado = 1;
    }

    return resultado;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int resultado;
    int indice;

    resultado = 0;

    if(pArrayListEmployee != NULL)
    {
        MostrarListadoEmpleados(pArrayListEmployee);
        indice = PedirIdEmpleado(pArrayListEmployee, "Ingrese el ID del empleado que quiera dar de baja: ");
        ll_remove(pArrayListEmployee, indice);
        resultado = 1;
    }

    return resultado;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int resultado;

    resultado = 0;

    if(pArrayListEmployee != NULL)
    {
        MostrarListadoEmpleados(pArrayListEmployee);

        resultado = 1;
    }

    return resultado;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int resultado;

    resultado = 0;

    if(pArrayListEmployee != NULL)
    {
        OrdenarEmpleados(pArrayListEmployee);

        resultado = 1;
    }

    return resultado;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int resultado;
    int tam;
    int i;
    FILE* pArchivo;
    Employee* empleado;

    resultado = 0;
    pArchivo = fopen(path, "w");

    if(pArrayListEmployee != NULL && pArchivo != NULL)
    {
        tam = ll_len(pArrayListEmployee);
        fprintf(pArchivo, "id,nombre,HorasTrabajadas,sueldo\n");

        for(i = 0; i < tam; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fprintf(pArchivo,"%d,%s,%d,%f\n",empleado->id,
                    empleado->nombre,
                    empleado->horasTrabajadas,
                    empleado->sueldo);
        }

        resultado = 1;
    }

    fclose(pArchivo);

    return resultado;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int resultado;
    int tam;
    int i;
    FILE* pArchivo;
    Employee* empleado;

    resultado = 0;
    pArchivo = fopen(path, "wb");

    if(pArrayListEmployee != NULL && pArchivo!=NULL)
    {
        tam = ll_len(pArrayListEmployee);

        for(i = 0; i < tam; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fwrite(empleado, sizeof(Employee), 1, pArchivo);
        }

        resultado = 1;
    }

    fclose(pArchivo);

    return resultado;
}

