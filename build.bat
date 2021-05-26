mkdir build
copy TodoList.pro build\TodoList.pro
cd build
qmake TodoList.pro
mingw32-make Makefile release
windeployqt --quick bin\
cd ..

