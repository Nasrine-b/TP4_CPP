CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS=
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= tab2D

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC) res_reactions.txt res_normalisation.txt

distclean : clean
