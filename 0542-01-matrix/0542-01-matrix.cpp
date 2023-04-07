class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push(make_tuple(i, j ,0));
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int dist = get<2>(q.front());
            distance[x][y] = dist;
            q.pop();
            for (const auto &direction : directions) {
                int nx = x + direction.first;
                int ny = y + direction.second;
                if (valid(nx, ny, n, m) && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push(make_tuple(nx, ny, dist + 1));
                }
            }
        }
        return distance;
    }
};