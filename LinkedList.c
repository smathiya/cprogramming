
#include <stdio.h>
 struct car;   // declartion
 struct node   // definiton 
    {                       
        int data;
        struct node *next; //you can have pointer referencing to node since pointer looks at the machine architecure address

        // Here compiler needs to know if there is a structure called node exist
       // struct car *x;     //To define a pointer to struct we need only the declartion, not the definition
       // struct car y;      // This wont work because definiton is not available before this statement 
    }; // one which has data and pointer to next 
// struct car definiton
struct car   //definiton 
{
    int wheel;
};

void printall(struct node *d) // here type of d and d->next is same becasue they are struct node*
{
  printf("The value at n[0] is %d\n",d->data);
  printf("The address at n[1] is %x\n",d->next);// it will be the address of n[1];
  printf("The value at n[1] is %d\n",d->next->data);
  printf("The value at n[2] is %d\n",d->next->next->data);
  //printf("The value at n[2] is %d\n",d->next->next->next->data); // segmentation fault - undefined behaviour 
}
void printall1(struct node *d)
{
    // while iterating through linkedlist we need to consider 3 parts:
    // 1. How do you break
    // 2. How to use the data
    // 3. How to go forward
    while (d != NULL) // breaking condition
    {
      printf("The value at node  %d\n",d->data); // access the data
      //d and d-> next are same type , so make use of it to go forward
      d= d->next;
    }
}

//How to add extra node
// Typically we keep pointer to head of the list(which is the first node),you traverse end of the list (you find NULL) and add the node
// This is inefficient . To popular ways to solve: 
// 1. Keep both head and tail pointers
// 2. Keep adding at the front . Here order is not preserved
void addnode(struct node *head,struct node *newNode)
{

}

int main()
{

struct node n[3]; // Here total bytes of n[0] will be 12 bytes since 4 bytes for integer and 8 bytes for pointer ( if its pointer variable regardless of data type it will be machine architecure address)
printf("The size of sturct node %lu\n",sizeof(struct node));
printf("The size of int is %lu\n",sizeof(int));

n[0].data=50;
n[1].data=100;
n[2].data=150;
n[0].next= &n[1];
n[1].next= &n[2];
n[2].next=NULL;
struct node *list=n;

printall(list);
printall1(list);

}

