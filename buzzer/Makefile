buzzer.bin: start.o main.o buzzer.o
	arm-linux-ld -Ttext 0x30000000 -o buzzer.elf $^
	arm-linux-objcopy -O binary buzzer.elf buzzer.bin
	arm-linux-objdump -D buzzer.elf > buzzer_elf.dis
	chmod 777 ./buzzer.bin
	sudo cp buzzer.bin /tftpboot
%.o : %.S
	arm-linux-gcc -o $@ $< -c

%.o : %.c
	arm-linux-gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis *.exe -f
