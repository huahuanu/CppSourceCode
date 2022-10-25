#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int dir[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size(), m = grid[0].size();
        deque<int> st, st2;
        // 先随便找一个岛
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    st.push_back(i * 1000 + j);
                    grid[i][j] = -1;
                    break;
                }
            }
            if (!st.empty()) break;
        }
        // 扩展全岛入队
        while (!st.empty()) {
            int cur = st.front(); st.pop_front(); st2.push_back(cur);
            int x = cur / 1000, y = cur % 1000;
            for (int p = 0; p < 4; ++p) {
                int i = x + dir[p][0], j = y + dir[p][1];
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (grid[i][j] == 0 || grid[i][j] == -1) continue;
                st.push_back(i * 1000 + j);
                grid[i][j] = -1;  // 原地标记一下已访问位置
            }
        }
        // 分步 BFS 找最短路
        for (int step = 0; !st2.empty(); ++step) {
            // one step
            for (int k = 0, s = st2.size(); k < s; ++k) {
                int cur = st2.front(); st2.pop_front();
                int x = cur / 1000, y = cur % 1000;
                for (int p = 0; p < 4; ++p) {
                    int i = x + dir[p][0], j = y + dir[p][1];
                    if (i < 0 || i >= n || j < 0 || j >= m) continue;
                    if (grid[i][j] == -1) continue;
                    if (grid[i][j] == 1) return step;
                    st2.push_back(i * 1000 + j);
                    grid[i][j] = -1;
                }
            }
        }
        return -1;
    }
};
