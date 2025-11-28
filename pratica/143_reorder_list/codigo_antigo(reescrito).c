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

    struct ListNode * newHead = head;
    

    for(int i = 0; i <= size; i++){
        curr = head;

        for(int j = 0; j <= size - i; j++){
            curr = curr->next;
        }

        if()

        curr->next = head->next;
        head->next = curr;

        head = head->next->next;
    }

    head = newHead;

}