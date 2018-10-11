/*
时间限制：1秒 空间限制：32768K 热度指数：106362
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/


//3ms 480k
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr){
            return true;
        }
        return isSymmetricalEqual(pRoot -> left, pRoot -> right);
    }
    
    bool isSymmetricalEqual(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }
        if(left -> val == right -> val){
            return isSymmetricalEqual(left -> left, right -> right)
                && isSymmetricalEqual(left -> right, right -> left);
        }
        else{
            return false;
        }
    }

};