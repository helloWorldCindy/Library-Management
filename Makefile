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

