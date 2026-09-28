class Solution {
public:
    void BFS(vector<vector<int>>& isConnected, int src, vector<bool>& visited) {
        queue<int> que;
        int n = isConnected.size();
        que.push(src);
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            for (int i = 0; i < n; i++) {
                if (isConnected[front][i] == 1 and visited[i] == false) {
                    que.push(i);
                    visited[i] = true;
                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0 ; i<n; i++)
        {
            if (visited[i]==false)
            {
                BFS(isConnected, i, visited);
                count++;
            }

        }
        return count;
    }
    
};