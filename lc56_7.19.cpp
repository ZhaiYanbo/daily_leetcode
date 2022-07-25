//合并区间
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;


/** 0.试图使用分治法，未通过 */
bool cmp (vector<int>v1,vector<int>v2)
{
    return (v1[0]>v2[0])||(v1[0]==v2[0])&&(v1[1]>v2[1]);
}
class Solution {
public:
    //合并两个区间
    vector<vector<int>>mergeTwo(vector<vector<int>>& intervals)
    {
        int l1=intervals[0][0],
            r1=intervals[0][1],
            l2=intervals[1][0],
            r2=intervals[1][1];
        //两区间有重叠，且区间1靠左
        if(l2>=l1&&l2<=r1)  return {{l1,r2}};
        //两区间有重叠，且区间2靠左
        if(r2>=l1&&r2<=r1)  return {{l2,r1}};
        //两区间无重叠，且区间1靠左
        if(l1<l2)   return{{l1,r1},{l2,r2}};
        //两区间无重叠，且区间2靠左
        return{{l2,r2},{l1,r1}};
    }

    //二分法
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int len=intervals.size();
        if(len==1) return intervals;
        if(len==2) return mergeTwo(intervals);
        //分别对左右两个区间进行合并
        vector<vector<int>>left;
        vector<vector<int>>right;
        for(int i=0;i<len/2;i++)
            left.push_back(intervals[i]);
        for(int i=len/2;i<len;i++)
            right.push_back(intervals[i]);

        vector<vector<int>>res;
        vector<vector<int>>res_left=merge(left);    
        vector<vector<int>>res_right=merge(right);
        int len_res_left=res_left.size();
        vector<vector<int>>mid;
        mid.push_back(res_left[len_res_left-1]);
        mid.push_back(res_right[0]);
        //左边的最大区间与右边的最小区间进行合并
        mid=mergeTwo(mid);
        //说明是重叠的，进行更改
        if(mid.size()==1)
        {
            res_left.pop_back();
            res_right[0]=mid[0];
        }
        
        res.insert(res.end(),res_left.begin(),res_left.end());
        res.insert(res.end(),res_right.begin(),res_right.end());
        sort(res.begin(),res.end(),cmp);
        return res;
    }
};

/*题解：排序后一次遍历*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {   
        sort(intervals.begin(),intervals.end());    //按区间起点排序
        vector<vector<int>>res;
        for(int i=0;i<intervals.size();i++)
        {
            int left=intervals[i][0],right=intervals[i][1];
            if(res.empty()||left>res.back()[1]) //vector的back()函数返回的是最后一个元素的引用
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1]=res.back()[1]>right?res.back()[1]:right;
            }
        }

        return res;
    }
};
int main()
{
    vector<vector<int>>t1={{1,4},{0,2},{3,5}};
    Solution s;
    vector<vector<int>>r1=s.merge(t1);
    
    return 0;
}