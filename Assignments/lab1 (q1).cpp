#include <iostream>
#include <limits>

// Function to calculate the sum of elements in an array
int summation(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum element in an array
int maximum(const int arr[], int n) {
    int maxElement = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    int n;

    // Get array length from the user
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // Declare an array of length n
    int* myArray = new int[n];

    // Input n integers from the user
    std::cout << "Enter " << n << " integers, separated by spaces:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> myArray[i];
    }

    // Output sum and maximum of the entered integers
    std::cout << "Sum of the array: " << summation(myArray, n) << std::endl;
    std::cout << "Maximum element in the array: " << maximum(myArray, n) << std::endl;

    // Free dynamically allocated memory
    delete[] myArray;

    return 0;
}
