#ifndef ST_NODE1_H
#define ST_NODE1_H
#include"STD_TYPES.h"

typedef struct Node1
{    
    f32 time;
    u16 id ;	
    struct Node1 * next;                                                                         
}Node1;  
                                              
Node1 * head1 = NULL;

#endif
   