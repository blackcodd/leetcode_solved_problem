#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // row[x] = set of y-coordinates in row x
        // col[y] = set of x-coordinates in column y
        unordered_map<int, set<int>> row, col;

        // build maps (single pass)
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row[x].insert(y);
            col[y].insert(x);
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // find position in row[x]
            auto itRow = row[x].find(y);
            // find position in col[y]
            auto itCol = col[y].find(x);

            // sanity: ensure the element exists (should, since we inserted)
            if (itRow == row[x].end() || itCol == col[y].end()) continue;

            bool hasLeft  = (itRow != row[x].begin());
            auto itRowNext = next(itRow);
            bool hasRight = (itRowNext != row[x].end());

            bool hasUp    = (itCol != col[y].begin());
            auto itColNext = next(itCol);
            bool hasDown  = (itColNext != col[y].end());

            if (hasLeft && hasRight && hasUp && hasDown) ++ans;
        }
        return ans;
    }
};
