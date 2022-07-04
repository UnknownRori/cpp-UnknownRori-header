COMPILER = g++
COMPILER_FLAG = -shared
SOURCE = ./src/UnknownRori.cpp
OUTPUT = ./bin/UnknownRori.o

all: build
	./bin/main
build: libs
	$(COMPILER) main.cpp $(OUTPUT) -o ./bin/main
libs:
	$(COMPILER) $(SOURCE) -shared -o $(OUTPUT)
