class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int child = 0;
        int cookies = 0;
        if(s.size()==0)
            return cnt;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(child<=g.size()-1 && cookies<=s.size()-1){
            if(g[child]<=s[cookies]){
                cnt++;
                child++;
                cookies++;
            }

            else if(g[child]>s[cookies])
                cookies++;
        }

        return cnt;
    }
};