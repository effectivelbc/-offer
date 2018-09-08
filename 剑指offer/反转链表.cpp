/*
时间限制：1秒 空间限制：32768K 热度指数：340166
本题知识点： 链表

题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//3ms 占用空间484k
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr){
            return nullptr;
        }
        ListNode* p = pHead;
        //记录当前
        
        //记录中间量
        ListNode* pTemp;
        ListNode* p2;
        //不使用额外空间
        while(p -> next != nullptr){
            //保存p2
            p2 = p -> next;
            //保存p2的下一个
            pTemp = p2 -> next;
            //p2指向pHead
            p2 -> next = pHead;
            //p1指向p2的下一个
            p -> next = pTemp;
            //更新pHead
            pHead = p2;
        }
        return pHead;
    }
};