CC = gcc
CFLAGS = -std=c23 -Wall -Wextra
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lm

TARGET = main_paint
SRC = paint.c

.PHONY: all debug release clean

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

release: CFLAGS += -O2 -mwindows
release: LDFLAGS += -static
release: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	if exist $(TARGET).exe del $(TARGET).exe