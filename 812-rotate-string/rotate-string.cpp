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


        // First, check if lengths are equal (if not, rotation is impossible)
        // Create a concatenated string s + s which contains all possible rotations
        // Check if goal is a substring of s + s
        // s = "abcde", goal = "cdeab"
        // s + s = "abcdeabcde"
        // "cdeab" is present in "abcdeabcde", so return True

        // if (s.length() != goal.length()) {
        //     return false;
        // }
        // return (s + s).find(goal) != string::npos;

    }
};