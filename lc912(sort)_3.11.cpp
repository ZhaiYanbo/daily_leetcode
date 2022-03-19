#include<vector>
#include<iostream>
using namespace std;
//排序数组
class Solution
{
    public:
    void merge(vector<int>&nums,int left,int mid,int right)
    {
        vector<int>temp(right-left);
        int i=left,j=mid+1,count=0;
        while(i<=mid&&j<=right)
        {
            if(nums[i]<nums[j])
                temp[count++]=nums[i++];
            else 
                temp[count++]=nums[j++];
        }
        while (i<=mid)
        {
            temp[count++]=nums[i++];
        }
        while(j<=right)
        {
            temp[count++]=nums[j++];
        }
        nums=temp;
    }
    void mergeSort(vector<int>&nums,int left,int right)
    {
        if(left>=right) return;
        int mid=(left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        //数组nums[left:mid]与数组nums[mid+1:right]已经有序，进行归并即可
        merge(nums,left,mid,right);
    }
};

int main()
{
    vector<int>a={5,4,3,2,1};
    Solution solution;
    solution.mergeSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<",";
}