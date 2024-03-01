.PHONY: all install uninstall clean dvi dist tests

FLAGS = gcc -lstdc++ -pedantic -Wall -Werror -Wextra -std=c++17
SOURCES_TEST = 3DViewer/Model/CalculationsClass/Parcer/parcer.cc 3DViewer/Model/Data/Iterator/vertexiterator.cc 3DViewer/Model/CalculationsClass/calculationsclass.cc
TEST = tests/test.cc

all: clean test install dist dvi open

clean:
	rm -rf *.o *.a test

test: clean
	$(FLAGS) $(SOURCES_TEST) $(TEST) -lgtest -lpthread -o test
	./test

install: clean uninstall
	mkdir build
	cd 3DViewer && qmake && make -j6 && make clean && rm Makefile
	mv 3DViewer/3DViewer.app build
	rm 3DViewer/.qmake.stash

dist:
	rm -rf Archive_3DViewer_v2.0/
	mkdir Archive_3DViewer_v2.0/
	mkdir Archive_3DViewer_v2.0/src
	cp -r ./build/3DViewer.app Archive_3DViewer_v2.0/src/
	tar cvzf Archive_3DViewer_v2.0.tgz Archive_3DViewer_v2.0/
	rm -rf Archive_3DViewer_v2.0/

open:
	./build/3DViewer.app/Contents/MacOS/3DViewer

dvi:
	open readme.md

uninstall:
	-rm -rf build

leak:
	leaks --atExit -- ./build/3DViewer.app/Contents/MacOS/3DViewer

check_style:
	cp ../materials/linters/.clang-format ./3DViewer
	find . \( -name '*.h' -o -name '*.cc' -o -name '*.cpp' \) -print0 | xargs -0 clang-format -n
	rm 3DViewer/.clang-format
