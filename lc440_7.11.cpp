//字典序的第k小数字
class Solution {
public:
    int findKthNumber(int n, int k) 
    {
        int cur=1;
        k--;    //因为1已经算遍历过了，因此减1

        while(k>0)
        {
            long long left=cur; //当前层的最左边元
            long long right=cur+1;  //当前层的最右边元的下一个元，及根节点右兄弟的最左边元
            int sumNode=0;      //节点个数和

            //统计每一层节点个数
            while(left<=n)
            {
                sumNode+=min(right,(long long)(n+1))-left;    
                //这一层个数要么是left-right，要么是n-left+1
                left*=10;   //到下一层
                right*=10;  //到下一层
            }

            //向后查找
            if(sumNode<=k)
            {
                k-=sumNode;
                cur++;
            }

            //在子树中查找
            else
            {
                k--;
                cur*=10;
            }
        }

        return cur;
    }
};