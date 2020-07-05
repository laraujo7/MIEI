CC      = gcc
LD      = gcc
CFLAGS  = -O2 -Wall -Wextra
CFLAGS += -Wno-unused-parameter -Wno-unused-function -Wno-unused-result
INCLDS  = -I $(INC_DIR)
BLD_DIR = build
DOC_DIR = docs
INC_DIR = .
SRC_DIR = src
TST_DIR = scripts
TARGETS = argus argusd

.DEFAULT_GOAL = all

.PHONY: $(TARGETS) all check checkdirs clean fmt lint test

all: checkdirs $(TARGETS)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(INCLDS) $(CFLAGS) $< -o $@

argus: $(BLD_DIR)/parsed_line.o
	   $(CC) $(INCLDS) $(CFLAGS) -o $@ argus.c $^

argusd: $(BLD_DIR)/server_funcs.o $(BLD_DIR)/execute.o $(BLD_DIR)/processor.o
		$(CC) $(INCLDS) $(CFLAGS) -o $@ argusd.c $^

start_argusd: all
	./argusd

start_argus: all
	./argus

stop:
	kill -s SIGTERM $(shell pidof sv)

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

check: all
	@echo "Write something to check!"

checkdirs:
	@mkdir -p $(BLD_DIR)

clean:
	@echo "Cleaning..."
	@echo ""
	@-rm -r $(BLD_DIR) tmp* *fifo signal_file log log.idx argus argusd
	@echo ""
	@echo "...✓ done!"