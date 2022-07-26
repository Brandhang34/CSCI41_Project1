#pragma once
#include "MovieNodes.h"
using namespace std;

struct CategoryNodes
{
    string category_name;
    CategoryNodes* next; //points to the next node within the category list
    CategoryNodes* prev; // points to the previous node within the category list
    MovieNodes* linkC; // points to the head node of the circular linked list (Movies list)
    int size; //Keeps track of the size of the list within the category

    CategoryNodes();

    CategoryNodes(string name);
};