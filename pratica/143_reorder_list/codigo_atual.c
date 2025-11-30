/*
====================
ReorderList
====================
*/
void ReorderList( listNode_t *head ) {
	if ( !head ) {
		return;
	}

	int size = 0;
	listNode_t *curr = head;

	while ( curr->next ) {
		printf( "\n-- %d\n", size );
		curr = curr->next;
		size++;
	}

	curr = head;
	for ( int i = 0; i < size / 2; i++ ) {
		// encontra o penúltimo (a partir de curr)
		listNode_t *prev = curr;
		while ( prev->next && prev->next->next ) {
			prev = prev->next;
		}

		listNode_t *last = prev->next;
		// se o "last" já é o próximo de curr (adjacente), acabou
		if ( last == curr->next ) {
            break;
        }

		listNode_t *next = curr->next;

		// remove o último
		prev->next = NULL;

		// insere o último logo após curr
		last->next = next;
		curr->next = last;

		// avança curr duas posições
		curr = next;
		if ( !curr ) {
            break;
        }
	}
}