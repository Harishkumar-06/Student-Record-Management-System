#include "head.h"

void stud_sort()
{
    char op;

    st *ptr1,*ptr2;

    if(hptr==0)
    {
        pf("\nNO RECORDS FOUND\n");
        return;
    }

    pf("\n\n\n");
    pf("\t\t\t|--------------------------|\n");
    pf("\t\t\t|         SORT MENU        |\n");
    pf("\t\t\t|--------------------------|\n");
    pf("\t\t\t|     P/p : PERCENTAGE     |\n");
    pf("\t\t\t|     N/n : NAME           |\n");
    pf("\t\t\t|--------------------------|\n");
    pf("\n\n\n");

    pf("\nENTER YOUR CHOICE : ");

    sf(" %c",&op);

    if(op=='n'||op=='N')
    {
        ptr1=hptr;

        while(ptr1)
        {
            ptr2=ptr1->next;

            while(ptr2)
            {
                if(strcmp(ptr1->name,ptr2->name)>0)
                {
                    int roll;
                    char name[50];
                    float per;

                    roll=ptr1->roll;
                    strcpy(name,ptr1->name);
                    per=ptr1->percent;

                    ptr1->roll=ptr2->roll;
                    strcpy(ptr1->name,ptr2->name);
                    ptr1->percent=ptr2->percent;

                    ptr2->roll=roll;
                    strcpy(ptr2->name,name);
                    ptr2->percent=per;
                }

                ptr2=ptr2->next;
            }

            ptr1=ptr1->next;
        }

        pf("\nSORTED BY NAME SUCCESSFULLY!\n");
    }

    else if(op=='p'||op=='P')
    {
        ptr1=hptr;

        while(ptr1)
        {
            ptr2=ptr1->next;

            while(ptr2)
            {
                if(ptr1->percent > ptr2->percent)
                {
                    int roll;
                    char name[50];
                    float per;

                    roll=ptr1->roll;
                    strcpy(name,ptr1->name);
                    per=ptr1->percent;

                    ptr1->roll=ptr2->roll;
                    strcpy(ptr1->name,ptr2->name);
                    ptr1->percent=ptr2->percent;

                    ptr2->roll=roll;
                    strcpy(ptr2->name,name);
                    ptr2->percent=per;
                }

                ptr2=ptr2->next;
            }

            ptr1=ptr1->next;
        }

        pf("\nSORTED BY PERCENTAGE SUCCESSFULLY!\n");
    }

    else
    {
        pf("\nINVALID OPTION\n");
    }
}
