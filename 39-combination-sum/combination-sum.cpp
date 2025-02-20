class Solution {
public:
    void findCombinations(int sum, int i, vector<int>& candidates, int target, 
                          vector<vector<int>>& ans, vector<int>& temp) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (i == candidates.size() || sum > target) {
            return;
        }

        temp.push_back(candidates[i]);
        findCombinations(sum + candidates[i], i, candidates, target, ans, temp);
        temp.pop_back();

        findCombinations(sum, i + 1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findCombinations(0, 0, candidates, target, ans, temp);
        return ans;
    }
};
