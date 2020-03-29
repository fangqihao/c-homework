//
//  main.c
//  素数判断
//
//  Created by EDZ on 2020/3/29.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

int main(void) {
   int a=0;
   int num=0;
   printf("输入一个整数：");
   scanf("%d",&num);
   for(int i=2;i<num;i++){
       if(num%i==0){
           a++;
       }
   }
   if(a==0){
       printf("%d是素数。\n", num);
   }else{
       printf("%d不是素数。\n", num);
   }

    return 0;
}
