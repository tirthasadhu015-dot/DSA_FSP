//maximum consecutive ones in binary representation of a number
#include <stdio.h>

int main() {
    int n, maxConsecutive = 0, currentConsecutive = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        if (n & 1) {
            currentConsecutive++;
            if (currentConsecutive > maxConsecutive) {
                maxConsecutive = currentConsecutive;
            }
        } else {
            currentConsecutive = 0;
        }
        n >>= 1;
    }

    printf("Maximum consecutive ones in binary representation: %d\n", maxConsecutive);
    return 0;
}