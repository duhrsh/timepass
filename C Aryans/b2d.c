#include <stdio.h>

int b2d(int binary) {
    int decimal = 0, base = 1;
    
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    
    return decimal;
}

int main() {
    int binary;
    
    printf("Enter a binary number: ");
    scanf("%d", &binary);
    
    printf("Decimal equivalent: %d\n", b2d(binary));
    
    return 0;
}
