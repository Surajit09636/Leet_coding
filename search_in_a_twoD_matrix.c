#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = *matrixColSize;
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];  
        
        if (midValue == target) {
            return true;  
        } else if (midValue < target) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }
    
    return false; 
}
