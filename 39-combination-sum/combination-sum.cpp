class Solution {
public:

    // see submission where i used a seperate sum variable insted of doing it in target 

    void findCombinations(int i, vector<int>& candidates, int target, 
                          vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == candidates.size() || target < 0) {
            return;
        }

        temp.push_back(candidates[i]);
        findCombinations(i, candidates, target-candidates[i], ans, temp);
        temp.pop_back();

        findCombinations( i + 1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findCombinations( 0, candidates, target, ans, temp);
        return ans;
    }
};
