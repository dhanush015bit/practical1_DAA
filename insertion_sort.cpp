#include <iostream>
#include <vector>

// Function to perform Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the key into its correct position
    }
}

// Helper function to print the vector
void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    
    std::cout << "Original vector: ";
    printVector(arr);
    
    insertionSort(arr);
    
    std::cout << "Sorted vector:   ";
    printVector(arr);
    
    return 0;
}
