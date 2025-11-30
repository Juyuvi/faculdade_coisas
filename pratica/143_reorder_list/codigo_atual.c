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

    curr = head;
    for (int i = 0; i < size/2; i++) {
        // encontra o penúltimo (a partir de curr)
        struct ListNode *prev = curr;
        while (prev->next && prev->next->next) {
            prev = prev->next;
        }

        struct ListNode *last = prev->next;
        // se o "last" já é o próximo de curr (adjacente), acabou
        if (last == curr->next) break;

        struct ListNode *next = curr->next;

        // remove o último
        prev->next = NULL;

        // insere o último logo após curr
        last->next = next;
        curr->next = last;

        // avança curr duas posições
        curr = next;
        if (!curr) break;
    }
}