class Solution {
    bool check(vector<bool>& visited, vector<vector<int>>& graph,int source, int destination) {
        if (source == destination)
            return true;
        visited[source] = false;
        int tem;
        for(int i = 0 ; i < graph[source].size() ; i++){
            tem = graph[source][i];
            if(visited[tem]){
                if(check(visited, graph, tem, destination)){
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,int destination) {
        vector<vector<int>> graph(n);
        int u, v;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, true);
        return check(visited, graph, source, destination);
    }
};