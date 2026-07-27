class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> store(n+1, 0);
        for(int i = 1; i <= n; i++){
            store[i] = store[i>>1] + (i & 1);
        }
        return store;
    }
};
