/*
时间限制：1秒 空间限制：32768K 热度指数：80237
本题知识点： 数组

题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

//3ms 占用空间480k
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.empty()){
            return vector<int>();
        }
        int len = A.size();
        vector<int> B(len, 1);
        vector<int> front(len, 1);
        vector<int> back(len, 1);
         
        for(int i = 1; i < len; i++){
            front[i] = front[i - 1] * A[i - 1];
        }
         
        for(int i = len - 2; i >= 0; i--){
            back[i] = back[i + 1] * A[i + 1];
        }
         
        for(int i = 0; i < len; i++)
            B[i] = front[i] * back[i];
         
        return B; 
    }
};