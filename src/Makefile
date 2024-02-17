# Const
CPP=g++ -std=c++17 -Wall -Werror -Wextra
LDFLAGS= -lcheck -lm
GCOVFLAGS= --coverage -O0 -g -fprofile-arcs -ftest-coverage
TESTFLAGS= -lgtest -lgtest_main
SRCS= tests/*.[ch]* MVC/controller/*.[ch]* MVC/model/*.[ch]* MVC/view/*.[ch]* patterns/*.[ch]*
OS := $(shell uname)

# Linux lib fix
ifeq ($(OS), Linux)
LDFLAGS += -lsubunit -lrt -pthread
OPEN_CMD= xdg-open
QMAKE = qmake6
else 
LDFLAGS+= -lpthread
OPEN_CMD = open
QMAKE = qmake
endif

.PHONY: all install uninstall run dvi dist clean gcov_report lcov_report clang_i clang_n rebuild cppcheck valgrind

all: uninstall install run

install: uninstall
	mkdir build
	@mkdir MVC/view/3rdparty
	cd MVC/view/3rdparty && git clone https://github.com/dbzhang800/QtGifImage.git
	cd build && $(QMAKE) ../MVC/view/viewer.pro -o makefile_f
	cd build && make -f makefile_f
	cd build && rm -rf *.o *.cpp *.h makefile_f .qmake.stash

uninstall:
	rm -rf build* MVC/view/3rdparty/*

run:
ifeq ($(OS), Linux)
	build/viewer
else
	open build/viewer.app
endif

dvi:
	rm -rf doxygen/doc
	cd doxygen && doxygen ./config
	$(OPEN_CMD) ./doxygen/doc/html/index.html

dist: clean uninstall
	cd MVC/view/3rdparty && git clone https://github.com/dbzhang800/QtGifImage.git
	tar -cvzf 3D_Viewer_v2.0.tar.gz Makefile MVC tests

test: clean build_tests
	./tests.out

build_tests:
	$(CPP) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) tests/*.cc  MVC/model/*.cc -o tests.out

build_tests_debug:
	$(CPP) $(CPPFLAGS) $(LDFLAGS) $(GCOVFLAGS) $(TESTFLAGS) tests/*.cc  MVC/model/*.cc -o tests.out

clean:
	rm -rf report *.tar doxygen/doc *.gcno *.gcda *.dSYM *.out

rebuild: clean all

gcov_report: clean build_tests_debug
	./tests.out || true
	@mkdir -p report
	gcovr --html --html-details -o report/index.html
	$(OPEN_CMD) report/index.html

clang_i:
	clang-format -i --style=Google $(SRCS)

clang_n:
	clang-format -n --style=Google $(SRCS)

leaks: clean build_tests
	leaks --atExit -- ./tests.out

valgrind: clean build_tests
	export CK_FORK=no && valgrind --tool=memcheck --leak-check=yes ./tests.out
