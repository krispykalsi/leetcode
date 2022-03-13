#include <iostream>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
    int** eggDrop;

    void initEggDrop(int k, int n) {
        eggDrop = new int*[k+1];
        for (int i = 0; i <= k; i++) {
            eggDrop[i] = new int[n+1];
            memset(eggDrop[i], 0, n+1);
        }
    }

    void disposeEggDrop(int k, int n) {
        for (int i = 0; i <= k; i++) {
            delete [] eggDrop[i];
        }
        delete [] eggDrop;
    }

public:
    int superEggDrop(int eggs, int floors) {
        initEggDrop(eggs, floors);
        if (floors > 0) {
            for (int egg = 0; egg <= eggs; egg++) {
                eggDrop[egg][1] = 1;
            }
        }
        if (eggs > 0) {
            std::iota(eggDrop[1], eggDrop[1] + floors+1, 0);
        }
        for(int egg = 2; egg <= eggs; egg++) {
            for (int floor = 2; floor <= floors; floor++) {
                int minDrops = std::max(eggDrop[egg-1][floors-1], eggDrop[egg][0]);
                for (int f = 2; f < floor; f++) {
                    auto drops = std::max(eggDrop[egg-1][floors-f], eggDrop[egg][f-1]);
                    minDrops = std::min(drops, minDrops);
                }
                eggDrop[egg][floor] = 1 + minDrops;
            }
        }
        int minDrops = eggDrop[eggs][floors];
        disposeEggDrop(eggs, floors);
        return minDrops;
    }
};