###################################
# OS COURSE - 2017
# Jan Ocampo & Thomas Griffin
#Assignment 1: Process control block
#2/13/17
###################################
CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm			# linked libraries	
LDFLAGS = -L.			# link flags
PROG = assignment1			# target executable (output)
SRC = main.cpp queue.cpp PCB.cpp readyqueue.cpp # .c or .cpp source files.
OBJ = $(SRC:.cpp=.o) 	# object files for the target. Add more to this and next lines if there are more than one source files.

all : $(PROG)

$(PROG): $(OBJ) 
	$(CC) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

# cleanup
clean:
	/bin/rm -f *.o $(PROG)

# DO NOT DELETE
