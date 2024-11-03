int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        // Keep swapping until the current number is in its correct position
        // or if it is out of range [1, numsSize]
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            // Swap nums[i] with nums[nums[i] - 1]
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    // Find the first missing positive
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all positions are filled correctly, the missing number is numsSize + 1
    return numsSize + 1;
}
