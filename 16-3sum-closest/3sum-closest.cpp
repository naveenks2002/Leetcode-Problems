class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int max_sum= INT_MIN;
        int diff = 0;
        int min_diff = INT_MAX;
        for(int i=0; i<nums.size()-2; i++){
            int k = i+1;
            int j = nums.size()-1;
            while(k<j){
                int sum = nums[i] + nums[j] + nums[k];
                diff = abs(target - sum);
                if(diff<min_diff){
                    max_sum = sum;
                    min_diff = diff;
                }
                if(sum>target){
                    j--;
                }
                else
                    k++;
            }   
        }
        return max_sum;
    }
};