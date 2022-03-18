// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <map>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto [x, y]: st){
            int ix = max(x, start);
            int iy = min(y, end);
            if(ix < iy) return false;
        }
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

