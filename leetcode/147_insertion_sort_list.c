/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if( head == NULL)
        return head;

    int c = 1;
    struct ListNode* curr = head;
    while(curr->next != NULL){
        c++;
        curr = curr->next;
    }

    printf("%d", c);
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));

    
    dummy->next = head;
    head = head->next;
    dummy->next->next = NULL;
    

    curr = head;
    struct ListNode* currDummy = dummy;
    for(curr = head; curr != NULL; 1){
        //printf("1");
        for(currDummy; currDummy != NULL; currDummy = currDummy->next){
            //printf("\n%d -- %d\n", curr->val, dummy->next->val);

            if(currDummy->next == NULL){
                struct ListNode* aux = curr->next;
                curr->next = currDummy->next;

                currDummy->next = curr;
                currDummy->next->next;
                curr = aux;
                break;
            }
            if (curr->val <= currDummy->next->val){

                //printf("3");
                struct ListNode* aux = curr->next;
                curr->next = currDummy->next;

                currDummy->next = curr;
                currDummy->next->next;
                curr = aux;
                break;
            }
        }

        currDummy = dummy;
    }


    return dummy->next;
}
