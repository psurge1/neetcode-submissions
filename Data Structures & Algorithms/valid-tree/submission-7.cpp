class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        A graph is a valid tree if it doesnt have any cycles, and all nodes are connected
        */

        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> bfsQueue;
        vector<int> parent(n, -1);

        parent[0] = 0;
        bfsQueue.push(0);

        while (!bfsQueue.empty()) {
            int node = bfsQueue.front();
            bfsQueue.pop();

            for (int edgeNode : graph[node]) {
                if (node == edgeNode) {
                    return false;
                }
                if (parent[node] != edgeNode) {
                    if (parent[edgeNode] != -1) {
                        return false;
                    }
                    parent[edgeNode] = node;
                    bfsQueue.push(edgeNode);
                }
            }
        }
        
        int unvisited = 0;
        for (auto p : parent) {
            if (p == -1) {
                ++unvisited;
            }
        }
        return unvisited == 0;
    }
};
