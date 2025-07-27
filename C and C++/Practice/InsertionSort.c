#include <stdio.h>

void insertionSort(int A[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int num;
    int arr[100];
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, num);

    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
