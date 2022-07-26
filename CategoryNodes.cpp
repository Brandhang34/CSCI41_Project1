#include"CategoryNodes.h"

//Default constructor
CategoryNodes::CategoryNodes()
{
    category_name = "";
    next = NULL;
    prev = NULL;
    linkC = NULL;
    size = 0;
}

//Constructor with a paramenter(setting the category name to the given name that was passed in)
CategoryNodes::CategoryNodes(string name)
{
    category_name = name;
    next = NULL;
    prev = NULL;
    linkC = NULL;
    size = 0;
}