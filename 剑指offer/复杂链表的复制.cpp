/*
时间限制：1秒 空间限制：32768K 热度指数：242418
本题知识点： 链表

题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

//4ms 占用空间492k
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr){
            return nullptr;
        }
        //将原list进行复制，每个复制出的结点接在原结点的后面
        RandomListNode* p = pHead;
        RandomListNode* temp;
        while(p){
            temp = p -> next;
            p -> next = new RandomListNode(p -> label);
            p -> next -> next = temp;
            p = p -> next -> next;
        }
        //复制点的random指向被复制点的random指向的结点的复制结点
        p = pHead;
        while(p){
            if(p -> random){
                p -> next -> random = p -> random -> next;
            }
            
            p = p -> next -> next;
        }
        p = pHead;
        RandomListNode* ans = pHead -> next;
        RandomListNode* a = ans;
        //分离链表
        while(p -> next){
            temp = p -> next;
            p -> next = temp -> next;
            p = temp;
        }
        return ans;
        
    }
};