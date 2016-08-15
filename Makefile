CPPFLAGS=-Wall -g
OBJECTS=main.o View.o Field.o Snake.o Game.o
TARGET=snake
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -o $(TARGET) -g -framework GLUT -framework OpenGL
main.o: main.cpp View.h Field.h
View.o: View.cpp View.h
Field.o: Field.cpp Field.h View.h
Snake.o: Snake.cpp Snake.h Field.h
Game.o: Game.cpp Game.h View.h Field.h Snake.h
