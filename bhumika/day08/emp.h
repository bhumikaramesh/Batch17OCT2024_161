#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
int id;
char Name[20];
float salary;
}Employee;

void getdetails(Employee e1[],int n);
void displaydetails(Employee e1[],int n);


