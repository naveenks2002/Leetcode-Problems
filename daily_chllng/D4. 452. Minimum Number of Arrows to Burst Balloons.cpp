class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& pairs) {
    int arrow = 1;
	sort(pairs.begin(),pairs.end());
	
	int start;
	int end  = pairs[0][1];
	for(int i=1;i<pairs.size();i++){
		if(pairs[i][0]<=end){
			end = min(end,pairs[i][1]);
		}
		else{
			arrow++;
			end = pairs[i][1];
		}
	}
    return arrow;
    }
};
