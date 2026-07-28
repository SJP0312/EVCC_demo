PROJECT := EVCC_demo
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include
AUTOSAR_COMMON_DIR := L0_BSW_Layer/_Common/Autosar_Common
APP_SOURCE_ROOTS := \
	L2_APP_Layer/App_1/source \
	L2_APP_Layer/App_2/source \
	L2_APP_Layer/App_3/source \
	L2_APP_Layer/App_4/source \
	L2_APP_Layer/App_5/source

SOURCE_ROOTS := \
	$(SRC_DIR) \
	L0_BSW_Layer \
	L1_RTE_Layer \
	L2_APP_Layer \
	$(APP_SOURCE_ROOTS)

HEADER_ROOTS := \
	$(AUTOSAR_COMMON_DIR) \
	$(INC_DIR) \
	L0_BSW_Layer \
	L1_RTE_Layer \
	L2_APP_Layer

rwildcard = $(strip $(foreach entry,$(wildcard $1*),$(call rwildcard,$(entry)/,$2) $(filter $(subst *,%,$2),$(entry))))

HEADER_FILES := $(sort \
	$(foreach root,$(HEADER_ROOTS),$(call rwildcard,$(root)/,*.h)) \
	$(foreach root,$(HEADER_ROOTS),$(call rwildcard,$(root)/,*.hpp)))
INCLUDE_DIRS := $(sort $(patsubst %/,%,$(dir $(HEADER_FILES))))

CC := gcc
CXX := g++
THREAD_LINK ?= dynamic
DISABLE_AUTOSAR_MEMMAP ?= 1

EXCLUDED_C_SOURCES := \
	L0_BSW_Layer/IpBase/_Appl_Rand.c \
	L0_BSW_Layer/IpBase/_Appl_Time.c

C_SOURCES := $(filter-out $(EXCLUDED_C_SOURCES),$(sort $(foreach root,$(SOURCE_ROOTS),$(call rwildcard,$(root)/,*.c))))
CPP_SOURCES := $(sort $(foreach root,$(SOURCE_ROOTS),$(call rwildcard,$(root)/,*.cpp)))
C_OBJECTS := $(addprefix $(BUILD_DIR)/,$(C_SOURCES:.c=.c.o))
CPP_OBJECTS := $(addprefix $(BUILD_DIR)/,$(CPP_SOURCES:.cpp=.cpp.o))
OBJECTS := $(C_OBJECTS) $(CPP_OBJECTS)
TARGET := $(BUILD_DIR)/$(PROJECT).exe
LINKER := $(if $(CPP_SOURCES),$(CXX),$(CC))

CPPFLAGS := $(addprefix -I,$(INCLUDE_DIRS)) -MMD -MP
ifeq ($(DISABLE_AUTOSAR_MEMMAP),1)
CPPFLAGS += -DMICROSAR_DISABLE_MEMMAP
endif
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

rebuild: clean
	$(MAKE) all

print-vars:
	@echo PROJECT=$(PROJECT)
	@echo C_SOURCES=$(C_SOURCES)
	@echo CPP_SOURCES=$(CPP_SOURCES)
	@echo TARGET=$(TARGET)
	@echo INCLUDE_DIRS=$(INCLUDE_DIRS)
	@echo THREAD_LINK=$(THREAD_LINK)
	@echo DISABLE_AUTOSAR_MEMMAP=$(DISABLE_AUTOSAR_MEMMAP)

-include $(OBJECTS:.o=.d)
