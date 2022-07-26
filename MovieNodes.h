#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

struct MovieNodes
{
    string movie_name; //has the variable movie name
    string movie_category; //has the variable category name
    Date upload_date; //Creates an object of date
    MovieNodes* next; // points to the next node
    MovieNodes* prev; // points to the previous node

    MovieNodes();

    MovieNodes(string m_name);

    MovieNodes(string m_category, string m_name, Date ul_date);
};