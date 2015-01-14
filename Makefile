CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = pong
OBJECTS = main.o game.o splashscreen.o mainmenu.o visiblegameobject.o playerpaddle.o
DEPENDS = ${OBJECTS:.o=.d}
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${LIBS}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
