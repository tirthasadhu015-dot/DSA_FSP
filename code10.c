// C program to find the longest common prefix among an array of strings
#include <stdio.h>
#define MAX 100

int main()
{
    int n , i , j ;
    char str[MAX][MAX];
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    printf("Enter the strings:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    for(j=0;str[0][j]!='\0';j++)
    {
        for(i=1;i<n;i++)
        {
            if(str[i][j]!=str[0][j])
            {
                str[0][j]='\0';
                break;
            }
        }
    }
    if(str[0][0]=='\0')
    {
        printf("No common prefix found.\n");
    }
    else
    {
        printf("Longest common prefix: %s\n", str[0]);
    }
}

