GCC       = gcc -g -O0 -Wall -Wextra -std=gnu99
CSOURCE   = numsort.c linesort.c inssort.c
CHEADER   = inssort.h
OBJECTS   = ${CSOURCE:.c=.o}
EXECBIN   = numsort linesort

all : numsort linesort

numsort : numsort.o inssort.o

linesort : linesort.o inssort.o

%.o : %.c
	${GCC} -c $<

ci : ${CSOURCE}
	checksource ${CSOURCE}
	ci ${CSOURCE}

clean :
	- rm -vf ${EXECBIN} 

spotless : clean
	- rm -vf ${EXECBIN}
	- rm -vf linesort.o inssort.o numsort.o

