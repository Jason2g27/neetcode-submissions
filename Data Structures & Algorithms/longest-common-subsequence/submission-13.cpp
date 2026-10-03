class Solution {
public:
    vector<vector<int>> subseq;
    int longestCommonSubsequence(string text1, string text2) {
        subseq.assign(text1.size(), vector<int>(text2.size(), -1));
        return traverse(text1, text2,0, 0);
    }

    int traverse(string& text1, string text2, int i, int j){
        if (i == text1.size() || j == text2.size()) return 0;
        if(subseq[i][j] != -1){
            return subseq[i][j];
        }
        if(text1[i] == text2[j]){
            return subseq[i][j] = traverse(text1, text2, i+1, j+1)+1;
        }
        return subseq[i][j] = max(traverse(text1, text2, i + 1, j), traverse(text1, text2, i, j + 1));
    }
};
