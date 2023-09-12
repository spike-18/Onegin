FLAGS = 

debug:
		g++ $(FLAGS) main.cpp -DDEBUG -o prog
release:
		g++ $(FLAGS) main.cpp -o prog