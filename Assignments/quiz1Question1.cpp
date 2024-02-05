    //Question One (1) Remove Duplicates from Sorted Array .Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int uniqueIndex = 0;

    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] != nums[uniqueIndex])
            nums[++uniqueIndex] = nums[i];

    return uniqueIndex + 1;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 4, 5};
    
    int newLength = removeDuplicates(nums);

    std::cout << "New Length: " << newLength << std::endl;
    std::cout << "Modified Array: ";
    for (int i = 0; i < newLength; ++i)
        std::cout << nums[i] << " ";

    return 0;
}
//according to the output im getting a warning about quote -comparison of integer expressions of  differrent signedness-.im confused.confused.tconfused.the output is correct though . 