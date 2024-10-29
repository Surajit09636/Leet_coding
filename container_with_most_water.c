int maxArea(int* height, int heightSize) {
    int max_area = 0;
    int left = 0;
    int right = heightSize - 1 ;

    while(left < right){
        int container_height = height[left] < height[right] ? height[left] : height[right];
        int container_width = right - left;
        int container_area = container_height * container_width;

        if(container_area > max_area){
            max_area = container_area;
        }

        if(height[left] < height[right]){
            left++;
        } else{
            right--;
        }
    } 
    return max_area;
}