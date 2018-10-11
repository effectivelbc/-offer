/*
时间限制：1秒 空间限制：32768K 热度指数：98889

题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == nullptr){
            return vector<vector<int> >();
        }
        //因为是二叉树
        vector<vector<int> > vec;
        //使用两个栈
        queue<TreeNode*> s1;
        queue<TreeNode*> s2;
        s1.push(pRoot);
        vector<int> vec1;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode* a = s1.front();
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
                    TreeNode* a = s2.front();
                    s2.pop();
                    if(a -> left){
                        s1.push(a -> left);
                    }
                    if(a -> right){
                        s1.push(a -> right);
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