all: toes
toes:
	g++ *.h *.cpp -o text-rpg 
	i686-w64-mingw32-g++ *.cpp *.h -o text-rpg.exe
