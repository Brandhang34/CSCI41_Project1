// CSCI41 Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "Date.h"
#include "CategoriesDLL.h"
#include "MovieCLL.h"
using namespace std;


int main()
{
    CategoriesDLL list_categories;
    MovieCLL list_movies;
    list_categories.addCategory("children");
    list_categories.addCategory("action");
    list_categories.addCategory("comedy");
    list_categories.addCategory("drama");
    list_categories.addCategory("horror");

    list_movies.insertMovieAlphabetical("action", "king kong", Date(4, 15, 2018), list_categories);
    list_movies.insertMovieAlphabetical("action", "godzilla", Date(1, 17, 2016), list_categories);
    list_movies.insertMovieAlphabetical("action", "foo", Date(6, 6, 2019), list_categories);
    list_movies.insertMovieAlphabetical("action", "extraction", Date(4, 24, 2020), list_categories);
    list_movies.insertMovieAlphabetical("drama", "hugo", Date(11, 23, 2011), list_categories);
    list_movies.insertMovieAlphabetical("drama", "fatherhood", Date(6, 18, 2021), list_categories);
    list_movies.insertMovieAlphabetical("drama", "22 july", Date(10, 10, 2010), list_categories);
    list_movies.insertMovieAlphabetical("children", "incredibles 2", Date(7, 30, 2019), list_categories);
    list_movies.insertMovieAlphabetical("children", "moana", Date(6, 20, 2017), list_categories);
    list_movies.insertMovieAlphabetical("comedy", "grown ups", Date(9, 20, 2021), list_categories);
    list_movies.insertMovieAlphabetical("children", "moana", Date(6, 20, 2017), list_categories);
    list_movies.insertMovieAlphabetical("children", "kung fu panda", Date(7, 1, 2021), list_categories);
    list_movies.insertMovieAlphabetical("comedy", "the interview", Date(8, 26, 2015), list_categories);
    list_movies.insertMovieAlphabetical("comedy", "hubie halloween", Date(10, 7, 2020), list_categories);
    list_movies.insertMovieAlphabetical("horror", "scary movie 5", Date(4, 12, 2013), list_categories);

    cout << "Printing category and their movies: " << endl;
    list_categories.print_categories_movies();

    cout << endl << "Removing the comedy category from the menu. " << endl << endl;
    list_categories.removeCategory("comedy");

    cout << "Printing category and their movies: " << endl;
    list_categories.print_categories_movies();

    cout << endl << "Deleteing movies that were uploaded before: 6, 21, 2017." << endl << endl;
    list_categories.deleteMovies(Date(6, 21, 2017));

    cout << "Printing category and their movies: " << endl;
    list_categories.print_categories_movies();

    cout << endl << "Printing indexes within the given drama: " << endl;
    list_movies.movieIndex("drama", list_categories);

    cout << endl << endl << "Search movie (kung fu panda) through all of the categories list: " << endl;
    list_categories.searchMovie("kung fu panda");
    cout << endl;

    cout << "Search movie (extraction) through all of the categories list: " << endl;
    list_movies.binarySearchMovie("action", "extraction", list_categories);

    cout << endl << "print movies in the category (children): " << endl;
    list_movies.print_Movies("children", list_categories);

    cout << endl;
    return 0;
}