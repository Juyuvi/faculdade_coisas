void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *res = malloc(nums1Size * sizeof(int));

    int i, j, k;
    i = j = k = 0;

    while( k < nums1Size ){
        if ( i < m && j < n ){
            if( nums1[ i ] <= nums2[ j ] ){
                res[k++] = nums1[ i++ ];
            } else{
                res[k++] = nums2[ j++ ];
            }
        }

        else if( i < m ){
            res[k++] = nums1[ i++ ];
        }
        else if( j < n ){
            res[k++] = nums2[ j++ ];
        }
    }

    for (int i = 0; i < nums1Size; i++)
        nums1[ i ] = res [ i ];
        

    free(res);

    
}
