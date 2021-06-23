#ifndef FILEINI_H
#define FILEINI_H

void  fileini()
{
	FILE* fptr;
	FILE* fptr2;

	

	char name[80];
	int score;


	int n=5,j,k;

	fptr=fopen("highscorename.txt","r");
	fptr2=fopen("highscorenumbers.txt","r");


	if(fptr==NULL && fptr2==NULL)
	{

		fptr=fopen("highscorename.txt","w");
     	fptr2=fopen("highscorenumbers.txt","w");
		for(int i=0;i<n;i=i+1)
		{
			fgets(name,sizeof(name),stdin);
			fputs(name,fptr);
			scanf("%d",&score);
			getchar();
			fprintf(fptr2,"%d\n",score);

		}

	}

	
    fclose (fptr);
    fclose(fptr2);
    


}
#endif