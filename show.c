#include "head.h"

void stud_show()
{
    st *ptr = hptr;

    if(hptr == 0)
    {
        pf("NO RECORDS FOUND\n");
        return;
    }

    pf("\n\n\n");
    pf("\t\t\t+------+----------------+------------+\n");
    pf("\t\t\t|ROLL  |NAME            |PERCENTAGE  |\n");
    pf("\t\t\t+------+----------------+------------+\n");

    while(ptr)
	{
    	pf("\t\t\t|%-6d|%-16s|%-12.2f|\n",
        ptr->roll,
        ptr->name,
        ptr->percent);

    	ptr = ptr->next;
	}
    pf("\t\t\t+------+----------------+------------+\n");
    pf("\n\n\n");

}
