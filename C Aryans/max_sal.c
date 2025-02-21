#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[3];
    int max_sal = 0;


    for (int i = 0; i < 3; i++) {
        printf("Enter ID, name, and salary of Employee %d: ", i + 1);
        scanf("%d", &emp[i].id);
        scanf("%s", emp[i].name);
        scanf("%f", &emp[i].salary);
        
        if (emp[i].salary > emp[max_sal].salary) 
            max_sal = i;
    }
    
    printf("\nEmployee with the highest salary:\n");
    printf("%d %s %.2f\n", emp[max_sal].id, emp[max_sal].name, emp[max_sal].salary);

    return 0;
}
