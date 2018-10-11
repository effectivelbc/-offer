/*
时间限制：1秒 空间限制：32768K 热度指数：120688

题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

//3ms 476k
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == nullptr){
            return vector<vector<int> >();
        }
        //因为是二叉树
        vector<vector<int> > vec;
        //使用两个栈
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(pRoot);
        vector<int> vec1;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode* a = s1.top();
                    s1.pop();
                    if(a -> left){
                        s2.push(a -> left);
                    }
                    if(a -> right){
                        s2.push(a -> right);
                    }
                    vec1.push_back(a -> val);
                }
                vec.push_back(vec1);
                vec1.clear();
            }
            if(!s2.empty()){
                while(!s2.empty()){
                    TreeNode* a = s2.top();
                    s2.pop();
                    if(a -> right){
                        s1.push(a -> right);
                    }
                    if(a -> left){
                        s1.push(a -> left);
                    }
                    vec1.push_back(a -> val);
                }
                vec.push_back(vec1);
                vec1.clear();
            }
        }
        return vec;
    }
    
};