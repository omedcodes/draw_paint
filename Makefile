CC = gcc
WINDRES = windres
CFLAGS = -std=c23 -Wall -Wextra

SRC_DIR = src
BUILD_DIR = build
ASSETS_DIR = assets

TARGET = $(BUILD_DIR)/DrawPaint
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/paint.c
RES_RC = resource.rc
RES_O = $(BUILD_DIR)/resource.res

LDFLAGS_BASE = -lmingw32 -lSDL2main -lSDL2 -lm

.PHONY: all debug release clean prep

all: prep $(TARGET)

prep:
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	@if not exist "$(ASSETS_DIR)" mkdir "$(ASSETS_DIR)"

debug: CFLAGS += -g
debug: prep $(TARGET)

release: CFLAGS += -O2
release: LDFLAGS_RELEASE = $(LDFLAGS_BASE) -mwindows -Wl,--dynamicbase -Wl,--nxcompat -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -static
release: prep $(RES_O) $(TARGET)

$(RES_O): $(RES_RC)
	$(WINDRES) $(RES_RC) -O coff -o $(RES_O)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(wildcard $(RES_O)) -o $(TARGET) $(if $(findstring release,$(MAKECMDGOALS)),$(LDFLAGS_RELEASE),$(LDFLAGS_BASE))

clean:
	@if exist "$(BUILD_DIR)" rd /s /q "$(BUILD_DIR)"