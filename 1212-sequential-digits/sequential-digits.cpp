class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for(int i=1; i<=9; i++){
            int num = i;
            int nextdig = num + 1;

            while(num<=high && nextdig<=9){
                num = num * 10 + nextdig;

                if(num>=low && num<=high)
                    res.push_back(num);

                nextdig++;
            }   
        }

        sort(res.begin(),res.end());
        return res;
    }
};