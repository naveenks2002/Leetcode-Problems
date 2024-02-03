class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(nums.size()==0)
            return "";
        
        stack<char> st;

        st.push(nums[0]);

        for(int i=1; i<nums.size(); i++){
            while(k>0 && !st.empty() && st.top()>nums[i]){
                k--;
                st.pop();
            }

            st.push(nums[i]);

            if(st.size()==1 && nums[i]=='0') 
                st.pop();
        }   

        while(k && !st.empty()){
            st.pop();
            k--;
        }

        string res = "";

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());

        if(res=="")
            return "0";
            
        return res;
    }
};