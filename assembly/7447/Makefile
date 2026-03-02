MCU=atmega328p
TARGET=main
PROGRAMMER=arduino
PORT=/dev/cu.usbmodem*     # change if needed
BAUD=115200

all: $(TARGET).hex

$(TARGET).elf: $(TARGET).asm
	avra -fI -o $(TARGET).hex $(TARGET).asm

flash: $(TARGET).hex
	avrdude -c $(PROGRAMMER) -p m328p -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex:i

clean:
	rm -f *.hex *.obj *.cof *.eep.hex *.asm~ *.map
