//加油站问题
class Solution {
public:
    bool isOK(vector<int>& gas, vector<int>& cost,int& index)
    {
        int total=gas[index],n=gas.size();
        for(int i=0;i<n;i++)
        {
            index++;
            //if(index==n)    index=0;
            //int nextCost=cost[index==0?n-1:index-1];
            int nextCost=cost[(index-1+n)%n];
            int nextGas=gas[index%n];
            if(total<nextCost) return false;
            total=total-nextCost+nextGas;
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int index=0;
        while(index<gas.size())
        {
            //index在循环中会不断增大
            if(isOK(gas,cost,index))    return index-gas.size();    
            //从index开始，走了一圈，index也在不断增加，因此最后应返回index-gas.size()
        }
        //未找到满足条件的index，返回-1
        return -1;
    }
};