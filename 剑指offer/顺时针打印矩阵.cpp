/*
时间限制：1秒 空间限制：32768K 热度指数：330078
本题知识点： 数组

题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

//3ms 占用空间492k 递归思想
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty() || matrix[0].empty()){
            vector<int> a;
            return a;
        }
        if(matrix.size() == 1){
            return matrix[0];
        }
        if(matrix[0].size() == 1){
            vector<int> a;
            for(int i = 0; i < matrix.size(); i++){
                a.push_back(matrix[i][0]);
            }
            return a;
        }
        //用递归来写
        vector<int> a;
        //打印4条边的
        for(int i = 0; i < matrix[0].size(); i++){
            a.push_back(matrix[0][i]);
        }
        for(int i = 1; i < matrix.size() - 1; i++){
            a.push_back(matrix[i][matrix[0].size() - 1]);
        }
        for(int i = matrix[0].size() - 1; i >= 0; i--){
            a.push_back(matrix[matrix.size() - 1][i]);
        }
        for(int i = matrix.size() - 2; i > 0; i--){
            a.push_back(matrix[i][0]);
        }
        //matrix去掉首尾
        matrix.pop_back();
        matrix.erase(matrix.begin());
        if(matrix.size() == 0){
            return a;
        }
        //去掉左右
        if(matrix[0].size() > 2){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i].pop_back();
                matrix[i].erase(matrix[i].begin());
            }
        }
        else{
            return a;
        }
        vector<int> b = printMatrix(matrix);
        a.insert(a.end(), b.begin(), b.end());
        return a;
};

//正常二维数组便历
//3ms 占用空间480k
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        
        int rl = 0, rr = matrix.size()-1;
        int cl = 0, cr = matrix[0].size()-1;
        while(rl <= rr && cl <= cr) {
            for (int i = cl; i <= cr; i++)
                ret.push_back(matrix[rl][i]);
            for (int i = rl+1; i <= rr; i++)
                ret.push_back(matrix[i][cr]);
            if (rl != rr)
                for (int i = cr - 1; i >= cl; i--)
                    ret.push_back(matrix[rr][i]);
            if (cl != cr)
                for (int i = rr - 1; i > rl; i--)
                    ret.push_back(matrix[i][cl]);
            rl++; rr--; cl++; cr--;
        }
        return ret;
    }
};