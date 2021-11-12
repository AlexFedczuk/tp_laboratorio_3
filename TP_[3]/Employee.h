#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* lista,int id);
int employee_getId(Employee* lista,int* id);

int employee_setNombre(Employee* lista,char* nombre);
int employee_getNombre(Employee* lista,char* nombre);

int employee_setHorasTrabajadas(Employee* lista,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* lista,int* horasTrabajadas);

int employee_setSueldo(Employee* lista,float sueldo);
int employee_getSueldo(Employee* lista,float* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);

#endif // employee_H_INCLUDED

int OrdenarEmpleados(LinkedList* pArrayListEmployee);
int CompararIdEmpleados(void* primerEmpleado, void* segundoEmpleado);
int CompararNombreEmpleados(void* primerEmpleado, void* segundoEmpleado);
int CompararHorasTrabajadasEmpleados(void* primerEmpleado, void* segundoEmpleado);
int CompararSueldoEmpleados(void* primerEmpleado, void* segundoEmpleado);
