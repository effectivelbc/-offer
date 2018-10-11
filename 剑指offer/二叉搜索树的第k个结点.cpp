/*
时间限制：1秒 空间限制：32768K 热度指数：139701

题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
*/

//4ms 476k
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr){
            return nullptr;
        }
        int a = count(pRoot -> left);
        //int b = count(pRoot -> right);
        if(a < k - 1){
            //找到右子树第k1小的返回
            int k1 = k - a - 1;
            return KthNode(pRoot -> right, k1);
        }
        else if(a == k - 1){
            return pRoot;
        }
        else{
            //找到左子树第k小的
            return KthNode(pRoot -> left, k);
        }
    }
    
    //计算一棵树有几个结点
    int count(TreeNode* pRoot){
        if(pRoot == nullptr){
            return 0;
        }
        int a = 1;
        if(pRoot -> left){
            a += count(pRoot -> left);
        }
        if(pRoot -> right){
            a += count(pRoot -> right);
        }
        return a;
    }

    
};