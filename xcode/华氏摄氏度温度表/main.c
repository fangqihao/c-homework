//
//  main.c
//  3.27上午作业1
//
//  Created by EDZ on 2020/3/27.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    printf("  F      C\n");
    int f,c;
    for (f = 40 ; f <= 240; f = f + 20) {
        c  = 5*(f -32)/9;
        printf("%3d    %3d\n",f ,c);
    }
    f = 300;    
    printf("%3d    %3d\n",f ,c  = 5*(f -32)/9);
    return 0;
}
