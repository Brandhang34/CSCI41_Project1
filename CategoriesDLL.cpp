#include <iostream>
#include"MovieNodes.h"
#include"MovieCLL.h"
#include"CategoryNodes.h"
#include"CategoriesDLL.h"

//Default constructor (sets the head and tail to NULL);
CategoriesDLL::CategoriesDLL()
{
    head = NULL;
    tail = NULL;
}

//Part 1A. Adds a new category in the double linked list (inserting at the rear so that it could be printed like a row)
void CategoriesDLL::addCategory(string name)
{
    CategoryNodes* temp = new CategoryNodes(name);

    if (head == NULL) //if the list is empty, set the temp node as the beginning of the list. 
    {
        head = temp;
        tail = temp;
    }
    else
    {
        CategoryNodes* last = head;
        while (last->next != NULL) //loops throuvh the list until it reaches the end, then inserts it
        {
            last = last->next;
        }

        last->next = temp;
        temp->prev = last;
    }//(Demonstrates the insert at rear)
}

//Part 1B. Searches a category by its name. (returns the pointer of that node when its name matches the given category name)
CategoryNodes* CategoriesDLL::search_categoryName(string name)
{
    CategoryNodes* temp = head;
    bool found = false;

    while (temp != NULL)// loops through the category list
    {
        if (temp->category_name == name) // checks if it is found and returns the pointer of that node.
        {
            found = true;
            return temp;
        }
        else //goes the the next category
        {
            temp = temp->next;
        }
    }
    if (found == false)//if not found, return NULL
    {
        return NULL;
    }
}

//Part 1C. Searches a movie by its name iteratively. (Returns the category that the movie is in) 
void CategoriesDLL::searchMovie(string movie)
{
    CategoryNodes* node = head;
    bool found = false;
    while (node != NULL) //This first loops through the categories DLL
    {
        CategoryNodes* cate = search_categoryName(node->category_name);
        MovieNodes* head = cate->linkC;

        do//This then loops through the movies CLL
        {
            if (cate->linkC->movie_name == movie)  
            {
                cout << "The movie was found at category: " << cate->category_name << endl;
                found = true;
            }
            cate->linkC = cate->linkC->next;
        } while (cate->linkC != head);
        
        if (found == true)
        {
            break;
        }
        else
        { 
            node = node->next;
        }
    }
    if (found == false)
    {
        cout << "Movie was not found in any category." << endl;
    }
}

//Part 1D. Removes the category with the given category name. (Iterates through the categories list, and if it matches, relink the list and remove the node)
void CategoriesDLL::removeCategory(string name)
{
    CategoryNodes* temp = new CategoryNodes;
    temp = head;
    while (temp != NULL)
    {
        if (temp->category_name == name)
        {
            if (temp->next != NULL) //links the node next to the node after it 
                temp->next->prev = temp->prev;

            if (temp->prev != NULL) //links the node prev to the node before it
                temp->prev->next = temp->next;

            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
}

//Part 1E. Deletes all of the movies that are before the given date.(Calls the operator overload (<) in the dates class to compare between the dates as it goes through each movie.
void CategoriesDLL::deleteMovies(Date date)
{
    CategoryNodes* node = head;

    while (node != NULL)//This first loops through the categories DLL
    {
        CategoryNodes* cate = search_categoryName(node->category_name);
        MovieNodes* head = cate->linkC;
        MovieNodes* tail = cate->linkC->prev;
        
        do //This then loops through the movies CLL
        {
            MovieNodes* curr = cate->linkC;
            if (curr->upload_date < date) //This calls the operator overload and checks if the movie upload date is less than the given date
                {
                    if (head == NULL)
                    {
                        return;
                    }
                    else if (curr->next == head && curr->prev == head) //Checks if there is only one element in the list
                    {
                        cate->linkC = NULL;
                        cate->size--; //Keeps track of the size of the list within the category
                        break;
                    }
                    else if (curr == head) //Deletes node that is in the front of the list 
                    {
                        MovieNodes* temp = head;
                        while (temp->next != head)
                        {
                            temp = temp->next;
                        }
                        temp->next = head->next;                     
                        head = temp->next;
                        head->prev = temp;
                        cate->size--; //Keeps track of the size of the list within the category
                    }
                    else if (curr->next == head) // Deletes the node that is at the end of the list
                    {
                        MovieNodes* temp = head;
                        while (temp->next->next != head)
                        {
                            temp = temp->next;
                        }
                        tail = temp;
                        tail->next = head;    
                        cate->size--; //Keeps track of the size of the list within the category
                    }                
                    else // If any other case doesnt pass, removes its current position.
                    {
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                        cate->size--; //Keeps track of the size of the list within the category
                    }  
            }
            curr = curr->next;
            cate->linkC = cate->linkC->next;
        } while (cate->linkC != head);
        node = node->next;
    }
}

//Part 1F. Prints all the movies of all categories.
void CategoriesDLL::print_categories_movies()
{
    CategoryNodes* node = head;
    while (node != NULL) //This first loops through the categories DLL
    {
        cout << "[" << node->category_name << "]->";
        CategoryNodes* cate = search_categoryName(node->category_name); //searches for the category so that it can bring up the circular linked list
        MovieNodes* head = cate->linkC;
        do//This then loops through the movies CLL
        {
            if (cate->linkC != NULL)
            {
                cout << "(" << cate->linkC->movie_name << ") <-> "; //Prints the movie.
            }
            else
            {
                break; //breaks the loop if the list is empty.
            }
            cate->linkC = cate->linkC->next;
        } while (cate->linkC != head);

        cout << endl;
        node = node->next;
    }
}