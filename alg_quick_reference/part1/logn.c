#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dichotomy(int *ary,int ary_size, int target, int *times){
    int low=ary[0];
    int high=ary[ary_size-1];
    int middle;
    int i=0;
    for(i=0;abs(high - low) > 1;i++){
        middle = (low+high)/2;
        if(middle == target){
            *times = i;
            return middle;
        }
        else if(middle < target)low = middle;
        else if(target < middle)high = middle;
    }
    *times = i+1;
    return middle;
}

int main(void){
    int ARY_SIZE = 10000;
    int *ary = calloc(ARY_SIZE, sizeof(int));
    int times;
    for(int index = 0; index< ARY_SIZE; index++)ary[index]=index;
    for(int target = 0; target < ARY_SIZE; target+=10){
        int result = dichotomy(ary, ARY_SIZE, target, &times);
        printf("実行回数: %d\n", times);
        /** 
         * 14回が上限かな。
         * log_2 10000 = 13.28...
        */
    }
    return 0;
}