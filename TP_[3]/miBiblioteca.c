#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "Employee.h"
#include "Controller.h"

int MostrarMenu(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcionIngresada);

    do
    {
        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del menu: ");
            scanf("%d", &opcionIngresada);
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

void MostrarListadoEmpleados(LinkedList* pArrayListEmployee)
{
    int tam;
    int i;

    Employee* empleado;

    tam = ll_len(pArrayListEmployee);

    printf("\n        ID          NOMBRE HS DE TRABAJO    SUELDO\n");
    for(i = 1; i < tam; i++)
    {
        empleado = (Employee*) ll_get(pArrayListEmployee, i);
        if(empleado->id > 0)
        {
            printf("%4d) %04d %15s         %3dhs $%5.2f\n",i,
                   empleado->id,
                   empleado->nombre,
                   empleado->horasTrabajadas,
                   empleado->sueldo);
        }
    }
}

void HacerLaLogicaCase1(int* banderaTexto, int* banderaBinario, char* path, LinkedList* listaEmpleados)
{
    if(*banderaTexto == 0 && *banderaBinario == 0)
    {
        *banderaTexto = controller_loadFromText(path, listaEmpleados);
        if(*banderaTexto == 1)
        {
            printf("\nSe cargaron los datos de los empleados desde el archivo 'data.csv' en modo texto...\n");
        }
        else
        {
            printf("\nError! No se pudieron cargar los datos...\n");
        }
    }
    else
    {
        if(*banderaTexto == 1 && *banderaBinario == 0)
        {
            printf("\nLos datos de los empleados ya se habian cargado en modo texto!\n");
        }
        else
        {
            if(*banderaTexto == 0 && *banderaBinario == 1)
            {
                printf("\nLos datos de los empleados ya se habian cargado en modo binario!\n");
            }
        }
    }
}

void HacerLaLogicaCase2(int* banderaTexto, int* banderaBinario, char* path, LinkedList* listaEmpleados)
{
    if(*banderaTexto == 0 && *banderaBinario == 0)
    {
        *banderaBinario = controller_loadFromBinary(path, listaEmpleados);
        if(*banderaBinario == 1)
        {
            printf("\nSe cargaron los datos de los empleados desde el archivo 'databin' en modo binario...\n");
        }
        else
        {
            printf("\nError! No se pudieron cargar los datos...\n");
        }
    }
    else
    {
        if(*banderaTexto == 0 && *banderaBinario == 1)
        {
            printf("\nLos datos de los empleados ya se habian cargado en modo binario!\n");
        }
        else
        {
            if(*banderaTexto == 1 && *banderaBinario == 0)
            {
                printf("\nLos datos de los empleados ya se habian cargado en modo texto!\n");
            }
        }
    }
}

int CalcularIdEmpleado(LinkedList* pArrayListEmployee, int minimo)
{
    int indiceAnterior;
    int idCalculado;

    indiceAnterior = CalcularIdMaximo(pArrayListEmployee, minimo);

    idCalculado = indiceAnterior + 1;

    return idCalculado;
}

int CalcularIdMaximo(LinkedList* pArrayListEmployee, int minimo)
{
    int maximo;
    int i;
    int tam;
    Employee* empleadoAuxiliar;

    maximo = minimo - 1;
    tam = ll_len(pArrayListEmployee);

    for(i = 0; i < tam; i++)
    {
        empleadoAuxiliar = (Employee*) ll_get(pArrayListEmployee, i);
        if(maximo < empleadoAuxiliar->id)
        {
            maximo = empleadoAuxiliar->id;
        }
    }

    return maximo;
}

int PedirDatosDeUnEmpleado(LinkedList* pArrayListEmployee, void* pElement)
{
    int idAuxiliar;
    char nombreAuxiliar[50];
    int horasDeTrabajoAuxiliar;
    float sueldoAuxiliar;
    int resultado;

    idAuxiliar = CalcularIdEmpleado(pArrayListEmployee, 1);
    PedirUnaCadena(nombreAuxiliar, 50, "Ingrese el nombre del empleado: ");
    horasDeTrabajoAuxiliar = PedirUnNumeroEntero("Ingrese las horas de trabajo del empleado: ");
    sueldoAuxiliar = PedirUnNumeroFlotante("Ingrese el sueldo del empleado: ");
    resultado = 1;

    if(pArrayListEmployee != NULL && pElement != NULL)
    {
        employee_setId(pElement, idAuxiliar);
        employee_setNombre(pElement, nombreAuxiliar);
        employee_setHorasTrabajadas(pElement, horasDeTrabajoAuxiliar);
        employee_setSueldo(pElement, sueldoAuxiliar);
        resultado = 0;
    }

    return resultado;
}

void PedirUnaCadena(char cadena[], int buffer, char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);

    while(strlen(cadena) > buffer)
    {
        printf("\nError! No ingrese mas de %d caracteres!\n", buffer);
        printf(mensaje);
        fflush(stdin);
        gets(cadena);
    }

    FormalizarUnNombre(cadena, buffer);
}

void FormalizarUnNombre(char nombre[], int buffer)
{
    int i;

    for(i = 0; i < buffer; i++)
    {
        if(i == 0)
        {
            nombre[i] = toupper(nombre[i]);
        }
        else
        {
            if(nombre[i] == ' ')
            {
                nombre[i + 1] = toupper(nombre[i + 1]);
            }
            else
            {
                nombre[i] = tolower(nombre[i]);
            }
        }
    }
}

