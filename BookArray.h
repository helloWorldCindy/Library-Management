#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

class BookArray              //This class is a book collection class where all the books of a single course are put into one array.
{
  public:
    BookArray();
    ~BookArray();
    void add(Book*);         //Add book to the book array
    Book* getBook(int);
    int  getSize();
    void cleanUp();
  private:
    int  size;
    Book *books[MAX_BOOKS];
};
#endif
