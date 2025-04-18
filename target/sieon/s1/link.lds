/*
 * linker script for STM32H743 with GNU ld
 */

/* Program Entry, set to mark it as "used" and avoid gc */
MEMORY
{
	/* First 0x8000(32KB) area is reserved for bootloader */
    CODE (rx) : ORIGIN = 0x08020000, LENGTH = 1920k /* 2048KB - 32KB flash */

    ITCM_RAM (rwx) : ORIGIN = 0x00000000, LENGTH =   64K
    DTCM_RAM (rw) : ORIGIN = 0x20000000, LENGTH =  128K
    SRAMD1 (rw) : ORIGIN = 0x24000000, LENGTH =  512k /* D1 512K sram */
    SRAMD2 (rw) : ORIGIN = 0x30000000, LENGTH =  256K /* D2 domain AHB bus */
	SRAMD3 (rw) : ORIGIN = 0x38000000, LENGTH =   64K /* D3 domain */
	BKPRAM (rw) : ORIGIN = 0x38800000, LENGTH =    4K
    RxDecripSection (rw) : ORIGIN =0x30040000, LENGTH =32k
    TxDecripSection (rw) : ORIGIN =0x30040060, LENGTH =32k
    RxArraySection (rw) : ORIGIN =0x30040200, LENGTH =32k
}
ENTRY(Reset_Handler)
_system_stack_size = 0x1000;

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _stext = .;
        KEEP(*(.isr_vector))            /* Startup code */
        . = ALIGN(4);
        *(.text)                        /* remaining code */
        *(.text.*)                      /* remaining code */
        *(.rodata)                      /* read-only data (constants) */
        *(.rodata*)
        *(.glue_7)
        *(.glue_7t)
        *(.gnu.linkonce.t*)

        /* section information for finsh shell */
        . = ALIGN(4);
        __fsymtab_start = .;
        KEEP(*(FSymTab))
        __fsymtab_end = .;
        . = ALIGN(4);
        __vsymtab_start = .;
        KEEP(*(VSymTab))
        __vsymtab_end = .;
        . = ALIGN(4);

        /* section information for initial. */
        . = ALIGN(4);
        __rt_init_start = .;
        KEEP(*(SORT(.rti_fn*)))
        __rt_init_end = .;
        . = ALIGN(4);

        PROVIDE(__ctors_start__ = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE(__ctors_end__ = .);
        . = ALIGN(4);

        /* section information for parameters. */
        . = ALIGN(4);
        __fmt_param_start = .;
        KEEP(*(ParamTab))
        __fmt_param_end = .;
        . = ALIGN(4);  

        /* section information for mlog. */
        . = ALIGN(4);
        __fmt_mlog_start = .;
        KEEP(*(MlogTab))
        __fmt_mlog_end = .;
        . = ALIGN(4);
		
		/* section information for utest */
		. = ALIGN(4);
		__rt_utest_tc_tab_start = .;
		KEEP(*(UtestTcTab))
		__rt_utest_tc_tab_end = .;
        . = ALIGN(4);

        /* section information for task. */
        . = ALIGN(4);
        __fmt_task_start = .;
        KEEP(*(TaskTab))
        __fmt_task_end = .;
        . = ALIGN(4);

        _etext = .;
    } > CODE = 0

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > CODE

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)

        /* This is used by the startup in order to initialize the .data secion */
        _sidata = .;
    } > CODE
    __exidx_end = .;

    /* .data section which is used for initialized data */

    .data : AT (_sidata)
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _sdata = . ;

        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d*)

        PROVIDE(__dtors_start__ = .);
        KEEP(*(SORT(.dtors.*)))
        KEEP(*(.dtors))
        PROVIDE(__dtors_end__ = .);

        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _edata = . ;
    } >SRAMD1

    .stack : 
    {
        _sstack = .;
        . = . + _system_stack_size;
        . = ALIGN(4);
        _estack = .;
    } >SRAMD1

    __bss_start = .;
    .bss :
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _sbss = .;

        *(.bss)
        *(.bss.*)
        *(COMMON)

        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _ebss = . ;
        
        *(.bss.init)
    } > SRAMD1
    __bss_end = .;

    .RxDecripSection (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4);
        *(.RxDecripSection)
        *(.RxDecripSection.*)
        . = ALIGN(4);
        __RxDecripSection_free__ = .;
    } > RxDecripSection
    
    .TxDecripSection (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4);
        *(.TxDecripSection)
        *(.TxDecripSection.*)
        . = ALIGN(4);
        __TxDecripSection_free__ = .;
    } > TxDecripSection
    
    .RxArraySection (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4);
        *(.RxArraySection)
        *(.RxArraySection.*)
        . = ALIGN(4);
        __RxArraySection_free__ = .;
    } > RxArraySection

    _end = .;

    /* Stabs debugging sections.  */
    .stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /* DWARF debug sections.
     * Symbols in the DWARF debugging sections are relative to the beginning
     * of the section so we begin them at 0.  */
    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }
}
