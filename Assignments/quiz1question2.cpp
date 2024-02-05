//Rotate Array. Given an array, rotate the array to the right by k steps, where k is non-negative.

#include <iostream>
#include <vector>

void rotateArray(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    std::vector<int> rotated(n);

    for (int i = 0; i < n; ++i) {
        rotated[(i + k) % n] = nums[i];
    }

    nums = rotated;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    rotateArray(nums, k);

    std::cout << "Rotated Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }

    return 0;
}