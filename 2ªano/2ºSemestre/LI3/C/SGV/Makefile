CC      = gcc
LD      = gcc
CFLAGS  = -O2 -Wall -Wextra -g -ansi -D_GNU_SOURCE `pkg-config --cflags glib-2.0`
CFLAGS += -Wno-unused-parameter -Wno-unused-function -Wno-unused-result
LIBS = `pkg-config --libs glib-2.0`
INCLDS  = -I $(INC_DIR)
BIN_DIR = bin
BLD_DIR = build
DOC_DIR = docs
INC_DIR = include
LOG_DIR = log
OUT_DIR = out
SRC_DIR = src
TST_DIR = tests
SRC     = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRC))
DEPS    = $(patsubst $(BLD_DIR)/%.o,$(BLD_DIR)/%.d,$(OBJS))
PROGRAM = sgv

vpath %.c $(SRC_DIR)

.DEFAULT_GOAL = build

.PHONY: build setup clean debug doc fmt lint run test

$(BLD_DIR)/%.d: %.c
	$(CC) -M $(INCLDS) $(CFLAGS) $< -o $@ $(LIBS)

$(BLD_DIR)/%.o: %.c
	$(CC) -c $(INCLDS) $(CFLAGS) $< -o $@ $(LIBS)

$(BIN_DIR)/$(PROGRAM): $(DEPS) $(OBJS)
	$(CC) $(INCLDS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

build: setup $(BIN_DIR)/$(PROGRAM)

run: build
	@./$(BIN_DIR)/$(PROGRAM)

fmt:
	@echo "C and Headers files:"
	@-clang-format -style="{BasedOnStyle: Google, IndentWidth: 4}" -verbose -i \
		$(SRC_DIR)/* $(INC_DIR)/*
	@echo ""
	@echo "Shell files:"
	@shfmt -l -w -i 2 .

lint:
	@splint -retvalint -hints -I $(INC_DIR) \
		$(SRC_DIR)/*

debug: CFLAGS = -Wall -Wextra -ansi -pedantic -O0 -g
debug: build
	gdb ./$(BIN_DIR)/$(PROGRAM)

doc:
	@den $(DOC_DIR)/Doxyfile

setup:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BLD_DIR)
	@mkdir -p $(DOC_DIR)
	@mkdir -p $(LOG_DIR)
	@mkdir -p $(OUT_DIR)

clean:
	@echo "Cleaning..."
	@echo ""
	@-rm -rf $(BLD_DIR)/* $(BIN_DIR)/* $(OUT_DIR)/* $(LOG_DIR)/* \
		$(DOC_DIR)/html $(DOC_DIR)/latex
	@echo ""
	@echo "...✓ done!"
