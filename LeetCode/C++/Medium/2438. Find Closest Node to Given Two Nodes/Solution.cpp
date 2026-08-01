class Solution {
public:
    void bfs(vector<int>& edges, int curr, vector<int>& dist) {
        queue<pair<int, int>> q;
        q.push({curr, 0});

        while(!q.empty()) {
            int u = q.front().first;
            int d = q.front().second;
            q.pop();
        
            if(dist[u] > d) {
                dist[u] = d;
                int neigh = edges[u];
                if(edges[u] == -1) continue;
                q.push({neigh, d+1});
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int ans = -1;
        int d = INT_MAX;
        for(int i = 0; i < n; i++) {
            int dis = max(dist1[i], dist2[i]);
            if(dis < d) {
                d = dis;
                ans = i;
            }
        
        }
        return ans;
    }
};