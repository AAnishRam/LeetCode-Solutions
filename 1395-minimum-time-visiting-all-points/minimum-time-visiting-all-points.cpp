class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int count = 0;
        for(int i=1; i<points.size(); i++) {
            int x1 = points[i - 1][0], y1 = points[i - 1][1];
            int x2 = points[i][0], y2 = points[i][1];

            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);

            count += min(dx, dy);        // diagonals
            count += abs(dx - dy);       // straight
        }
        return count;
    }
};