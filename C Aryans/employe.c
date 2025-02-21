#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee e1, e2, e3, maxEmp;

    // Taking input
    printf("Enter ID, Name, Salary of Employee 1: ");
    scanf("%d %[^\n] %f", &e1.id, e1.name, &e1.salary);

    printf("Enter ID, Name, Salary of Employee 2: ");
    scanf("%d %[^\n] %f", &e2.id, e2.name, &e2.salary);

    printf("Enter ID, Name, Salary of Employee 3: ");
    scanf("%d %[^\n] %f", &e3.id, e3.name, &e3.salary);

    // Finding the highest salary employee
    maxEmp = (e1.salary > e2.salary) ? ((e1.salary > e3.salary) ? e1 : e3) : ((e2.salary > e3.salary) ? e2 : e3);

    // Display result
    printf("\nHighest Salary Employee:\nID: %d\nName: %s\nSalary: %.2f\n", maxEmp.id, maxEmp.name, maxEmp.salary);

    return 0;
}
