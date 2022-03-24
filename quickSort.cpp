#include <iostream>
#include "common.h"
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int left = low + 1;
    int right = high;
    while (left <= right)
    {
        while (left <= high && arr[left] <= pivot)
        {
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[right], &arr[low]);
    return right;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        for (int i = low; i < high; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// use this main function when you want to take length input from user else leave as it is
/*
int main()
{
    int length;
    cout << "Input size" << endl;
    cin >> length;
    int *ptr = fun(length);
    auto start = high_resolution_clock::now();
    quickSort(ptr, 0, length - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << length << " " << duration.count() << endl;
    return 0;
}
*/

int main()
{
    int length[21] = {1, 3, 5, 7, 10, 50, 100, 300, 500, 700, 1000, 2000, 3000, 5000, 7000, 10000, 20000, 30000, 50000, 70000, 100000};
    for (auto i : length)
    {
        int *ptr = fun(i);
        auto start = high_resolution_clock::now();
        quickSort(ptr, 0, i - 1);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        cout << i << " " << duration.count() << endl;
    }

    return 0;
}