int main()
{
    int length;
    cout << "Input size" << endl;
    cin >> length;
    int *ptr = fun(length);
    cout << "Unsorted array :" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
    auto start = high_resolution_clock::now();
    heapSort(ptr, length);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Sorted array :" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;

    cout << "Array of length : " << length << " took " << duration.count() << " milliseconds" << endl;
    return 0;
}