#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char buff[255];
    char a[20],b[20],c[20],d[5],e[10];
    int i=0,j=0,k=0;;


    fp = fopen("students.csv", "r");
    while(fscanf(fp, "%s", buff) > 0)
    {
        j=0;k=0;i=0;
        while(*(buff+i) != 0)
        {
            if(buff[i] == ';')
            {
                j++;
                k=0;
            }
            else{
                if(j==0)
                {
                 a[k] = buff[i];
                 if(buff[i+1]== ';')
                    a[k+1]='\0';
                }
               if(j==1)
                {
                 b[k] = buff[i];
                 if(buff[i+1]== ';')
                    b[k+1]='\0';
                }
                if(j==2)
                {
                 c[k] = buff[i];
                 if(buff[i+1]== ';')
                    c[k+1]='\0';
                }
                if(j==3)
                {
                 d[k] = buff[i];
                 if(buff[i+1]== ';')
                    d[k+1]='\0';
                }
                 if(j==4)
                {
                 e[k] = buff[i];
                 if(buff[i+1]== 0)
                    e[k+1]='\0';
                }
                k++;
            }
            i++;
        }

        if(strcmp(e,"Cluj") == 0 && atof(d) > 8.00)
        {
            printf("%s %s\n",a,b);
        }
    }
	return 0;
}
