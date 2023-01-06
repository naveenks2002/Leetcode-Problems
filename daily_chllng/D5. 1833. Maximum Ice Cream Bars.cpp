class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());

        int count = 0;
        int cost = 0;
        for(int i=0; i<costs.size(); i++){
            if((cost + costs[i])<=coins){
                count++;
                cost += costs[i];
            }
            else
                break;
        }
        return count;
    }
};
