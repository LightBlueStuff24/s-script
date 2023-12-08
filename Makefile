CC = clang
CFLAGS = -Wall -Wextra -Isrc/include -std=c11  # Adjust flags as needed

SRC_DIR = src
BUILD_DIR = build
TARGET = sscript

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
run:
	make
	cp sscript ~/sscript
	cp ./test/main.ss ~/main.ss
	chmod +x sscript
	echo "\n\n"
	~/sscript ~/main.ss