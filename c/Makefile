CC := gcc

SRCS=$(shell find . -type f -name '*.c')
OBJS=$(SRCS:%.c=%)

.PHONY: all clean
all: $(OBJS)
clean:
	find . -perm +100 -type f -delete
