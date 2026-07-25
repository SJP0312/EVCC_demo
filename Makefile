PROJECT := EVCC_demo
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include

CC := gcc
CXX := g++

C_SOURCES := $(wildcard $(SRC_DIR)/*.c)
CPP_SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
C_OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.c.o,$(C_SOURCES))
CPP_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.cpp.o,$(CPP_SOURCES))
OBJECTS := $(C_OBJECTS) $(CPP_OBJECTS)
TARGET := $(BUILD_DIR)/$(PROJECT).exe
LINKER := $(if $(CPP_SOURCES),$(CXX),$(CC))

CPPFLAGS := -I$(INC_DIR) -MMD -MP
CFLAGS := -std=c17 -Wall -Wextra -g -O0
CXXFLAGS := -std=c++17 -Wall -Wextra -g -O0
LDFLAGS :=
LDLIBS :=

.PHONY: all run clean rebuild print-vars

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(LINKER) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/%.c.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

run: all
	./$(TARGET)

clean:
	if exist "$(BUILD_DIR)" rmdir /S /Q "$(BUILD_DIR)"

rebuild: clean all

print-vars:
	@echo PROJECT=$(PROJECT)
	@echo C_SOURCES=$(C_SOURCES)
	@echo CPP_SOURCES=$(CPP_SOURCES)
	@echo TARGET=$(TARGET)

-include $(OBJECTS:.o=.d)