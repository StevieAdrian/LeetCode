class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        bool flag = false;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if (!par.empty() && (s[i] == ')' && par.top() == '(' || s[i] == ']' && par.top() == '[' || s[i] == '}' && par.top() == '{')) {
                    flag = true;
                    par.pop();
                } else {
                    par.push(s[i]);
                    flag = false;
                }
            } else {
                par.push(s[i]);
            }
            // debug(par.top());
        }

        // for (auto p: par);

        if (!par.empty()){
            flag = false;
        }

        return flag;
    }
};