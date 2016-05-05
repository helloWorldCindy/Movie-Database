#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#define BUFFERSIZE 100

int main()//the main function is for testing
{
	
	Movie *new,*delete;
	char str1[MAX_STR_SIZE];
	char str2[MAX_STR_SIZE];
	char str3[MAX_STR_SIZE];
	char str4[MAX_STR_SIZE];
	enum MovieGenre genre;
	int choice,year,castNum,i,genreChoice;

	DblList *movie=malloc(sizeof(DblList));//allocate and initialize the list
	dl_init(movie);
	

	while(1)
	{

	//ask the user what does he want to do 
	printf("What do you want to do ?\n");
	printf("1.add a movie\n");
	printf("2.delete a movie\n");
	printf("3.print all movies forward\n");
	printf("4.print all movies backward\n");
	printf("5.print movies by genre\n");
	printf("6.Exit\n");
	scanf("%d",&choice);
	clearTheLine();
	switch(choice)
	{
	case 1://when the user chose to add a movie
	
	//ask about title, year,genre, actor and actress to initialize a movie
	printf("Enter a title:\n");
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1)-1]='\0';
	printf("Enter a year\n");
	scanf("%d",&year);
	clearTheLine();
	
	while(year<0)
	{
	printf("Enter a valid year\n");
	scanf("%d",&year);
	clearTheLine();
	}

	printf("Choose a genre\n");
	
	printf("Comedy---1\n");
	printf("Drama----2\n");
	printf("Action---3\n");
	printf("Horror---4\n");
	printf("Romantic-5\n");
	scanf("%d",&genreChoice);
	clearTheLine();
	while(genreChoice<=0||genreChoice>5)
	{printf("please enter valid number\n");
	scanf("%d",&genreChoice);
	clearTheLine();
	}
	if(genreChoice>0&&genreChoice<=5)
	{switch(genreChoice)
	{
	case 1:
	{
	genre=comedy;
	break;
	}
	case 2:
	{
	genre=drama;
	break;
	}
	case 3:
	{
	genre=action;
	break;
	}
	case 4:
	{
	genre=horror;
	break;
	}
	case 5:
	{
	genre=romantic;
	break;
	}
	default:
	break;
	}
	}
	
	
	printf("main actor:");
	fgets(str2,BUFFERSIZE,stdin);
	str2[strlen(str2)-1]='\0';
	printf("main actress:");
	fgets(str4,BUFFERSIZE,stdin);
	str4[strlen(str4)-1]='\0';
	
	initMovie(str1,year,str2,str4,genre,&new);
	dl_add(movie,new);
	
	
	break;
	

	case 2://when user chose to delete a movie
	
	
	printf("Enter a title :");//ask him to enter a title
	fgets(str3,BUFFERSIZE,stdin);
	str3[strlen(str3)-1]='\0';
	initMovie(str3,0,"null","null",comedy,&delete);
	dl_del(movie,delete);//found if there is a movie with the same title
	
	free(delete);
	break;
	
	

	case 3:
	//when user chose to print the list forward
	 dl_printFwd(movie);
	break;
	
	case 4:
	//when user chose to print the list backward
	dl_printBack(movie);
	break;
	
	case 5:
 	//when user chose to print by genre
	printf("Choose a genre\n");
	
	printf("Comedy---1\n");
	printf("Drama----2\n");
	printf("Action---3\n");
	printf("Horror---4\n");
	printf("Romantic-5\n");
	scanf("%d",&genreChoice);
	clearTheLine();
	if(genreChoice>0&&genreChoice<=5)
	{switch(genreChoice)
	{
	case 1:
	{
	genre=comedy;
	break;
	}
	case 2:
	{
	genre=drama;
	break;
	}
	case 3:
	{
	genre=action;
	break;
	}
	case 4:
	{
	genre=horror;
	break;
	}
	case 5:
	{
	genre=romantic;
	break;
	}
	}
	}
	else
	{
	printf("please enter valid number");
	}
	dl_printByGenre(movie,genre);
	break;
	case 6://when the user chose to quit, clean up all the allocated memory
	dl_cleanup(movie);
	free(movie);
	return C_NOK;
	break;
	
	}

	
	
	}



return 0;
}

