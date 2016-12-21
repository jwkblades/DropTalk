FLAGS:=-Wall -pedantic -std=c++11
CC:=g++

EXE=DropTalk

.cpp.o:
	${CC} ${FLAGS} -c $^ -o $@

${EXE}: main.o DropTable.o Ratio.o
	${CC} ${FLAGS} -o $@ $^

.Phony: clean

clean:
	@rm -f *.o ${EXE}
