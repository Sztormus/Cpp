OUTPUT = test

CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS) -std=c++11
CXXFLAGS+=-g

#Dependency for the ouotput file
DEP_FLAGS=-MMD
DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=${SRC:.cpp=.d}
EDT_FILES=$(wildcard *.cpp *.c *.h *.hpp *.inl *.inc *.f)

#Add dependency generation to the compiler options
CXXFLAGS+=$(DEP_FLAGS)

all: $(OUTPUT)
	@echo Kompilacja zakonczona sukcesem. Zbudowano $(OUTPUT)

$(OUTPUT): $(OBJ)
	@$(CXX) $(OBJ) -o $@
	
%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) $<

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f run $(OBJ) $(DEP)

run: $(OUTPUT)
	@./$(OUTPUT)

valgrind: $(OUTPUT)
	@valgrind --leak-check=full ./$(OUTPUT)
zip:
	@tar -czvf Visitor.tar.gz $(EDT_FILES) [mM]akefile

-include $(DEP) 
