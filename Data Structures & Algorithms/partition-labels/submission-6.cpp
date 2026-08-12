class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> partition;
        vector<int> res;
        for(int i = 0; i < s.length(); i++){
            partition[s[i]] = i;
        }
        int j = 0;
        while(j < s.length()){
            int cur = j;
            int size = partition[s[j]];
            while(j <= size){
                size = max(size, partition[s[j]]);
                j++;
            }
            res.push_back(size-cur+1);
        }
        return res;
    }
};
