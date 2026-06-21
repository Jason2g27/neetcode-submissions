class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> cur;
        for(string token : tokens){
            if (token != "+" && token != "-" &&
                token != "*" && token != "/")
            {
                cur.push(stoi(token));
            }
            else{
                int second = cur.top();
                cur.pop();
                int first = cur.top();
                cur.pop();
                if (token == "+") {
                    cur.push(first + second);
                } else if (token == "-") {
                    cur.push(first - second);
                } else if (token == "*") {
                    cur.push(first * second);
                } else {
                    cur.push(first / second);
                }
            }
        }
        return cur.top();
    }
};
