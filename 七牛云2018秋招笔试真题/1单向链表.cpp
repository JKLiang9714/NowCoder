#include <iostream>
#include <cstdio>
using namespace std;

/*
题解：快慢指针
*/

// 链表节点 = 数据 + 索引(指针) 
struct Node {
	int data;
	Node *next;
};

Node *the_reciprocal_kth_node(Node *head, int k) {
	if (k < 1) return NULL;
    Node *slow = head;
    Node *fast = head;
    int i = k;
    for (; i > 0 && fast != NULL; i--) {
        fast = fast->next;
    }
    // 如果k大于链表长度
    if (i > 0) return NULL;
    // 如果k小于等于链表长度
    while (fast != NULL) { // show与fast相隔k，当fast到达1时，show到达k
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 10 7 5 3 2 1
int main() {
	// 构造链表
	Node root; // 根节点(链表的首节点)
	root.data = 10;

	Node n1;
	n1.data = 7;
	root.next = &n1;

	Node n2;
	n2.data = 5;
	n1.next = &n2;

	Node n3;
	n3.data = 3;
	n2.next = &n3;

	Node n4;
	n4.data = 2;
	n3.next = &n4;

	Node n5;
	n5.data = 1;
	n4.next = &n5;
	n5.next = NULL; // n5后面没有节点了NULL。

	Node *res = the_reciprocal_kth_node(&root, 4);
	printf("%d\n", res->data);
	return 0;
}
