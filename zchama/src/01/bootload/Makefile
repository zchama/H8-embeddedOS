PREFIX	=/usr/local/h8300-elf
BINDER	=$(PREFIX)/bin

# definition of tools
AR	= $(BINDER)/ar
AS	= $(BINDER)/as
CC	= $(BINDER)/gcc
LD	= $(BINDER)/ld
NM	= $(BINDER)/nm
OBJCOPY	= $(BINDER)/objcopy
OBJDUMP	= $(BINDER)/objdump
RANLIB	= $(BINDER)/ranlib
STRIP	= $(BINDER)/strip

H8WRITE	= ../../tools/kz_h8write/kz_h8write

H8WRITE_SERDEV = /dev/tty.usbserial-FTK1PRAV  

OBJS  	= vector.o startup.o main.o
OBJS	+= lib.o serial.o

TARGET	= kzload

CFLAGS	= -Wall -mh -nostdinc -nostdlib -fno-builtin
CFLAGS	+= -I
#CFLAGS	+= -g
CFLAGS	+= -Os
CFLAGS	+= -DKZLOAD

LFLAGS	= -static -T ld.scr -L.

.SUFFIX: .c .o
.SUFFIX: .s .o

all :	$(TARGET)
$(TARGET)	:	$(OBJS)
			$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
			cp $(TARGET) $(TARGET).elf
			$(STRIP) $(TARGET)	

.c.o		:	$<
			$(CC) -c $(CFLAGS) $<

.s.o		:	$<
			$(CC) -c $(CFLAGS) $<

$(TARGET).mot	:	$(TARGET)
			$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

image		:	$(TARGET).mot

# write to flash ROM
write		:	$(TARGET).mot
			$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)
	
clean		:	rm -f $($OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot

