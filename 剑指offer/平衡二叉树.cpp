/*
时间限制：1秒 空间限制：32768K 热度指数：133747

题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

//2ms 占用空间476k
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr){
            return true;
        }
        //左右子树都是平衡二叉树，且深度之差不超过1
        int depth = getDepthAndIsBalanced(pRoot);
        if(depth != -1){
            return true;
        }
        else{
            return false;
        }
        
    }
    int getDepthAndIsBalanced(TreeNode* pRoot) {
        if(pRoot == nullptr){
            return 0;
        }
        int a = getDepthAndIsBalanced(pRoot -> left);
        int b = getDepthAndIsBalanced(pRoot -> right);
        //左右任一一边不是平衡二叉树
        if(a == -1 || b == -1){
            return -1;
        }
        else {
            //左右深度相差1以内
            if(abs(a - b) <= 1){
                return max(a, b) + 1;
            }
            else{
                return -1;
            }
        }
    }
};