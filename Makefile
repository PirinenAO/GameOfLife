gameoflife: game_of_life.o functions.o display.o
	gcc -o gameoflife game_of_life.o functions.o display.o -lncursesw
game_of_life.o: display.c functions.c header.h
	gcc -c game_of_life.c -g
display.o: display.c header.h
	gcc -c display.c -g
functions.o: functions.c header.h
	gcc -c functions.c -g
clean:
	del *.o *.exe