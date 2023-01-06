class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map <int,int> freq;
        for(auto task: tasks){
            freq[task]++;
        }
        int min_rounds=0;
        for(auto [task,count] : freq){
            if(count==1)
                return -1;
            else if(count%3==0){
                min_rounds += count/3;
            }
            else{
                min_rounds += count/3 + 1;
            }
        }   
        return min_rounds;
    }
};
