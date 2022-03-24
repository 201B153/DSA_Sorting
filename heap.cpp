// imports ...
#include <iostream>
#include "common_heap.h"
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

int Left(int num)
{
    return num * 2 + 1;
}

int Right(int num)
{
    return num * 2 + 2;
}

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void maxheapify(int *arr, int i, int length)
{
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < length && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < length && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, largest, length);
    }
}

void buildMaxHeap(int *arr, int length)
{
    int start = length / 2 - 1;
    for (int i = start; i >= 0; i--)
    {
        maxheapify(arr, i, length);
    }
}

void heapSort(int *arr, int length)
{
    buildMaxHeap(arr, length);
    for (int i = length - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxheapify(arr, 0, i);
    }
}

// use this main function when you want to take length input from user else leave as it is

// int main()
// {
//     int length;
//     cout << "Input size" << endl;
//     cin >> length;
//     int *ptr = fun(length);
//     cout << "Unsorted array :" << endl;
//     for (int i = 0; i < length; i++)
//     {
//         cout << ptr[i] << " ";
//     }
//     cout << endl;
//     auto start = high_resolution_clock::now();
//     heapSort(ptr, length);
//     auto end = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(end - start);
//     cout << "Sorted array :" << endl;
//     for (int i = 0; i < length; i++)
//     {
//         cout << ptr[i] << " ";
//     }
//     cout << endl;

//     cout << "Array of length : " << length << " took " << duration.count() << " milliseconds" << endl;
//     return 0;
// }

int main()
{
    int length[21] = {1, 3, 5, 7, 10, 50, 100, 300, 500, 700, 1000, 2000, 3000, 5000, 7000, 10000, 20000, 30000, 50000, 70000, 100000};
    for (auto i : length)
    {
        int *ptr = fun(i);
        auto start = high_resolution_clock::now();
        heapSort(ptr, i);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        cout << i << " " << duration.count() << endl;
    }

    return 0;
}
