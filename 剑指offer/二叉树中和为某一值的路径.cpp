/*
时间限制：1秒 空间限制：32768K 热度指数：245668

题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
*/


//3ms 占用空间 476k
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
    vector<vector<int>> ret;
    vector<int> trace;

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if (root != nullptr)
            dfs(root, expectNumber);
        return ret;
    }

    void dfs(TreeNode* cur, int n) {
        //剪枝
        if(cur -> val > n){
            return;
        }
        trace.push_back(cur -> val);
        // 结束条件
        if (cur -> left == nullptr && cur -> right == nullptr) {
            if (cur -> val == n)
                ret.push_back(trace);      // C++ 默认深拷贝
        }
        if (cur -> left)
            dfs(cur -> left, n - cur -> val);  // 这里没有求和，而是用递减的方式
        if (cur -> right)
            dfs(cur -> right, n - cur -> val);
        trace.pop_back();
    }
};