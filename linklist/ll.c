#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct test_struct
{
    int val;
    struct test_struct *next;
};

struct test_struct *head = NULL;
struct test_struct *curr = NULL;

struct test_struct* create_list(int val) 
{
    printf("\n creating list with headnode as [%d]\n", val);
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if (NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

struct test_struct* add_to_list(int val, bool add_to_end)
{
    if(NULL == head)
    {
        return (create_list(val));
    }

    if(add_to_end)
    {
        printf("\n Adding node to end of list with value [%d]\n", val);
    } 
    else 
    {
        printf("\n Adding node to beginning of list with value [%d]\n", val);
    }

    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if (NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

struct test_struct* search_in_list(int val, struct test_struct **prev)
{
    struct test_struct *ptr = head;
    struct test_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n", val);

    while (ptr != NULL)
    {
        if (ptr->val == val)
        {
            found = true;
            break;
        }
        else 
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
        {
            *prev = tmp;
        }
        return ptr;
    }
    else
    {
        return NULL;
    }
    
}