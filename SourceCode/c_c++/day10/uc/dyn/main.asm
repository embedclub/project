
a.out:     file format elf32-i386


Disassembly of section .init:

08048398 <_init>:
 8048398:	53                   	push   %ebx
 8048399:	83 ec 08             	sub    $0x8,%esp
 804839c:	e8 00 00 00 00       	call   80483a1 <_init+0x9>
 80483a1:	5b                   	pop    %ebx
 80483a2:	81 c3 53 1c 00 00    	add    $0x1c53,%ebx
 80483a8:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80483ae:	85 c0                	test   %eax,%eax
 80483b0:	74 05                	je     80483b7 <_init+0x1f>
 80483b2:	e8 49 00 00 00       	call   8048400 <__gmon_start__@plt>
 80483b7:	e8 f4 00 00 00       	call   80484b0 <frame_dummy>
 80483bc:	e8 df 01 00 00       	call   80485a0 <__do_global_ctors_aux>
 80483c1:	83 c4 08             	add    $0x8,%esp
 80483c4:	5b                   	pop    %ebx
 80483c5:	c3                   	ret    

Disassembly of section .plt:

080483d0 <add@plt-0x10>:
 80483d0:	ff 35 f8 9f 04 08    	pushl  0x8049ff8
 80483d6:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 80483dc:	00 00                	add    %al,(%eax)
	...

080483e0 <add@plt>:
 80483e0:	ff 25 00 a0 04 08    	jmp    *0x804a000
 80483e6:	68 00 00 00 00       	push   $0x0
 80483eb:	e9 e0 ff ff ff       	jmp    80483d0 <_init+0x38>

080483f0 <show@plt>:
 80483f0:	ff 25 04 a0 04 08    	jmp    *0x804a004
 80483f6:	68 08 00 00 00       	push   $0x8
 80483fb:	e9 d0 ff ff ff       	jmp    80483d0 <_init+0x38>

08048400 <__gmon_start__@plt>:
 8048400:	ff 25 08 a0 04 08    	jmp    *0x804a008
 8048406:	68 10 00 00 00       	push   $0x10
 804840b:	e9 c0 ff ff ff       	jmp    80483d0 <_init+0x38>

08048410 <__libc_start_main@plt>:
 8048410:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 8048416:	68 18 00 00 00       	push   $0x18
 804841b:	e9 b0 ff ff ff       	jmp    80483d0 <_init+0x38>

Disassembly of section .text:

08048420 <_start>:
 8048420:	31 ed                	xor    %ebp,%ebp
 8048422:	5e                   	pop    %esi
 8048423:	89 e1                	mov    %esp,%ecx
 8048425:	83 e4 f0             	and    $0xfffffff0,%esp
 8048428:	50                   	push   %eax
 8048429:	54                   	push   %esp
 804842a:	52                   	push   %edx
 804842b:	68 90 85 04 08       	push   $0x8048590
 8048430:	68 20 85 04 08       	push   $0x8048520
 8048435:	51                   	push   %ecx
 8048436:	56                   	push   %esi
 8048437:	68 d4 84 04 08       	push   $0x80484d4
 804843c:	e8 cf ff ff ff       	call   8048410 <__libc_start_main@plt>
 8048441:	f4                   	hlt    
 8048442:	90                   	nop
 8048443:	90                   	nop
 8048444:	90                   	nop
 8048445:	90                   	nop
 8048446:	90                   	nop
 8048447:	90                   	nop
 8048448:	90                   	nop
 8048449:	90                   	nop
 804844a:	90                   	nop
 804844b:	90                   	nop
 804844c:	90                   	nop
 804844d:	90                   	nop
 804844e:	90                   	nop
 804844f:	90                   	nop

