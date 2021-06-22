#ifndef ASSIGNSCORE_H
#define ASSIGNSCORE_H
#include "object.h"

void  assignscore(highscore hscore[5])
{

    FILE* fptr;
    fptr=fopen("highscorename.txt","r");

    char c;
    int i=0,k=0,j;

	for (c = getc(fptr); c != EOF; c = getc(fptr))
	{
		
		if(c == '\n') // Increment count if this character is newline
        {

        	hscore[i].name[k]='\n';
        	k++;
        	hscore[i].name[k]='\0';
        	i++;
        	k=0;

        }
        else
        {
        	hscore[i].name[k]=c;
        	k++;
        }

	}

	fclose(fptr);
	fptr=fopen("highscorenumbers.txt","r");
	fscanf(fptr, "%d", &hscore[0].score);
    fscanf(fptr, "%d", &hscore[1].score);
    fscanf(fptr, "%d", &hscore[2].score);
    fscanf(fptr, "%d", &hscore[3].score);
    fscanf(fptr, "%d", &hscore[4].score);


    fclose(fptr);



       


}
#endif