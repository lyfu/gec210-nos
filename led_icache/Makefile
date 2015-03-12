led_icache.bin: start.o led.o
	arm-linux-ld -Ttext 0x30000000 -o led_icache.elf $^
	arm-linux-objcopy -O binary led_icache.elf led_icache.bin
	arm-linux-objdump -D led_icache.elf > led_icache_elf.dis


%.o : %.S
	arm-linux-gcc -o $@ $< -c

%.o : %.c
	arm-linux-gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis  -f
