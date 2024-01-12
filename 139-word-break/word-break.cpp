class Solution {
public:
    bool check(string s,set<string> &st,map<string,bool> &mp){
	    int n = s.size();

	    if(n==0)
		    return true;

	    if(mp.find(s)!=mp.end())
			return mp[s];

	    for(int i=0; i<s.size(); i++){
		    string pre = s.substr(0,i+1);
		    string suff = s.substr(i+1);

		    if(st.find(pre)!=st.end() && (st.find(suff)!=st.end() || check(suff,st,mp))){
			    mp[s] = true;
			    return true;
		    }
	    }
	    mp[s] = false;
	    return false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
	    map<string, bool> mp;

	    for(int i=0; i<wordDict.size(); i++){
		    st.insert(wordDict[i]);
	    }

        return check(s,st,mp);
    }
};