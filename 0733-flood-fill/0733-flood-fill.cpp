class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    bool is_valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    void dfs(vector<vector<int>> &image, vector<vector<int>> &visited, int x, int y, int src_color, int color, int n, int m) {
        visited[x][y] = true;
        image[x][y] = color;
        for (auto &direction : directions) {
            int _x = x + direction.first;
            int _y = y + direction.second;
            if (is_valid(_x, _y, n, m) && !visited[_x][_y] && image[_x][_y] == src_color) {
                dfs(image, visited, _x, _y, src_color, color, n, m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int src_color = image[sr][sc];
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dfs(image, visited, sr, sc, src_color, color, n, m);
        return image;
    }
};