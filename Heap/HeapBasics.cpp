#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // 1st we add element in array at last
    // 2nd then check with their parent
    // 3rd find parent i/2
    // 4th then swap if parent is smaller than child
    // for maxHeap

    // for left child 2*i
    // for right child 2*i+1

    void insertionInHeap(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletionInHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete";
        }

        // step 1: put last element in to root index
        arr[1] = arr[size];

        // step 2: decrease the size of array
        size = size - 1;

        // step 3: take root to the correct position
        int i = 1;
        while (i < size)
        {
            int leftChildIndex = 2 * i;
            int rightChildIndex = 2 * i + 1;

            if (leftChildIndex < size && arr[i] < arr[leftChildIndex])
            {
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            }
            else if (rightChildIndex < size && arr[i] < arr[rightChildIndex])
            {
                swap(arr[i], arr[rightChildIndex]);
                i = rightChildIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int j = 1; j <= size; j++)
        {
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
};

// for. max heap
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChildIndex = 2 * i;
    int rightChildIndex = 2 * i + 1;

    // if 1 based index we <= n
    if (leftChildIndex <= n && arr[largest] < arr[leftChildIndex])
    {

        largest = leftChildIndex;
    }
    if (rightChildIndex <= n && arr[largest] < arr[rightChildIndex])
    {

        largest = rightChildIndex;
    }

    // agar largest update hua toh woh i ko point karega iska matlb largest element heap ke root mein ho gaya
    if (largest != i)
    {
        // ye ek iteration ke liye hua hai
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
};

// for min heap
void heapifyForMinHeap(int arr[], int n, int i)
{
    int smallest = i;
    int leftChildIndex = 2 * i;
    int rightChildIndex = 2 * i + 1;

    // if 1 based index we <= n
    if (leftChildIndex <= n && arr[smallest] > arr[leftChildIndex])
    {
        smallest = leftChildIndex;
    }
    if (rightChildIndex <= n && arr[smallest] > arr[rightChildIndex])
    {
        smallest = rightChildIndex;
    }

    // agar largest update hua toh woh i ko point karega iska matlb largest element heap ke root mein ho gaya
    if (smallest != i)
    {
        // ye ek iteration ke liye hua hai
        swap(arr[smallest], arr[i]);
        heapifyForMinHeap(arr, n, smallest);
    }
}

// Heap Sort
void HeapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        // step 1: swap first to last
        swap(arr[size], arr[1]);
        size--;

        // step 2 : heapify the reduced heap
        heapify(arr, size, 1);
    }
}
int main()
{
    heap h;
    h.insertionInHeap(50);
    h.insertionInHeap(55);
    h.insertionInHeap(53);
    h.insertionInHeap(52);
    h.insertionInHeap(54);

    h.print();
    h.deletionInHeap();
    h.print();

    h.insertionInHeap(70);
    h.print();

    h.deletionInHeap();
    h.print();

    // insertion and deletion T.C = long(n)

    // we kown that all the leaf nodes are already in heap
    // so we only need to heapify the non-leaf nodes
    // we can do this by heapifying the nodes from bottom to top
    // non leaf node from n/2+1 to 0

    // max heapify T.C = O(n)
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i); // build heap o(n)
    }

    cout << "printing array now after max heapify" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;


    // heap sort T.C = O(nlog(n))
    HeapSort(arr, n); 
    cout << "printing array now after heap sort" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // min heapify T.C = O(n)
    int arr1[6] = {-1, 54, 53, 55, 52, 50};
    int n1 = 5;
    for (int i = n1 / 2; i > 0; i--)
    {
        heapifyForMinHeap(arr1, n1, i); // build heap o(n)
    }

    cout << "printing array now after min heapify" << endl;

    for (int i = 1; i <= n1; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;

    
    return 0;
}