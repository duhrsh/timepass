#include <stdio.h>

// Define structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[3];
    int max_sal = 0;

    // Input employee details
    for (int i = 0; i < 3; i++) {
        printf("Enter ID, name, and salary of Employee %d: ", i + 1);
        scanf("%d", &emp[i].id);
        scanf("%s", emp[i].name); // Accepts single-word names
        scanf("%f", &emp[i].salary);
        
        if (emp[i].salary > emp[max_sal].salary) 
            max_sal = i;
    }

    // Display highest salary employee
    printf("\nEmployee with the highest salary:\n");
    printf("%d %s %.2f\n", emp[max_sal].id, emp[max_sal].name, emp[max_sal].salary);

    return 0;
}
