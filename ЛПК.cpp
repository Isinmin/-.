#include <iostream> 
#include <conio.h> 
#include <stdlib.h> 
#include <time.h> 

using namespace std; 

struct CBinTree 
{ 
char symbol; 
CBinTree *left, *right; 
}; 

CBinTree* tree=NULL; 

void push(char newEl,CBinTree **tree) 
{ 
if ((*tree)==NULL) 
{ 
(*tree)=new CBinTree; 
(*tree)->symbol=newEl; 
(*tree)->left=(*tree)->right=NULL; 
return; 
} 
if (newEl>(*tree)->symbol) push(newEl,&(*tree)->right); 
else push(newEl,&(*tree)->left); 
} 


void printLVR (CBinTree *tree) 
{ 
if (tree==NULL) return; 
else 
{ 
printLVR(tree->left); 
cout«tree->symbol; 
printLVR(tree->right); } 
} 

void printVLR (CBinTree *tree) 
{ 
if (tree==NULL) return; 
else 
{ 
cout«tree->symbol; 
printVLR(tree->left); 
printVLR(tree->right); } 
} 

void printLRV (CBinTree *tree) 
{ 
if (tree==NULL) return; 
else 
{ 
printLRV(tree->left); 
printLRV(tree->right); 
cout«tree->symbol; 
} 
} 

int main () 
{ 
srand(time(NULL)); 
int n; 
char s; 
cin>>n; 

for (int i=0;i<n;++i) 
{ 
do{s = (char)rand()%123; } 
while ((s<48)||((s>57)&&(s<65))||((s>90)&&(s<97))||(s>122)); 
push(s,&tree); 
} 
cout<<"\nleft root right:\n"; 
printLVR(tree); 
cout<<"\nleft right root:\n"; 
printVLR(tree); 
cout<<"\nleft right root:\n"; 
printLRV(tree); 
_getch(); 
} 
