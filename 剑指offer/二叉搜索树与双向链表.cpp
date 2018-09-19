/*
时间限制：1秒 空间限制：32768K 热度指数：171778

题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

//4ms 占用空间376k
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        //左根右 中序
        if(pRootOfTree == nullptr){
            return nullptr;
        }
        if(pRootOfTree -> left){
            TreeNode* a = Convert(pRootOfTree -> left);
            while(a -> right){
                a = a -> right;
            }
            pRootOfTree -> left = a;
            a -> right = pRootOfTree;
        }
        if(pRootOfTree -> right){
            TreeNode* a = Convert(pRootOfTree -> right);
            while(a -> left){
                a = a -> left;
            }
            pRootOfTree -> right = a;
            a -> left = pRootOfTree;
        }
        while(pRootOfTree -> left){
            pRootOfTree = pRootOfTree -> left;
        }
        return pRootOfTree;
        
    }
};