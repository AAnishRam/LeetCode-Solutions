class Solution {
public:
    // bool calcArea(vector<vector<int>>& squares, double line) {
    //     double lA = 0;
    //     double uA = 0;

    //     for(auto it : squares) {
    //         double yEnd = (double)it[1] + (double)it[2];

    //         if(yEnd <= line) lA += (double)it[2] * (double)it[2];
    //         else if(it[1] > line) uA += (double)it[2] * (double)it[2];
    //         else {
    //             uA += (double)it[2] * (yEnd - line);
    //             lA += (double)it[2] * (line - it[1]);
    //         }
    //     }

    //     if(lA >= uA)
    //         return true;
    //     else
    //         return false;
    // }
    
    // double separateSquares(vector<vector<int>>& squares) {
    //     double lb = 0;
    //     double ub = 0;

    //     for(auto it : squares)
    //         ub = max(ub, (double)it[1] + it[2]);
        
    //     while (abs(ub - lb) > 1e-5) {
    //         double mid = (lb + ub) / 2;

    //         if(calcArea(squares, mid)) {
    //             ub = mid;
    //         }
    //         else{
    //             lb = mid;
    //         }
    //     }
    //     return ub;
    // }
    bool calcArea(vector<vector<int>>& squares, double line, double half) {
        double lA = 0;

        for (auto &it : squares) {
            double y = it[1];
            double s = it[2];
            double yEnd = y + s;

            if (yEnd <= line)
                lA += s * s;
            else if (y < line)
                lA += s * (line - y);
        }
        return lA >= half;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double lb = 0, ub = 0;
        double total = 0;

        for (auto &it : squares) {
            total += 1.0 * it[2] * it[2];
            ub = max(ub, (double)it[1] + it[2]);
        }

        double half = total / 2.0;

        while (ub - lb > 1e-5) {
            double mid = lb + (ub - lb) / 2;

            if (calcArea(squares, mid, half))
                ub = mid;
            else
                lb = mid;
        }
        return ub;
    }

};