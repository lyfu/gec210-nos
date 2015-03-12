SECTIONS
{
	. = 0x30000000;
	.text : {
		start.o
		* (.text)
	}
	.bss : {
		* (.bss)
	}
	.data : {
		* (.data)
	}	
}
