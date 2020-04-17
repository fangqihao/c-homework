//
//  main.c
//  实现atof函数
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double my_atof(char *nptr){
    double s = 0.0;
    double d = 10.0;
    
    while(*nptr == '\0'){
        nptr++;
    }

    if((*nptr>='0' && *nptr<='9') || *nptr=='.'){
        while(*nptr>='0' && *nptr<='9'){ //当开始是数字进入整数部分的转化
            s = 10*s+*nptr-'0';
            nptr++;
        }

        if(*nptr == '.'){
            nptr++;
            while(*nptr>='0' && *nptr<='9'){ //进行小数部分的转换
                s = s+(*nptr-'0')/d;
                d *= 10;
                nptr++;
            }
        }
        return s;
    }else
        return 0;
}

    int main() {
        printf("%f\n", my_atof("0.123"));
        printf("%f\n", my_atof(".123"));
        printf("%f\n", my_atof("16.4"));
        printf("%f\n", my_atof("16."));
        printf("%f\n", my_atof("0.0"));
        printf("%f\n", my_atof("0."));
        return 0;
    }



