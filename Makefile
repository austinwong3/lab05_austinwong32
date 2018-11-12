CXX=g++

CXXFLAGS= -std=c++11 -Wall -g

BINARIES=lab05Test

all: ${BINARIES}

lab05Test: lab05Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o