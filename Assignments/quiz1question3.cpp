//Question Three (3) - Contains Duplicate



//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> uniqueSet;

    for (int num : nums) {
        if (uniqueSet.find(num) != uniqueSet.end()) {
            return true; // Found a duplicate
        } else {
            uniqueSet.insert(num);
        }
    }

    return false; // No duplicates found
}

int main() {
    // Example usage
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 3, 4, 1};

    std::cout << "Array 1 has duplicates: " << std::boolalpha << containsDuplicate(nums1) << std::endl;
    std::cout << "Array 2 has duplicates: " << std::boolalpha << containsDuplicate(nums2) << std::endl;

    return 0;
}