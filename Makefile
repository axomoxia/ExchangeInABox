# compiler variables
CC := "/usr/bin/g++"
CFLAGS := "-Wall"

# wot we call the app
APPNAME :="exchange"

# source files - currently we only have files in the current directory,
# but in the future we will include sub-dirs.

SRC=$(wildcard *.cpp)

#our object files 
OBJS=$(patsubst %.cpp,%.o, $(SRC))

# associates obj file with the underlying c++

# build the application
all: $(APPNAME)

# the app is make from all the object files
# $@ is the target (in this case the exchange app) and
# $^ is the list of all the object files
$(APPNAME): $(OBJS)
	$(CC) -o $@ $^

#each object file is made by compiling an individual cpp file
# $@ is the target file (e.g. Foo.o) and $< is the individual c++ file
# e.g. Foo.cpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# this is the clean target. It just removes all the object files and deletes the end binary
clean:
	rm -rf *.o
	rm $(APPNAME)