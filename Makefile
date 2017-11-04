all:
	make -C test .depend
	make -C test

clean:
	make -C test clean

