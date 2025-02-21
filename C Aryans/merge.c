#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int a[n1];

    printf("Enter sorted elements: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int b[n2];

    printf("Enter sorted elements: ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;

    for (; i < n1 && j < n2; k++) {
        merged[k] = (a[i] < b[j]) ? a[i++] : b[j++];
    }

    while (i < n1) merged[k++] = a[i++];
    while (j < n2) merged[k++] = b[j++];

    printf("Merged Sorted Array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    
    return 0;
}
