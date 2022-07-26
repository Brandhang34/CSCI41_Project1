#include "MovieNodes.h"

//default constructor
MovieNodes::MovieNodes()
{}

//constructor with parameter of only the movie name
MovieNodes::MovieNodes(string m_name)
{
    movie_name = m_name;
    next = NULL;
    prev = NULL;
}

//constructor with parameter of only the movie category, movie name, and the upload date.
MovieNodes::MovieNodes(string m_category, string m_name, Date ul_date)
{
    upload_date = ul_date;
    movie_name = m_name;
    movie_category = m_category;
    next = NULL;
    prev = NULL;
}