#include <iostream>
using namespace std;

struct ListNode {
	int val{};
	ListNode* next{};
	ListNode(int x) : val(x) {}
};

//2 两数相加
class CTwoListAdd {
	/*
	给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
	如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
	您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

	示例：
	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 0 -> 8
	原因：342 + 465 = 807
	*/
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		/*
		遍历两个链表 将两个链表的每一项相加 如果其中一个链表当前项为null 则用0代替
		将相加的值与上一项的除数相加div10
		余数为当前项的值 商留到下一项使用
		*/
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* r = new ListNode(0);
		ListNode* h = r;
		int quot = 0;

		while (p || q)
		{
			if (p) {
				quot += p->val;
				p = p->next;
			}
			if (q) {
				quot += q->val;
				q = q->next;
			}
			auto ret = std::div(quot, 10);
			quot = ret.quot;

			r->next = new ListNode(ret.rem);
			r = r->next;
		}
		if (quot > 0) {	//如果有进位 需要额外添加一个节点
			r->next = new ListNode(quot);
			r = r->next;
		}

		r = h->next;
		delete h;	//删除不需要的头节点
		return r;
	}
};

int main(int argc, char const* argv[])
{
	ListNode* l1 = new ListNode(2);
	auto* p = l1;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	p = l2;
	p->next = new ListNode(6);
	p = p->next;
	p->next = new ListNode(4);
	CTwoListAdd cls;
	auto ret = cls.addTwoNumbers(l1, l2);
	p = ret;
	auto q = ret;
	while (p) {
		p = p->next;
		cout << q->val << " << ";
		delete q;
		q = p;
	}
	cout << endl;
	p = l1;
	q = l1;
	while (p)
	{
		p = p->next;
		delete q;
		q = p;
	}
	p = l2;
	q = l2;
	while (p)
	{
		p = p->next;
		delete q;
		q = p;
	}
	return 0;
}
