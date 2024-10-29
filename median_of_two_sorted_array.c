#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;

    while (low <= high) {
        int partitionx = (low + high) / 2;
        int partitiony = (x + y + 1) / 2 - partitionx;

        int maxX = (partitionx == 0) ? INT_MIN : nums1[partitionx - 1];
        int minX = (partitionx == x) ? INT_MAX : nums1[partitionx];  

        int maxY = (partitiony == 0) ? INT_MIN : nums2[partitiony - 1]; 
        int minY = (partitiony == y) ? INT_MAX : nums2[partitiony];  
        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return ((double)fmax(maxX, maxY) + fmin(minX, minY)) / 2;  
            } else {
                return (double)fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionx - 1;
        } else {
            low = partitionx + 1;
        }
    }

    return 0.0;
}
