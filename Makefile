CXX = g++
LDLIBS =  -lglut -lGL -lGLU -lm -lSDL

OBJS = quit.o events.o display.o
HEADERS = prototypes.h

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif


pendpoc :	main.o $(OBJS)
	$(CXX) $(CFLAGS) main.o -o pendpoc $(LDLIBS) $(OBJS)

main.o : main.cpp $(HEADERS)
	$(CXX) $(CFLAGS) main.cpp -c

quit.o : quit.cpp $(HEADERS)
	$(CXX) $(CFLAGS) quit.cpp -c

events.o : events.cpp $(HEADERS)
	$(CXX) $(CFLAGS) events.cpp -c

display.o : display.cpp $(HEADERS)
	$(CXX) $(CFLAGS) display.cpp -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *
