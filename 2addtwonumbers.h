#ifndef HEADER_2addtwonumbers
#define HEADER_2addtwonumbers 
#include<iostream>
#include "ListNode.h"

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		ListNode *resList = NULL, *pNode = NULL, *pNext = NULL;
		ListNode *p = l1, *q = l2;
		int up = 0;

		while (p != NULL && q != NULL)
		{
			pNext = new ListNode(p->val + q->val + up);//和+前一位
			up = pNext->val / 10;    //计算进位  
			pNext->val = pNext->val % 10;   //计算该位的数字  

			if (resList == NULL)  //头结点为空  
			{
				resList = pNode = pNext;
			}
			else //头结点不为空
			{
				pNode->next = pNext;
				pNode = pNext;
			}
			p = p->next;
			q = q->next;
		}
		//处理链表l1剩余的高位  
		while (p != NULL)
		{
			pNext = new ListNode(p->val + up);
			up = pNext->val / 10;
			pNext->val = pNext->val % 10;
			pNode->next = pNext;
			pNode = pNext;
			p = p->next;
		}

		//处理链表l2剩余的高位  
		while (q != NULL)
		{
			pNext = new ListNode(q->val + up);
			up = pNext->val / 10;
			pNext->val = pNext->val % 10;
			pNode->next = pNext;
			pNode = pNext;
			q = q->next;
		}

		//如果有最高处的进位，需要增加结点存储  
		if (up > 0)
		{
			pNext = new ListNode(up);
			pNode->next = pNext;
		}

		return resList;
	}
};
#endif

//#include "num2listnode.h"
//#include "2addtwonumbers.h"
//#include "ListNode.h"
//void main(){
//	int x = 0;
//	int y = 99;
//	wheels a;
//	Solution b;
//
//	ListNode *l1 = a.num2listnode(x), *l2 = a.num2listnode(y);
//	ListNode *l3 = b.addTwoNumbers(l1, l2);
//	while (l3 != NULL){
//		cout << l3->val << '\t';
//		l3 = l3->next;
//	};
//}