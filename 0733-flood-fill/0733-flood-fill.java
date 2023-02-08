class Solution {
    private boolean isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    private void dfs(int[][] image, int x, int y, int n, int m, int currColor, int newColor) {
        int[][] directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < directions.length; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (isValid(newX, newY, n, m) && (image[newX][newY] == currColor)) {
                image[newX][newY] = newColor;
                dfs(image, newX, newY, n, m, currColor, newColor);
            }
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int n = image.length;
        int m = image[0].length;
        int currColor = image[sr][sc];
        if (currColor != newColor) {
            image[sr][sc] = newColor;
            dfs(image, sr, sc, n, m, currColor, newColor);
        }
        return image;
    }
}