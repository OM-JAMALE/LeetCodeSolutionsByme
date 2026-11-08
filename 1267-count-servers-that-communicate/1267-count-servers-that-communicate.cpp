class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int total = 0;
        // All test cases passed on first try without any errors Yoooo !
        vector<int> colum(grid[0].size(), 0);
        vector<int> row(grid.size(), 0);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                } else {
                    row[i]++;
                    colum[j]++;
                }
            }
        }
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 0) {
                continue;
            } else {
                if ((row[i] - 1 > 0) || (colum[j] - 1 > 0)) {
                    total++;
                }
            }
        }
    }
    return total;
    }
}

;