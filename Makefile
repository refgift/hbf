.c.o:
	cc -c $< -O3
.cc.o:
	c++ -std=c++20 -c $< -O3

hbf:	hbf.o reduce.o
	c++ $^ -o $@

clean:
	rm *.o

deploy:
	cp hbf /usr/local/bin

install: hbf
	systemctl stop hpf || true
	cp $< /usr/local/bin || true
	cp $<.service /etc/systemd/system
	systemctl enable hbf
	systemctl start hbf
	systemctl status hbf
