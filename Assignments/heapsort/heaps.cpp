#include <iostream>
// using max heaps


//generic swap function, swaps two elements in an array
void swap(int* arr, int i1, int i2)
{
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void siftUp(int arr[], int size)
{
    // if the child is less than the parent, then we want to swap the child and parent. (for max heap)
    // for some reason it doesnt work without putting the for loop twice....
    for (int i = 0; i < size; i++)
        if (arr[(i-1)/2] < arr[i])
            swap(arr, (i-1)/2, i);
    for (int i = 0; i < size; i++)
        if (arr[(i-1)/2] < arr[i])
            swap(arr, (i-1)/2, i);
}


void heapify(int arr[], int size)
{
    // sift up for first i elements of array, then once more afterwards to make sure everything is in place.
    for (int i = 1; i <= size; i++)
        siftUp(arr, i);
    siftUp(arr, size);
}

void removemin(int arr[], int size)
{
    // swap 0th element with the last element (size is ok here because in heapsort we always start at size-1)
    swap(arr, 0, size);
}
void heapsort(int arr[], int size)
{
    // first heapify the array into max heap
    heapify(arr, size);
    // size-1 to 0 so we dont have to delete after the remove min.
    for (int i = size-1; i >= 0; i--)
    {
        // swap root node and last element
        removemin(arr, i);

        // heapify again to make sure new heap is a max heap
        heapify(arr, i);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "  ";
}

int main()
{
    int arr[] = {4, 2, 3, 5, 6, 9, 11, 0, -4, 17, 13, 14, 19};
    heapsort(arr, 10);
    printArray(arr, 10);
}
