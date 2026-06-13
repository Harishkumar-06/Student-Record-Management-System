#include "head.h"

void stud_dlt()
{
    char op;

    pf("\n\n\n");
    pf("\t\t\t|----------------------------------|\n");
    pf("\t\t\t|     R/r : DELETE BY ROLL NO.     |\n");
    pf("\t\t\t|     N/n : DELETE BY NAME         |\n");
    pf("\t\t\t|----------------------------------|\n");
    pf("\n\n\n");

    pf("\nENTER YOUR CHOICE: ");
    sf(" %c",&op);

    if(op=='r'||op=='R')
    {
	system("clear");
        del_roll();
    }
    else if(op=='n'||op=='N')
    {
	system("clear");
        del_name();
    }
    else
        pf("\nINVALID OPTION\n");
}

void del_roll()
{
    int roll;

    if(hptr==0)
    {
        pf("\nNO RECORDS FOUND\n");
        return;
    }

    pf("\nENTER THE ROLL NO TO DELETE : ");
    sf("%d",&roll);

    ptr=hptr;
    prev=0;

    while(ptr)
    {
        if(ptr->roll==roll)
        {
            if(ptr==hptr)      // first node
            {
                hptr=hptr->next;

                if(ptr==temp)
                    temp=hptr;
            }
            else
            {
                prev->next=ptr->next;

                if(ptr==temp)
                    temp=prev;
            }

            free(ptr);

            pf("\nRECORD DELETED SUCCESSFULLY\n");
            return;
        }

        prev=ptr;
        ptr=ptr->next;
    }

    pf("\nRECORD NOT FOUND\n");
}

void del_name()
{
    char name[50];

    if(hptr==0)
    {
        pf("\nNO RECORDS FOUND\n");
        return;
    }

    pf("\nENTER THE NAME TO DELETE : ");
    sf("%s",name);

    pf("\n\n\n");
    pf("\t\t\tMATCHING RECORDS\n");
    pf("\t\t\t+------+----------------+------------+\n");
    pf("\t\t\t|ROLL  |NAME            |PERCENTAGE  |\n");
    pf("\t\t\t+------+----------------+------------+\n");

    st *ptr=hptr;
    int found=0;

    while(ptr)
    {
        if(strcmp(ptr->name,name)==0)
        {
            found=1;

            pf("\t\t\t|%-6d|%-16s|%-12.2f|\n",
               ptr->roll,
               ptr->name,
               ptr->percent);
        }

        ptr=ptr->next;
    }

    pf("\t\t\t+------+----------------+------------+\n");
    pf("\n\n\n");

    if(found==0)
    {
        pf("\nNAME NOT FOUND\n");
        return;
    }


    del_roll();
}
