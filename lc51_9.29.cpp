//N皇后
/**
 * @brief 回溯
 * 基于集合
 *  时间：O（N!）
 *  空间：O（N）
 */
class Solution {
public:
    int N;
    void backTrack(int i,vector<vector<string>>& res, vector<int>& col_record,unordered_set<int>&col,unordered_set<int>&dia1,unordered_set<int>dia2) {
        if(i == N) {
            res.push_back(getS(col_record));
        } else {
            //每一列都试一下
            for(int j = 0; j < N; j++) {
                if(col.find(j) != col.end())    continue;
                if(dia1.find(i+j) != dia1.end())    continue;
                if(dia2.find(i-j) != dia2.end())    continue;

                col_record[i] = j;
                col.insert(j);
                dia1.insert(i+j);
                dia2.insert(i-j);

                backTrack(i+1,res,col_record,col,dia1,dia2);

                col_record[i] = -1;
                col.erase(j);
                dia1.erase(i+j);
                dia2.erase(i-j);
            }
        }
    }

    vector<string>getS(vector<int>& col_record) {
        //return {"",""};
        string temp = "";
        for(int i = 0; i < N; i++) temp.push_back('.');
        vector<string>res(N,temp);
        for(int i = 0; i < N; i++) {
            if(col_record[i] != -1)
                res[i][col_record[i]] = 'Q';
        }

        return res;
    }

    vector<vector<string>> solveNQueens(int n) {
        this->N = n;
        vector<vector<string>>res;
        vector<int>col_record(n,-1);
        unordered_set<int>col;
        unordered_set<int>dia1;
        unordered_set<int>dia2;
        backTrack(0,res,col_record,col,dia1,dia2);

        return res;
    }
};