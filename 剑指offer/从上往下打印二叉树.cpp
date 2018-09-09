/*
时间限制：1秒 空间限制：32768K 热度指数：243753

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印
*/


//3ms 占用空间468k
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr) 
            return vector<int>();
        //广度遍历二叉树
        queue<TreeNode*> q;
        vector<int> tree;
        q.push(root);
        while(!q.empty()){
            auto a = q.front();
            tree.push_back(a -> val);
            if(a -> left){
                q.push(a -> left);
            }
            if(a -> right){
                q.push(a -> right);
            }
            q.pop();
        }
        return tree;
    }
};