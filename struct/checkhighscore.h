#ifndef CHECKHIGHSCORE_H
#define CHECKHIGHSCORE_H
#include "object.h"

void  checkhighscore(char name[],int count,highscore hscore[3])
{
	//cout<<name<<" "<<hscore[0].name<<" "<<hscore[1].name<<" "<<hscore[2].name<<endl;
	if(count>hscore[0].score)//new highest score
	{
		FILE* fptr;
     	FILE* fptr2;
     	fptr=fopen("highscorename.txt","w");
     	fptr2=fopen("highscorenumbers.txt","w");
		

		//writing changed names and scores
		fputs(name,fptr);
		fputs(hscore[0].name,fptr);
		fputs(hscore[1].name,fptr);
		fputs(hscore[2].name,fptr);
		fputs(hscore[3].name,fptr);


		fprintf(fptr2, "%d\n", count);
        fprintf(fptr2, "%d\n", hscore[0].score);
        fprintf(fptr2, "%d\n", hscore[1].score);
        fprintf(fptr2, "%d\n", hscore[2].score);
        fprintf(fptr2, "%d\n", hscore[3].score);

       //assigning the names and scores
        strcpy(hscore[4].name,hscore[3].name);
        strcpy(hscore[3].name,hscore[2].name);
        strcpy(hscore[2].name,hscore[1].name);
        strcpy(hscore[1].name,hscore[0].name);
        strcpy(hscore[0].name,name);


        hscore[4].score=hscore[3].score;
        hscore[3].score=hscore[2].score;
        hscore[2].score=hscore[1].score;
        hscore[1].score=hscore[0].score;
        hscore[0].score=count;




		fclose(fptr);
		fclose(fptr2);


	}

	else if(count<=hscore[0].score && count>hscore[1].score)//new 2nd highest score
	{

		FILE* fptr;
     	FILE* fptr2;
     	fptr=fopen("highscorename.txt","w");
     	fptr2=fopen("highscorenumbers.txt","w");
		
		//writing changed names and scores
		fputs(hscore[0].name,fptr);
		fputs(name,fptr);
		fputs(hscore[1].name,fptr);
		fputs(hscore[2].name,fptr);
		fputs(hscore[3].name,fptr);

		fprintf(fptr2, "%d\n", hscore[0].score);
        fprintf(fptr2, "%d\n", count);
        fprintf(fptr2, "%d\n", hscore[1].score);
        fprintf(fptr2, "%d\n", hscore[2].score);
        fprintf(fptr2, "%d\n", hscore[3].score);


        //assigning the names and scores
        strcpy(hscore[4].name,hscore[3].name);
        strcpy(hscore[3].name,hscore[2].name);
        strcpy(hscore[2].name,hscore[1].name);
        strcpy(hscore[1].name,name);
        

        hscore[4].score=hscore[3].score;
        hscore[3].score=hscore[2].score;
        hscore[2].score=hscore[1].score;
        hscore[1].score=count;
        


		fclose(fptr);
		fclose(fptr2);

	}

	else if(count<=hscore[0].score && count<=hscore[1].score && count>hscore[2].score)//3rd highest score
	{

		FILE* fptr;
     	FILE* fptr2;
     	fptr=fopen("highscorename.txt","w");
     	fptr2=fopen("highscorenumbers.txt","w");
     	//writing changed names and scores
		
		fputs(hscore[0].name,fptr);
		fputs(hscore[1].name,fptr);
		fputs(name,fptr);
		fputs(hscore[2].name,fptr);
		fputs(hscore[3].name,fptr);




		fprintf(fptr2, "%d\n", hscore[0].score);
        fprintf(fptr2, "%d\n", hscore[1].score);
        fprintf(fptr2, "%d\n", count);
        fprintf(fptr2, "%d\n", hscore[2].score);
        fprintf(fptr2, "%d\n", hscore[3].score);



        //assigning the names and scores
        strcpy(hscore[4].name,hscore[3].name);
        strcpy(hscore[3].name,hscore[2].name);
        strcpy(hscore[2].name,name);
        
        hscore[4].score=hscore[3].score;
        hscore[3].score=hscore[2].score;
        hscore[2].score=count;
       


		fclose(fptr);
		fclose(fptr2);


	}


	else if(count<=hscore[0].score && count<=hscore[1].score && count<=hscore[2].score && count>hscore[3].score)//4th highest score
	{

		FILE* fptr;
     	FILE* fptr2;
     	fptr=fopen("highscorename.txt","w");
     	fptr2=fopen("highscorenumbers.txt","w");

     	//writing changed names and scores
		
		fputs(hscore[0].name,fptr);
		fputs(hscore[1].name,fptr);
		fputs(hscore[2].name,fptr);
		fputs(name,fptr);
		fputs(hscore[3].name,fptr);




		fprintf(fptr2, "%d\n", hscore[0].score);
        fprintf(fptr2, "%d\n", hscore[1].score);
        fprintf(fptr2, "%d\n", hscore[2].score);
        fprintf(fptr2, "%d\n", count);
        fprintf(fptr2, "%d\n", hscore[3].score);


        //assigning the names and scores

        strcpy(hscore[4].name,hscore[3].name);
        strcpy(hscore[3].name,name);
        
        
        hscore[4].score=hscore[3].score;
        hscore[3].score=count;
       


		fclose(fptr);
		fclose(fptr2);


	}

	else if(count<=hscore[0].score && count<=hscore[1].score && count<=hscore[2].score && count<=hscore[3].score && count>hscore[4].score)//5th highest score
	{

		FILE* fptr;
     	FILE* fptr2;
     	fptr=fopen("highscorename.txt","w");
     	fptr2=fopen("highscorenumbers.txt","w");

     	//writing changed names and scores
		
		fputs(hscore[0].name,fptr);
		fputs(hscore[1].name,fptr);
		fputs(hscore[2].name,fptr);
		fputs(hscore[3].name,fptr);
		fputs(name,fptr);


        

		fprintf(fptr2, "%d\n", hscore[0].score);
        fprintf(fptr2, "%d\n", hscore[1].score);
        fprintf(fptr2, "%d\n", hscore[2].score);
        fprintf(fptr2, "%d\n", hscore[3].score);
        fprintf(fptr2, "%d\n", count);



        //assigning the names and scores
        strcpy(hscore[4].name,name);
      
        
        hscore[4].score=count;
        
       


		fclose(fptr);
		fclose(fptr2);


	}

}
#endif