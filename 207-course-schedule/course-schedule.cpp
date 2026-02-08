class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        // topo sort
        vector<int> v(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it: adj[i]) {
                v[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (v[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);
            for (auto it : adj[front]) {
                v[it]--;
                if (v[it] == 0)
                    q.push(it);
            }
        }
        if (topo.size() == numCourses)
            return true;
        return false;
    }
};