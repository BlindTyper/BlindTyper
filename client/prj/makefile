# ============================================================================
# Конфигурация проекта
# ============================================================================

# Имя исполняемого файла
ifeq ($(OS),Windows_NT)
	TARGET      = blind_typer.exe
	CXXDEPFLAGS = -I"E:/mingw64/SFML/include"
	LDDEPFLAGS  = -L"E:/mingw64/SFML/bin" -L"E:/mingw64/SFML/lib"
	LDFLAGS     = $(LDDEPFLAGS) -lsfml-window -lsfml-graphics -lsfml-system -lopengl32 -lgdi32 -lwinmm -mwindows -lfreetypeL
	GCHS        = main.pch
else
	TARGET      = blind_typer
	CXXDEPFLAGS =
	LDDEPFLAGS  =
	LDFLAGS     = $(LDDEPFLAGS) -lsfml-window -lsfml-graphics -lsfml-system -lGL
	GCHS        = main.gch
endif

# Директории
PRJ_DIR   = .
SRC_DIR   = $(PRJ_DIR)/../src
INC_DIR   = $(PRJ_DIR)/../inc
OBJ_DIR   = $(PRJ_DIR)/../obj
BIN_DIR   = $(PRJ_DIR)/../bin

# Компилятор и флаги
CXX       = g++
CXXFLAGS  = -I$(INC_DIR) $(CXXDEPFLAGS) -Wall -Wextra -std=c++17

# ============================================================================
# Автоматическое определение файлов (с поддержкой поддиректорий)
# ============================================================================

# Рекурсивный поиск всех .cpp файлов
SRCS      = $(shell find $(SRC_DIR) -name "*.cpp")
# Преобразуем пути .cpp в пути .obj
OBJS      = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.obj,$(SRCS))
PCHS      = main.hpp

# ============================================================================
# Вспомогательные цели
# ============================================================================

all: $(INC_DIR)/$(GCHS) $(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/$(TARGET) $(INC_DIR)/$(GCHS)
	@echo "Очистка завершена"

rebuild: clean all

run: all
	@echo "Запуск программы..."
	@cd $(BIN_DIR) && ./$(TARGET)

# Отладка с цветными сообщениями
debug: CXXFLAGS += -g -DDEBUG -fdiagnostics-color=always
debug: clean all

release: CXXFLAGS += -O3 -DNDEBUG
release: clean all

# Проверка исходного кода
check:
	@echo "Проверка исходных файлов:"
	@echo "Количество .cpp файлов: $(words $(SRCS))"
	@echo "Список файлов:"
	@$(foreach src,$(SRCS),echo "  $(src)";)


# ============================================================================
# Основные цели
# ============================================================================

# Основная цель - сборка исполняемого файла
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "Сборка завершена: $(BIN_DIR)/$(TARGET)"

# Правило для компиляции main.hpp
$(INC_DIR)/$(GCHS): $(INC_DIR)/$(PCHS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Скомпилирован: $<"

# Правило для компиляции .cpp в .obj
$(OBJ_DIR)/%.obj: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Скомпилирован: $<"

.PHONY: all clean rebuild run debug release check

# SRC = $(wildcard ../src/*.cpp)
# O = $(SRC:.cpp=.o)
# OBJ = $(O:/src/=/obj/)
#
# all: win
#
# linux: $(OBJ)
# 	g++ ../src/mainWindow.cpp -c -o ../obj/main.o -I"../inc"
# 	g++ ../obj/*.o -o ../bin/_prog -lsfml-window -lsfml-graphics -lsfml-system -lGL
#
# ../obj/%.o: ../src/%.cpp
# 	g++ -I"../inc" -c -o $@ $<
#
# win:
# 	g++ ../src/mainWindow.cpp -c -o ../obj/main.o -I"E:/mingw64/SFML/include"
# 	g++ ../obj/*.o -o ../bin/_prog.exe -lsfml-window -lsfml-graphics -lsfml-system -lopengl32 -lgdi32 -lwinmm -mwindows -lfreetype -L"E:/mingw64/SFML/lib" -L"E:/mingw64/SFML/bin"
#
# obj_cpp:
# 	g++ ../src/imgui_demo.cpp -c -o ../obj/imgui_demo.o -I"E:/mingw64/SFML/include" -I"inc"
# 	g++ ../src/imgui_draw.cpp -c -o ../obj/imgui_draw.o -I"E:/mingw64/SFML/include" -I"inc"
# 	g++ ../src/imgui_tables.cpp -c -o ../obj/imgui_tables.o -I"E:/mingw64/SFML/include" -I"inc"
# 	g++ ../src/imgui_widgets.cpp -c -o ../obj/imgui_widgets.o -I"E:/mingw64/SFML/include" -I"inc"
# 	g++ ../src/imgui-SFML.cpp -c -o ../obj/imgui-SFML.o -I"E:/mingw64/SFML/include" -I"inc"
# 	g++ ../src/imgui.cpp -c -o ../obj/imgui.o -I"E:/mingw64/SFML/include" -I"inc"
