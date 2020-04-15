//
//  main.c
//  4.15作业
//
//  Created by EDZ on 2020/4/15.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct Tree {
    int value;
    struct Tree* left;
    struct Tree* right;
}Tree_node;

static Tree_node *root;//根节点做全局静态变量

void create_tree() { //初始化树
    root = NULL;
}

Tree_node* insert(Tree_node *node,int value) {
    if(node == NULL){
        node = (Tree_node*)malloc(sizeof(Tree_node));
        node -> value = value;
        node -> left = NULL;
        node -> right = NULL;
        if(root == NULL)
            root = node;
    }
    else{
        if (value < node -> value) {
            node -> left = insert(node->left, value);
        }
        else{
            node -> right = insert(node->right, value);
        }
    }
    return node;
  }
   
//显示树中所有内容
void show_all(Tree_node *node) {
    if(node != NULL)
    {
        if(node->left != NULL)
            show_all(node->left);
        printf("%d ",node->value);
        if(node->right != NULL);
            show_all(node->right);
    }
}

int main() {
        create_tree();//初始化
        int list[size] = {8,4,11,2,6,10,13,7,3,5};//插入
        int i;
        for(i = 0; i < size; i++)
            insert(root,list[i]);
        show_all(root);//显示全部
        putchar('\n');
        return 0;
    }
    

