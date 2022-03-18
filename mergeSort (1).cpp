#include <iostream>
#include "common.h"
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

void put(int *n1, int *n2)
{
    *n1 = *n2;
}
void merge(int *arr, int low, int mid, int high)
{
    int temp[high - low + 1], c = 0;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            put(&temp[c++], &arr[left++]);
        }
        else
        {
            put(&temp[c++], &arr[right++]);
        }
    }
    while (left <= mid)
    {
        put(&temp[c++], &arr[left++]);
    }
    while (right <= high)
    {
        put(&temp[c++], &arr[right++]);
    }
    for (int i = low, j = 0; i <= high; i++, j++)
    {
        put(&arr[i], &temp[j]);
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    mergeSort(ptr, 0, length - 1);
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
        mergeSort(ptr, 0, i - 1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << i << " " << duration.count() << endl;
    }

    return 0;
}