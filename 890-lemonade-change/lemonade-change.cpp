class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int  no_of_5 = 0;
        int  no_of_10 = 0;
        int n = bills.size();

        for(int i=0; i<n; i++){
            if(bills[i]==5)
                no_of_5++;

            else if(bills[i]==10){
                if(no_of_5==0){
                    return false;
                }
                no_of_5--;
                no_of_10++;
            }

            else {
                if(no_of_10>0 && no_of_5>0){
                    no_of_5--;
                    no_of_10--;
                }
                else if(no_of_5>=3)
                    no_of_5 -= 3;
        
                else
                    return false;
            }
        }
        return true;

    }
};