/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Step 1 :- Create the deep copy without random pointer
        Node* dummy = new Node(0) ;
        Node* tempd = dummy ;
        Node* temp = head ;
        while(temp){
            Node* a = new Node(temp->val);
            tempd->next=a;
            tempd=tempd->next;
            temp=temp->next;
        }
        Node* duplicate = dummy->next ;
        //Step 2 :- Create alternate connections (merge)
        Node* d = new Node(0);
        Node* td = d ;
        Node* a = head ;
        Node* b = duplicate ;
        while(b){
            td->next = a ;
            a = a->next ;
            td = td->next ;
            td->next = b ;
            td = td->next ;
            b = b->next ;
        }
        d = d->next ;
        //Step 3 :- Assigning random pointer of duplicate
        Node* t1 = d ;
        while(t1){
            Node* t2=t1->next;
            if(t1->random) t2->random = t1->random->next ;
            t1=t1->next->next;
        }
        //Step 4 :- Removing the connections
        Node* d1 = new Node(0);
        Node* d2 = new Node(0);
        Node* temp1 = d1;
        Node* temp2 = d2;
        Node* t = d ;
        while(t){
            temp1->next=t;
            t=t->next;
            temp1=temp1->next;

            temp2->next=t;
            t=t->next;
            temp2=temp2->next;
        }
        temp1->next=NULL;
        temp2->next=NULL;
        d1=d1->next;
        d2=d2->next;
        return d2;
    }
};