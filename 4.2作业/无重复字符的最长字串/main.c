//
//  main.c
//  4.2作业
//
//  Created by EDZ on 2020/4/2.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int duplicate(char* s, int n){
    for (int i = 0; i < n; i++) {
        if (s[i] == s[n]) {
            return 1;
        }
    }
    return 0;
}

int find_max_substring(char * s) {
    int i;
    int len = (int)strlen(s);
    if (len == 1)
        return 1;
    for (i = 1 ;i < len ;i++){
        if (duplicate(s ,i)) {
            break;
        }
    }
    return i;
}

int lengthOfLongestSubstring(char * s){
    int max = 0;
    unsigned int n = (unsigned int)strlen(s);
    for (int i = 0; i < n ; i++) {
        //从s+i(还是一个字符串)开始找不重复的字串，返回长度
        int current_len = find_max_substring(s + i);
        //用这个字串的长度和max比较，更新max的值
        if (current_len > max ) {
            max = current_len;
        }
    }
    return max;
}

int main() {
    char * s = malloc(100);
    while (1) {
        printf("input string:");
        scanf("%s",s);
        printf("max is %d\n",lengthOfLongestSubstring(s));
    }
    return 0;
}
