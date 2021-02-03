CXX = g++
LDLIBS =  -lglut -lGL -lGLU -lm -lSDL

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif


pendpoc :	main.o
	$(CXX) $(CFLAGS) main.o -o pendpoc $(LDLIBS)

main.o : main.cpp
	$(CXX) $(CFLAGS) main.cpp -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *
