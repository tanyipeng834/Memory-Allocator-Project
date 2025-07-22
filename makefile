CC = gcc
TARG = memory
TEST_TARG = run_tests
OPTS = -Wall -O -g -Werror
SRC_DIR = src
INC_DIR = include
TEST_DIR = test
BUILD_DIR = build

CFLAGS = -I$(INC_DIR) $(OPTS)

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
SRC_OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.test.o, $(TEST_FILES))

# Default
all: $(TARG)

# Create build dir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Main target
$(TARG): $(BUILD_DIR) $(SRC_OBJS)
	$(CC) -o $@ $(CFLAGS) $(SRC_OBJS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run tests
test: $(BUILD_DIR) $(SRC_OBJS) $(TEST_OBJS)
	$(CC) -o $(TEST_TARG) $(CFLAGS) $(SRC_OBJS) $(TEST_OBJS)
	./$(TEST_TARG)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARG) $(TEST_TARG)
