//
// Created by Ikroop Singh Kalsi on 10/4/2021.
//
#include <vector>
#include <utility>

using namespace std;

class Solution {
    size_t w;
    size_t h;
    vector<vector<int>> *grid;
    vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };

    bool isInsideGrid(size_t x, size_t y) const {
        return x >= 0 && x < w && y >= 0 && y < h;
    }

    int getUntouchedSides(size_t x, size_t y) {
        int untouched = 4;
        for (auto dir: directions) {
            if (isInsideGrid(x + dir.second, y + dir.first)) {
                untouched -= grid->at(y + dir.first)[x + dir.second];
            }
        }
        return untouched;
    }

public:
    int islandPerimeter(vector<vector<int>> &g) {
        h = g.size();
        w = g[0].size();
        grid = &g;

        int perimeter = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid->at(i)[j] == 1) {
                    perimeter += getUntouchedSides(j, i);
                }
            }
        }
        return perimeter;
    }
};