08048450 <__do_global_dtors_aux>:
 8048450:	55                   	push   %ebp
 8048451:	89 e5                	mov    %esp,%ebp
 8048453:	53                   	push   %ebx
 8048454:	83 ec 04             	sub    $0x4,%esp
 8048457:	80 3d 18 a0 04 08 00 	cmpb   $0x0,0x804a018
 804845e:	75 3f                	jne    804849f <__do_global_dtors_aux+0x4f>
 8048460:	a1 1c a0 04 08       	mov    0x804a01c,%eax
 8048465:	bb 18 9f 04 08       	mov    $0x8049f18,%ebx
 804846a:	81 eb 14 9f 04 08    	sub    $0x8049f14,%ebx
 8048470:	c1 fb 02             	sar    $0x2,%ebx
 8048473:	83 eb 01             	sub    $0x1,%ebx
 8048476:	39 d8                	cmp    %ebx,%eax
 8048478:	73 1e                	jae    8048498 <__do_global_dtors_aux+0x48>
 804847a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048480:	83 c0 01             	add    $0x1,%eax
 8048483:	a3 1c a0 04 08       	mov    %eax,0x804a01c
 8048488:	ff 14 85 14 9f 04 08 	call   *0x8049f14(,%eax,4)
 804848f:	a1 1c a0 04 08       	mov    0x804a01c,%eax
 8048494:	39 d8                	cmp    %ebx,%eax
 8048496:	72 e8                	jb     8048480 <__do_global_dtors_aux+0x30>
 8048498:	c6 05 18 a0 04 08 01 	movb   $0x1,0x804a018
 804849f:	83 c4 04             	add    $0x4,%esp
 80484a2:	5b                   	pop    %ebx
 80484a3:	5d                   	pop    %ebp
 80484a4:	c3                   	ret    
 80484a5:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80484a9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080484b0 <frame_dummy>:
 80484b0:	55                   	push   %ebp
 80484b1:	89 e5                	mov    %esp,%ebp
 80484b3:	83 ec 18             	sub    $0x18,%esp
 80484b6:	a1 1c 9f 04 08       	mov    0x8049f1c,%eax
 80484bb:	85 c0                	test   %eax,%eax
 80484bd:	74 12                	je     80484d1 <frame_dummy+0x21>
 80484bf:	b8 00 00 00 00       	mov    $0x0,%eax
 80484c4:	85 c0                	test   %eax,%eax
 80484c6:	74 09                	je     80484d1 <frame_dummy+0x21>
 80484c8:	c7 04 24 1c 9f 04 08 	movl   $0x8049f1c,(%esp)
 80484cf:	ff d0                	call   *%eax
 80484d1:	c9                   	leave  
 80484d2:	c3                   	ret    
 80484d3:	90                   	nop

080484d4 <main>:
 80484d4:	55                   	push   %ebp
 80484d5:	89 e5                	mov    %esp,%ebp
 80484d7:	83 e4 f0             	and    $0xfffffff0,%esp
 80484da:	83 ec 20             	sub    $0x20,%esp
 80484dd:	dd 05 f0 85 04 08    	fldl   0x80485f0
 80484e3:	dd 5c 24 08          	fstpl  0x8(%esp)
 80484e7:	dd 05 f8 85 04 08    	fldl   0x80485f8
 80484ed:	dd 1c 24             	fstpl  (%esp)
 80484f0:	e8 eb fe ff ff       	call   80483e0 <add@plt>
 80484f5:	dd 5c 24 14          	fstpl  0x14(%esp)
 80484f9:	dd 05 f0 85 04 08    	fldl   0x80485f0
 80484ff:	dd 5c 24 0c          	fstpl  0xc(%esp)
 8048503:	c7 44 24 08 2b 00 00 	movl   $0x2b,0x8(%esp)
 804850a:	00 
 804850b:	dd 05 f8 85 04 08    	fldl   0x80485f8
 8048511:	dd 1c 24             	fstpl  (%esp)
 8048514:	e8 d7 fe ff ff       	call   80483f0 <show@plt>
 8048519:	b8 00 00 00 00       	mov    $0x0,%eax
 804851e:	c9                   	leave  
 804851f:	c3                   	ret    

