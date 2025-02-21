// // #include <stdio.h>

// // int main() {
// //     int arr[100], n, position;

// //     printf("Enter the size of the array: ");
// //     scanf("%d", &n);

// //     printf("Enter the elements of the array: ");
// //     for (int i = 0; i < n; i++) {
// //         scanf("%d", &arr[i]);
// //     }

// //     printf("Enter the position to delete (0 to %d): ", n - 1);
// //     scanf("%d", &position);

// //     for (int i = position; i < n - 1; i++) {
// //         arr[i] = arr[i + 1];
// //     }
// //     n--;

// //     printf("Array after deletion: ");
// //     for (int i = 0; i < n; i++) {
// //         printf("%d ", arr[i]);
// //     }

// //     return 0;
// // }

// #include <stdio.h>

// int main() {
//     int n, i, smallest;

//     // Prompt user for number of elements
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);

//     if (n <= 0) {
//         printf("Array size must be greater than zero.\n");
//         return 1; // Exit with error
//     }

//     int array[n]; // Declare the array

//     // Input elements of the array
//     printf("Enter %d elements:\n", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &array[i]);
//     }

//     // Assume the first element is the smallest
//     smallest = array[0];

//     // Find the smallest element in a single loop
//     for (i = 1; i < n; i++) 
//         if (array[i] < smallest) 
//             smallest = array[i];
        
    

//     // Display the smallest number
//     printf("The smallest number in the array is: %d\n", smallest);

//     return 0; // Exit successfully
// }

#include <stdio.h>

#define MAX_SIZE 1

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    // Ensure we do not exceed the maximum size
    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Error: Rows and columns must be less than or equal to %d.\n", MAX_SIZE);
        return 1;
    }

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Output the original matrix
    printf("Original matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Output the transposed matrix
    printf("Transposed matrix:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%d ", transposed[j][i]);
        }
        printf("\n");
    }

    return 0;
}
