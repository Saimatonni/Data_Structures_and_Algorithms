#include <iostream>
using namespace std;

#define MAX 1000 // Max size of Heap

void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {

        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);

            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}

// Function to insert a new node to the Heap
int deleteElement(int heap[], int &n)

{

    int temp;

    temp = heap[1];

    heap[1] = heap[n];

    --n;

    heapify(heap, 1, n);

    return temp;
}
// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}

// Driver Code
int main()
{

    int arr[MAX] = {10, 5, 3, 2, 4};

    int n = 5;

    int key = 3;
    printArray(arr, n);
    deleteElement(arr, n);

    printArray(arr, n);

    return 0;
}