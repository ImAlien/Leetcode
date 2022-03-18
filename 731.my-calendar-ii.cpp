/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo {
public:
    set<pair<int, int>> st;
    MyCalendarTwo() {
        
    }
    bool intersect(int a, int b, int c, int d){
        return max(a, c) < min(b, d);
    }
    bool book(int start, int end) {
        int cnt = 0;
        int pa = -1, pb = -1;
        for(auto [x, y]: st){
            int nx = max(start, x);
            int ny = min(end, y);
            if(nx < ny){
                if(intersect(nx, ny, pa, pb)) return false;
                else {
                    pa = nx; pb = ny;
                }
            }
        }
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

