all: win

linux: obj
	g++ src/mainWindow.cpp -c -o obj/main.o
	g++ obj/*.o -o bin/_prog -lsfml-window -lsfml-graphics -lsfml-system -lGL

obj:
	g++ src/imgui_demo.cpp -c -o obj/imgui_demo.o -I"inc"
	g++ src/imgui_draw.cpp -c -o obj/imgui_draw.o -I"inc"
	g++ src/imgui_tables.cpp -c -o obj/imgui_tables.o -I"inc"
	g++ src/imgui_widgets.cpp -c -o obj/imgui_widgets.o -I"inc"
	g++ src/imgui-SFML.cpp -c -o obj/imgui-SFML.o -I"inc"
	g++ src/imgui.cpp -c -o obj/imgui.o -I"inc"

win:
	g++ src/mainWindow.cpp -c -o obj/main.o -I"E:/mingw64/SFML/include"
	g++ obj/*.o -o bin/_prog.exe -lsfml-window -lsfml-graphics -lsfml-system -lopengl32 -lgdi32 -lwinmm -mwindows -lfreetype -L"E:/mingw64/SFML/lib" -L"E:/mingw64/SFML/bin"
	
obj_cpp: 
	g++ src/imgui_demo.cpp -c -o obj/imgui_demo.o -I"E:/mingw64/SFML/include" -I"inc"
	g++ src/imgui_draw.cpp -c -o obj/imgui_draw.o -I"E:/mingw64/SFML/include" -I"inc"
	g++ src/imgui_tables.cpp -c -o obj/imgui_tables.o -I"E:/mingw64/SFML/include" -I"inc"
	g++ src/imgui_widgets.cpp -c -o obj/imgui_widgets.o -I"E:/mingw64/SFML/include" -I"inc"
	g++ src/imgui-SFML.cpp -c -o obj/imgui-SFML.o -I"E:/mingw64/SFML/include" -I"inc"
	g++ src/imgui.cpp -c -o obj/imgui.o -I"E:/mingw64/SFML/include" -I"inc"
	
