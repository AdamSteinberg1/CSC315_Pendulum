CXX = g++
LDLIBS =  -lglut -lGL -lGLU -lm -lSDL

OBJS = quit.o events.o display.o init.o model.o metrics.o camera.o
HEADERS = prototypes.h

CFLAGS += -std=c++17 #needed for clamp

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif


pendpoc :	main.o $(OBJS)
	$(CXX) $(CFLAGS) main.o $(OBJS) $(LDLIBS) -o pendpoc

main.o : main.cpp $(HEADERS)
	$(CXX) $(CFLAGS) main.cpp -c

quit.o : quit.cpp $(HEADERS)
	$(CXX) $(CFLAGS) quit.cpp -c

events.o : events.cpp $(HEADERS)
	$(CXX) $(CFLAGS) events.cpp -c

display.o : display.cpp $(HEADERS)
	$(CXX) $(CFLAGS) display.cpp -c

init.o : init.cpp $(HEADERS)
	$(CXX) $(CFLAGS) init.cpp -c

model.o : model.cpp $(HEADERS)
	$(CXX) $(CFLAGS) model.cpp -c

metrics.o : metrics.cpp $(HEADERS)
	$(CXX) $(CFLAGS) metrics.cpp -c

camera.o : camera.cpp $(HEADERS)
	$(CXX) $(CFLAGS) camera.cpp -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *
