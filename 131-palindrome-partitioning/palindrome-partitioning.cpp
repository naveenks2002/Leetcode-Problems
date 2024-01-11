class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        part(0,s,path,res);
        return res;
    }
    void part(int ind, string s,vector<string> &path,vector<vector<string>> &res){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(ispallindrome(ind,i,s)){
                path.push_back(s.substr(ind, i - ind + 1));
                part(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool ispallindrome(int start, int end, string s){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};