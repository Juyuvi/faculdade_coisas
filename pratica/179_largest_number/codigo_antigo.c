#include <string.h>

int* quickSort(int* nums, int numsSize, int fEl, int lEl){

    printf("\nenter new qs\n");
    int last = nums[0];
    bool sorted = true;
    for(int i = 0; i < numsSize; i++){
        printf("%d, ", nums[i]);
        
        
        if(last > nums[i])
            sorted = false;

        
        last = nums[i];

    }

    if (sorted)
        return nums;


    printf("\n%d - %d = %d", lEl, fEl, lEl - fEl);
    if((lEl - fEl) <= 1){
        return nums;
    }

    int middle = (lEl - fEl) / 2;
    int m_element = nums[middle];

    int i = fEl;
    int j = lEl - 1;

    while(i < j){
        while((nums[i] < m_element)){
            printf("\n%d < %d", nums[i], m_element);
            i++;
        }

        while(nums[j] > m_element){
            printf("\n%d > %d", nums[j], m_element);
            j--;

        }

        if(i > j)
            break;

        int temp = nums[i];
        printf("\nswitching: %d n %d", nums[i], nums[j]);
        nums[i] = nums[j];
        nums[j] = temp;
        
        


        
    }

    quickSort(nums, numsSize, fEl, j);
    quickSort(nums, numsSize, i, lEl);

    return nums;
}

char* largestNumber(int* nums, int numsSize) {
    int* res = quickSort(nums, numsSize, 0, numsSize);

    char* str = malloc(sizeof(char) * 100 * 999);

    str = "";

    for(int i = 0; i < numsSize; i++){
        printf("\n%d", nums[i]);

        strcat(str, ("%d", nums[i]));


    }
    
    return str;
}
