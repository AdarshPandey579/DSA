#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    ListNode* head = new ListNode();
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);

    head=l1;
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    l5->next=l6;
    l6->next=l3; // Creating a cycle for testing

    ListNode* slow=head;
    ListNode* fast=head;
    bool isCycle = false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            isCycle = true;
            break;
        }
    }
    slow=head;
    if(isCycle){
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        cout << slow->val;
        return 0;
    }
    cout << "NULL";
    return 0;
}

// g++ _142.cpp -o _142;./_142