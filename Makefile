CC       := gcc
INCLUDES := -I./include
CFLAGS   := -Wall -Wextra -Wpedantic -std=c11 -O0 -g -fstack-usage -pthread \
             $(INCLUDES) -MMD -MP 
LDFLAGS  :=

CPPCHECK   := cppcheck
CLANG_TIDY := clang-tidy

SRC_DIR  := source
INC_DIR  := include
BUILD_DIR:= build
TARGET   := $(BUILD_DIR)/student_list

SRC      := $(wildcard $(SRC_DIR)/*.c)
OBJ      := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS     := $(OBJ:.o=.d)

.PHONY: all
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Include auto-generated dependency files
-include $(DEPS)


.PHONY: check tidy analyze

cppcheck:
	$(CPPCHECK) --enable=all --suppress=missingIncludeSystem \
	--error-exitcode=1 $(SRC_DIR) $(INC_DIR)

clangtidy:
	$(CLANG_TIDY) $(SRC) -checks=bugprone-*,clang-analyzer-*,cert-*,portability-* \
	-- $(INCLUDES)

analyze: cppcheck clangtidy

.PHONY: run clean debug rebuild

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -O0
debug: rebuild

rebuild: clean all

clean:
	$(RM) -r $(BUILD_DIR)