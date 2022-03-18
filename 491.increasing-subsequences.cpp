// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <set>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution {
public:
    vector<int> nums;
    vector<int> temp;
    set<vector<int>> ans;
    void dfs(int pos){
        if(pos == nums.size()){
            if(temp.size() > 1)
            ans.insert(temp);
            return ;
        }
        if(temp.size() == 0 || nums[pos] >= temp.back()){
            temp.push_back(nums[pos]);
            dfs(pos + 1);
            temp.pop_back();
        }
        dfs(pos + 1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        dfs(0);
        vector<vector<int>> aa;
        for(auto x: ans) aa.emplace_back(x);
        return aa;
    }
};
// @lc code=end

