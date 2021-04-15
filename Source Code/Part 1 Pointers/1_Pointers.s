	.file	"1_Pointers.cc"
 # GNU C++14 (MinGW.org GCC Build-20200227-1) version 9.2.0 (mingw32)
 #	compiled by GNU C version 9.2.0, GMP version 6.1.2, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.21-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -fpreprocessed 1_Pointers.ii -mtune=generic -march=i586
 # -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations -fassume-phsa
 # -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
 # -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
 # -feliminate-unused-debug-types -fexceptions -ffp-int-builtin-inexact
 # -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
 # -finline-atomics -fipa-stack-alignment -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
 # -fpeephole -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fshrink-wrap-separate
 # -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
 # -m96bit-long-double -maccumulate-outgoing-args -malign-double
 # -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mstv -mvzeroupper

	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.def	___main;	.scl	2;	.type	32;	.endef
LC0:
	.ascii "int address = \0"
LC1:
	.ascii " \0"
LC2:
	.ascii "Address of void = \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1518:
	.cfi_startproc
	leal	4(%esp), %ecx	 #,
	.cfi_def_cfa 1, 0
	andl	$-16, %esp	 #,
	pushl	-4(%ecx)	 #
	pushl	%ebp	 #
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp	 #,
	pushl	%ecx	 #
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$36, %esp	 #,
 # 1_Pointers.cc:4: int main(){
	call	___main	 #
 # 1_Pointers.cc:5:     int a = 1025;
	movl	$1025, -20(%ebp)	 #, a
 # 1_Pointers.cc:7:     p=&a;
	leal	-20(%ebp), %eax	 #, tmp97
	movl	%eax, -12(%ebp)	 # tmp97, p
 # 1_Pointers.cc:8:     cout<<"int address = "<<p<<" "<<*(p)<<endl;
	movl	$LC0, 4(%esp)	 #,
	movl	$__ZSt4cout, (%esp)	 #,
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movl	%eax, %edx	 #, _1
 # 1_Pointers.cc:8:     cout<<"int address = "<<p<<" "<<*(p)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp98
	movl	%eax, (%esp)	 # tmp98,
	movl	%edx, %ecx	 # _1,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:8:     cout<<"int address = "<<p<<" "<<*(p)<<endl;
	movl	$LC1, 4(%esp)	 #,
	movl	%eax, (%esp)	 # _2,
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movl	%eax, %edx	 #, _3
 # 1_Pointers.cc:8:     cout<<"int address = "<<p<<" "<<*(p)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp99
	movl	(%eax), %eax	 # *p_17, _4
	movl	%eax, (%esp)	 # _4,
	movl	%edx, %ecx	 # _3,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:8:     cout<<"int address = "<<p<<" "<<*(p)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _5,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	$LC0, 4(%esp)	 #,
	movl	$__ZSt4cout, (%esp)	 #,
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	-12(%ebp), %edx	 # p, tmp100
	addl	$4, %edx	 #, _7
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	%edx, (%esp)	 # _7,
	movl	%eax, %ecx	 # _6,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	$LC1, 4(%esp)	 #,
	movl	%eax, (%esp)	 # _8,
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movl	%eax, %edx	 #, _9
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp101
	addl	$4, %eax	 #, _10
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	(%eax), %eax	 # *_10, _11
	movl	%eax, (%esp)	 # _11,
	movl	%edx, %ecx	 # _9,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:9:     cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _12,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:12:     void* v = (void*)p;
	movl	-12(%ebp), %eax	 # p, tmp102
	movl	%eax, -16(%ebp)	 # tmp102, v
 # 1_Pointers.cc:13:     cout<<"Address of void = "<<(v);
	movl	$LC2, 4(%esp)	 #,
	movl	$__ZSt4cout, (%esp)	 #,
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movl	%eax, %edx	 #, _13
 # 1_Pointers.cc:13:     cout<<"Address of void = "<<(v);
	movl	-16(%ebp), %eax	 # v, tmp103
	movl	%eax, (%esp)	 # tmp103,
	movl	%edx, %ecx	 # _13,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 1_Pointers.cc:14: }
	movl	$0, %eax	 #, _41
	movl	-4(%ebp), %ecx	 #,
	.cfi_def_cfa 1, 0
	leave	
	.cfi_restore 5
	leal	-4(%ecx), %esp	 #,
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
LFE1518:
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1997:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	subl	$8, %esp	 #,
 # c:\mingw\lib\gcc\mingw32\9.2.0\include\c++\iostream:74:   static ios_base::Init __ioinit;
	movl	$__ZStL8__ioinit, %ecx	 #,
	call	__ZNSt8ios_base4InitD1Ev	 #
	leave	
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
LFE1997:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1996:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	subl	$24, %esp	 #,
 # 1_Pointers.cc:14: }
	cmpl	$1, 8(%ebp)	 #, __initialize_p
	jne	L6	 #,
 # 1_Pointers.cc:14: }
	cmpl	$65535, 12(%ebp)	 #, __priority
	jne	L6	 #,
 # c:\mingw\lib\gcc\mingw32\9.2.0\include\c++\iostream:74:   static ios_base::Init __ioinit;
	movl	$__ZStL8__ioinit, %ecx	 #,
	call	__ZNSt8ios_base4InitC1Ev	 #
	movl	$___tcf_0, (%esp)	 #,
	call	_atexit	 #
L6:
 # 1_Pointers.cc:14: }
	nop	
	leave	
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
LFE1996:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1998:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	subl	$24, %esp	 #,
 # 1_Pointers.cc:14: }
	movl	$65535, 4(%esp)	 #,
	movl	$1, (%esp)	 #,
	call	__Z41__static_initialization_and_destruction_0ii	 #
	leave	
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
LFE1998:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPKv;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
