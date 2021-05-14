
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define VACIO 1
#define OCUPADO 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;


#endif
