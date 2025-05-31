class Solution {
private:
    void BFS(vector<vector<int>>& v, int start, vector<int>& dis) {
        dis[start] = 0;
        vector<int> vis(dis.size(), 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto it : v[cur]) {
                if (!vis[it]) {
                    dis[it] = dis[cur] + 1;
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis_1(n, INT_MAX);
        vector<int> dis_2(n, INT_MAX);
        vector<vector<int>> v(n);
        
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                v[i].push_back(edges[i]);
        }

        BFS(v, node1, dis_1);
        BFS(v, node2, dis_2);

        int ans = -1;
        int min_dis = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dis_1[i] != INT_MAX && dis_2[i] != INT_MAX) {
                int max_dis = max(dis_1[i], dis_2[i]);
                if (max_dis < min_dis) {
                    min_dis = max_dis;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
