#include "head.h"

void stud_mod()
{
    char op;

    if(hptr==0)
    {
        pf("\nNO RECORDS FOUND\n");
        return;
    }

    pf("\n\n\n");
    pf("\t\t\t|------------------------------------|\n");
    pf("\t\t\t|     R/r : SEARCH BY ROLL NO.       |\n");
    pf("\t\t\t|     N/n : SEARCH BY NAME           |\n");
    pf("\t\t\t|     P/p : SEARCH BY PERCENTAGE     |\n");
    pf("\t\t\t|------------------------------------|\n");
    pf("\n\n\n");

    pf("\nENTER YOUR CHOICE: ");

    sf(" %c",&op);

    if(op=='r'||op=='R')
    {
        int roll;
        st *ptr=hptr;

        pf("\nENTER ROLL NO : ");
        sf("%d",&roll);

        while(ptr)
        {
            if(ptr->roll==roll)
            {
                char ch;
	    
		pf("\n\n\n");
		pf("\t\t\t|----------------------------------|\n");
		pf("\t\t\t|   ENTER WHICH RECORD TO MODIFY   |\n");
	    	pf("\t\t\t|----------------------------------|\n");
    		pf("\t\t\t|         P/p : PERCENTAGE         |\n");
    		pf("\t\t\t|         N/n : NAME               |\n");
    		pf("\t\t\t|----------------------------------|\n");
    		pf("\n\n\n");

                pf("\nENTER YOUR CHOICE: ");

                sf(" %c",&ch);

                if(ch=='n'||ch=='N')
                {
                    pf("\nENTER NEW NAME : ");
                    sf("%s",ptr->name);
                }
                else if(ch=='p'||ch=='P')
                {
                    pf("\nENTER NEW PERCENTAGE : ");
                    sf("%f",&ptr->percent);
                }

                pf("\nRECORD MODIFIED SUCCESSFULLY!\n");
                return;
            }

            ptr=ptr->next;
        }

        pf("\nROLL NO NOT FOUND\n");
    }

    else if(op=='n'||op=='N')
    {
        char name[50];
        int roll;
        st *ptr=hptr;

        pf("\nENTER NAME : ");
        sf("%s",name);

        pf("\nMATCHING RECORDS\n");

        while(ptr)
        {
            if(strcmp(ptr->name,name)==0)
            {
                pf("%d\t%s\t%.2f\n",
                   ptr->roll,
                   ptr->name,
                   ptr->percent);
            }

            ptr=ptr->next;
        }

        pf("\nENTER ROLL NO TO MODIFY : ");
        sf("%d",&roll);

        ptr=hptr;

        while(ptr)
        {
            if(ptr->roll==roll)
            {
                char ch;

		pf("\n\n\n");
                pf("\t\t\t|----------------------------------|\n");
                pf("\t\t\t|         P/p : PERCENTAGE         |\n");
                pf("\t\t\t|         N/n : NAME               |\n");
                pf("\t\t\t|----------------------------------|\n");
                pf("\n\n\n");

                pf("\nENTER YOUR CHOICE: ");

                sf(" %c",&ch);

                if(ch=='n'||ch=='N')
                {
                    pf("\nENTER NEW NAME : ");
                    sf("%s",ptr->name);
                }
                else if(ch=='p'||ch=='P')
                {
                    pf("\nENTER NEW PERCENTAGE : ");
                    sf("%f",&ptr->percent);
                }

                pf("\nRECORD MODIFIED SUCCESSFULLY!\n");
                return;
            }

            ptr=ptr->next;
        }

        pf("\nROLL NO NOT FOUND\n");
    }

    else if(op=='p'||op=='P')
    {
        float per;
        int roll;
        st *ptr=hptr;

        pf("\nENTER PERCENTAGE : ");
        sf("%f",&per);

        pf("\nMATCHING RECORDS\n");

        while(ptr)
        {
            if(ptr->percent==per)
            {
                pf("%d\t%s\t%.2f\n",
                   ptr->roll,
                   ptr->name,
                   ptr->percent);
            }

            ptr=ptr->next;
        }

        pf("\nENTER ROLL NO TO MODIFY : ");
        sf("%d",&roll);

        ptr=hptr;

        while(ptr)
        {
            if(ptr->roll==roll)
            {
                char ch;

                pf("\n\n\n");
                pf("\t\t\t|----------------------------------|\n");
                pf("\t\t\t|         P/p : PERCENTAGE         |\n");
                pf("\t\t\t|         N/n : NAME               |\n");
                pf("\t\t\t|----------------------------------|\n");
                pf("\n\n\n");

                pf("\nENTER YOUR CHOICE: ");
                sf(" %c",&ch);

                if(ch=='n'||ch=='N')
                {
                    pf("\nENTER NEW NAME : ");
                    sf("%s",ptr->name);
                }
                else if(ch=='p'||ch=='P')
                {
                    pf("\nENTER NEW PERCENTAGE : ");
                    sf("%f",&ptr->percent);
                }

                pf("\nRECORD MODIFIED SUCCESSFULLY!\n");
                return;
            }

            ptr=ptr->next;
        }

        pf("\nROLL NO NOT FOUND\n");
    }

    else
    {
        pf("\nINVALID OPTION\n");
    }
}
