#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"
void dl_init(DblList *dlist){
	dlist->head=NULL;
	dlist->tail=NULL;
}
void dl_add(DblList *dlist, Movie *newMovie){//adding a movie 
	MovieNode *currNode;
	MovieNode *prevNode;
	MovieNode *newNode;

	newNode=malloc(sizeof(MovieNode));
	newNode->data=newMovie;
	newNode->prev=NULL;
	newNode->next=NULL;
	currNode=dlist->head;
	prevNode=NULL;
	while(currNode!=NULL)
	{
	if(strcmp(currNode->data->title,newNode->data->title)>=0)//put the movie in alphabetical order
	{
	break;
	}
	prevNode=currNode;
	currNode=currNode->next;
	
        
	}

	if(prevNode==NULL)//if by the alphabetical order, the node should put at the head, then change the head to the new node
	{
	dlist->head=newNode;
	}
	else
	{
	prevNode->next=newNode;
	}
	newNode->prev=prevNode;
	newNode->next=currNode;
	if(currNode!=NULL)
	{
	currNode->prev=newNode;
	}

	if(newNode->next==NULL)
	{
	dlist->tail=newNode;
	}
	
	
	

}
void dl_del(DblList *dlist, Movie *newMovie)
{
	MovieNode *currNode=dlist->head;
	MovieNode *prevNode=NULL;
	
	if(currNode==NULL)//if the list is empty
	{
	printf("Empty List\n");
	}
	else{
	while(currNode!=NULL)
	{
	if(strcmp(currNode->data->title,newMovie->title)==0)//find the movie with the same title
	{
	break;
	}
	prevNode=currNode;
	currNode=currNode->next;
	}
	if(currNode==NULL)//if the movie is not found
	{
	printf("NOT FOUND");
	}
	else{
	if(prevNode==NULL)
	{
	dlist->head=currNode->next;
	
	}
	else
	{
	prevNode->next=currNode->next;
	}
	if(currNode->next!=NULL)
	{
	currNode->next->prev=prevNode;
	}
	else
	{
	dlist->tail=prevNode;
	}
	//free the memory
	free(currNode->data);
	free(currNode);
	}
	}
	
	
}
void dl_printFwd(DblList *dlist)
	{
	MovieNode *currNode=dlist->head;

	
	
	char tmp[MAX_STR_SIZE];
	
	while(currNode!=NULL)
	{
	printf("Movie Title: %s\n",currNode->data->title);
	printf("Movie Year: %d\n",currNode->data->year);
	switch(currNode->data->genre)//for print out the genre
	{
	case 1:
	{
	strcpy(tmp,"Comedy");
	break;
	}
	case 2:
	{
	strcpy(tmp,"Drama");
	break;
	}
	case 3:
	{
	strcpy(tmp,"Action");
	break;
	}
	case 4:
	{
	strcpy(tmp,"Horror");
	break;
	}
	case 5:
	{
	strcpy(tmp,"Romantic");
	}
	default:
	 break;
	}
	printf("Movie Genre: %s\n",tmp);
	printf("Main Actor: %s\n",currNode->data->castMember[0]);
	printf("Main Actress: %s\n",currNode->data->castMember[1]);
	
	currNode=currNode->next;
	
	}

	


	}
 void dl_printBack(DblList *dlist)
	{
	MovieNode *currNode=dlist->tail;//print from the tail
	MovieNode *prevNode=NULL;
	int i;
	char tmp[MAX_STR_SIZE];
	while(currNode!=NULL)
	{
	printf("Movie Title: %s\n",currNode->data->title);
	printf("Movie Year: %d\n",currNode->data->year);
	switch(currNode->data->genre)
	{
	case 1:
	{
	strcpy(tmp,"Comedy");
	break;
	}
	case 2:
	{
	strcpy(tmp,"Drama");
	break;
	}
	case 3:
	{
	strcpy(tmp,"Action");
	break;
	}
	case 4:
	{
	strcpy(tmp,"Horror");
	break;
	}
	case 5:
	{
	strcpy(tmp,"Romantic");
	break;
	}
	}
	printf("Movie Genre: %s\n",tmp);
	printf("Main Actor: %s\n",currNode->data->castMember[0]);
	printf("Main Actress: %s\n",currNode->data->castMember[1]);
	currNode=currNode->prev;
	//prevNode=prevNode->prev;
	}

	}
void dl_printByGenre(DblList *dlist, enum MovieGenre genre)
	{
	MovieNode *currNode=dlist->tail;
	int i;
	char tmp[MAX_ARR_SIZE];
	int check=1;
	switch(genre)
	{
	case 1:
	{
	strcpy(tmp,"Comedy");
	break;
	}
	case 2:
	{
	strcpy(tmp,"Drama");
	break;
	}
	case 3:
	{
	strcpy(tmp,"Action");
	break;
	}
	case 4:
	{
	strcpy(tmp,"Horror");
	break;
	}
	case 5:
	{
	strcpy(tmp,"Romantic");
	break;
	}
	default:
	break;
	}
	while(currNode!=NULL)
	{
	if(currNode->data->genre==genre)//find the movie with the same genre
	{
	printf("Movie Title: %s\n",currNode->data->title);
	printf("Movie Year: %d\n",currNode->data->year);
	printf("Movie Genre: %s\n",tmp);
	printf("Main Actor: %s\n",currNode->data->castMember[0]);
	printf("Main Actress: %s\n",currNode->data->castMember[1]);
	
	check=1;
	
	}
	currNode=currNode->prev;
	}

	if(check==-1)//if the genre cannot be found
	{
	printf("Can't find genre");
	}

	}
void dl_cleanup(DblList *dlist)
	{
	//clean up the memory
	MovieNode *currNode=dlist->head;
	MovieNode *nextNode;
	while(currNode!=NULL)
	{
	nextNode=currNode->next;
	free(currNode->data);
	free(currNode);
	currNode=nextNode;
	}
	
	}
void initMovie(char *title,int year,char *actor,char *actress,enum MovieGenre genre,Movie **new)
{	//initialize a movie
	*new=malloc(sizeof(Movie));
	strcpy((*new)->title,title);
	(*new)->year=year;
	(*new)->genre=genre;
	strcpy((*new)->castMember[0],actor);
	strcpy((*new)->castMember[1],actress);
}
void clearTheLine() {//for the fgets function works correctly
 int c;
 do {
  c = getchar();
 }
 while (c != '\n' && c != EOF);
}

