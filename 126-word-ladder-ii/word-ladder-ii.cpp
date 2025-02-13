class Solution {
// public:

    // normal code will give rise to tle
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //     unordered_set<string> st (wordList.begin(), wordList.end());
    //     queue<vector<string>>q;
    //     q.push({beginWord});
    //     vector<string> usedOnLevel;
    //     usedOnLevel.push_back(beginWord);
    //     int level = 0;
    //     vector<vector<string>> ans;

    //     while(!q.empty())
    //     {
    //         vector<string> vec = q.front();
    //         q.pop();
    //         string word = vec.back();

    //         if(vec.size() > level)
    //         {
    //             level++;
    //             for(auto it : usedOnLevel)
    //                 st.erase(it);
    //         }

    //         if(word == endWord)
    //         {
    //             if(ans.size() == 0)
    //                 ans.push_back(vec);
    //             else if(ans.back().size() == vec.size())
    //                 ans.push_back(vec);
    //         }

    //         for(int i=0;i<word.size();i++)
    //         {
    //             char original = word[i];

    //             for(char ch = 'a' ; ch <= 'z' ; ch++)
    //             {
    //                 word[i] = ch;
    //                 if(st.count(word))
    //                 {
    //                     usedOnLevel.push_back(word);
    //                     vec.push_back(word);
    //                     q.push(vec);
    //                     vec.pop_back();
    //                 }
    //             }

    //             word[i] = original;
    //         }

    //     }

    //     return ans;

    // }

    map<string, int>mpp;
    vector<vector<string>> ans;
    string b;

    public:

    void dfs(string word, vector<string> &seq)
    {
        if(word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int level = mpp[word];

        for(int i=0 ;i<word.size(); i++)
        {
            char original = word[i];
            for(char ch = 'a' ; ch<= 'z'; ch++)
            {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && level == mpp[word] + 1)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(), wordList.end());
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        mpp[beginWord] = 1;
        b = beginWord;

        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            int level = mpp[word];

            if(word == endWord) break;

            for(int i=0; i<word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++)
                {
                    word[i] = ch;
                    if(st.count(word))
                    {
                        q.push(word);
                        mpp[word] = level + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        if(mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;



    }
};