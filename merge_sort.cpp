#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Merge function using vector iterators
void merge(std::vector<int>::iterator left, std::vector<int>::iterator mid, std::vector<int>::iterator right) {
    // Temporary vector to store merged results
    std::vector<int> temp;
    temp.reserve(std::distance(left, right));

    auto it1 = left;
    auto it2 = mid;

    // Merge elements from both halves into temp
    while (it1 != mid && it2 != right) {
        if (*it1 <= *it2) {
            temp.push_back(*it1);
            ++it1;
        } else {
            temp.push_back(*it2);
            ++it2;
        }
    }

    // Copy remaining elements from the left half, if any
    while (it1 != mid) {
        temp.push_back(*it1);
        ++it1;
    }

    // Copy remaining elements from the right half, if any
    while (it2 != right) {
        temp.push_back(*it2);
        ++it2;
    }

    // Move the sorted elements back into the original vector range
    std::move(temp.begin(), temp.end(), left);
}

// Main Merge Sort function using iterators
void mergeSort(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    auto dist = std::distance(left, right);
    if (dist <= 1) return; // Base case: 0 or 1 element is already sorted

    // Find the exact middle iterator safely
    auto mid = std::next(left, dist / 2);

    // Sort first and second halves
    mergeSort(left, mid);
    mergeSort(mid, right);

    // Merge the sorted halves
    merge(left, mid, right);
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Original vector: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    // Call mergeSort using standard begin and end iterators
    mergeSort(arr.begin(), arr.end());

    std::cout << "Sorted vector:   ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
