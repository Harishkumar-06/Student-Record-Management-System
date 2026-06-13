#include"head.h"

st*node,*temp,*ptr,*prev,*hptr=0;

int main()
{
	load_data();

menu:
	system("clear");
	pf("\n\n\n");
	pf("\t\t\t|-------------------------------------|\n");
	pf("\t\t\t|                                     |\n");
	pf("\t\t\t|    **** STUDENT RECORD MENU ****    |\n");
	pf("\t\t\t|                                     |\n");
	pf("\t\t\t|       A/a  : ADD NEW RECORD         |\n");
        pf("\t\t\t|       D/d  : DELETE A RECORD        |\n");
	pf("\t\t\t|       S/s  : SHOW THE LIST          |\n");
	pf("\t\t\t|       M/m  : MODIFY A RECORD        |\n");
	pf("\t\t\t|       V/v  : SAVE                   |\n");
	pf("\t\t\t|       E/e  : EXIT                   |\n");
	pf("\t\t\t|       T/t  : SORT THE LIST          |\n");
	pf("\t\t\t|       L/l  : DELETE ALL RECORDS     |\n");
	pf("\t\t\t|       R/r  : REVERSE THE LIST       |\n");
	pf("\t\t\t|                                     |\n");
	pf("\t\t\t|-------------------------------------|\n");
	pf("\n\n\n");

	pf("ENTER THE OPTION: ");
	char op,op1;
	sf(" %c",&op);

	if(op=='a'||op=='A')
	{
    		do
    		{
        		system("clear");
        		stud_add();

        		pf("\nDO YOU NEED TO ADD ANOTHER! [YES(Y/y) or NO(N/n)]: ");
        		sf(" %c",&op1);

    		}while(op1=='y'||op1=='Y');
	}
	else if(op=='d'||op=='D')
        {
		system("clear");
                stud_dlt();
        }
        else if(op=='s'||op=='S')
        {
                system("clear");
                stud_show();
		printf("\nPress Enter to return to menu...");
		getchar();
		getchar();
        }
        else if(op=='m'||op=='M')
        {
		system("clear");
                stud_mod();
        }
        else if(op=='v'||op=='V')
        {
		system("clear");
                stud_save();
        }
        else if(op=='e'||op=='E')
        {
		system("clear");
		stud_save();
                stud_exit();
        }
        else if(op=='t'||op=='T')
        {
		system("clear");
                stud_sort();
        }
        else if(op=='l'||op=='L')
        {
		system("clear");
                stud_dlta();
        }
        else if(op=='r'||op=='R')
        {
		system("clear");
                stud_rev();
        }
	else
	{
		pf("WRONG INPUT!\n");
		sleep(1);
		pf("RETRY...\n");
		sleep(1);
	}

	sleep(1);

	system("clear");
	goto menu;
}
