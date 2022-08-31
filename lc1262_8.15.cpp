//可被3整除的最大和

//1.贪心
class Solution {
public:
    /**
        取数组中的最小的数
        前置条件：数组不为空
    */
    void getmin(vector<int>&nums,int& min)
    {
        min = nums[0];
        for(int i=1;i<nums.size();i++)
            if(nums[i]<min)
                min = nums[i];
    }

    /**
        取数组中最小的数和第二小的数
        前置条件：数组长度不小于2
    */
    void getmin2(vector<int>&nums,int& min1,int& min2)
    {
        min1 = nums[0]; min2 = nums[1];
        if(min2<min1)   swap(min1,min2);
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]<min1)
            {
                int temp = min1;
                min1 = nums[i];
                min2 = temp;
            }
            else if(nums[i]<min2)
            {
                min2 = nums[i];
            }
        }
    }

    //贪心
    int maxSumDivThree(vector<int>& nums) 
    {
        vector<int>div0,div1,div2;
        long long sum = 0;
        for(int num:nums)
        {
            sum += num;
            if(num%3==0)        div0.push_back(num);
            else if(num%3==1)   div1.push_back(num);
            else                div2.push_back(num); 
        }
        if(sum%3==0)    return sum;
        /**
            sum模3为1：去除1个div1最小或去除2个div2中最小的
            二者取更小的
        */
        else if(sum%3==1)
        {
            if(div1.empty()&&div2.size()<2) return 0;
            if(div1.empty())
            {
                int min1,min2;
                getmin2(div2,min1,min2);
                return sum-min1-min2;
            }
            else if(div2.size()<2)
            {
                int min;
                getmin(div1,min);
                return sum-min;
            }
            else
            {
                int min,min1,min2;
                getmin(div1,min);
                getmin2(div2,min1,min2);
                return sum-min1-min2<sum-min?sum-min:sum-min1-min2;
            }
        }
        /**
            sum模3为2：去除2个div1最小或去除1个div2中最小的
            二者取更小的
        */
        else
        {
            if(div2.empty()&&div1.size()<2) return 0;
            if(div2.empty())
            {
                int min1,min2;
                getmin2(div1,min1,min2);
                return sum-min1-min2;
            }
            else if(div1.size()<2)
            {
                int min;
                getmin(div2,min);
                return sum-min;
            }
            else
            {
                int min,min1,min2;
                getmin(div2,min);
                getmin2(div1,min1,min2);
                return sum-min1-min2<sum-min?sum-min:sum-min1-min2;
            }
        }

    }
};

//2.DP
class Solution {
public:
    int mymax(int a,int b)
    {
        return a>b?a:b;
    }
    int maxSumDivThree(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        dp[0][0] = 0,dp[0][1] = INT_MIN,dp[0][2] = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            
            int mod3=nums[i]%3;

            if(i==0)
            {
                dp[0][mod3] = nums[0];
                continue;
            }    

            if(mod3==0)
            {
                dp[i][0] = dp[i-1][0]+nums[i];
                dp[i][1] = dp[i-1][1] + nums[i];
                dp[i][2] = dp[i-1][2] + nums[i];
            }
            else if(mod3==1)
            {
                dp[i][0] = mymax(dp[i-1][2]+nums[i],dp[i-1][0]);
                dp[i][1] = mymax(dp[i-1][0]+nums[i],dp[i-1][1]);
                dp[i][2] = mymax(dp[i-1][1]+nums[i],dp[i-1][2]);
            }
            else
            {
                dp[i][0] = mymax(dp[i-1][1]+nums[i],dp[i-1][0]);
                dp[i][1] = mymax(dp[i-1][2]+nums[i],dp[i-1][1]);
                dp[i][2] = mymax(dp[i-1][0]+nums[i],dp[i-1][2]);
            }
            
        }
        return dp[n-1][0];
        
    }
};