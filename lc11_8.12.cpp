//盛水最多的容器

//1.暴力：O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int res = 0;
        for(int i=0;i<height.size();i++)
            for(int j=i+1;j<height.size();j++)
            {
                int cur_h = height[i]<height[j]?height[i]:height[j];
                int cur_s = (j-i)*cur_h;
                res = cur_s>res?cur_s:res;
            }
        return res;
    }
};

//2.双指针：O(N)
class Solution {
public:
    int mymin(int a,int b)
    {
        return a<b?a:b;
    }
    
    int maxArea(vector<int>& height) 
    {
        int res = 0;
        int i= 0, j = height.size()-1;
        while(i<j)
        {
            int cur_s = mymin(height[i],height[j])*(j-i);
            res = cur_s>res?cur_s:res;
            if(height[i]>height[j]) j--;
            else                    i++;
        }
        return res;
        
    }
};