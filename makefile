main: driver.cpp
	g++ -Wall -o main driver.cpp tollBooth.cpp truck.cpp car.cpp

run: main
	./main toll.txt

clean:
	rm main
	rm dailyTotals.txt
