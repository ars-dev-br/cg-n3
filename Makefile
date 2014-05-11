CPP = g++
CPPFLAGS = -flto -O3 -Wall -Wextra -c -g --std=c++11
LDFLAGS = -flto
LIBS = -lm -lGL -lglut -lGLU

DEPS = $(wildcard *.hpp)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = n3

.PHONY: all doc clean cleandoc

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(LDFLAGS) $(LIBS) $(OBJECTS) -o $@

.cpp.o: $(DEPS)
	$(CPP) $(CPPFLAGS) $< -o $@

doc:
	doxygen Doxyfile

clean:
	rm $(EXECUTABLE) *.o

cleandoc:
	rm -rf html latex
