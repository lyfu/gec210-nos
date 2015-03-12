led.bin: start.o 
	arm-none-linux-gnueabi-ld -Ttext 0x30000000 -o led.elf $^
	arm-none-linux-gnueabi-objcopy -O binary led.elf led.bin
	arm-none-linux-gnueabi-objdump -D led.elf > led_elf.dis
%.o : %.S
	arm-none-linux-gnueabi-gcc -o $@ $< -c

clean:
	rm *.o *.elf *.bin 
