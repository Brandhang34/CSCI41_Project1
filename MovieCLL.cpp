#include <iostream>
#include"MovieNodes.h"
#include"MovieCLL.h"
#include"CategoryNodes.h"
#include"CategoriesDLL.h"
using namespace std;

//Default constructor
MovieCLL::MovieCLL()
{
    head = NULL;
    tail = NULL;
}

//Part 2A. inserts a movie alphabetically in each list of within its specified category.
void MovieCLL::insertMovieAlphabetical(string movieCategory, string movieName, Date ULdate, CategoriesDLL list)
{
    MovieNodes* temp = new MovieNodes(movieCategory, movieName, ULdate);

    CategoryNodes* cate = list.search_categoryName(movieCategory);
    head = cate->linkC;

    MovieNodes* checkIfSame = head;

    if (head == NULL) //checks if the is nothing in the list and inserts it as the head and tail.
    {
        cate->linkC = temp;
        head = temp;
        tail = temp;
        temp->next = head;
        temp->prev = head;
    }
    else
    {
        // Checks if the movie name belongs at the beginning of the movie list(only if there is only one element in the list)
        if (temp->movie_name < head->movie_name && head->next == head)
        {
            temp->next = head;
            temp->prev = head;
            head->prev = temp;
            cate->linkC = temp;
            head = temp;
            tail->next = head;
        }
        else if (temp->movie_name < head->movie_name)// checks if the movie name belongs at the beginning of the movie list (if there is more than one element in the list.)
        {
            temp->next = head;
            temp->prev = head->prev;
            head->prev = temp;
            cate->linkC = temp;
            head = temp;
            tail->next = head;
        }
        else
        {
            MovieNodes* curr = head;
            do
            {
                if (temp->movie_name > curr->movie_name) // checks if the current movie is less than the movie that was passed in.
                {
                    do
                    {
                        if (temp->movie_name == checkIfSame->movie_name) //checks if the movie is same if it does, return nothing so that nothing happens with that node.
                        {
                            return;
                        }
                        else
                        {
                            checkIfSame = checkIfSame->next;
                        }
                    } while (checkIfSame != head);

                    //inserts accordingly
                    temp->next = curr->next;
                    temp->prev = curr;
                    curr->next = temp;
                    curr->next->prev = temp;
                    break;
                }
                else if (curr->next == head) // if the node is at the end of the list it inserts it at the end of the list.
                {
                    curr->next = temp;
                    curr = temp;
                    curr->next = head;
                    break;
                }
                else //traverses to the next node
                {
                    curr = curr->next;
                }
            } while (curr != head);
        }
    }
    cate->size++;
}

//Part 2B. search for a movie using binary search.
void MovieCLL::binarySearchMovie(string movieCategory, string movieName, CategoriesDLL list)
{
    CategoryNodes* cate = list.search_categoryName(movieCategory); //sets the cate to the category that was passed 
    head = cate->linkC;
    MovieNodes* start = head;
    MovieNodes* end = head->prev;

    MovieNodes* temp = head;

    int middle = cate->size / 2; // Finds the first middle of the list
    bool found = false;
    int numOfComparisons = 0;
    do
    {
        for (int i = 0; i < middle; i++) // loops through to find the middle
        {
            temp = temp->next;
        }

        if (temp->movie_name == movieName) // if the middle is matched with the given movie name, then it is found
        {
            cout << "Movie found!" << endl;
            found = true;
            break;
        }
        else if (temp->movie_name < movieName) //if the middle is less than the given movie name, set the start after the middle.
        {
            start = temp->next;
            temp = temp->next;
        }
        else //else set the end before the middle of the list.
        {
            end = temp->prev;
            temp = start;
        }
        middle /= 2; //sets the middle divided by two so that is the new middle.
        numOfComparisons++;
        if (numOfComparisons > cate->size) // if the number of comparisons pass the size of the array, it breaks so it doesn't infinitely loop.
        {
            cout << "Movie not found!" << endl;
            break;
        }
    } while (found == false);
}

//Part 2C. Prints out the movie index of within the category that is given.
void MovieCLL::movieIndex(string movieCategory, CategoriesDLL list)
{
    CategoryNodes* cate = list.search_categoryName(movieCategory); //sets the cate to the category that was passed 
    head = cate->linkC;
    int index = 0;

    MovieNodes* temp = head;
    cout << "In the category (" << movieCategory << "), "; //First prints out the category name

    do //loops through the circular linked list of movies
    {
        cout << cate->linkC->movie_name << " is at index: " << index << " "; //prints the movies name and the index in which it is at within the list.
        index++; //increments so next index can be printed.
        temp = temp->next;
        cate->linkC = cate->linkC->next;
    } while (temp != head);
}

//Part 2D. Prints all of the movies that is within the category that is being passed. 
void MovieCLL::print_Movies(string movieCategory, CategoriesDLL list)
{
    CategoryNodes* cate = list.search_categoryName(movieCategory); //sets the cate to the category that was passed 
    head = cate->linkC;
    MovieNodes* temp = head;

    do//loops through the circular linked list of movies
    {
        cout << "(" << cate->linkC->movie_name << ") <-> "; //Prints the movie name
        temp = temp->next;
        cate->linkC = cate->linkC->next;
    } while (temp != head);
    cout << endl;
}