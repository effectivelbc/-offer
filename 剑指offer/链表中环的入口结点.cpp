/*
时间限制：1秒 空间限制：32768K 热度指数：127496
本题知识点： 链表

题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

//3ms 476k
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //一个一次一步，一个一次两步
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while(p1 != nullptr && p2 != nullptr && p2 -> next != nullptr){
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
            //p1 p2相遇
            if(p1 == p2){
                ListNode *p3 = pHead;
                while(1){
                    if(p1 == p3){
                        return p1;
                    }
                    p1 = p1 -> next;
                    p3 = p3 -> next;
                }
            }
        }
        return nullptr;
        
    }
};