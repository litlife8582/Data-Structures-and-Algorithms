#include <stdio.h>

void sort(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

int binarySearch(int *A, int n, int element)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (A[mid] == element)
        {
            return mid;
        }
        else if (A[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[100];
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, num);

    int ele;
    scanf("%d", &ele);

    int result = binarySearch(arr, num, ele);
    printf("%d\n", result);

    return 0;
}