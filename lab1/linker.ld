SECTIONS
{
  . = 0x80000;
  .text : { *(.text.boot) *(.text .text.*) }
  .rodata : { *(.rodata) }
  .data : { *(.data .data.*) }
  .bss : {
	. = ALIGN(16);
   	_bss_start = .;
    	*(.bss .bss.*)
	_bss_end = .;
  }
  _end = .;

}
_bss_size = (_bss_end - _bss_start) >> 3;
