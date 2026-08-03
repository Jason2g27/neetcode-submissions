class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> reqs(numCourses);
        vector<int> indegrees(numCourses, 0);
        vector<int> results;
        for(auto& prereq : prerequisites){
            reqs[prereq[1]].push_back(prereq[0]);
            indegrees[prereq[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!indegrees[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            results.push_back(course);
            for(auto& req : reqs[course]){
                indegrees[req]--;
                if(indegrees[req] == 0)q.push(req);
            }
            q.pop();
        }

        return results.size() == numCourses ? results : vector<int>{};
    }
};
