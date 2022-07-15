TARGET   := program

ifeq ($(OS),Windows_NT)
	SYSTEM 	= win
	SUFFIX	= .exe
	RUN	= libs/sfml-win/bin/${TARGET}${SUFFIX}
	RUN_TEST= libs/sfml-win/bin/${TARGET}-test${SUFFIX}
	OUT_DIR	= libs/sfml-win/bin/
	MKDIR	= @if not exist $(subst /,\,$(dir $@)) mkdir $(subst /,\,$(dir $@))
	GCOVR	=
	CLEAN	=
else
	SYSTEM 	= linux
	SUFFIX	=
	RUN	= export LD_LIBRARY_PATH=libs/sfml-linux/lib && ./${TARGET}${SUFFIX}
	RUN_TEST= export LD_LIBRARY_PATH=libs/sfml-linux/lib && ./${TARGET}-test${SUFFIX}
	OUT_DIR	= 
	MKDIR	= @mkdir -p $(@D)
	GCOVR	= gcovr -r . --html --html-details -o coverage/relatorio.html --exclude libs/
	CLEAN	= @rm -rf
endif

CC       := g++
CXXFLAGS := -std=c++11 -g -Wall --coverage
LDFLAGS  := -Llibs/sfml-${SYSTEM}/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
BUILD    := ./build
INCLUDE  := -I include -I libs/sfml-${SYSTEM}/include -I libs/doctest/
SRC_DIR  := src
TEST_DIR := tests

SRC      := $(wildcard $(SRC_DIR)/**/**/**/*.cpp) $(wildcard $(SRC_DIR)/**/**/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
SRC_TEST := $(wildcard $(TEST_DIR)/**/**/**/*.cpp) $(wildcard $(TEST_DIR)/**/**/*.cpp) $(wildcard $(TEST_DIR)/**/*.cpp) $(wildcard $(TEST_DIR)/*.cpp)
OBJECTS  := $(SRC:%.cpp=$(BUILD)/%.o)
OBJ_TEST := $(SRC_TEST:%.cpp=$(BUILD)/%.o)


all: $(TARGET)

$(BUILD)/%.o: %.cpp
	${MKDIR}
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET): $(OBJECTS) $(OBJ_TEST)
	${MKDIR}
	$(CXX) $(CXXFLAGS) -o ${OUT_DIR}$(TARGET)${SUFFIX} $(subst build/tests/main-test.o,,$^) $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o ${OUT_DIR}$(TARGET)-test${SUFFIX} $(subst build/src/main.o,,$^) $(LDFLAGS)	

.PHONY: run test
	
run:
	${RUN} 

test:
	${RUN_TEST}
	${GCOVR}
	
clean:
	${CLEAN} ${BUILD}/*
