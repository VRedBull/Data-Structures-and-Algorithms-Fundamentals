	.file	"7_2DArray.cc"
 # GNU C++14 (MinGW.org GCC Build-20200227-1) version 9.2.0 (mingw32)
 #	compiled by GNU C version 9.2.0, GMP version 6.1.2, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.21-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -fpreprocessed 7_2DArray.ii -mtune=generic -march=i586
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
	subl	$52, %esp	 #,
 # 7_2DArray.cc:4: int main(){
	call	___main	 #
 # 7_2DArray.cc:6:     int A[2][3]={
	movl	$2, -36(%ebp)	 #, A
	movl	$3, -32(%ebp)	 #, A
	movl	$5, -28(%ebp)	 #, A
	movl	$6, -24(%ebp)	 #, A
	movl	$7, -20(%ebp)	 #, A
	movl	$8, -16(%ebp)	 #, A
 # 7_2DArray.cc:11:     int (*p)[3]=A;          //Standard Syntax for 2D arrays pointers initialization
	leal	-36(%ebp), %eax	 #, tmp144
	movl	%eax, -12(%ebp)	 # tmp144, p
 # 7_2DArray.cc:16:     cout<<p<<endl;
	movl	-12(%ebp), %eax	 # p, tmp145
	movl	%eax, (%esp)	 # tmp145,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:16:     cout<<p<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _1,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:17:     cout<<*p<<endl;
	movl	-12(%ebp), %eax	 # p, tmp146
	movl	%eax, (%esp)	 # tmp146,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:17:     cout<<*p<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _2,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:19:     cout<<A<<endl;
	leal	-36(%ebp), %eax	 #, tmp147
	movl	%eax, (%esp)	 # tmp147,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:19:     cout<<A<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _3,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:20:     cout<<*A<<endl;
	leal	-36(%ebp), %eax	 #, tmp148
	movl	%eax, (%esp)	 # tmp148,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:20:     cout<<*A<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _4,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:21:     cout<<A[0]<<endl;
	leal	-36(%ebp), %eax	 #, tmp149
	movl	%eax, (%esp)	 # tmp149,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:21:     cout<<A[0]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _5,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:22:     cout<<&A[0]<<endl;
	leal	-36(%ebp), %eax	 #, tmp150
	movl	%eax, (%esp)	 # tmp150,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:22:     cout<<&A[0]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _6,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:23:     cout<<&A[0][0]<<endl;
	leal	-36(%ebp), %eax	 #, tmp151
	movl	%eax, (%esp)	 # tmp151,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:23:     cout<<&A[0][0]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _7,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:25:     cout<<p+1<<endl;
	movl	-12(%ebp), %eax	 # p, tmp152
	addl	$12, %eax	 #, _8
 # 7_2DArray.cc:25:     cout<<p+1<<endl;
	movl	%eax, (%esp)	 # _8,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:25:     cout<<p+1<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _9,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:26:     cout<<*(p+1)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp153
	addl	$12, %eax	 #, _10
 # 7_2DArray.cc:26:     cout<<*(p+1)<<endl;
	movl	%eax, (%esp)	 # _10,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:26:     cout<<*(p+1)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _11,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:28:     cout<<A+1<<endl;
	leal	-36(%ebp), %eax	 #, _12
	addl	$12, %eax	 #, _12
	movl	%eax, (%esp)	 # _12,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:28:     cout<<A+1<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _13,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:29:     cout<<*(A+1)<<endl;
	leal	-36(%ebp), %eax	 #, _14
	addl	$12, %eax	 #, _14
	movl	%eax, (%esp)	 # _14,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:29:     cout<<*(A+1)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _15,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:30:     cout<<A[1]<<endl;
	leal	-36(%ebp), %eax	 #, tmp154
	addl	$12, %eax	 #, tmp155
	movl	%eax, (%esp)	 # tmp155,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:30:     cout<<A[1]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _16,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:31:     cout<<&A[1]<<endl;
	leal	-36(%ebp), %eax	 #, tmp156
	addl	$12, %eax	 #, tmp157
	movl	%eax, (%esp)	 # tmp157,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:31:     cout<<&A[1]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _17,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:32:     cout<<&A[1][0]<<endl;
	leal	-36(%ebp), %eax	 #, tmp158
	addl	$12, %eax	 #, tmp159
	movl	%eax, (%esp)	 # tmp159,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:32:     cout<<&A[1][0]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _18,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:34:     cout<<*(A+1)+1<<endl;
	leal	-36(%ebp), %eax	 #, _19
	addl	$16, %eax	 #, _19
	movl	%eax, (%esp)	 # _19,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:34:     cout<<*(A+1)+1<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _20,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:35:     cout<<*(p+1)+1<<endl;
	movl	-12(%ebp), %eax	 # p, tmp160
	addl	$12, %eax	 #, _21
 # 7_2DArray.cc:35:     cout<<*(p+1)+1<<endl;
	addl	$4, %eax	 #, _22
	movl	%eax, (%esp)	 # _22,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:35:     cout<<*(p+1)+1<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _23,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:36:     cout<<A[1]+1<<endl<<endl;
	leal	-36(%ebp), %eax	 #, tmp161
	addl	$12, %eax	 #, _24
	addl	$4, %eax	 #, _24
	movl	%eax, (%esp)	 # _24,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEPKv	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:36:     cout<<A[1]+1<<endl<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _25,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:36:     cout<<A[1]+1<<endl<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _26,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:40:     cout<<*(*p)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp162
	movl	(%eax), %eax	 # *p_69, _27
	movl	%eax, (%esp)	 # _27,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:40:     cout<<*(*p)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _28,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:41:     cout<<*(*A)<<endl;
	leal	-36(%ebp), %eax	 #, A.0_29
 # 7_2DArray.cc:41:     cout<<*(*A)<<endl;
	movl	(%eax), %eax	 # MEM[(int *)A.0_29], _30
	movl	%eax, (%esp)	 # _30,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:41:     cout<<*(*A)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _31,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:42:     cout<<*(A[0])<<endl;
	movl	-36(%ebp), %eax	 # A, _32
	movl	%eax, (%esp)	 # _32,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:42:     cout<<*(A[0])<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _33,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:43:     cout<<*(*(&A[0]))<<endl;
	movl	-36(%ebp), %eax	 # A, _34
	movl	%eax, (%esp)	 # _34,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:43:     cout<<*(*(&A[0]))<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _35,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:44:     cout<<*(&A[0][0])<<endl;
	movl	-36(%ebp), %eax	 # A, _36
 # 7_2DArray.cc:44:     cout<<*(&A[0][0])<<endl;
	movl	%eax, (%esp)	 # _36,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:44:     cout<<*(&A[0][0])<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _37,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:45:     cout<<A[0][0]<<endl;
	movl	-36(%ebp), %eax	 # A, _38
	movl	%eax, (%esp)	 # _38,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:45:     cout<<A[0][0]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _39,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:47:     cout<<*(*p+1)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp163
	addl	$4, %eax	 #, _40
 # 7_2DArray.cc:47:     cout<<*(*p+1)<<endl;
	movl	(%eax), %eax	 # *_40, _41
	movl	%eax, (%esp)	 # _41,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:47:     cout<<*(*p+1)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _42,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:49:     cout<<*(*(p+1))<<endl;
	movl	-12(%ebp), %eax	 # p, tmp164
	addl	$12, %eax	 #, _43
 # 7_2DArray.cc:49:     cout<<*(*(p+1))<<endl;
	movl	(%eax), %eax	 # *_43, _44
	movl	%eax, (%esp)	 # _44,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:49:     cout<<*(*(p+1))<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _45,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:50:     cout<<*(*(A+1))<<endl;
	leal	-36(%ebp), %eax	 #, _46
	addl	$12, %eax	 #, _46
 # 7_2DArray.cc:50:     cout<<*(*(A+1))<<endl;
	movl	(%eax), %eax	 # *_46, _47
	movl	%eax, (%esp)	 # _47,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:50:     cout<<*(*(A+1))<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _48,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:51:     cout<<*(A[1])<<endl;
	movl	-24(%ebp), %eax	 # A, _49
	movl	%eax, (%esp)	 # _49,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:51:     cout<<*(A[1])<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _50,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:52:     cout<<*(*(&A[1]))<<endl;
	movl	-24(%ebp), %eax	 # A, _51
	movl	%eax, (%esp)	 # _51,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:52:     cout<<*(*(&A[1]))<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _52,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:53:     cout<<*(&A[1][0])<<endl;
	movl	-24(%ebp), %eax	 # A, _53
 # 7_2DArray.cc:53:     cout<<*(&A[1][0])<<endl;
	movl	%eax, (%esp)	 # _53,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:53:     cout<<*(&A[1][0])<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _54,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:54:     cout<<A[1][0]<<endl;
	movl	-24(%ebp), %eax	 # A, _55
	movl	%eax, (%esp)	 # _55,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:54:     cout<<A[1][0]<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _56,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:56:     cout<<*(*(p+1)+1)<<endl;
	movl	-12(%ebp), %eax	 # p, tmp165
	addl	$12, %eax	 #, _57
 # 7_2DArray.cc:56:     cout<<*(*(p+1)+1)<<endl;
	addl	$4, %eax	 #, _58
 # 7_2DArray.cc:56:     cout<<*(*(p+1)+1)<<endl;
	movl	(%eax), %eax	 # *_58, _59
	movl	%eax, (%esp)	 # _59,
	movl	$__ZSt4cout, %ecx	 #,
	call	__ZNSolsEi	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:56:     cout<<*(*(p+1)+1)<<endl;
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)	 #,
	movl	%eax, %ecx	 # _60,
	call	__ZNSolsEPFRSoS_E	 #
	subl	$4, %esp	 #,
 # 7_2DArray.cc:58: }
	movl	$0, %eax	 #, _166
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
LFB1994:
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
LFE1994:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1993:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	subl	$24, %esp	 #,
 # 7_2DArray.cc:58: }
	cmpl	$1, 8(%ebp)	 #, __initialize_p
	jne	L6	 #,
 # 7_2DArray.cc:58: }
	cmpl	$65535, 12(%ebp)	 #, __priority
	jne	L6	 #,
 # c:\mingw\lib\gcc\mingw32\9.2.0\include\c++\iostream:74:   static ios_base::Init __ioinit;
	movl	$__ZStL8__ioinit, %ecx	 #,
	call	__ZNSt8ios_base4InitC1Ev	 #
	movl	$___tcf_0, (%esp)	 #,
	call	_atexit	 #
L6:
 # 7_2DArray.cc:58: }
	nop	
	leave	
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
LFE1993:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1995:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	subl	$24, %esp	 #,
 # 7_2DArray.cc:58: }
	movl	$65535, 4(%esp)	 #,
	movl	$1, (%esp)	 #,
	call	__Z41__static_initialization_and_destruction_0ii	 #
	leave	
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
LFE1995:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
	.def	__ZNSolsEPKv;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
