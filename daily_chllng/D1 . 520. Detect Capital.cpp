class Solution {
public:
    bool detectCapitalUse(string word) {

        int x = int(word[0]);
        int z = int(word[1]);

        if((65<=x && x<=90)&&(65<=z&&z<=90) ){
        for(int i=2; i<word.size(); i++){
            int y = int(word[i]);
            if(65<=y && y<=90)
                continue;
            else
                return false;
        } }
        else{
        for(int i=1; i<word.size(); i++){
            int y = int(word[i]);
            if(97<=y && y<=122)
                continue;
            else
                return false;
            }
        }
      return true;
    }
};
