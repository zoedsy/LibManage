main:main.exe

main.exe:login/main.cpp src/book.cpp  src/libTime.cpp src/library.cpp src/person.cpp src/trace.cpp
	g++ -std=c++11 login/main.cpp src/* -omain.exe

