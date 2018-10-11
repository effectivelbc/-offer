/*
时间限制：1秒 空间限制：32768K 热度指数：111897

题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针
*/

//4ms 468k
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* root = GetRoot(pNode);
        TreeLinkNode* lastNode = GetLastNode(root);
        //中序遍历是左 根 右
        if(pNode -> right == nullptr){
            //右边没有，返回根
            if(pNode == lastNode){
                return nullptr;
            }
            if(pNode -> next != nullptr){
                //右边没有，且本身是根的右子树，返回根的根
                if(pNode -> next -> right == pNode){
                    return pNode -> next -> next;
                }
                return pNode -> next;
            }
            else{
                return nullptr;
            }
        }
        else{
            return GetLeft(pNode -> right);
        }
    }
    
    TreeLinkNode* GetLeft(TreeLinkNode* pNode){
        if(pNode -> left){
            return GetLeft(pNode -> left);
        }
        else{
            return pNode;
        }
    }
    
    TreeLinkNode* GetRoot(TreeLinkNode* pNode){
        if(pNode -> next){
            return GetRoot(pNode -> next);
        }
        else{
            return pNode;
        }
    
    }
    
    TreeLinkNode* GetLastNode(TreeLinkNode* pNode){
        if(pNode -> right){
            return GetLastNode(pNode -> right);
        }
        else{
            return pNode;
        }
        //没有右侧结点，那么看看自己是不是根的最右侧结点
    }
};