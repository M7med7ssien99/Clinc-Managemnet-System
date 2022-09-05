#ifndef ST_NODE_H
#define ST_NODE_H
#include"STD_TYPES.h"
#include"ST_ADD_NEW.h"
typedef struct Node
{    
    ST_ADD Data;                                                                             
    struct Node * Next;                                                                         
}Node;  
                                              
Node * head = NULL;

#endif
   