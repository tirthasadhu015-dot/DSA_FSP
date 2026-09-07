//creat a array & moving all zero elements to the end of the array in c program using only for loop.
#include <stdio.h>
int main() {
   int a[10],n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements of the array: ", n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int j =0;
    for(i=0; i<n;  i++)
    {
        if (a[i] != 0)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }}
        printf("Array after moving zero elements to the end: ");
        for(i=0; i<n; i++)
        {
            printf("%d ", a[i]);
        }
        return 0;
}