S_DIR=src
O_DIR=obj
B_DIR=bin

game: $(O_DIR)/main.o $(O_DIR)/Game.o $(O_DIR)/TextureManager.o $(O_DIR)/GameObject.o
	g++ $(O_DIR)/main.o $(O_DIR)/Game.o $(O_DIR)/TextureManager.o $(O_DIR)/GameObject.o -o $(B_DIR)//game `pkg-config --cflags --libs sdl2`

$(O_DIR)/main.o: $(S_DIR)/main.cpp
	g++ -c $(S_DIR)/main.cpp `pkg-config --cflags --libs sdl2` -o $(O_DIR)/main.o

$(O_DIR)/Game.o: $(S_DIR)/Game.cpp $(S_DIR)/Game.h
	g++ -c $(S_DIR)/Game.cpp `pkg-config --cflags --libs sdl2` -o $(O_DIR)/Game.o

$(O_DIR)/TextureManager.o: $(S_DIR)/TextureManager.cpp $(S_DIR)/TextureManager.h
	g++ -c $(S_DIR)/TextureManager.cpp `pkg-config --cflags --libs sdl2` -o $(O_DIR)/TextureManager.o

$(O_DIR)/GameObject.o: $(S_DIR)/GameObject.cpp $(S_DIR)/GameObject.h
	g++ -c $(S_DIR)/GameObject.cpp `pkg-config --cflags --libs sdl2` -o $(O_DIR)/GameObject.o

clean:
	rm $(O_DIR)/*.o $(B_DIR)/game