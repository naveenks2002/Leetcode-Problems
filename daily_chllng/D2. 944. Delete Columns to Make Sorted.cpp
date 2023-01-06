class Solution {
public:
    int minDeletionSize(vector<string>& arr) {
        	
	int count = 0;
	
	for(int i=0; i<arr[0].length(); i++){
		for(int j=0; j<arr.size()-1; j++){
			if(int(arr[j][i])>int(arr[j+1][i])){
				count++;
				break;
			}
		}
	}
	
    return count;
	
    }
};
