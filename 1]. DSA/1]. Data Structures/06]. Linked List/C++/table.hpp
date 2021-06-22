#ifndef TABLE_H_
#define TABLE_H_
#include<cstdio>
#include<cstdlib>
#include<cstdarg>

typedef struct node node;
typedef struct node* ptr_node;

#define MAKENODE\
    ((ptr_node)malloc(sizeof(node)));

#define TYPE int

#define TYPEINIT(lhs,param)\
    lhs = ((TYPE*)malloc(sizeof(TYPE)));\
    *lhs=param

#define CONS(car,cdr) _Generic((car),TYPE:cons,\
                        ptr_node:cons_ptr)(car,cdr)

typedef enum {PTR_TYPE,DATA_TYPE} TYPESELECT;
typedef enum {DATA,LIST} data_type;

struct node {
    data_type type;
    union {
        TYPE* d;
        ptr_node d_node;
    } data;
    struct node* next;
};
void display_generic_list(ptr_node list);
void  displaylist (ptr_node list) {

    printf("(");
    while(list) {
        if(list->type==DATA)
            printf("%d,",*(list->data.d));
        if(list->type==LIST) {
            displaylist(list->data.d_node);
        }
        list=list->next;
    }
    printf(")");
}
ptr_node cons(TYPE inserted,ptr_node next) {
    ptr_node n = MAKENODE;
    n->next=NULL;
    n->type=DATA;
    TYPEINIT(n->data.d,inserted);
    n->next = next;
    return n;
}
ptr_node cons_ptr(ptr_node n,ptr_node next) {
    ptr_node res = MAKENODE;
    res->type = LIST;
    res->data.d_node=n;
    res->next = next;
    return res;
}

ptr_node process_param(va_list* parampkg,int count) {
    if(count>0) {
        int type = va_arg(*parampkg,TYPESELECT);
        if(type==PTR_TYPE) {
            ptr_node n =va_arg(*parampkg,ptr_node);
            return CONS(n,process_param(
                            parampkg,
                            count-1
                        ));
        } else if(type==DATA_TYPE) {
            TYPE n =va_arg(*parampkg,TYPE);
            return CONS(n,process_param(
                            parampkg,
                            count-1
                        ));
        }
    }
    return NULL;
}
ptr_node LIST_(int count,...) {
    va_list param_list;
    va_start(param_list,count);
    ptr_node res = process_param(&param_list,(count-1)*2);
    va_end(param_list);
    return res;
}

void free_cons(ptr_node* phead)
{   while(*phead) {
        if((*phead)->type==LIST)
            free_cons(&((*phead)->data.d_node));
        ptr_node ptr = (*phead)->next;
        ptr_node ptemp = (*phead);
        (*phead)=ptr;
        free(ptemp);
        ptemp=NULL;
    }
}
#endif