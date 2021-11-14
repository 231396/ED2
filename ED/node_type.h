#ifndef NODETYPE_H 
#define NODETYPE_H 

#include "vertex.h"

struct NodeType
{
	Vertex info;
	NodeType* next;
};

#endif
