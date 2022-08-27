
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    inline static const int MAX_ROWS = 250;
    inline static const int MAX_COLUMNS = 250;
    
public:
    int countServers(vector<vector<int>>& grid) {
        array<int, MAX_ROWS + 1 > serversInRow{};
        array<int, MAX_COLUMNS + 1 > serversInColumn{};

        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    ++serversInRow[r];
                    ++serversInColumn[c];
                }
            }
        }

        int connectedServers = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1 && (serversInRow[r] > 1 || serversInColumn[c] > 1)) {
                    ++connectedServers;
                }
            }
        }
        return connectedServers;
    }
};
