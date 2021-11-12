#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "miBiblioteca.h"

int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int compare;

    compare = 0;

    if(e1->id > e2->id)
    {
        compare = 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            compare = -1;
        }
    }

    return compare;
}

Employee* employee_new()
{
    Employee* nuevoEmpleado;
    Employee* empleadoAuxiliar;

    nuevoEmpleado = NULL;
    empleadoAuxiliar = (Employee*) malloc(sizeof(Employee));

    if(empleadoAuxiliar != NULL)
    {
        nuevoEmpleado = empleadoAuxiliar;

        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    float sueldo;

    Employee* empleado;
    Employee* empleadoAuxiliar;

    id = atoi(idStr);
    strcpy(nombre, nombreStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atof(sueldoStr);

    empleado = NULL;
    empleadoAuxiliar = employee_new();

    if(empleadoAuxiliar != NULL)
    {
        empleado = empleadoAuxiliar;

        employee_setId(empleado, id);
        employee_setNombre(empleado, nombre);
        employee_setHorasTrabajadas(empleado, horasTrabajadas);
        employee_setSueldo(empleado, sueldo);
    }

    return empleado;
}

int employee_setId(Employee* lista,int id)
{
    int resultado;

    resultado = 1;

    if(lista != NULL && id > 0)
    {
        lista->id = id;
        resultado = 0;
    }

    return resultado;
}

int employee_getId(Employee* lista,int* id)
{
    int resultado;

    resultado = 0;

    if(lista != NULL  && id != NULL)//Falta desarrollar...
    {
        *id = lista->id;
        resultado = 1;
    }

    return resultado;
}

int employee_setNombre(Employee* lista,char* nombre)
{
    int resultado;

    resultado = 1;

    if(lista != NULL && nombre != NULL)
    {
        strcpy(lista->nombre, nombre);
        resultado = 0;
    }

    return resultado;
}


int employee_getNombre(Employee* lista,char* nombre)
{
    int resultado;

    resultado = 1;

    if(lista != NULL && nombre != NULL)
    {
        strcpy(nombre, lista->nombre);
        resultado = 0;
    }

    return resultado;
}

int employee_setHorasTrabajadas(Employee* lista,int horasTrabajadas)
{
    int resultado;

    resultado = 1;

    if(lista != NULL && horasTrabajadas > 0)
    {
        lista->horasTrabajadas = horasTrabajadas;
        resultado = 0;
    }

    return resultado;
}

int employee_getHorasTrabajadas(Employee* lista,int* horasTrabajadas)
{
    int resultado;

    resultado = 1;

    if(lista != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = lista->horasTrabajadas;
        resultado = 0;
    }

    return resultado;
}

int employee_setSueldo(Employee* lista,float sueldo)
{
    int resultado;

    resultado = 1;

    if(lista != NULL && sueldo > 0)
    {
        lista->sueldo = sueldo;
        resultado = 0;
    }

    return resultado;
}

int employee_getSueldo(Employee* lista,float* sueldo)
{
    int resultado;

    resultado = 0;

    if(lista != NULL && sueldo != NULL)
    {
        *sueldo = lista->sueldo;
        resultado = 1;
    }

    return resultado;
}

int OrdenarEmpleados(LinkedList* pArrayListEmployee)
{
    int resultado;
    int opcion;
    int opcionCase;

    resultado = 1;

    do
    {
        opcion = MostrarMenuDeOrdenamiento(1, 5);

        switch(opcion)
        {
        case 1:
            opcionCase = MostrarMenuDeOrdenamientoId(0, 1);
            printf("\nOrdenando los ID de los empleados...");
            ll_sort(pArrayListEmployee,CompararIdEmpleados,opcionCase);
            //MostrarListadoEmpleados(pArrayListEmployee);
            break;
        case 2:
            opcionCase = MostrarMenuDeOrdenamientoNombre(0, 1);
            printf("\nOrdenando los nombres de los empleados...");
            ll_sort(pArrayListEmployee,CompararNombreEmpleados,opcionCase);
            //MostrarListadoEmpleados(pArrayListEmployee);
            break;

        case 3:
            opcionCase = MostrarMenuDeOrdenamientoHorasTrabajadas(0, 1);
            printf("\nOrdenando las horas trabajadas de los empleados...");
            ll_sort(pArrayListEmployee,CompararHorasTrabajadasEmpleados,opcionCase);
            //MostrarListadoEmpleados(pArrayListEmployee);
            break;

        case 4:
            opcionCase = MostrarMenuDeOrdenamientoSueldo(0, 1);
            printf("\nOrdenando los sueldos de los empleados...");
            ll_sort(pArrayListEmployee,CompararSueldoEmpleados,opcionCase);
            MostrarListadoEmpleados(pArrayListEmployee);
            break;

        default:
            break;
        }

    }
    while(opcion != 5);

    return resultado;
}

int CompararIdEmpleados(void* primerEmpleado, void* segundoEmpleado)
{
    int resultado;
    int primerId;
    int segundoId;
    Employee* empleadoUno;
    Employee* empleadoDos;

    resultado = -1;

    empleadoUno = (Employee*) primerEmpleado;
    empleadoDos = (Employee*) segundoEmpleado;

    employee_getId(empleadoUno, &primerId);
    employee_getId(empleadoDos, &segundoId);

    if(primerId > segundoId)
    {
        resultado = 1;
    }
    else
    {
        if(primerId == segundoId)
        {
            resultado = 0;
        }
    }

    return resultado;
}

int CompararNombreEmpleados(void* primerEmpleado, void* segundoEmpleado)
{
    int resultado;
    char nombreUno[50];
    char nombreDos[50];
    Employee* empleadoUno;
    Employee* empleadoDos;

    resultado = -1;

    empleadoUno = (Employee*) primerEmpleado;
    empleadoDos = (Employee*) segundoEmpleado;

    employee_getNombre(empleadoUno, nombreUno);
    employee_getNombre(empleadoDos, nombreDos);

    resultado = stricmp(nombreUno, nombreDos);

    return resultado;
}

int CompararHorasTrabajadasEmpleados(void* primerEmpleado, void* segundoEmpleado)
{
    int resultado;
    int horasUno;
    int horasDos;
    Employee* empleadoUno;
    Employee* empleadoDos;

    resultado = -1;

    empleadoUno = (Employee*) primerEmpleado;
    empleadoDos = (Employee*) segundoEmpleado;

    employee_getHorasTrabajadas(empleadoUno, &horasUno);
    employee_getHorasTrabajadas(empleadoDos, &horasDos);

    if(horasUno > horasDos)
    {
        resultado = 1;
    }
    else
    {
        if(horasUno == horasDos)
        {
            resultado = 0;
        }
    }

    return resultado;
}

int CompararSueldoEmpleados(void* primerEmpleado, void* segundoEmpleado)
{
    int resultado;
    float sueldoUno;
    float sueldoDos;
    Employee* empleadoUno;
    Employee* empleadoDos;

    resultado = -1;

    empleadoUno = (Employee*) primerEmpleado;
    empleadoDos = (Employee*) segundoEmpleado;

    employee_getSueldo(empleadoUno, &sueldoUno);
    employee_getSueldo(empleadoDos, &sueldoDos);

    if(sueldoUno > sueldoDos)
    {
        resultado = 1;
    }
    else
    {
        if(sueldoUno == sueldoDos)
        {
            resultado = 0;
        }
    }

    return resultado;
}
