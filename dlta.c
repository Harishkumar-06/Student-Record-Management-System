#include "head.h"

void stud_dlta()
{
    st *ptr;

    if(hptr==0)
    {
        pf("\nNO RECORDS FOUND\n");
        return;
    }

    while(hptr)
    {
        ptr=hptr;

        hptr=hptr->next;

        free(ptr);
    }

    temp=0;

    pf("\nALL RECORDS DELETED SUCCESSFULLY\n");
}
