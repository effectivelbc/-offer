/*
时间限制：1秒 空间限制：32768K 热度指数：440496

题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

//5ms 占用空间452k
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() <= 0){
            return NULL;
        }
        
        TreeNode* root = new TreeNode{ pre[0] };
        for(auto i = 0; i < vin.size(); i++){
            if(vin[i] == pre[0]){
                root -> left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + i), vector<int>(vin.begin(), vin.begin() + i));
                root -> right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + i, pre.end()), vector<int>(vin.begin() + 1 + i, vin.end()));
            }
        }
        return root;
    }
};