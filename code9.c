// C program to find the largest odd number from a given number
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* largestoddnumber(char* num)
{
    int n = strlen(num);
    int i;
    for (i = n - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        if (digit % 2 ==1)
        {
            num[i + 1] = '\0';
            return num;
        }
    }
    return "";
}
int main()
{
    char str[25];
    printf("Enter a number: ");
    gets(str);
    char* result = largestoddnumber(str);
    if (result[0]=='\0') {
        printf("No odd number found.\n");
    } else {
        printf("Largest odd number: %s\n", result);
    }
}