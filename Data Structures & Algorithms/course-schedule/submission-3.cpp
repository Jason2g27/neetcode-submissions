class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        vector<int> visited(numCourses, 0);
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(dfs(preMap, visited, i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& mapped, vector<int>& visited, int course){
        if(visited[course] == 1) return true;
        if (visited[course] == 2) return false;
        visited[course] = 1;
        for(int prereq : mapped[course]){
            if(dfs(mapped, visited, prereq))return true;
        }
        visited[course] = 2;
        return false;
    }
};
