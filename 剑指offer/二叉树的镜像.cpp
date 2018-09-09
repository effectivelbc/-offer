/*
时间限制：1秒 空间限制：32768K 热度指数：185543
 算法知识视频讲解
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
		
*/

//3ms 占用空间476k
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr){
            return;
        }
        if(pRoot -> right == nullptr && pRoot -> left == nullptr){
            return;
        }
        else{
            TreeNode *pTemp = pRoot -> right;
            pRoot -> right = pRoot -> left;
            pRoot -> left = pTemp;
        }
        Mirror(pRoot -> left);
        Mirror(pRoot -> right);
    }
};

