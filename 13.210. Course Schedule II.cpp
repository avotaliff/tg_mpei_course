//https://leetcode.com/problems/course-schedule-ii/
//Представим в виде графа. Если бы у нас шло ответвление от одной вершины
//то значит существует цикл и мы не смогли бы пройти курс, иначе dfs
//для этого используется топологическая сортировка, означающая, что все ребра направлены в одну сторону.
//
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
