/*
时间限制：1秒 空间限制：32768K 热度指数：109136

题目描述
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
最长路径的长度为树的深度
*/

//3ms 占用空间 484k
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr){
            return 0;
        }
        int depth = 1;
        int leftDepth = 0;
        int rightDepth = 0;
        if(pRoot -> left){
            leftDepth = TreeDepth(pRoot -> left);
        }
        if(pRoot -> right){
            rightDepth = TreeDepth(pRoot -> right);
        }
        return depth + max(leftDepth, rightDepth);
                                                                                                             
    }
};