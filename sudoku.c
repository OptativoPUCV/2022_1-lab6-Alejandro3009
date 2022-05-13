#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
/*  int i = 0,k = 0,p;
  
  while(1)
    if(n->sudo[i][k] != 0){
      i++;
      if(i == 8){
        k++;
        i = 0;
      }
      continue;
    }

    for(p = 0; p < 9; p++){

    }
  
*/
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int i=0,k=0,p;

  while(1){
    if(n->sudo[i][k] != 0){
      i++;
      if(i == 8){
        k++;
        i = 0;
      }
      continue;
    }
    break;
  }

  Node *newN = createNode();
  newN->sudo[i][k] = 1;
  pushFront(list,newN);

  for(p=2; p<10; p++){
    Node *newN = createNode();
    newN->sudo[i][k] = p;
    pushCurrent(list,newN);
  }

  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/