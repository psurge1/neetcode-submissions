class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        A tree must be a connected graph with no cycles
        This is only possible if the number of edges is 1 less than the number of nodes
        We can just check the count of the number of edges, and then make sure all nodes are visited
        */

        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> nodes;
        vector<bool> visited(n, false);
        visited[0] = true;
        nodes.push(0);

        int visitCount = 0;

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            ++visitCount;

            for (int edge : graph[node]) {
                if (!visited[edge]) {
                    visited[edge] = true;
                    nodes.push(edge);
                }
            }
        }
        return visitCount == n;
    }
};
