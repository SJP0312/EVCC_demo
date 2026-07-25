PROJECT := EVCC_demo
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include
SOURCE_DIRS := \
	$(SRC_DIR) \
	L0_BSW_Layer/Lib_1/source \
	L0_BSW_Layer/Lib_2/source \
	L0_BSW_Layer/Lib_3/source \
	L1_RTE_Layer/Interface/source \
	L1_RTE_Layer/OS/source \
	L2_APP_Layer/App_1/source \
	L2_APP_Layer/App_2/source \
	L2_APP_Layer/App_3/source

INCLUDE_DIRS := \
	$(INC_DIR) \
	L0_BSW_Layer/Lib_1/include \
	L0_BSW_Layer/Lib_2/include \
	L0_BSW_Layer/Lib_3/include \
	L1_RTE_Layer/Interface/include \
	L1_RTE_Layer/OS/include \
	L2_APP_Layer/App_1/include \
	L2_APP_Layer/App_2/include \
	L2_APP_Layer/App_3/include

CC := gcc
CXX := g++
THREAD_LINK ?= dynamic

C_SOURCES := $(strip $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.c)))
CPP_SOURCES := $(strip $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.cpp)))
C_OBJECTS := $(addprefix $(BUILD_DIR)/,$(C_SOURCES:.c=.c.o))
CPP_OBJECTS := $(addprefix $(BUILD_DIR)/,$(CPP_SOURCES:.cpp=.cpp.o))
OBJECTS := $(C_OBJECTS) $(CPP_OBJECTS)
TARGET := $(BUILD_DIR)/$(PROJECT).exe
LINKER := $(if $(CPP_SOURCES),$(CXX),$(CC))

CPPFLAGS := $(addprefix -I,$(INCLUDE_DIRS)) -MMD -MP
CFLAGS := -std=c17 -Wall -Wextra -g -O0 -pthread
CXXFLAGS := -std=c++17 -Wall -Wextra -g -O0 -pthread
ifeq ($(THREAD_LINK),static)
LDFLAGS := -static -static-libgcc
LDLIBS := -pthread -Wl,-Bstatic -lwinpthread -Wl,-Bdynamic
else ifeq ($(THREAD_LINK),dynamic)
LDFLAGS :=
LDLIBS := -pthread
else
$(error THREAD_LINK must be dynamic or static)
endif

vpath %.c $(SOURCE_DIRS)
vpath %.cpp $(SOURCE_DIRS)

.PHONY: all run clean rebuild print-vars

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(LINKER) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/%.c.o: %.c | $(BUILD_DIR)
	@if not exist "$(@D)" mkdir "$(@D)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp | $(BUILD_DIR)
	@if not exist "$(@D)" mkdir "$(@D)"
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
	@echo INCLUDE_DIRS=$(INCLUDE_DIRS)
	@echo THREAD_LINK=$(THREAD_LINK)

-include $(OBJECTS:.o=.d)
