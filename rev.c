#include "head.h"

void stud_rev()
{
    st *prev = 0;
    st *cur = hptr;
    st *next = 0;

    if(hptr == 0)
    {
        pf("\nNO RECORDS FOUND\n");
        return;
    }

    temp = hptr;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    hptr = prev;

    pf("\nLIST REVERSED SUCCESSFULLY\n");
}