08048520 <__libc_csu_init>:
 8048520:	55                   	push   %ebp
 8048521:	57                   	push   %edi
 8048522:	56                   	push   %esi
 8048523:	53                   	push   %ebx
 8048524:	e8 69 00 00 00       	call   8048592 <__i686.get_pc_thunk.bx>
 8048529:	81 c3 cb 1a 00 00    	add    $0x1acb,%ebx
 804852f:	83 ec 1c             	sub    $0x1c,%esp
 8048532:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 8048536:	8d bb 18 ff ff ff    	lea    -0xe8(%ebx),%edi
 804853c:	e8 57 fe ff ff       	call   8048398 <_init>
 8048541:	8d 83 18 ff ff ff    	lea    -0xe8(%ebx),%eax
 8048547:	29 c7                	sub    %eax,%edi
 8048549:	c1 ff 02             	sar    $0x2,%edi
 804854c:	85 ff                	test   %edi,%edi
 804854e:	74 29                	je     8048579 <__libc_csu_init+0x59>
 8048550:	31 f6                	xor    %esi,%esi
 8048552:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048558:	8b 44 24 38          	mov    0x38(%esp),%eax
 804855c:	89 2c 24             	mov    %ebp,(%esp)
 804855f:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048563:	8b 44 24 34          	mov    0x34(%esp),%eax
 8048567:	89 44 24 04          	mov    %eax,0x4(%esp)
 804856b:	ff 94 b3 18 ff ff ff 	call   *-0xe8(%ebx,%esi,4)
 8048572:	83 c6 01             	add    $0x1,%esi
 8048575:	39 fe                	cmp    %edi,%esi
 8048577:	75 df                	jne    8048558 <__libc_csu_init+0x38>
 8048579:	83 c4 1c             	add    $0x1c,%esp
 804857c:	5b                   	pop    %ebx
 804857d:	5e                   	pop    %esi
 804857e:	5f                   	pop    %edi
 804857f:	5d                   	pop    %ebp
 8048580:	c3                   	ret    
 8048581:	eb 0d                	jmp    8048590 <__libc_csu_fini>
 8048583:	90                   	nop
 8048584:	90                   	nop
 8048585:	90                   	nop
 8048586:	90                   	nop
 8048587:	90                   	nop
 8048588:	90                   	nop
 8048589:	90                   	nop
 804858a:	90                   	nop
 804858b:	90                   	nop
 804858c:	90                   	nop
 804858d:	90                   	nop
 804858e:	90                   	nop
 804858f:	90                   	nop

08048590 <__libc_csu_fini>:
 8048590:	f3 c3                	repz ret 

08048592 <__i686.get_pc_thunk.bx>:
 8048592:	8b 1c 24             	mov    (%esp),%ebx
 8048595:	c3                   	ret    
 8048596:	90                   	nop
 8048597:	90                   	nop
 8048598:	90                   	nop
 8048599:	90                   	nop
 804859a:	90                   	nop
 804859b:	90                   	nop
 804859c:	90                   	nop
 804859d:	90                   	nop
 804859e:	90                   	nop
 804859f:	90                   	nop

080485a0 <__do_global_ctors_aux>:
 80485a0:	55                   	push   %ebp
 80485a1:	89 e5                	mov    %esp,%ebp
 80485a3:	53                   	push   %ebx
 80485a4:	83 ec 04             	sub    $0x4,%esp
 80485a7:	a1 0c 9f 04 08       	mov    0x8049f0c,%eax
 80485ac:	83 f8 ff             	cmp    $0xffffffff,%eax
 80485af:	74 13                	je     80485c4 <__do_global_ctors_aux+0x24>
 80485b1:	bb 0c 9f 04 08       	mov    $0x8049f0c,%ebx
 80485b6:	66 90                	xchg   %ax,%ax
 80485b8:	83 eb 04             	sub    $0x4,%ebx
 80485bb:	ff d0                	call   *%eax
 80485bd:	8b 03                	mov    (%ebx),%eax
 80485bf:	83 f8 ff             	cmp    $0xffffffff,%eax
 80485c2:	75 f4                	jne    80485b8 <__do_global_ctors_aux+0x18>
 80485c4:	83 c4 04             	add    $0x4,%esp
 80485c7:	5b                   	pop    %ebx
 80485c8:	5d                   	pop    %ebp
 80485c9:	c3                   	ret    
 80485ca:	90                   	nop
 80485cb:	90                   	nop

Disassembly of section .fini:

080485cc <_fini>:
 80485cc:	53                   	push   %ebx
 80485cd:	83 ec 08             	sub    $0x8,%esp
 80485d0:	e8 00 00 00 00       	call   80485d5 <_fini+0x9>
 80485d5:	5b                   	pop    %ebx
 80485d6:	81 c3 1f 1a 00 00    	add    $0x1a1f,%ebx
 80485dc:	e8 6f fe ff ff       	call   8048450 <__do_global_dtors_aux>
 80485e1:	83 c4 08             	add    $0x8,%esp
 80485e4:	5b                   	pop    %ebx
 80485e5:	c3                   	ret    
