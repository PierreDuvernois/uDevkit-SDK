ifndef SYS_FILE
SYS_FILE=

vpath %.c $(RTPROG)/support/sys/

SRC += fifo.c buffer.c device.c

test-fifo:
	gcc $(RTPROG)/support/sys/fifo.c -I../../include -DTEST_FIFO -o a.exe && ./a.exe
	rm a.exe

endif
