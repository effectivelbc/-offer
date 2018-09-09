/*
时间限制：1秒 空间限制：32768K 热度指数：274939

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

//二叉树问题很容易就联想到递归，利用后序遍历的特点将数组分成左右根三个部分
//且右部分应该递增

//3ms 占用空间 352k
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()){
            return false;
        }
        return dfs(sequence, 0, sequence.size() - 1);
    }
    
    bool dfs(vector<int> &sequence, int start, int end){
        if(start >= end){
            return true;
        }
        int root = sequence[end];
        int mid = 0;
        //寻找大于根节点的元素
        for(; mid < end; mid++){
            if(sequence[mid] > root){
                break;
            }
        }
        bool flag = true;
        for(int i = mid; i < end; i++){
            if(sequence[i] < root){
                flag = false;
                break;
            }
        }
        return flag && dfs(sequence, start, mid - 1) && dfs(sequence, mid, end - 1);
    }
};