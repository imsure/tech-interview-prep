#include "common.hpp"

// BFS

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int nr = image.size();
    int nc = image[0].size();

    vector<vector<bool>> visited (nr, vector<bool>(nc, false));
    queue<pair<int, int>> cells;
    cells.push({sr, sc});
    int origColor = image[sr][sc];

    while (!cells.empty()) {
      auto rc = cells.front();
      sr = rc.first;
      sc = rc.second;
      cells.pop();
      image[sr][sc] = newColor;
      visited[sr][sc] = true;

      if (sc-1 >= 0 && image[sr][sc-1] == origColor && !visited[sr][sc-1]) cells.push({sr, sc-1}); // left
      if (sc+1 < nc && image[sr][sc+1] == origColor && !visited[sr][sc+1]) cells.push({sr, sc+1}); // right
      if (sr-1 >= 0 && image[sr-1][sc] == origColor && !visited[sr-1][sc]) cells.push({sr-1, sc}); // up
      if (sr+1 < nr && image[sr+1][sc] == origColor && !visited[sr+1][sc]) cells.push({sr+1, sc}); // down
    }

    return image;
  }
};

int main()
{
  Solution sol;
  // vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
  // sol.floodFill(image, 1, 1, 2);
  // vector<vector<int>> image = {{0,1,1}, {0,1,1}};
  // sol.floodFill(image, 1, 1, 1);
  vector<vector<int>> image = {{0,0,0}, {0,1,0}};
  sol.floodFill(image, 1, 0, 2);
  for (auto row : image) {
    for (int p : row) cout << p << ' ';
    cout << endl;
  }
}
