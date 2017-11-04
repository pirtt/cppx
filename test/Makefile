CC=g++
FLAG=-std=c++11 -g -Wall -pthread -fPIC
app_name=th_app
test_list=$(shell find ./ -name "*.cpp")
test_app=$(basename $(test_list))
test_o	=$(addsuffix .o,$(test_app))

.PHONY=all clean .depend

all:$(app_name) .depend $(test_app)
	@if [ ! -f .depend ];then echo "Error:you must make .depend ";exit 1; fi
$(app_name):

.depend:
	$(foreach app,$(test_app),$(shell echo "$(app):$(app).o\n\t$(CC) $(app).o $(FLAG) -o $(app) ">>$@))
include .depend

%.o:%.cpp
	$(CC) -c $^ -std=c++11

clean:
	rm $(test_app) .depend *.o

