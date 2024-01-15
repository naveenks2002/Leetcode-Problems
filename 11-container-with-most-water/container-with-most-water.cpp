class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
       int right = height.size() - 1;
       int maxarea = 0;

       while(left<right){
           int curr_area = (right - left) * min(height[right],height[left]);
           maxarea = max(maxarea,curr_area);

           if(height[left]>=height[right])
                right--;

            else
                left++;

       }

       return maxarea;
    }

};