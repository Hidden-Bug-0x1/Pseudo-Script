CC=gcc
CXX=g++
CFLAGS=-Wall -g
CXXFLAGS=-Wall -g -std=c++17

SRC=src
OBJ=objs

CSRCS=$(wildcard $(SRC)/*.c)
CPPSRCS=$(wildcard $(SRC)/*.cpp)

COBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CSRCS)) 
CPPOBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(CPPSRCS))

BIN=bin
OUT=pseudo

MAIN_FILE=$(OBJ)/main.o

$(BIN)/$(OUT): $(COBJS) $(CPPOBJS) $(MAIN_FILE)
	$(CXX) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< $(CFLAGS) -o $@ 

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

run:
	@echo "Program output:"
	@$(BIN)/./$(OUT)

clean:
	$(RM) $(OBJ)/* $(BIN)/*