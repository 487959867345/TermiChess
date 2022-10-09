
SRC := src
INCL := include

src_files := $(wildcard $(SRC)/*.c)
header_files = $(wildcard $(INCL)/*.h)

gen_objects: $(src_files)
	CC $^ -I$(INCL) -o build/bin/program
