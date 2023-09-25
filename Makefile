TARGET  = interpola

SRCDIR = ./src/
INCDIR = ./include/

CC			= gcc
CFILES		= $(wildcard $(SRCDIR)/*.c)
CFLAGS		= -O3 -mavx -march=native -I${LIKWID_INCLUDE} -DLIKWID_PERFMON
LDFLAGS		= -lm -I$(INCDIR) -L${LIKWID_LIB} -llikwid
OBJFILES	= $(patsubst %.c, %.o, $(CFILES))

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $^

clean:
	rm -f $(TARGET) $(OBJFILES)

purge: 
	rm -f $(TARGET) $(OBJFILES) *.txt *.log
