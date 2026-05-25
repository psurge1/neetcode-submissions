class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(size_t n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int node) {
        int root = parent[node];
        while (parent[root] != root) {
            root = parent[root];
        }
        return root;
    }

    bool joinedNodes(int nodeOne, int nodeTwo) {
        int rootOne = findRoot(nodeOne);
        int rootTwo = findRoot(nodeTwo);
        if (rootOne == rootTwo) {
            return true;
        }
        parent[rootOne] = rootTwo;
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind dset(edges.size());
        for (const vector<int>& edge : edges) {
            bool alreadyConnected = dset.joinedNodes(edge[0] - 1, edge[1] - 1);
            if (alreadyConnected) {
                // last edge of cycle found
                return edge;
            }
        }
        return {};
    }
};
