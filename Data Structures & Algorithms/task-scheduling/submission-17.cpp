class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> available;
        int cycles = 0;
        unordered_map<char, int> freq;
        for(auto& task : tasks){
            freq[task]++;
        }
        for(auto& num : freq){
            available.push(num.second);
        }
        queue<pair<int, int>> q;
        while(!available.empty() || !q.empty()){
            cycles++;
            if(q.front().second == cycles){
                available.push(q.front().first);
                q.pop();
            }
            if(!available.empty()){
                int cur = available.top()-1;
                available.pop();
                if(cur > 0)q.push({cur, cycles + n+1});
            }else{
                cycles = q.front().second-1;
            }
        }
        return cycles;
    }
};




