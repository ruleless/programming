	.file	"test.cpp"
	.section	.rodata
.LC0:
	.string	"default construct %p %d\n"
	.section	.text._ZN3ObjC2Ei,"axG",@progbits,_ZN3ObjC5Ei,comdat
	.align 2
	.weak	_ZN3ObjC2Ei
	.type	_ZN3ObjC2Ei, @function
_ZN3ObjC2Ei:
.LFB1:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTV3Obj+16, (%rax)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	-8(%rbp), %rax
	movl	8(%rax), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN3ObjC2Ei, .-_ZN3ObjC2Ei
	.weak	_ZN3ObjC1Ei
	.set	_ZN3ObjC1Ei,_ZN3ObjC2Ei
	.section	.rodata
.LC1:
	.string	"~ destruct %p %d\n"
	.section	.text._ZN3ObjD2Ev,"axG",@progbits,_ZN3ObjD5Ev,comdat
	.align 2
	.weak	_ZN3ObjD2Ev
	.type	_ZN3ObjD2Ev, @function
_ZN3ObjD2Ev:
.LFB8:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTV3Obj+16, (%rax)
	movq	-8(%rbp), %rax
	movl	8(%rax), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	testb	%al, %al
	je	.L6
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN3ObjD2Ev, .-_ZN3ObjD2Ev
	.weak	_ZN3ObjD1Ev
	.set	_ZN3ObjD1Ev,_ZN3ObjD2Ev
	.section	.text._ZN3ObjD0Ev,"axG",@progbits,_ZN3ObjD5Ev,comdat
	.align 2
	.weak	_ZN3ObjD0Ev
	.type	_ZN3ObjD0Ev, @function
_ZN3ObjD0Ev:
.LFB10:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3ObjD1Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	_ZN3ObjD0Ev, .-_ZN3ObjD0Ev
	.section	.text._ZN3Obj3setEi,"axG",@progbits,_ZN3Obj3setEi,comdat
	.align 2
	.weak	_ZN3Obj3setEi
	.type	_ZN3Obj3setEi, @function
_ZN3Obj3setEi:
.LFB11:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	_ZN3Obj3setEi, .-_ZN3Obj3setEi
	.text
.globl _Z9testFunc1v
	.type	_Z9testFunc1v, @function
_Z9testFunc1v:
.LFB12:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	movq	%rbx, %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZN3ObjC1Ei
	movq	%rbx, %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZN3Obj3setEi
.L14:
	movq	%rbx, %rax
	movq	%rbx, %rax
	addq	$8, %rsp
	popq	%rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	_Z9testFunc1v, .-_Z9testFunc1v
.globl _Z9testFunc2v
	.type	_Z9testFunc2v, @function
_Z9testFunc2v:
.LFB13:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	movq	%rbx, %rax
	movl	$2, %esi
	movq	%rax, %rdi
	call	_ZN3ObjC1Ei
	movq	%rbx, %rax
	movq	%rbx, %rax
	addq	$8, %rsp
	popq	%rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	_Z9testFunc2v, .-_Z9testFunc2v
.globl _Unwind_Resume
.globl main
	.type	main, @function
main:
.LFB14:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA14
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	.cfi_offset 3, -32
	.cfi_offset 12, -24
	call	_Z9testFunc1v
.LEHE0:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_Z9testFunc2v
	movl	$0, %ebx
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3ObjD1Ev
.LEHE1:
	jmp	.L23
.L22:
.L20:
	movl	%edx, %ebx
	movq	%rax, %r12
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3ObjD1Ev
	movq	%r12, %rax
	movslq	%ebx, %rdx
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume
.L23:
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3ObjD1Ev
.LEHE2:
	movl	%ebx, %eax
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	main, .-main
.globl __gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA14:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE14-.LLSDACSB14
.LLSDACSB14:
	.uleb128 .LEHB0-.LFB14
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB1-.LFB14
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L22-.LFB14
	.uleb128 0x0
	.uleb128 .LEHB2-.LFB14
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE14:
	.text
	.weak	_ZTV3Obj
	.section	.rodata._ZTV3Obj,"aG",@progbits,_ZTV3Obj,comdat
	.align 32
	.type	_ZTV3Obj, @object
	.size	_ZTV3Obj, 32
_ZTV3Obj:
	.quad	0
	.quad	_ZTI3Obj
	.quad	_ZN3ObjD1Ev
	.quad	_ZN3ObjD0Ev
	.weak	_ZTS3Obj
	.section	.rodata._ZTS3Obj,"aG",@progbits,_ZTS3Obj,comdat
	.type	_ZTS3Obj, @object
	.size	_ZTS3Obj, 5
_ZTS3Obj:
	.string	"3Obj"
	.weak	_ZTI3Obj
	.section	.rodata._ZTI3Obj,"aG",@progbits,_ZTI3Obj,comdat
	.align 16
	.type	_ZTI3Obj, @object
	.size	_ZTI3Obj, 16
_ZTI3Obj:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS3Obj
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-17)"
	.section	.note.GNU-stack,"",@progbits
