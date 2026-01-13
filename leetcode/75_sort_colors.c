void quickSort(int * arr, int fEl, int lEl){
    int i, j, mid;
    i = fEl;
    j = lEl;

    mid = arr[(fEl + lEl) / 2];
    printf("%d\n", (fEl + lEl) / 2);

    do{
        while(arr[i] < mid){
            i++;
        }

        while(arr[j] > mid){
            printf("\narr[j] = %d\nmid = %d\n", arr[j], mid);
            j--;
        }
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
        
    }while(i <= j);
    if (fEl < j)
        quickSort(arr, fEl, j);

    if(i < lEl)
        quickSort(arr, i, lEl);
}

void sortColors(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
}

