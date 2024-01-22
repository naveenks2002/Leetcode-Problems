class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto brack : s){
            if(brack=='(' || brack=='{' || brack=='[')
                st.push(brack);

            else if(brack==')' || brack=='}' || brack==']'){
                if(st.empty())
                    return false;
                
                char top = st.top();  
                st.pop();
                if(brack==')' && top!='(') return false;
                if(brack==']' && top!='[') return false;
                if(brack=='}' && top!='{') return false;
            }
        }
        if(st.empty())
            return true;
        
        return false;
    }

};