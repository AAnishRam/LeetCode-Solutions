class Solution {
    struct hasher
    {
        size_t operator()(const pair<int, int>& p) const
        {
            return hash<int>{}(p.first) ^ hash<int>{}(p.second);
        }
    };
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        constexpr static array<pair<int, int>, 4> directions{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
        int res = 0;
        unordered_set<pair<int, int>, hasher> s;
        for (const vector<int>& obstacle: obstacles)
            s.emplace(obstacle.front(), obstacle.back());
        pair<int, int> start{0, 0};
        pair<int, int> direct{0, 1};
        for (int command: commands)
        {
            if (command > 0)
            {
                while (-- command >= 0 && !s.count({start.first + direct.first, start.second + direct.second}))
                {
                    start = make_pair(start.first + direct.first, start.second + direct.second);
                }
                res = max(res, start.first * start.first + start.second * start.second);
            }
            else if (command == -1)
            {
                if (direct == directions[0])
                    direct = directions[3];
                else if (direct == directions[1])
                    direct = directions[0];
                else if (direct == directions[2])
                    direct = directions[1];
                else if (direct == directions[3])
                    direct = directions[2];
            }
            else if (command == -2)
            {
                if (direct == directions[0])
                    direct = directions[1];
                else if (direct == directions[1])
                    direct = directions[2];
                else if (direct == directions[2])
                    direct = directions[3];
                else if (direct == directions[3])
                    direct = directions[0];
            }
        }
        return res;
    }
};