int PedirUnNumeroEnteroMayorACero(char mensaje[])
{
    int numeroIngresado;

    do
    {
        printf(mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        if(numeroIngresado <= 0)
        {
            printf("Error! El valor ingresado debe ser mayor a cero!\n");
        }
    }
    while(numeroIngresado <= 0);

    return numeroIngresado;
}

int PedirUnNumeroEntero(char mensaje[])
{
    int numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

float PedirUnNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    do
    {
        printf(mensaje);
        fflush(stdin);
        scanf("%f", &numeroIngresado);
        if(numeroIngresado <= 0)
        {
            printf("Error! El valor ingresado debe ser mayor a cero!\n");
        }
    }
    while(numeroIngresado <= 0);

    return numeroIngresado;
}

int PedirIdEmpleado(LinkedList* pArrayListEmployee, char* mensaje)
{
    int idIngresado;
    int idMaximo;
    int indice;
    int i;
    int tam;
    Employee* empleadoAuxiliar;

    idMaximo = ll_len(pArrayListEmployee);
    indice = -1;
    tam = ll_len(pArrayListEmployee);

    MostrarListadoEmpleados(pArrayListEmployee);
    do
    {
        printf(mensaje);
        scanf("%d", &idIngresado);
        if(idIngresado < 0 || idIngresado > idMaximo)
        {
            printf("Error! El ID ingresado es invalido!\n");
        }
    }
    while(idIngresado < 0 || idIngresado > idMaximo);

    for(i = 0; i < tam; i++)
    {
        empleadoAuxiliar = (Employee*) ll_get(pArrayListEmployee, i);
        if(idIngresado == empleadoAuxiliar->id)
        {
            indice = ll_indexOf(pArrayListEmployee, empleadoAuxiliar);
            break;
        }
    }

    return indice;
}

void ModificarEmpleado(LinkedList* pArrayListEmployee, void* pElement)
{
    char nombreAuxiliar[50];
    int horasTrabajadasAuxiliar;
    float sueldoAuxiliar;
    int opcionIngresada;
    int bandera;

    bandera = 0;

    do
    {
        opcionIngresada = MenuDeModificaciones(1, 4, bandera);
        switch(opcionIngresada)
        {
        case 1:
            PedirUnaCadena(nombreAuxiliar, 50, "\nIngrese el nombre del empleado: ");
            employee_setNombre(pElement, nombreAuxiliar);
            break;
        case 2:
            horasTrabajadasAuxiliar = PedirUnNumeroEnteroMayorACero("\nIngrese las horas trabajadas del empleado: ");
            employee_setHorasTrabajadas(pElement, horasTrabajadasAuxiliar);
            break;
        case 3:
            sueldoAuxiliar = PedirUnNumeroFlotante("\nIngrese el sueldo del empleado: ");
            employee_setSueldo(pElement, sueldoAuxiliar);
            break;
        default:
            break;
        }

        bandera = 1;

    }
    while(opcionIngresada != 4);
}

int MenuDeModificaciones(int opcionMinima, int opcionMaxima, int bandera)
{
    int opcionIngresada;
    if(bandera == 1)
    {
        printf("\nNecesita modificar algo mas?");
    }
    printf("\n1. Modificar el nombre del empleado");
    printf("\n2. Modificar las horas trabajadas del empleado");
    printf("\n3. Modificar el sueldo del empleado");
    printf("\n4. Continuar\n");
    opcionIngresada = PedirUnNumeroEntero("Elija una opcion: ");

    do
    {
        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del menu: ");
            scanf("%d", &opcionIngresada);
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int MostrarMenuDeOrdenamiento(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("\n1. Ordenar por ID de empleado\n");
    printf("2. Ordenar por nombre de empleado\n");
    printf("3. Ordenar por horas de trabajadas de empleado\n");
    printf("4. Ordenar por sueldo de empleado\n");
    printf("5. Continuar\n");

    do
    {
        opcionIngresada = PedirUnNumeroEntero("Elija una opcion: ");

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! La opcion ingresada es invalida!\n");
            printf("Ingrese una opcion del menu\n");
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int MostrarMenuDeOrdenamientoId(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("\nIngrese (0) para ordenar de mayor a menor\n");
    printf("Ingrese (1) para ordenar de menor a mayor\n");

    do
    {
        opcionIngresada = PedirUnNumeroEntero("Elija una opcion: ");

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! La opcion ingresada es invalida!\n");
            printf("Ingrese una opcion del menu\n");
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int MostrarMenuDeOrdenamientoNombre(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("\nIngrese (0) para ordenar de Z a A\n");
    printf("Ingrese (1) para ordenar de A a Z\n");

    do
    {
        opcionIngresada = PedirUnNumeroEntero("Elija una opcion: ");

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! La opcion ingresada es invalida!\n");
            printf("Ingrese una opcion del menu\n");
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int MostrarMenuDeOrdenamientoHorasTrabajadas(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("\nIngrese (0) para ordenar de mayor a menor\n");
    printf("Ingrese (1) para ordenar de menor a mayor\n");

    do
    {
        opcionIngresada = PedirUnNumeroEntero("Elija una opcion: ");

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! La opcion ingresada es invalida!\n");
            printf("Ingrese una opcion del menu\n");
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int MostrarMenuDeOrdenamientoSueldo(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("\nIngrese (0) para ordenar de mayor a menor\n");
    printf("Ingrese (1) para ordenar de menor a mayor\n");

    do
    {
        opcionIngresada = PedirUnNumeroEntero("Elija una opcion: ");

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! La opcion ingresada es invalida!\n");
            printf("Ingrese una opcion del menu\n");
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}
