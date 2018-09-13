/* the symbol _start from boot.s in the entry point */
ENTRY(_start)

SECTIONS
{
	/* starts at LOADER_ADDR */
	. = 0x8000;
	__start = .;
	__text_start = .;
	.text :
	{
		/* Don't optimize .text.boot section */
		KEEP(*(.text.boot))
		*(.text)
	}
	/* memory management */
	. = ALIGN(4096);
	__text_end = .;

	__rodata_start = .;
	.rodata :
	{
		*(.rodata)
	}
	. = ALIGN(4096);
	__rodata_end = .;

	__data_start = .;
	.data :
	{
		*(.data)
	}
	. = ALIGN(4096);
	__data_end = .;

	__bss_start = .;
	.bss :
	{
		*(.bss)
	}
	. = ALIGN(4096);
	__bss_end = .;
	__end = .;
}