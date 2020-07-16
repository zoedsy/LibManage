# test by mingw32-make
main:main.exe
obj = src/book.obj src/libTime.obj src/library.obj src/person.obj src/trace.obj
OutFilePath = src
StaticLibName = library
StaticLibPath = src
main.exe:login/main.cpp $(obj)
	g++ -std=c++11 login/main.cpp $(obj) -o main.exe

src/book.obj:src/book.cpp  
	g++ -c src/book.cpp -o src/book.obj
src/libTime.obj:src/libTime.cpp  
	g++ -c src/libTime.cpp -o src/libTime.obj
src/library.obj:src/library.cpp
	g++ -c src/library.cpp -o src/library.obj
src/person.obj:src/person.cpp
	g++ -c src/person.cpp -o src/person.obj
src/trace.obj:src/trace.cpp
	g++ -c src/trace.cpp -o src/trace.obj

libMake:lib$(StaticLibName).a
	g++ -std=c++11 login/main.cpp -L $(StaticLibPath) -l $(StaticLibName) -o main.exe
static:$(obj)
	ar -rc liblibrary.a $(obj)
clean:$(obj) $(StaticLibPath)/lib$(StaticLibName).a
	rm src/book.obj 
	rm src/libTime.obj 
	rm src/library.obj 
	rm src/person.obj 
	rm src/trace.obj 
	rm $(StaticLibPath)/lib$(StaticLibName).a
	echo 'clean done'