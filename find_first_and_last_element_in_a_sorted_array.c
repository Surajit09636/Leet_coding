/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2* sizeof(int));
    result[0] = -1;
    result[1] = -1;

    *returnSize = 2;

    int left = 0, right = numsSize - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // check if target was foun at the leftmost position

    if (left < numsSize && nums[left] == target) {
        result[0] = left;
    } else {
        return result;
    }

    right = numsSize - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    result[1] = right;

    return result;
}