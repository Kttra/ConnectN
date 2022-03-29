connectn.out: win.o setUpAndPlay.o inputVal.o cleanUp.o main.o
	gcc -g -Wall -Werror -o connectn.out win.o setUpAndPlay.o inputVal.o cleanUp.o main.o

win.o: win.c win.h setUpAndPlay.h cleanUp.h
	gcc -g -Wall -Werror -c win.c

setUpAndPlay.o: setUpAndPlay.c setUpAndPlay.h inputVal.h
	gcc -g -Wall -Werror -c setUpAndPlay.c

inputVal.o: inputVal.c inputVal.h
	gcc -g -Wall -Werror -c inputVal.c

cleanUp.o: cleanUp.c cleanUp.h
	gcc -g -Wall -Werror -c cleanUp.c

main.o: main.c inputVal.h win.h setUpAndPlay.h cleanUp.h
	gcc -g -Wall -Werror -c main.c

clean:
	rm -fr *.o *.out
