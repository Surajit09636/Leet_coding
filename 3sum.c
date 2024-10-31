int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);  // Sort the array
    *returnSize = 0;
    int capacity = 1000;  // Initial capacity for the result array
    int **result = (int **)malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])  // Skip duplicates for the first number
            continue;
        
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                
                // Resize result array if capacity is reached
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int **)realloc(result, capacity * sizeof(int *));
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Move left and right pointers to the next unique elements
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}
