# ===== Mini Blockchain — Makefile =====

APP      := mini_blockchain

# Toolchain
CXX      ?= c++
STD      ?= c++23                   # latest stable version
WARN     := -Wall -Wextra -Wpedantic
OPT_DBG  := -O0 -g3
OPT_REL  := -O2 -DNDEBUG
CXXFLAGS := $(WARN) -std=$(STD) -Iinclude -MMD -MP

# Dirs
SRCDIR   := src
INCDIR   := include
OBJDIR   := build
BINDIR   := bin

# Sources / Objects
SOURCES  := $(wildcard $(SRCDIR)/*.cpp) main.cpp
OBJECTS  := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
DEPS     := $(OBJECTS:.o=.d)

TARGET   := $(BINDIR)/$(APP)

# Build mode: release (default) or debug
MODE ?= release
ifeq ($(MODE),debug)
  CXXFLAGS += $(OPT_DBG)
else
  CXXFLAGS += $(OPT_REL)
endif

.PHONY: all debug release re clean fclean run dirs help

all: dirs $(TARGET)

debug: MODE=debug
debug: re

release: MODE=release
release: re

re: fclean all

$(TARGET): $(OBJECTS)
	@echo "Linking $@"
	@$(CXX) $(OBJECTS) -o $@

# Compile *.cpp -> build/*.o (mirrors directory structure)
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

dirs:
	@mkdir -p $(OBJDIR)/$(SRCDIR) $(BINDIR)

run: all
	@$(TARGET)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Cleaning binary"
	@rm -rf $(BINDIR)

help:
	@echo "Targets:"
	@echo "  make            - build (release)"
	@echo "  make debug      - build with debug flags"
	@echo "  make release    - build with release flags"
	@echo "  make run        - build then run"
	@echo "  make clean      - remove objects"
	@echo "  make fclean     - remove objects and binary"

-include $(DEPS)
