class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> greatest;
        int result = 0;
        for(int stone : stones){
            greatest.push(stone);
        }
        while(greatest.size() > 1){
            int x = greatest.top();
            greatest.pop();
            int y = greatest.top();
            greatest.pop();
            if(y < x){
                greatest.push(x-y);
            }
        }
        greatest.push(0);
        return greatest.top();
    }
};
