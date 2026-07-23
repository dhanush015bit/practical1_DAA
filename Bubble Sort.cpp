#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Stop if the array is already sorted
        if (!swapped)
            break;
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    srand(time(0));

    // Generate random numbers
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    cout << "\nOriginal Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // Measure execution time
    auto start = high_resolution_clock::now();

    bubbleSort(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nSorted Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    cout << "\nExecution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}
