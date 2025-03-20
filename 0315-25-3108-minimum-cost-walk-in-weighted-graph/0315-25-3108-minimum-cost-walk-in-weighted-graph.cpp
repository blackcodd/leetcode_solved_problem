class Solution {
public:
vector<int>p;
vector<int>dept;
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        p.resize(n,-1);
        dept.resize(n,0);
        vector<unsigned int>componentcost(n,-1);
        for(auto it:edges){
            Union(it[0],it[1]);

        }
        for(auto it:edges){
             int root=Find(it[0]);
            componentcost[root]&=it[2];
        }
        vector<int>ans;
        for(auto it:query){
            if(Find(it[0])!=Find(it[1])){
                ans.push_back(-1);
            }
            else {
                ans.push_back(componentcost[Find(it[0])]);
            }
        }
        return ans;
    }
    private:
    int Find(int u){
        if(p[u]==-1) return u;
        return Find(p[u]);
    }
    void Union(int u, int v){
        int  root1=Find(u);
        int root2=Find(v);
        if(root1==root2) return;
        if(dept[root1]<dept[root2]) swap(root1,root2);
        p[root2]=root1;
        if(dept[root1]==dept[root2]){
            dept[root1]++;
        }

    }
};