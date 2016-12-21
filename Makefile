FLAGS:=-Wall -pedantic -std=c++11
CC:=g++

EXE=DropTalk

.cpp.o:
	${CC} ${FLAGS} -c $@ $^

${EXE}: main.cpp DropTable.cpp Ratio.cpp
	${CC} ${FLAGS} -o $@ $^

.Phony: clean

clean:
	@rm -f *.o ${EXE}
