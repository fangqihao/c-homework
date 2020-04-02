//
//  main.c
//  只出现一次的数字
//
//  Created by EDZ on 2020/4/2.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int singleNumber(int* nums, int numsSize){
    int count[numsSize];
    for (int i = 0;i < numsSize;i++)
        count[i] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int duplicate = 0;
        if (count[i] == 1){
            continue;
        }
        for (int j = i + 1; j < numsSize; j++) {
            if (count[j] == 1){
                continue;
            }
            if (nums[j] == nums[i]) {
                count[i] = count[j] = 1;
                duplicate = 1;
                break ;
            }
        }
        if (!duplicate)
            return nums[i];
    }
    return -1;
}
