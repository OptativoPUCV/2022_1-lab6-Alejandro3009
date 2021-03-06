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
  int i,j,k,m,p;
  int nums[9];

  k = 0;
  /*for(i=0;i<9;i++)nums[i] = 0;

  j=0;
  for(i=0;i<9;i++){
    if(n->sudo[i][j] == 0)continue;
    else{
      while (1)
      {
        if(n->sudo[i][j] == nums[k] && n->sudo[i][j] != 0 && nums[k] != 0)return 0;

        if(nums[k] != 0)k++;
        else{
          nums[k] = n->sudo[i][j];
          break;
        }
      }
    }
    k = 0;

    if(i == 8){
      i = 0;
      j++;
      for(k=0;k<9;k++)nums[k] = 0;
      k = 0;
    }
    if(j>8)break;
  }

  for(j=0;j<9;j++){
    if(n->sudo[i][j] == 0)continue;
    else{
      while (1)
      {
        if(n->sudo[i][j] == nums[k] && n->sudo[i][j] != 0 && nums[k] != 0)return 0;

        if(nums[k] != 0)k++;
        else{
          nums[k] = n->sudo[i][j];
          break;
        }
      }
    }
    k = 0;

    if(j == 8){
      i++;
      j = 0;
      for(k=0;k<9;k++)nums[k] = 0;
      k = 0;
    }
    if(i>8)break;
  }*/

  j=0;
  while (1){
    for(i=0;i<9;i++){
      nums[k] = n->sudo[i][j];
      k++;
    }

    for(m=0;m<9;m++){
      for (k=m+1;k<9;k++){
        if(nums[m] == nums[k] && nums[m] != 0)return 0;
      }
    }

    k=0;
    if(j == 8)break;
    j++;
  }

  k=0;
  i=0;
  while (1){
    for(j=0;j<9;j++){
      nums[k] = n->sudo[i][j];
      k++;
    }

    for(m=0;m<9;m++){
      for (k=m+1;k<9;k++){
        if(nums[m] == nums[k] && nums[m] != 0)return 0;
      }
    }

    k=0;
    if(i == 8)break;
    i++;
  }

  for(k=0;k<9;k++){ 
    m = 0;
    for(p=0;p<9;p++){
      i=3*(k/3) + (p/3) ;
      j=3*(k%3) + (p%3) ;
      /*if(n->sudo[i][j] == 0)continue;
      while (1)
      {
        if(n->sudo[i][j] == nums[m] && n->sudo[i][j] != 0 && nums[m] != 0)return 0;

        if(nums[m] != 0)m++;
        else{
          nums[m] = n->sudo[i][j];
          break;
        }
      }*/
      nums[m] = n->sudo[i][j];
      m++;
    }

    for(m=0;m<9;m++){
      for (p=m+1;k<9;k++){
        if(nums[m] == nums[p] && nums[m] != 0)return 0;
      }
    }

    for(m=0;m<9;m++)nums[m] = 0;
  }

  return 1;
}



List* get_adj_nodes(Node* n){
  List* list=createList();
  int i,j,k;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        for(k=1;k<10;k++){
          n->sudo[i][j]=k;
          if(is_valid(n)){
            Node* adj=copy(n);
            pushBack(list,adj);
          }
        }
        n->sudo[i][j]=0;
        return list;
      }
    }
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