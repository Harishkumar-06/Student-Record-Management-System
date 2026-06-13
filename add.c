#include"head.h"

void stud_add()
{
        node=(st*)malloc(sizeof(st));
	if(node == NULL)
	{
    	printf("Memory Allocation Failed\n");
    	return;
	}
	node->roll=get_roll();
        pf("\nENTER THE NAME: ");
        sf("%s",node->name);
        pf("\nENTER THE PERCENTAGE: ");
        sf("%f",&node->percent);
        pf("\n");
	node->next=0;
	if(hptr==0)
		hptr=temp=node;
	else
	{
		temp->next=node;
		temp=node;
	}
}

int get_roll()
{
    int n = 1;
    st *ptr = hptr;

    while(ptr)
    {
        if(ptr->roll == n)
            n++;

        ptr = ptr->next;
    }

    return n;
}

