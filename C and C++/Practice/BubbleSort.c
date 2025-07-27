#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    int arr[100];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    BubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
