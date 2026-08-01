class Solution {
public:
    bool rotateString(string s, string goal) {
        // if(s.size()!=goal.size()) return false;
        // string temp=s+s;
        // return temp.find(goal)!=string::npos;




        if(s.size()!=goal.size())
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s==goal) return true;
            char start=s[0];
            s.erase(s.begin());
            s.push_back(start);
        }
        return false;
        
    }
};


// string::npos kya hai?

// Ye ek special constant hai jo batata hai:

// "String nahi mili."

// Jab find() search karta hai aur substring nahi milti, to wo string::npos return karta hai.