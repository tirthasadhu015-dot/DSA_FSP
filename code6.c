//creat a array then sort it then remove duplicate elements from the array.give me in short code in c language.
 #include <stdio.h>
int main() {
    int n, i, j, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Sort the array
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Remove duplicates
    k = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[k++] = arr[i];
        }
    }
    printf("Array after removing duplicates: ");
    for (i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}