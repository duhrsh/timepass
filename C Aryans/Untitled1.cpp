#include <stdio.h>
#include <math.h>

int main() {
    int radius;

    // Ask the user for the radius of the circle
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    // Define the diameter
    int diameter = 2 * radius + 1;

    // Iterate through each point in the square grid
    for (int y = 0; y < diameter; y++) {
        for (int x = 0; x < diameter; x++) {
            // Calculate the distance from the center
            int dx = x - radius;
            int dy = y - radius;
            double distance = sqrt(dx * dx + dy * dy);

            // Print a '*' if the distance is within 0.5 of the radius, for better visual approximation of the circumference
            if (fabs(distance - radius) < 0.5) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
