#include "head.h"

void stud_save()
{
    FILE *fp;
    st *ptr=hptr;

    fp=fopen("student.csv","w");

    if(fp==NULL)
    {
        pf("\nFILE OPEN FAILED\n");
        return;
    }

    fprintf(fp,"ROLLNO,NAME,PERCENTAGE\n");

    while(ptr)
    {
        fprintf(fp,"%d,%s,%.2f\n",
                ptr->roll,
                ptr->name,
                ptr->percent);

        ptr=ptr->next;
    }

    fclose(fp);

    pf("\nRECORDS SAVED SUCCESSFULLY\n");
}

void load_data()
{
    FILE *fp;
    char buf[100];

    fp=fopen("student.csv","r");

    if(fp==NULL)
        return;

    /* Skip Header Line */
    fgets(buf,sizeof(buf),fp);

    while(1)
    {
        node=(st *)malloc(sizeof(st));

        if(fscanf(fp,"%d,%s,%f\n",
                  &node->roll,
                  node->name,
                  &node->percent)!=3)
        {
            free(node);
            break;
        }

        node->next=0;

        if(hptr==0)
            hptr=temp=node;
        else
        {
            temp->next=node;
            temp=node;
        }
    }

    fclose(fp);
}
