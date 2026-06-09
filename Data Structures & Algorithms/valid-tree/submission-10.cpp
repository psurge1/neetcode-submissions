class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int node) {
        int root = node;
        while (parent[root] != root) {
            root = parent[root];
        }

        int curr = node;
        while (parent[curr] != root) {
            int temp = parent[curr];
            parent[curr] = root;
            curr = temp;
        }
        return root;
    }

    bool containsCycle(int nodeA, int nodeB) {
        return findRoot(nodeA) == findRoot(nodeB);
    }

    void markEdge(int nodeA, int nodeB) {
        parent[findRoot(nodeB)] = findRoot(nodeA);
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        DSU

        We take each edge, find the roots of both nodes in that edge
        If they already share a root, a cycle exists
        Otherwise, we join the nodes

        For checking that every node is connected, we have two options
        - check that the number of edges = n - 1 (given no cycles, this enforces connectivity)
        - track visited nodes in a vector/set and make sure all n nodes are visited
        */

        UnionFind graph(n);
        for (const vector<int>& edge : edges) {
            if (graph.containsCycle(edge[0], edge[1])) {
                return false;
            }
            graph.markEdge(edge[0], edge[1]);
        }

        return edges.size() == n - 1;
    }
};
