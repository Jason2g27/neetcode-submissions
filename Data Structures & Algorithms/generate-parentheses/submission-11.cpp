class Solution {
public:
    vector<string> results;
    vector<string> generateParenthesis(int n) {
        string cur;
        traverse(n, cur, 0, 0);
        return results;
    }

    void traverse(int n, string cur, int op, int cl) {
        if(cur.length() == 2*n){
            results.push_back(cur);
            return;
        }
        if(op < n){
            traverse(n, cur + '(', op+1, cl);
        }
        if(cl < op){
            traverse(n, cur + ')', op, cl + 1);
        }
    }
};
