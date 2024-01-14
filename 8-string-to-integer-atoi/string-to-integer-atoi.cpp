class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long res=0;
        while(i<s.length() && s[i]==' ')
            i++;

        if(s[i]=='-'){
            sign = -1;
            i++;
        }

        else if(s[i]=='+'){
            i++;
        }

        for(;i<s.size(); i++){
            int k = s[i] - '0';
            if(k>=0 && k<=9){
                res = res*10 + k;
                if(res>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(res>INT_MAX && sign==1)
                    return INT_MAX;
            }
            else
                return res*sign;
        }

        return res*sign;
    }

};