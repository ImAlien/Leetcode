// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n= s.size();
        vector<int> cnt(26), vis(26);
        vector<int> stk;
        for(int i = 0;i < n; i ++){
            cnt[s[i] - 'a'] = i;
        }
        for(int i = 0; i < n; i ++){
            char c = s[i];
            if(vis[c - 'a']) continue;
            while(stk.size() && c < s[stk.back()] &&  cnt[s[stk.back()] - 'a'] > i){     
                vis[s[stk.back()] - 'a'] = 0;
                stk.pop_back();
            }
            stk.push_back(i);
            vis[c-'a'] = 1;
            
        }
        string ans;
        for(int x: stk){
            ans += s[x];
        }
        return ans;
    }
};
// @lc code=end

