// C language's array does not store their lengths
// Fat pointers have been proposed to solve this problem by holding more than just the address of elements
// in a pointer. 
// The idea behind is to allocate a little extra space in the beginning of the array when it is created. 
// This extra space is used to hold length and capcaity parameters of the array.
// Beginning address of elements is returned to the users instead of the actual beginning of allocated space.
// Thus, users are able to use the fat pointer as a regular pointer to access its elements.
#ifndef _FAT_POINTER_H 
#define _FAT_POINTER_H 

#define TYPE int 

typedef TYPE *ARR;

ARR arrnew(void);
ARR arrnewcap(int);
void arrdelete(ARR);
ARR arrappend(ARR, TYPE);
ARR arrresize(ARR, int);
TYPE arrremove(ARR);
int arrlen(ARR);
int arrcap(ARR);


#endif
