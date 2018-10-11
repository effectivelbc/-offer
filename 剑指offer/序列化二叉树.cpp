/*
时间限制：1秒 空间限制：32768K 热度指数：119071

题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
*/

//5ms 480k
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
    void dfsSerialize(TreeNode* node, string &s){
        if(node == nullptr){
            s.push_back('#');
            s.push_back(',');
            return;
        }
        s += to_string(node -> val);
        s.push_back(',');
        dfsSerialize(node -> left, s);
        dfsSerialize(node -> right, s);
    }
    
    char* Serialize(TreeNode *root) {    
        if(root == nullptr){
            return nullptr;
        }
        string s = "";
        dfsSerialize(root, s);
        
        char *ret = new char[s.length() + 1];
        strcpy(ret, s.c_str());
        return ret;
    }
    
    TreeNode* dfsDeserialize(string &s){
        if(s.empty()){
            return nullptr;
        }
        if(s[0] == '#'){
            s = s.substr(2);
            return nullptr;
        }
        TreeNode *ret = new TreeNode(stoi(s));
        s = s.substr(s.find_first_of(',') + 1);
        ret -> left = dfsDeserialize(s);
        ret -> right = dfsDeserialize(s);
        return ret;
    }
    
    TreeNode* Deserialize(char *str) {
        if(str == nullptr){
            return nullptr;
        }
        string s(str);
        return dfsDeserialize(s);
    }
};