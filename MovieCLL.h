#pragma once
#include"MovieNodes.h"
#include"Date.h"
#include"CategoryNodes.h"
#include"CategoriesDLL.h"
#include<iostream>
#include<string>

using namespace std;

class MovieCLL
{
private:
    MovieNodes* head;
    MovieNodes* tail;
public:
    MovieCLL();

    void insertMovieAlphabetical(string movieCategory, string movieName, Date ULdate, CategoriesDLL list);

    MovieNodes* binarySearchMiddle(MovieNodes* start, MovieNodes* end);

    void binarySearchMovie(string movieCategory, string movieName, CategoriesDLL list);

    void movieIndex(string movieCategory, CategoriesDLL list);

    void print_Movies(string movieCategory, CategoriesDLL list);
};