# Library-Management

Program author: Qianyi Yu, Yuzhong Hu
Purpose: to let the user operate the Book Store Management System
Source files: Course.cc, Book.cc, BookArray.cc, Computer.cc, Coat.cc, Cup.cc, Product.cc
Header files: Course.h, Book.h, BookArray.h, BMScontrol.h, UImanager.h, Product.h, Computer.h, Coat.h, Cup.h, Dlist.h, MoreServices.h, defs.h

Compilation command :
OBJ = main.o BookArray.o Course.o Book.o Product.o Computer.o Cup.o Coat.o MoreServices.h

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:		main.cc UImanager.h BMScontrol.h Dlist.h
	g++ -c main.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

Book.o:		Book.cc Book.h defs.h
	g++ -c Book.cc

Product.o: 	Product.cc Product.h defs.h
	g++ -c Product.cc

Computer.o: 	Computer.cc Computer.h Product.h
	g++ -c Computer.cc

Coat.o: 	Coat.cc Coat.h Product.h
	g++ -c Coat.cc

Cup.o:  	Cup.cc Cup.h Product.h
	g++ -c Cup.cc

clean:
	rm -f *.o a4


Classes and functions involved in implementing the polymorphic behaviour:
Abstract class: MoreServices
Concrete classes: FindCourseByInstructor
                  SortBooks
                  LoanBooks
                  BooksAvailable
Virtual function: services(string, string*)

Launching and operation instruction: 

    1. Untar the file using tar xvf.
    2. Place the file in the directory that the user want to compile and run.
    3. Use “make” to compile the program.
    4. Use ”./a1” to run the program.
    5. If the user choose 1, the user can either choose to add one course or several courses at a time, enter the course code, course name, instruction's name and enrolment.
    6. If the user choose 2, then all the existing courses will be printed.
    7. If the user choose 3, then enter the course code, the title, author, ISBN, year and edition of that book.
    8. If the user choose 4, and enter the course code, the existed books of that course will be printed.
    9. If the user choose 5, he can choose either delete one course or several courses at a time.
    10. If the user choose 6, he can specify the product he wants.
    11. If the user choose 7, he can print out all the invertory products on sale.
    12. If the user choose 8, he can access other services such as:
                              1. Finding a course by name of instructor;
                              2. Sort a list of books for a specific course;
                              3. Loan books from the bookstore;
                              4. See which books are available for loan.
    13. If the user choose 0, the program will be terminated.
