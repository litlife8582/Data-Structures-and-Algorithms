#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("The elements of the array are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d\n", arr.A[i]);
    }
}

int delete(struct Array *arr, int element)
{
    int index = -1;
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == element)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("INVALID INPUT");
        return 0;
    }

    else
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->A[arr->length] = 0;
        arr->length--;
    }
}

int main()
{
    struct Array arr;
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));

    printf("Enter the length of the array: ");
    scanf("%d", &arr.length);

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    display(arr);

    int element;
    printf("Enter the element to be deleted:\n");
    scanf("%d", &element);

    delete(&arr, element);
    display(arr);

    return 0;
}