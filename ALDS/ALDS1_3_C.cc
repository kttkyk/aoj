#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


struct node {
    int v;
    node *next;
    node *prev;
};


node *nil;


void init(void)
{
    nil = (node *)malloc(sizeof(node));
    nil->next = nil;
    nil->prev = nil;
}


void insert_node(int v)
{
    node *p = (node *)malloc(sizeof(node));
    p->v = v;

    nil->next->prev = p;
    p->next = nil->next;
    nil->next = p;
    p->prev = nil;
}


void delete_node(int v)
{
    node *p = nil->next;
    while (p->v != v && p != nil)
        p = p->next;
    if (p == nil)
        return;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
}


void delete_first(void)
{
    node *p = nil->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}


void delete_last(void)
{
    node *p = nil->prev;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}


int main(void)
{
    int n;
    init();
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        char str[100];
        fgets(str, 100, stdin);
        if (str[0] == 'i') {
            insert_node(atoi(&str[7]));
        } else if (str[0] == 'd' && str[6] == 'F') {
            delete_first();
        } else if (str[0] == 'd' && str[6] == 'L') {
            delete_last();
        } else if (str[0] == 'd') {
            delete_node(atoi(&str[7]));
        }
    }

    node *p = nil->next;
    while(p->next != nil) {
        printf("%d ", p->v);
        p = p->next;
    }
    printf("%d\n", p->v);
}
