// https://leetcode.com/problems/satisfiability-of-equality-equations/

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU() {
        parent.resize(26, 0);
        rank.resize(26, 0);
        for(int i = 0; i < 26; i++)
            parent[i] = i;
    }

    int find(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void Union(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a == parent_b)
            return;
        if(rank[parent_a] < rank[parent_b]) {
            parent[parent_a] = parent_b;
        }
        else if(rank[parent_a] > rank[parent_b]) {
            parent[parent_b] = parent_a;
        }
        else {
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        DSU dsu;
        for(auto &eq : equations) {
            int a = eq[0] - 'a', b = eq.back() - 'a';
            if(eq[1] == '=') {
                int a_parent = dsu.find(a);
                int b_parent = dsu.find(b);
                dsu.Union(a_parent, b_parent);
            }
            else {
                int a_parent = dsu.find(a);
                int b_parent = dsu.find(b);
                if(a_parent == b_parent) 
                    return false;
                
            }
        }
        for(auto &eq : equations) {
            int a = eq[0] - 'a', b = eq.back() - 'a';
            
            if(eq[1] != '=') {
                int a_parent = dsu.find(a);
                int b_parent = dsu.find(b);
                if(a_parent == b_parent) 
                    return false;
                
            }
        }
        return true;
    }
};