class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // this vairable is to how far till can he travel;
        int travelTo = startFuel;
        int i = 0;
        priority_queue<int> pq;
        int move = 0;

        while(travelTo < target)
        {
            while(i < stations.size() && stations[i][0] <= travelTo)
            {
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.size() == 0) return -1;

            travelTo += pq.top();
            pq.pop();
            move++;
        }

        return move;
    }
};