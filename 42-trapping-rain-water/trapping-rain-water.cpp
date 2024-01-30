class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        for(int i=1; i<n; i++){
            int max_left = height[i];
            int max_right = height[i];

            for(int j=0; j<i; j++)
                max_left = max(max_left,height[j]);

            for(int j=i+1; j<n; j++)
                max_right = max(max_right,height[j]);
            
            res  = res + (min(max_right,max_left) - height[i]);
        }
        return res;
    }
};