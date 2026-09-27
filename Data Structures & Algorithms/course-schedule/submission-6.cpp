class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>());
        for(auto& prereq : prerequisites){
            indegrees[prereq[0]]++;
            adjList[prereq[1]].push_back(prereq[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int requirement = q.front();
            q.pop();
            count++;
            for(int course : adjList[requirement]){
                indegrees[course]--;
                if(indegrees[course] == 0){
                    q.push(course);
                }
            }
        }
        return count == numCourses;
    }
};
