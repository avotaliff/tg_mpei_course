//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
            vector<int>indegree(numCourses);
                vector<vector<int>>graph(numCourses);
        
        for(auto p: prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        for(int i = 0; i < numCourses; i++){
            int j = 0;
                for(; j < numCourses; j++) if(indegree[j] == 0) break;
                 if(j == numCourses) return vector<int>();
                    indegree[j] = -1;
                 for(auto x: graph[j]) indegree[x]--;
            res.push_back(j);
        }
        return res;
    }
};
