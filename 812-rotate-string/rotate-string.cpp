class Solution {
public:

    string rotate(string goal)
    {
        char temp = goal[0];

        for(int i=1;i<goal.size();i++)
        {
            goal[i-1] = goal[i];
        }

        goal[goal.size() - 1] = temp;

        return goal;
    }

    bool rotateString(string s, string goal) {
        
        if(s == goal)
            return true;

        for(int i = 0;i<s.length();i++)
        {
            goal = rotate(goal);

            if(s == goal)
                return true;
        }

        return false;

    }
};