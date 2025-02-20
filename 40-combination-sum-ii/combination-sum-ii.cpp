class Solution {
public:

    void findCombination(int i, set<vector<int>> &ans, vector<int> &temp, 
    vector<int>& candidates, int target)
    {
        if(target == 0)
        {
            ans.insert(temp);
            return;
        }

        if(i == candidates.size() || target < 0)
            return;

        temp.push_back(candidates[i]);
        findCombination(i+1, ans, temp, candidates, target - candidates[i]);
        temp.pop_back();

        //remove duplicates so that it will form distinct ans only
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;

        findCombination(i+1, ans, temp, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());

        findCombination(0, ans, temp, candidates, target);

        vector<vector<int>>fin;
        for(auto it : ans)
            fin.push_back(it);
        return fin;
    }
};