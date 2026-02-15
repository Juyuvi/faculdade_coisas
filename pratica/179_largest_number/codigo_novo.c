#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareNums(int a, int b) {
    char ab[25], ba[25];

    sprintf(ab, "%d%d", a, b);
    sprintf(ba, "%d%d", b, a);

    return strcmp(ab, ba);
}

int* quickSort(int* nums, int numsSize, int fEl, int lEl){

    printf("\nenter new qs\n");

    int middle = fEl + (lEl - fEl) / 2; 
    int m_element = nums[middle];

    int i = fEl;
    int j = lEl;

    do{
        while(compareNums(nums[i], m_element) > 0){
            printf("\n%d before %d", nums[i], m_element);
            i++;
        }

        while(compareNums(nums[j], m_element) < 0){
            printf("\n%d after %d", nums[j], m_element);
            j--;
        }

        if(i <= j){
            int temp = nums[i];
            printf("\nswitching: %d n %d", nums[i], nums[j]);
            nums[i] = nums[j];
            nums[j] = temp;

            i++;
            j--;
        }

    }while(i <= j);

    if(fEl < j)
        quickSort(nums, numsSize, fEl, j);

    if(i < lEl)
        quickSort(nums, numsSize, i, lEl);

    return nums;
}

char* largestNumber(int* nums, int numsSize) {

    quickSort(nums, numsSize, 0, numsSize - 1);

    
    int total = 0;
    for (int i = 0; i < numsSize; i++)
        total += snprintf(NULL, 0, "%d", nums[i]);

    char* str = malloc(total + 1);
    char* p = str;

    for(int i = 0; i < numsSize; i++){
        printf("\n%d", nums[i]);
        p += sprintf(p, "%d", nums[i]);
    }

    
    if(str[0] == '0')
        str[1] = '\0';

    return str;
}

int main(){

    int num[] = {3, 30, 34, 5, 9};

   int* nums  = num;

   char* res = largestNumber(nums, 5);

   printf("%s", res);

   free(res);


}