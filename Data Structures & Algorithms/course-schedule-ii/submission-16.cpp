class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> requiredBy(numCourses);
        for(auto& course : prerequisites){
            requiredBy[course[1]].push_back(course[0]);
            indegrees[course[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!indegrees[i]){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            res.push_back(course);
            for(int& req : requiredBy[course]){
                if((--indegrees[req]) == 0)q.push(req);
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};
