#include <stdio.h>
#define MAX_PARAMS     8
#define MAX_ARR_SIZE  16
#define MAX_STR_SIZE       32
#define C_OK           0
#define C_NOK         -1
enum MovieGenre
{
  comedy=1,
  drama=2,
  action=3,
  horror=4,
  romantic=5,
};
typedef struct {
char title[MAX_STR_SIZE];
int year;
enum MovieGenre genre;
char castMember[MAX_ARR_SIZE][MAX_STR_SIZE];
} Movie;
typedef struct Node{
Movie *data;
struct Node *prev;
struct Node *next;
}MovieNode;
typedef struct{
MovieNode *head;
MovieNode *tail;
}DblList;

void dl_init(DblList *);
void dl_add(DblList *, Movie *);
void dl_del(DblList *, Movie *);
void dl_printFwd(DblList *);
void dl_printBack(DblList *);
void dl_printByGenre(DblList *, enum MovieGenre );
void dl_cleanup(DblList *);
void initMovie(char *,int ,char*,char *,enum MovieGenre ,Movie **);
void clearTheLine() ;




