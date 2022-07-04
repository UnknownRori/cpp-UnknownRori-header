SOURCE = main.cpp
OUTPUT = ./bin/main
COMPILER = g++

all: build
	$(COMPILER) $(SOURCE) -o $(OUTPUT)
	$(OUTPUT)
