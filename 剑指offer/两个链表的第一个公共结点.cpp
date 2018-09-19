/*
时间限制：1秒 空间限制：32768K 热度指数：144689
本题知识点： 链表

题目描述
输入两个链表，找出它们的第一个公共结点。
*/

//2ms 占用空间476k
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr){
            return nullptr;
        }
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        int m = 0, n = 0;
        while(p1){
            p1 = p1 -> next;
            m++;
        }
        while(p2){
            p2 = p2 -> next;
            n++;
        }
        int k;
        p1 = pHead1;
        p2 = pHead2;
        if(m > n){
            k = m - n;
            while(k--){
                p1 = p1 -> next;
            }
        }
        else{
            k = n - m;
            while(k--){
                p2 = p2 -> next;
            }
        }
        while(p1 && p2){
            if(p1 == p2){
                return p1;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return nullptr;
    }
};