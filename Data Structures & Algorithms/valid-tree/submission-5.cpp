class Solution {
private:
    bool checkForCycles(int node, int parent, vector<vector<int>>& neighbors, unordered_set<int>& visited) {
        for (int neighbor : neighbors[node]) {
            if (neighbor != parent) {
                if (visited.contains(neighbor)) {
                    return true;
                }
                visited.insert(neighbor);
                if (checkForCycles(neighbor, node, neighbors, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        Tree Definition:
        no cycles exist
        a path exists between all nodes (connected)

        Inputs;
        n -> number of nodes
        edges -> unique list of undirected edges between nodes

        Output:
        whether or not the graph is a valid tree
        */

        unordered_set<int> visited;
        vector<vector<int>> neighbors(n);
        for (const vector<int>& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        visited.insert(0);
        bool hasCycles = checkForCycles(0, -1, neighbors, visited);
        return !hasCycles && visited.size() == n;
    }
};
