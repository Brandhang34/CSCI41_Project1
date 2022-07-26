#pragma once
#include "CategoryNodes.h"
#include "Date.h"
#include<iostream>

class CategoriesDLL
{
private:
    CategoryNodes* head;
    CategoryNodes* tail;
    int numOfCategories;
public:
    CategoriesDLL();

    //Part 1A. Add a new category by name (e.g., void addCategory(string name))
    void addCategory(string name);

    //Part 1B. Search a category by name. If the category is found, return the pointer of the category.
    //If the category is not available, return a null pointer.
    CategoryNodes* search_categoryName(string name);

    void removeCategory(string name);

    void searchMovie(string movie);

    void deleteMovies(Date date);

    void print_categories_movies();
};