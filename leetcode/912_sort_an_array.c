/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* merge(int* left, int leftSize, int* right, int rightSize){
    int i = 0, j = 0, k = 0;
    int* res = malloc((leftSize + rightSize) * sizeof(int));

    while(k < leftSize + rightSize){
        while(i < leftSize && j < rightSize){
            if(left[i] < right[j]){
                res[k++] = left[i++];
            }
            else{
                res[k++] = right[j++];
            }
            //printf("\nRes[k]: %d", res[k]);
        }

        if(i < leftSize){
            res[k++] = left[i++];
        }

        if(j < rightSize){
            res[k++] = right[j++];
        }

        //printf("\nRes[k]: %d", res[k - 1]);


    }



    return res;

 }


int* sortArray(int* nums, int numsSize, int* returnSize) {

    if (numsSize <= 1){
        //printf("\nnumsSize: %d", numsSize);
        *returnSize = numsSize;
        return nums;
    }
    
    
    int half = numsSize / 2;
    int otherHalf = numsSize - half;

    int* p_half = nums + half;

    int returnSizeLeft = 0;
    int returnSizeRight = 0;


    int* left = sortArray(nums, half, &returnSizeLeft);
    int* right = sortArray(p_half, otherHalf, &returnSizeRight);

    int* res = merge(left, returnSizeLeft, right, returnSizeRight);

    *returnSize = numsSize;
    return res;

}
