/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

void reorderList(struct ListNode* head) {

    if(head == NULL){

        return;

    }


    int size = 0;

    struct ListNode * curr = head;


    while (curr->next != NULL){

        printf("\n-- %d\n", size);

        curr = curr->next;

        size++;

    }

    



}
