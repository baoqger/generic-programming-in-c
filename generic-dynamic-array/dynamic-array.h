#ifndef _DYNAMIC_ARRAY
#define _DYNAMIC_ARRAY 

#define TYPE void* 

struct arr {
    TYPE *buf;
    int len;
    int cap;
};

struct arr* arrnew(void);
struct arr* arrnewcap(int);
void arrdelete(struct arr*);
int arrappend(struct arr*, TYPE);
int arrresize(struct arr*, int);
TYPE arrremove(struct arr*);
void arrprint(struct arr*, void(*pt)(void*));

#endif 
