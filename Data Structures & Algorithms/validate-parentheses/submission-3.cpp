class Solution {
public:
    bool isValid(string s) {
        stack<int> brackets;
        for(char bracket : s){
            if (bracket == '(' || bracket == '{' || bracket == '[') {
                brackets.push(bracket);
            }
            else{
                if (brackets.empty()) {
                    return false;
                }
                char start = brackets.top();
                brackets.pop();
                if ((bracket == ')' && start != '(') ||
                (bracket == '}' && start != '{') ||
                (bracket == ']' && start != '[')) {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};
