//An Armstrong number is a number whose sum of the cubes of its digits equals the number itself.
#include <stdio.h>

int main() {
    int num, originalNum, remainder, result = 0;

    printf("Enter a three-digit integer: ");
    scanf("%d", &num);

    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;// Get the last digit
        // Add the cube of the digit to the result
        result += remainder * remainder * remainder;
        
         originalNum /= 10; // Removing of  the last digit from the original number
    }

    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);

    return 0;
}

