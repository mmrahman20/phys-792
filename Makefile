.PHONY: all clean

CXXFLAGS = -Wall -O2
CXXFLAGS+= $(shell root-config --cflags)

LIBS = $(shell root-config --libs)

RM = rm -fr
SRC = $(wildcard *.cc)
EXE = $(SRC:.cc=.exe)

all: $(EXE)

%.exe: %.cc
	$(CXX) $(CXXFLAGS) $(LIBS) $< -o $@

install:
	mv *.exe ~/bin/
info:
	@echo $(SRC)
	@echo $(EXE)
	@echo $(LIBS)

clean:
	$(RM) *.exe
