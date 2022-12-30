#pragma once
#include<iostream>
#include<vector>
using std::vector;
void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (arr[j] > key && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int getNextd(int d)
{
    // Shrink d by Shrink factor
    d = (d * 10) / 13;

    if (d < 1)
        return 1;
    return d;
}
void combSort(vector<int>& arr, int n)
{
    int d = n;
    bool IsSwapped = true;
    while (d != 1 || IsSwapped == true)
    {
        d = getNextd(d);
        IsSwapped = false;
        for (int i = 0; i < n - d; i++)
        {
            if (arr[i] > arr[i + d])
            {
                std::swap(arr[i], arr[i + d]);
                IsSwapped = true;
            }
        }
    }
}

void shellSort(vector<int>& arr, int n)
{
    for (int d = n / 2; d > 0; d /= 2)
    {
        for (int i = d; i < n; i++)
        {
            int j;
            int tmp = arr[i];
            for (j = i; j >= d && arr[j - d] > tmp; j -= d)
                arr[j] = arr[j - d];
            arr[j] = tmp;
        }
    }
}
void oddEvenSort(vector<int>& arr, int n)
{
    bool f = false;
    while (!f)
    {
        f = true;
        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                f = false;
            }
        }
        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
               std::swap(arr[i], arr[i + 1]);
                f = false;
            }
        }
    }
}
void bubbleSort(vector<int>& arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sorts(){
    std::string s;
    std::cout << "Choose type of sort\n";
    std::cout << "insertion\nshell\nbubble\nodd-even\ncomb\n";
    std::cin >> s;
    int n;
    std::cout << "enter size of array\n";
    std::cin >> n;
    std::cout << "enter array\n";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    if (s == "insertion") {
        insertionSort(arr, n);
    }
    if (s == "shell") {
        shellSort(arr, n);
    }
    if (s == "bubble") {
        bubbleSort(arr, n);
    }
    if (s == "odd-even") {
        oddEvenSort(arr, n);
    }
    if (s == "comb") {
        combSort(arr, n);
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}
