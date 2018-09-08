/*
时间限制：1秒 空间限制：32768K 热度指数：322175
本题知识点： 链表

题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/


//3ms 占用空间476k
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr){
            return pHead2;
        }
        if(pHead2 == nullptr){
            return pHead1;
        }
        
        ListNode *tempHead = new ListNode{ 0 };
        tempHead -> next = pHead1;
        
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        ListNode *pCurrent = tempHead;
        ListNode *pTemp = nullptr;
        while(p1 != nullptr && p2 != nullptr){
            if(p2 -> val < p1 -> val){
                //p2的值放在p1的前面
                pTemp = p2 -> next;
                p2 -> next = p1;
                pCurrent -> next = p2;
                pCurrent = p2;
                p2 = pTemp;
            }
            else{
                pCurrent = p1;
                p1 = p1 -> next;
            }
        }
        //p2剩下的都比p1大
        if(p2 != nullptr){
            pCurrent -> next = p2;
        }
        //p1剩下的都比p2大
        if(p1 != nullptr){
            pCurrent -> next = p1;
        }
        
        return tempHead -> next;
    }
};

//也可以使用递归