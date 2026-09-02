class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto& task : tasks){
            freq[task]++;
        }
        priority_queue<int> maxHeap;
        for(auto& p : freq){
            maxHeap.push(p.second);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
            if(!maxHeap.empty()){
                int top = maxHeap.top()-1;
                maxHeap.pop();
                if(top > 0)q.push(pair{top, time+n+1});
            }else{
                time = q.front().second-1;
            }
        }
        return time;
    }
};
