//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(auto l: lists) if(l) pq.push(l);
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        if(node->next) pq.push(node->next);
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);
    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);
    ListNode* c = new ListNode(2);
    c->next = new ListNode(6);
    vector<ListNode*> lists = {a, b, c};
    ListNode* merged = mergeKLists(lists);
    cout << "Merged List: ";
    printList(merged);
}
