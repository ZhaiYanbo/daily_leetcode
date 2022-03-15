//不借助临时变量交换两个变量的值
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) 
    {
        //异或操作，利用a^b^a=a的结论
       numbers[1]=numbers[0]^numbers[1];
       numbers[0]=numbers[0]^numbers[1];
       numbers[1]=numbers[0]^numbers[1];
       return numbers;
    }
};