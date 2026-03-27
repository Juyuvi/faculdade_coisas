#include <stdbool.h>

typedef struct{
    int length;
    int* data;

    int _maxSize;
    int _growth; // Linear: 0; Exponencial: >=1
    int _copies;
} ArrayList;

ArrayList* createArray(int growth);
bool insert(ArrayList* arr, int val);