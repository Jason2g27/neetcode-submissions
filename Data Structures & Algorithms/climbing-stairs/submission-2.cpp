class Solution {
public:
    vector<int> cache;
    int climbStairs(int n) {
        cache.resize(n, -1);
        return climb(n, 0);
        
    }
    int climb(int n, int i){
        if(i>=n) return i == n;
        if(cache[i] != -1) return cache[i];
        return cache[i] = climb(n, i+1) + climb(n, i+2);
    }
};
