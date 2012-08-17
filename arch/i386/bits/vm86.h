#ifndef _BITS_VM86_H
#define _BITS_VM86_H

#define X86_EFLAGS_CF	0x00000001 
#define X86_EFLAGS_PF	0x00000004 
#define X86_EFLAGS_AF	0x00000010 
#define X86_EFLAGS_ZF	0x00000040 
#define X86_EFLAGS_SF	0x00000080 
#define X86_EFLAGS_TF	0x00000100 
#define X86_EFLAGS_IF	0x00000200 
#define X86_EFLAGS_DF	0x00000400 
#define X86_EFLAGS_OF	0x00000800 
#define X86_EFLAGS_IOPL	0x00003000 
#define X86_EFLAGS_NT	0x00004000 
#define X86_EFLAGS_RF	0x00010000 
#define X86_EFLAGS_VM	0x00020000 
#define X86_EFLAGS_AC	0x00040000 
#define X86_EFLAGS_VIF	0x00080000 
#define X86_EFLAGS_VIP	0x00100000 
#define X86_EFLAGS_ID	0x00200000 

#define X86_CR0_PE	0x00000001 
#define X86_CR0_MP	0x00000002 
#define X86_CR0_EM	0x00000004 
#define X86_CR0_TS	0x00000008 
#define X86_CR0_ET	0x00000010 
#define X86_CR0_NE	0x00000020 
#define X86_CR0_WP	0x00010000 
#define X86_CR0_AM	0x00040000 
#define X86_CR0_NW	0x20000000 
#define X86_CR0_CD	0x40000000 
#define X86_CR0_PG	0x80000000 

#define X86_CR3_PWT	0x00000008 
#define X86_CR3_PCD	0x00000010 

#define X86_CR4_VME	0x00000001 
#define X86_CR4_PVI	0x00000002 
#define X86_CR4_TSD	0x00000004 
#define X86_CR4_DE	0x00000008 
#define X86_CR4_PSE	0x00000010 
#define X86_CR4_PAE	0x00000020 
#define X86_CR4_MCE	0x00000040 
#define X86_CR4_PGE	0x00000080 
#define X86_CR4_PCE	0x00000100 
#define X86_CR4_OSFXSR	0x00000200 
#define X86_CR4_OSXMMEXCPT 0x00000400 
#define X86_CR4_VMXE	0x00002000 
#define X86_CR4_OSXSAVE 0x00040000 

#define X86_CR8_TPR	0x0000000F 

#define CX86_PCR0	0x20
#define CX86_GCR	0xb8
#define CX86_CCR0	0xc0
#define CX86_CCR1	0xc1
#define CX86_CCR2	0xc2
#define CX86_CCR3	0xc3
#define CX86_CCR4	0xe8
#define CX86_CCR5	0xe9
#define CX86_CCR6	0xea
#define CX86_CCR7	0xeb
#define CX86_PCR1	0xf0
#define CX86_DIR0	0xfe
#define CX86_DIR1	0xff
#define CX86_ARR_BASE	0xc4
#define CX86_RCR_BASE	0xdc

#define BIOSSEG		0x0f000

#define CPU_086		0
#define CPU_186		1
#define CPU_286		2
#define CPU_386		3
#define CPU_486		4
#define CPU_586		5

#define VM86_TYPE(retval)	((retval) & 0xff)
#define VM86_ARG(retval)	((retval) >> 8)

#define VM86_SIGNAL	0
#define VM86_UNKNOWN	1
#define VM86_INTx	2
#define VM86_STI	3
#define VM86_PICRETURN	4
#define VM86_TRAP	6

#define VM86_PLUS_INSTALL_CHECK	0
#define VM86_ENTER		1
#define VM86_ENTER_NO_BYPASS	2
#define	VM86_REQUEST_IRQ	3
#define VM86_FREE_IRQ		4
#define VM86_GET_IRQ_BITS	5
#define VM86_GET_AND_RESET_IRQ	6

struct vm86_regs {
	long ebx;
	long ecx;
	long edx;
	long esi;
	long edi;
	long ebp;
	long eax;
	long __null_ds;
	long __null_es;
	long __null_fs;
	long __null_gs;
	long orig_eax;
	long eip;
	unsigned short cs, __csh;
	long eflags;
	long esp;
	unsigned short ss, __ssh;
	unsigned short es, __esh;
	unsigned short ds, __dsh;
	unsigned short fs, __fsh;
	unsigned short gs, __gsh;
};

struct revectored_struct {
	unsigned long __map[8];
};

struct vm86_struct {
	struct vm86_regs regs;
	unsigned long flags;
	unsigned long screen_bitmap;
	unsigned long cpu_type;
	struct revectored_struct int_revectored;
	struct revectored_struct int21_revectored;
};

#define VM86_SCREEN_BITMAP	0x0001

struct vm86plus_info_struct {
	unsigned long force_return_for_pic:1;
	unsigned long vm86dbg_active:1;
	unsigned long vm86dbg_TFpendig:1;
	unsigned long unused:28;
	unsigned long is_vm86pus:1;
	unsigned char vm86dbg_intxxtab[32];
};
struct vm86plus_struct {
	struct vm86_regs regs;
	unsigned long flags;
	unsigned long screen_bitmap;
	unsigned long cpu_type;
	struct revectored_struct int_revectored;
	struct revectored_struct int21_revectored;
	struct vm86plus_info_struct vm86plus;
};


#endif
