class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (const vector<int>& edge: edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        queue<int> nodesToVisit;
        vector<bool> visited(n, false);
        int numComponents = 0;
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                ++numComponents;
                visited[node] = true;
                nodesToVisit.push(node);
                while (!nodesToVisit.empty()) {
                    int visitingNode = nodesToVisit.front();
                    nodesToVisit.pop();
                    for (int neighbor : neighbors[visitingNode]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            nodesToVisit.push(neighbor);
                        }
                    }
                }
            }
        }

        return numComponents;
    }
};
