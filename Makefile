OBJ = main.o PLScontrol.o View.o Book.o Patron.o Library.o DepArray.o BookArray.o PatronArray.o Storage.o



a1:	$(OBJ)

	g++ -o a1 $(OBJ)



main.o:	main.cc types.h

	g++ -c main.cc



PLScontrol.o:	PLScontrol.cc PLScontrol.h types.h

	g++ -c PLScontrol.cc



View.o:	View.cc View.h types.h DepArray.h

	g++ -c View.cc



Book.o:	Book.cc Book.h types.h

	g++ -c Book.cc



Patron.o:	Patron.cc Patron.h types.h DepArray.h BookArray.h PatronArray.h

	g++ -c Patron.cc



Library.o:	Library.cc Library.h types.h Storage.h PatronArray.h BookArray.h

	g++ -c Library.cc



BookArray.o: BookArray.cc Book.h

	g++ -c BookArray.cc



PatronArray.o: PatronArray.cc Patron.h

	g++ -c PatronArray.cc

		

Storage.o:	Storage.cc Book.h Patron.h types.h PatronArray.h DepArray.h BookArray.h

	g++ -c Storage.cc

	



DepArray.o: DepArray.cc DepArray.h Patron.h

	g++ -c DepArray.cc



clean:

	rm -f a1 *.o
