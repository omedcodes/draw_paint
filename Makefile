CC = gcc
WINDRES = windres
CFLAGS = -std=c23 -Wall -Wextra
LDFLAGS_BASE = -lmingw32 -lSDL2main -lSDL2 -lm
TARGET = DrawPaint
SRC = main.c paint.c
RES_RC = resource.rc
RES_O = resource.res

.PHONY: all debug release clean check_dirs

check_dirs:
	@if not exist "assets" mkdir "assets"

all: check_dirs $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

release: CFLAGS += -O2
release: LDFLAGS_RELEASE = $(LDFLAGS_BASE) -mwindows -Wl,--dynamicbase -Wl,--nxcompat -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -static
release: $(RES_O) $(TARGET)

$(RES_O): $(RES_RC)
	$(WINDRES) $(RES_RC) -O coff -o $(RES_O)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(wildcard $(RES_O)) -o $(TARGET) $(if $(findstring release,$(MAKECMDGOALS)),$(LDFLAGS_RELEASE),$(LDFLAGS_BASE))

clean:
ifeq ($(OS),Windows_NT)
	if exist $(TARGET).exe del $(TARGET).exe
	if exist *.res del *.res
else
	rm -f $(TARGET) *.res
endif