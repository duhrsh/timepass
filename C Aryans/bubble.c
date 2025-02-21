#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[3], maxEmp;
    
    for (int i = 0; i < 3; i++) {
        printf("\nEnter ID, Name, and Salary of Employee %d: ", i + 1);
        scanf("%d", &emp[i].id);
        scanf(" %[^\n]", emp[i].name);
        scanf("%f", &emp[i].salary);
        
        if (i == 0 || emp[i].salary > maxEmp.salary) {
            maxEmp = emp[i];
        }
    }

    printf("\nHighest Salary Employee:\nID: %d\nName: %s\nSalary: %.2f\n", maxEmp.id, maxEmp.name, maxEmp.salary);
    
    return 0;
}
