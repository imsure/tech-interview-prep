#include "../common.hpp"

class Solution {
private:
  void floodHori(vector<vector<int>>& image, int sr, int sc, int newColor, int origColor) {
    int h = image.size();
    int w = image[0].size();

    // go left
    int lc = sc - 1;
    while (lc >= 0 && image[sr][lc] == origColor) {
      image[sr][lc] = newColor;
      floodVerti2(image, sr, lc, newColor, origColor);
      --lc;
    }

    // go right
    int rc = sc + 1;
    while (rc < w && image[sr][rc] == origColor) {
      image[sr][rc] = newColor;
      floodVerti2(image, sr, rc, newColor, origColor);
      ++rc;
    }
  }

  void floodVerti(vector<vector<int>>& image, int sr, int sc, int newColor, int origColor) {
    int h = image.size();
    int w = image[0].size();

    // go up
    int ur = sr - 1;
    while (ur >= 0 && image[ur][sc] == origColor) {
      image[ur][sc] = newColor;
      floodHori(image, ur, sc, newColor, origColor);
      --ur;
    }

    // floodHori(image, sr, sc, newColor, origColor);

    // go down
    int dr = sr + 1;
    while (dr < h && image[dr][sc] == origColor) {
      image[dr][sc] = newColor;
      floodHori(image, dr, sc, newColor, origColor);
      ++dr;
    }
  }

  void floodHori2(vector<vector<int>>& image, int sr, int sc, int newColor, int origColor) {
    int h = image.size();
    int w = image[0].size();

    // go left
    int lc = sc - 1;
    while (lc >= 0 && image[sr][lc] == origColor) {
      image[sr][lc] = newColor;
      floodVerti2(image, sr, lc, newColor, origColor);
      --lc;
    }

    // floodVerti2(image, sr, sc, newColor, origColor);

    // go right
    int rc = sc + 1;
    while (rc < w && image[sr][rc] == origColor) {
      image[sr][rc] = newColor;
      floodVerti2(image, sr, rc, newColor, origColor);
      ++rc;
    }
  }

  void floodVerti2(vector<vector<int>>& image, int sr, int sc, int newColor, int origColor) {
    int h = image.size();
    int w = image[0].size();

    // go up
    int ur = sr - 1;
    while (ur >= 0 && image[ur][sc] == origColor) {
      image[ur][sc] = newColor;
      --ur;
    }

    // go down
    int dr = sr + 1;
    while (dr < h && image[dr][sc] == origColor) {
      image[dr][sc] = newColor;
      ++dr;
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int ori_color = image[sr][sc];
    image[sr][sc] = newColor;
    floodVerti(image, sr, sc, newColor, ori_color);
    floodHori2(image, sr, sc, newColor, ori_color);

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
