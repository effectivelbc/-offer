/*
时间限制：1秒 空间限制：32768K 热度指数：469527
本题知识点： 链表

题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/


//4ms 468k 前后指针相隔k O(n)
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr){
            return nullptr;
        }
        ListNode* p1 = pListHead;
        ListNode* p2 = pListHead;
        //两个指针，一个正常遍历，一个晚k步开始遍历
        while(k && p1){
            p1 = p1 -> next;
            k--;
        }
        //k长度大于链表长度
        if(k > 0){
            return nullptr;
        }
        while(p1){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p2;
        
    }
};