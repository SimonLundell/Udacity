#Collect all source files
sources = $(wildcard src/*.cpp)
#Rename source-files from .cpp -> .o
objects = $(sources:.cpp=.o)
#Name of the outputprogram
executable = PersonProgram

compiler = g++
# Tell where to search for headers - DOesnt work for now
flags = -I./include

$(executable): $(objects)
	$(compiler) $(objects) -o $@

%.o: %.cpp include/%.hpp
	$(compiler) -c $< -o $@