#include <stdio.h>
int main() {
    int n, target, count = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Binary Search
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;

        if (arr[mid] == target) {  // Found target
            count++;  // First occurrence counted

            // Count left occurrences
            for (int i = mid - 1; i >= 0; i--) {
                if (arr[i] == target)
                    count++;
            }

            // Count right occurrences
            for (int i = mid + 1; i < n; i++) {
                if (arr[i] == target)
                    count++;
            }

            break;
        }
        else if (target > arr[mid])  // Move right
            l = mid + 1;
        else  // Move left
            r = mid - 1;
    }

    // Print result
    if (count > 0)
        printf("%d appears %d times.\n", target, count);
    else
        printf("%d not found.\n", target);

    return 0;
}
