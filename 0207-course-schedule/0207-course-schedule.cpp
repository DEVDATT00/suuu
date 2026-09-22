class Solution {
    bool topo(int index , unordered_map<int,list<int>>&map , vector<int>&visited,vector<int>&path){
        visited[index] = 1;
        path[index] = 1;

        for(auto node : map[index]){
            if(!visited[node]){
                if(topo(node , map , visited, path)){
                    return true;
                }
            }
            else if(path[node])
                return true;
        }
        path[index] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>map;
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            map[v].push_back(u);
        }
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                if(topo(i,map,visited,path))
                    return false;
            }
        }
        return true;
    }
};