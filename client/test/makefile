# ============================================================================
# Конфигурация проекта
# ============================================================================

# Имя исполняемого файла
ifeq ($(OS),Windows_NT)
	TARGET      = test.exe
	CXXDEPFLAGS = -I"$(MinGW-w64)/SFML/include"
	LDDEPFLAGS  = -L"$(MinGW-w64)/SFML/bin" -L"$(MinGW-w64)/SFML/lib"
	LDFLAGS     = $(LDDEPFLAGS) -lsfml-window -lsfml-graphics -lsfml-system -lopengl32 -lgdi32 -lwinmm -lfreetypeL
	GCHS        = Main.pch
else
	TARGET      = test
	CXXDEPFLAGS =
	LDDEPFLAGS  =
	LDFLAGS     = $(LDDEPFLAGS) -lsfml-window -lsfml-graphics -lsfml-system -lGL
	GCHS        = Main.gch
endif

# Директории
PRJ_DIR   = .
SRC_DIR   = $(PRJ_DIR)/../src
INC_DIR   = $(PRJ_DIR)/../inc
OBJ_DIR   = $(PRJ_DIR)/../obj
BIN_DIR   = $(PRJ_DIR)/../bin

# Компилятор и флаги
CXX       = g++
CXXFLAGS  = -I$(INC_DIR) $(CXXDEPFLAGS) -Wall -Wextra -std=c++20

# ============================================================================
# Автоматическое определение файлов (с поддержкой поддиректорий)
# ============================================================================

# Рекурсивный поиск всех .cpp файлов
SRCS      = $(filter-out $(SRC_DIR)/Main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
# Преобразуем пути .cpp в пути .o
OBJS      = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
PCHS      = Main.hpp

# ============================================================================
# Вспомогательные цели
# ============================================================================

all: tests

test: $(OBJS) main.cpp UnitTests.hpp
	@echo "Сборка тестов"
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)
	@echo "Сборка завершена: $@"

print:
	@echo "$(OBJS)"

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/$(TARGET) $(INC_DIR)/$(GCHS)
	@echo "Очистка завершена"

rebuild: clean all

run: all
	@echo "Запуск программы..."
	@cd $(BIN_DIR) && ./$(TARGET)

# Отладка с цветными сообщениями
debug: CXXFLAGS += -g -DDEBUG -fdiagnostics-color=always
debug: all

release: CXXFLAGS += -O3
release: all

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
	@echo "Сборка цели: $(@)"
#	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "Сборка завершена: $(BIN_DIR)/$(TARGET)"

# Правило для компиляции main.hpp
$(INC_DIR)/$(GCHS): $(INC_DIR)/$(PCHS)
#	@mkdir -p $(dir $@)
	@echo "Сборка цели: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Скомпилирован: $<"

# Правило для компиляции .cpp в .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
#	@mkdir -p $(dir $@)
	@echo "Сборка цели: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Скомпилирован: $<"

.PHONY: all clean rebuild run debug release check print
