CC=gcc
CXX=g++
CFLAGS=-Wall -g
CXXFLAGS=

SRC=src
OBJ=objs

CSRCS=$(wildcard $(SRC)/*.c)
CPPSRCS=$(wildcard $(SRC)/*.cpp)

COBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CSRCS)) 
CPPOBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(CPPSRCS))

BIN=bin
OUT=pseudo

MAIN_FILE=$(SRC)/main.cpp

$(BIN)/$(OUT): $(COBJS) $(CPPOBJS)
	$(CXX) -o $@ $(MAIN_FILE)

$(COBJS): $(CSRCS)
	$(CC) $(CFLAGS) -c -o %@ $<

$(CPPOBJS): $(CPPSRCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run:
	@echo "Program output:"
	@$(BIN)/./$(OUT)

clean:
	$(RM) $(OBJ)/* $(BIN)/*