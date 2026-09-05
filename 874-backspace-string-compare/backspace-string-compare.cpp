class Solution {
public:
    string build(string k)
    {
        stack<char>st;
        for(char c:k)
        {
            if(c=='#')
            {
               if(!st.empty())
               {
                st.pop();
               }
            }
            else
            {
                st.push(c);
            }
        }
        string rev;
        while(!st.empty())
        {
            rev+=st.top();
            st.pop();
        }
        return rev;
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
        
    }
};