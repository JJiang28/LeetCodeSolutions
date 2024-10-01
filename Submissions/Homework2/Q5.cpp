class Solution {
public:
    bool isValid(string s) {
        stack<char> meow;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                meow.push(s[i]);
            } 
            else {
                if(meow.empty()){
                    return false;
                }
                char top = meow.top();
                meow.pop();
                if((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '[')) {
                    return false; 
                }
            }
        }
        return meow.empty();
    }
};
