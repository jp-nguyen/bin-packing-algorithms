CXXFLAGS=-std=c++14
HEADERS=project2.h utils.h
SOURCES= \
	main.cpp\
	next_fit.cpp \
	first_fit.cpp \
	best_fit.cpp \
	utils.cpp

proj2: $(HEADERS) $(SOURCES)
	g++ $(CXXFLAGS) $(SOURCES) -o proj2

clean:
	rm -rf proj2 *.csv
