CC = g++
FLAGS = -Wall






html_pages: html_pages.o
	$(CC) -o $@ $^

html_pages.o: html_pages.cpp
	$(CC) $(FLAGS) -c -o $@ $^ 


PHONY: clean
clean:
	rm -f html_pages
	rm -f *.o

