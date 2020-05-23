#include<stdio.h>
int main ()
{
    int *pnum, inum;
    char *pname, cname, sname[10];
       inum=450;
    pnum= &inum;
    //sname = &cname; // its not allowable in C since sname is fixed pointer. 
    pname = &cname; 
    pname = sname;
    printf("size of sname %d\n",sizeof(pname));
    printf("size of pname %d\n",sizeof(sname));
   // pname = &sname; // invalid
   //   pname = &sname[0]; //valid
         pname = &sname[1]; 
         pname = sname + 1;
     pname =  &inum;
    pname = (char *) &inum;
     printf("size of sname %d\n",sizeof(sname));
     printf("size of pnum %d\n",sizeof(pnum));
     printf("size of pnum %d\n",sizeof(*pnum));
     printf("size of inum %d\n",sizeof(inum));
     printf("size of pname %d\n",sizeof(pname));
     printf("size of pname %d\n",sizeof(*pname));
     printf("size of sname %d\n",sizeof(sname));
     printf("Number is %d\n", inum);

     printf("Number is %d\n", *pname);
}
