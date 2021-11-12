#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char idAuxiliar[50];
    char nombreAuxiliar[50];
    char horasTrabajadasAuxiliar[50];
    char sueldoAuxiliar[50];
    int resultado;

    Employee* empleado;

    resultado = 0;

    if(pFile != NULL)
    {
        do
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAuxiliar,
                   nombreAuxiliar,
                   horasTrabajadasAuxiliar,
                   sueldoAuxiliar);

            empleado = employee_newParametros(idAuxiliar,
                                              nombreAuxiliar,
                                              horasTrabajadasAuxiliar,
                                              sueldoAuxiliar);
            ll_add(pArrayListEmployee, empleado);

            resultado = 1;
        }
        while(!feof(pFile));
    }

    return resultado;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int estado;
    int resultado;
    Employee* empleado;

    resultado = 0;
    empleado = NULL;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            empleado = employee_new();
            estado = fread(empleado, sizeof(Employee), 1, pFile);
            if(estado == 1)
            {
                ll_add(pArrayListEmployee, empleado);
            }
        }

        resultado = 1;
    }

    return resultado;
}
