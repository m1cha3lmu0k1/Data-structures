// Single Number

//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.



#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num;
    }

    return result;
}

int main() {
    // Example usage
    std::vector<int> nums = {4, 2, 3, 2, 4};

    int single = singleNumber(nums);

    std::cout << "The single number is: " << single << std::endl;

    return 0;
}