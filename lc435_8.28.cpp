//无重叠区间
/**
 * @brief 贪心解法
 * 
 * O（NlogN），O（NlogN）
 * 类似于安排开会的问题
 */
bool cmp(const vector<int>&a,const vector<int>&b) {
    return a[1] < b[1];
}
class Solution {
    
public:
    //贪心解法
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())   return 0;
        
        //按照结束事件进行升序排序
        sort(intervals.begin(),intervals.end(),cmp);

        int cnt = 1, rightTime = intervals[0][1];
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] >= rightTime) {
                cnt++;
                rightTime = intervals[i][1];
            }
        }
        
        return intervals.size() - cnt;
    }
};