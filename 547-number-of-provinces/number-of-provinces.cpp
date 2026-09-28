class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int src, vector<bool>& visited) {
        stack<int> st;
        int n = isConnected.size();
        st.push(src);
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            for (int i = 0; i < n; i++) {
                if (isConnected[top][i] == 1 and visited[i] == false) {
                    st.push(i);
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
                dfs(isConnected, i, visited);
                count++;
            }

        }
        return count;
    }
    
};