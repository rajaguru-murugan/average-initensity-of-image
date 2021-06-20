all: avg_intensity
.PHONY: avg_intensity

avg_intensity:
	g++ -O3 -Wall -o avg_intensity ../src/avg_intensity.cpp `pkg-config --cflags --libs opencv` -std=c++11

clean:
	rm avg_intensity
