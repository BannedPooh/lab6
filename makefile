all: stats rhymes

stats: stats.cpp
	g++ -o stats stats.cpp -Wall -std=c++11

rhymes: rhymes.cpp
	g++ -o rhymes rhymes.cpp -Wall -std=c++11

clean:
	rm -rf stats rhymes