#include "arraylist.h"
#include <stdio.h>

int main(){
    ArrayList* linearArray = createArray(0);
    ArrayList* exponentialArray = createArray(1);

    for (int i = 0; i < 10000; i++){
        insert(linearArray, 1);
        insert(exponentialArray, 1);
    }

    printf("Array linear realizou %d copias.\n", linearArray->_copies);
    printf("Array exponencial realizou %d copias.\n", exponentialArray->_copies);

}