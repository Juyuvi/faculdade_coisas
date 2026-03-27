#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int length;
    int* data;

    int _maxSize;
    int _growth; // Linear: 0; Exponencial: >=1
    int _copies;
} ArrayList;

bool _increaseArraySize(ArrayList * arr);

ArrayList* createArray(int growth){
    ArrayList* array = (ArrayList*) malloc(sizeof(ArrayList));

    if(array == NULL){
        printf("ERROR ALLOCATING ARRAY (for some reason...)");
        exit(1);
    }
        
    array->length = 0;

    array->data = (int*) malloc(sizeof(int) * 1);
    if (array->data == NULL){
        printf("ERROR ALLOCATING ARRAY DATA (for some reason...)");
        exit(1);
    }

    array->_maxSize = 1;

    if (growth)
        array->_growth = 1;
    else
        array->_growth = 0;

    array->_copies = 0;

    return array;
}

bool insert(ArrayList* arr, int val){
    arr->data[arr->length++] = val;
    bool res = true;

    if(arr->length == arr->_maxSize)
        res = _increaseArraySize(arr);

    return res;
}

bool _increaseArraySize(ArrayList* arr){
    int* oldArrayData = arr->data;
    int* newArrayData;
    int newMaxSize;

    if (arr->_growth) // Exponencial
        newMaxSize = 2 * arr->_maxSize;
    else // Linear
        newMaxSize = 100 + arr->_maxSize;

    newArrayData = (int*) malloc(sizeof(int) * newMaxSize);
    if (newArrayData == NULL)
        return false;

    for(int i = 0; i < arr->length; i++){
        newArrayData[i] = oldArrayData[i];
        arr->_copies++;
    }

    arr->data = newArrayData;
    arr->_maxSize = newMaxSize;

    free(oldArrayData);

    return true;
}