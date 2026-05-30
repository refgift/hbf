.cc.o:
	g++ -std=c++20 -c $< -O3

hbf:	hbf.o reduce.o
	g++ $^ -o $@

clean:
	rm *.o

deploy:
	cp hbf /usr/sbin
