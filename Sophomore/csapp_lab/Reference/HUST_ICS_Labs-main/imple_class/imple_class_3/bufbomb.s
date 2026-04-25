
bufbomb：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64 
  401004:	48 83 ec 08          	sub    $0x8,%rsp
  401008:	48 8b 05 e9 2f 00 00 	mov    0x2fe9(%rip),%rax        # 403ff8 <__gmon_start__@Base>
  40100f:	48 85 c0             	test   %rax,%rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	call   *%rax
  401016:	48 83 c4 08          	add    $0x8,%rsp
  40101a:	c3                   	ret    

Disassembly of section .plt:

0000000000401020 <free@plt-0x10>:
  401020:	ff 35 e2 2f 00 00    	push   0x2fe2(%rip)        # 404008 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 e4 2f 00 00    	jmp    *0x2fe4(%rip)        # 404010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401030 <free@plt>:
  401030:	ff 25 e2 2f 00 00    	jmp    *0x2fe2(%rip)        # 404018 <free@GLIBC_2.2.5>
  401036:	68 00 00 00 00       	push   $0x0
  40103b:	e9 e0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401040 <strcpy@plt>:
  401040:	ff 25 da 2f 00 00    	jmp    *0x2fda(%rip)        # 404020 <strcpy@GLIBC_2.2.5>
  401046:	68 01 00 00 00       	push   $0x1
  40104b:	e9 d0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401050 <__isoc99_fscanf@plt>:
  401050:	ff 25 d2 2f 00 00    	jmp    *0x2fd2(%rip)        # 404028 <__isoc99_fscanf@GLIBC_2.7>
  401056:	68 02 00 00 00       	push   $0x2
  40105b:	e9 c0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401060 <puts@plt>:
  401060:	ff 25 ca 2f 00 00    	jmp    *0x2fca(%rip)        # 404030 <puts@GLIBC_2.2.5>
  401066:	68 03 00 00 00       	push   $0x3
  40106b:	e9 b0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401070 <fclose@plt>:
  401070:	ff 25 c2 2f 00 00    	jmp    *0x2fc2(%rip)        # 404038 <fclose@GLIBC_2.2.5>
  401076:	68 04 00 00 00       	push   $0x4
  40107b:	e9 a0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401080 <strlen@plt>:
  401080:	ff 25 ba 2f 00 00    	jmp    *0x2fba(%rip)        # 404040 <strlen@GLIBC_2.2.5>
  401086:	68 05 00 00 00       	push   $0x5
  40108b:	e9 90 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401090 <printf@plt>:
  401090:	ff 25 b2 2f 00 00    	jmp    *0x2fb2(%rip)        # 404048 <printf@GLIBC_2.2.5>
  401096:	68 06 00 00 00       	push   $0x6
  40109b:	e9 80 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010a0 <strcmp@plt>:
  4010a0:	ff 25 aa 2f 00 00    	jmp    *0x2faa(%rip)        # 404050 <strcmp@GLIBC_2.2.5>
  4010a6:	68 07 00 00 00       	push   $0x7
  4010ab:	e9 70 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010b0 <fprintf@plt>:
  4010b0:	ff 25 a2 2f 00 00    	jmp    *0x2fa2(%rip)        # 404058 <fprintf@GLIBC_2.2.5>
  4010b6:	68 08 00 00 00       	push   $0x8
  4010bb:	e9 60 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010c0 <memcpy@plt>:
  4010c0:	ff 25 9a 2f 00 00    	jmp    *0x2f9a(%rip)        # 404060 <memcpy@GLIBC_2.14>
  4010c6:	68 09 00 00 00       	push   $0x9
  4010cb:	e9 50 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010d0 <malloc@plt>:
  4010d0:	ff 25 92 2f 00 00    	jmp    *0x2f92(%rip)        # 404068 <malloc@GLIBC_2.2.5>
  4010d6:	68 0a 00 00 00       	push   $0xa
  4010db:	e9 40 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010e0 <__isoc99_sscanf@plt>:
  4010e0:	ff 25 8a 2f 00 00    	jmp    *0x2f8a(%rip)        # 404070 <__isoc99_sscanf@GLIBC_2.7>
  4010e6:	68 0b 00 00 00       	push   $0xb
  4010eb:	e9 30 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010f0 <realloc@plt>:
  4010f0:	ff 25 82 2f 00 00    	jmp    *0x2f82(%rip)        # 404078 <realloc@GLIBC_2.2.5>
  4010f6:	68 0c 00 00 00       	push   $0xc
  4010fb:	e9 20 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401100 <fopen@plt>:
  401100:	ff 25 7a 2f 00 00    	jmp    *0x2f7a(%rip)        # 404080 <fopen@GLIBC_2.2.5>
  401106:	68 0d 00 00 00       	push   $0xd
  40110b:	e9 10 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401110 <atoi@plt>:
  401110:	ff 25 72 2f 00 00    	jmp    *0x2f72(%rip)        # 404088 <atoi@GLIBC_2.2.5>
  401116:	68 0e 00 00 00       	push   $0xe
  40111b:	e9 00 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401120 <exit@plt>:
  401120:	ff 25 6a 2f 00 00    	jmp    *0x2f6a(%rip)        # 404090 <exit@GLIBC_2.2.5>
  401126:	68 0f 00 00 00       	push   $0xf
  40112b:	e9 f0 fe ff ff       	jmp    401020 <_init+0x20>

0000000000401130 <__ctype_b_loc@plt>:
  401130:	ff 25 62 2f 00 00    	jmp    *0x2f62(%rip)        # 404098 <__ctype_b_loc@GLIBC_2.3>
  401136:	68 10 00 00 00       	push   $0x10
  40113b:	e9 e0 fe ff ff       	jmp    401020 <_init+0x20>

Disassembly of section .text:

0000000000401140 <_start>:
  401140:	f3 0f 1e fa          	endbr64 
  401144:	31 ed                	xor    %ebp,%ebp
  401146:	49 89 d1             	mov    %rdx,%r9
  401149:	5e                   	pop    %rsi
  40114a:	48 89 e2             	mov    %rsp,%rdx
  40114d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  401151:	50                   	push   %rax
  401152:	54                   	push   %rsp
  401153:	45 31 c0             	xor    %r8d,%r8d
  401156:	31 c9                	xor    %ecx,%ecx
  401158:	48 c7 c7 c2 15 40 00 	mov    $0x4015c2,%rdi
  40115f:	ff 15 8b 2e 00 00    	call   *0x2e8b(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.34>
  401165:	f4                   	hlt    
  401166:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  40116d:	00 00 00 

0000000000401170 <_dl_relocate_static_pie>:
  401170:	f3 0f 1e fa          	endbr64 
  401174:	c3                   	ret    
  401175:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  40117c:	00 00 00 
  40117f:	90                   	nop

0000000000401180 <deregister_tm_clones>:
  401180:	b8 c0 40 40 00       	mov    $0x4040c0,%eax
  401185:	48 3d c0 40 40 00    	cmp    $0x4040c0,%rax
  40118b:	74 13                	je     4011a0 <deregister_tm_clones+0x20>
  40118d:	b8 00 00 00 00       	mov    $0x0,%eax
  401192:	48 85 c0             	test   %rax,%rax
  401195:	74 09                	je     4011a0 <deregister_tm_clones+0x20>
  401197:	bf c0 40 40 00       	mov    $0x4040c0,%edi
  40119c:	ff e0                	jmp    *%rax
  40119e:	66 90                	xchg   %ax,%ax
  4011a0:	c3                   	ret    
  4011a1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  4011a8:	00 00 00 00 
  4011ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004011b0 <register_tm_clones>:
  4011b0:	be c0 40 40 00       	mov    $0x4040c0,%esi
  4011b5:	48 81 ee c0 40 40 00 	sub    $0x4040c0,%rsi
  4011bc:	48 89 f0             	mov    %rsi,%rax
  4011bf:	48 c1 ee 3f          	shr    $0x3f,%rsi
  4011c3:	48 c1 f8 03          	sar    $0x3,%rax
  4011c7:	48 01 c6             	add    %rax,%rsi
  4011ca:	48 d1 fe             	sar    %rsi
  4011cd:	74 11                	je     4011e0 <register_tm_clones+0x30>
  4011cf:	b8 00 00 00 00       	mov    $0x0,%eax
  4011d4:	48 85 c0             	test   %rax,%rax
  4011d7:	74 07                	je     4011e0 <register_tm_clones+0x30>
  4011d9:	bf c0 40 40 00       	mov    $0x4040c0,%edi
  4011de:	ff e0                	jmp    *%rax
  4011e0:	c3                   	ret    
  4011e1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  4011e8:	00 00 00 00 
  4011ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004011f0 <__do_global_dtors_aux>:
  4011f0:	f3 0f 1e fa          	endbr64 
  4011f4:	80 3d cd 2e 00 00 00 	cmpb   $0x0,0x2ecd(%rip)        # 4040c8 <completed.0>
  4011fb:	75 13                	jne    401210 <__do_global_dtors_aux+0x20>
  4011fd:	55                   	push   %rbp
  4011fe:	48 89 e5             	mov    %rsp,%rbp
  401201:	e8 7a ff ff ff       	call   401180 <deregister_tm_clones>
  401206:	c6 05 bb 2e 00 00 01 	movb   $0x1,0x2ebb(%rip)        # 4040c8 <completed.0>
  40120d:	5d                   	pop    %rbp
  40120e:	c3                   	ret    
  40120f:	90                   	nop
  401210:	c3                   	ret    
  401211:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  401218:	00 00 00 00 
  40121c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401220 <frame_dummy>:
  401220:	f3 0f 1e fa          	endbr64 
  401224:	eb 8a                	jmp    4011b0 <register_tm_clones>

0000000000401226 <initialize_bomb>:
  401226:	55                   	push   %rbp
  401227:	48 89 e5             	mov    %rsp,%rbp
  40122a:	48 83 ec 30          	sub    $0x30,%rsp
  40122e:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  401232:	c7 45 fc 0a 00 00 00 	movl   $0xa,-0x4(%rbp)
  401239:	c7 45 f8 14 00 00 00 	movl   $0x14,-0x8(%rbp)
  401240:	c7 45 f4 1e 00 00 00 	movl   $0x1e,-0xc(%rbp)
  401247:	c7 45 f0 28 00 00 00 	movl   $0x28,-0x10(%rbp)
  40124e:	c7 45 ec 32 00 00 00 	movl   $0x32,-0x14(%rbp)
  401255:	c7 45 e8 3c 00 00 00 	movl   $0x3c,-0x18(%rbp)
  40125c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401260:	48 89 c7             	mov    %rax,%rdi
  401263:	e8 18 fe ff ff       	call   401080 <strlen@plt>
  401268:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  40126b:	83 7d e4 0a          	cmpl   $0xa,-0x1c(%rbp)
  40126f:	74 19                	je     40128a <initialize_bomb+0x64>
  401271:	48 8d 05 90 0d 00 00 	lea    0xd90(%rip),%rax        # 402008 <_IO_stdin_used+0x8>
  401278:	48 89 c7             	mov    %rax,%rdi
  40127b:	e8 e0 fd ff ff       	call   401060 <puts@plt>
  401280:	bf 00 00 00 00       	mov    $0x0,%edi
  401285:	e8 96 fe ff ff       	call   401120 <exit@plt>
  40128a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40128e:	48 89 c6             	mov    %rax,%rsi
  401291:	48 8d 05 aa 0d 00 00 	lea    0xdaa(%rip),%rax        # 402042 <_IO_stdin_used+0x42>
  401298:	48 89 c7             	mov    %rax,%rdi
  40129b:	b8 00 00 00 00       	mov    $0x0,%eax
  4012a0:	e8 eb fd ff ff       	call   401090 <printf@plt>
  4012a5:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  4012a8:	48 98                	cltq   
  4012aa:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
  4012ae:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4012b2:	48 01 d0             	add    %rdx,%rax
  4012b5:	0f b6 00             	movzbl (%rax),%eax
  4012b8:	3c 37                	cmp    $0x37,%al
  4012ba:	74 37                	je     4012f3 <initialize_bomb+0xcd>
  4012bc:	48 8d 05 8d 0d 00 00 	lea    0xd8d(%rip),%rax        # 402050 <_IO_stdin_used+0x50>
  4012c3:	48 89 c7             	mov    %rax,%rdi
  4012c6:	e8 95 fd ff ff       	call   401060 <puts@plt>
  4012cb:	48 8d 05 b6 0d 00 00 	lea    0xdb6(%rip),%rax        # 402088 <_IO_stdin_used+0x88>
  4012d2:	48 89 c7             	mov    %rax,%rdi
  4012d5:	e8 86 fd ff ff       	call   401060 <puts@plt>
  4012da:	48 8d 05 df 0d 00 00 	lea    0xddf(%rip),%rax        # 4020c0 <_IO_stdin_used+0xc0>
  4012e1:	48 89 c7             	mov    %rax,%rdi
  4012e4:	e8 77 fd ff ff       	call   401060 <puts@plt>
  4012e9:	bf 00 00 00 00       	mov    $0x0,%edi
  4012ee:	e8 2d fe ff ff       	call   401120 <exit@plt>
  4012f3:	90                   	nop
  4012f4:	c9                   	leave  
  4012f5:	c3                   	ret    

00000000004012f6 <smoke>:
  4012f6:	55                   	push   %rbp
  4012f7:	48 89 e5             	mov    %rsp,%rbp
  4012fa:	48 8d 05 e5 0d 00 00 	lea    0xde5(%rip),%rax        # 4020e6 <_IO_stdin_used+0xe6>
  401301:	48 89 c7             	mov    %rax,%rdi
  401304:	e8 57 fd ff ff       	call   401060 <puts@plt>
  401309:	bf 00 00 00 00       	mov    $0x0,%edi
  40130e:	e8 0d fe ff ff       	call   401120 <exit@plt>

0000000000401313 <fizz>:
  401313:	55                   	push   %rbp
  401314:	48 89 e5             	mov    %rsp,%rbp
  401317:	48 83 ec 10          	sub    $0x10,%rsp
  40131b:	89 7d fc             	mov    %edi,-0x4(%rbp)
  40131e:	8b 05 c4 2d 00 00    	mov    0x2dc4(%rip),%eax        # 4040e8 <cookie>
  401324:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  401327:	75 1b                	jne    401344 <fizz+0x31>
  401329:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40132c:	89 c6                	mov    %eax,%esi
  40132e:	48 8d 05 cc 0d 00 00 	lea    0xdcc(%rip),%rax        # 402101 <_IO_stdin_used+0x101>
  401335:	48 89 c7             	mov    %rax,%rdi
  401338:	b8 00 00 00 00       	mov    $0x0,%eax
  40133d:	e8 4e fd ff ff       	call   401090 <printf@plt>
  401342:	eb 19                	jmp    40135d <fizz+0x4a>
  401344:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401347:	89 c6                	mov    %eax,%esi
  401349:	48 8d 05 d0 0d 00 00 	lea    0xdd0(%rip),%rax        # 402120 <_IO_stdin_used+0x120>
  401350:	48 89 c7             	mov    %rax,%rdi
  401353:	b8 00 00 00 00       	mov    $0x0,%eax
  401358:	e8 33 fd ff ff       	call   401090 <printf@plt>
  40135d:	bf 00 00 00 00       	mov    $0x0,%edi
  401362:	e8 b9 fd ff ff       	call   401120 <exit@plt>

0000000000401367 <bang>:
  401367:	55                   	push   %rbp
  401368:	48 89 e5             	mov    %rsp,%rbp
  40136b:	48 83 ec 10          	sub    $0x10,%rsp
  40136f:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401372:	8b 15 74 2d 00 00    	mov    0x2d74(%rip),%edx        # 4040ec <global_value>
  401378:	8b 05 6a 2d 00 00    	mov    0x2d6a(%rip),%eax        # 4040e8 <cookie>
  40137e:	39 c2                	cmp    %eax,%edx
  401380:	75 1e                	jne    4013a0 <bang+0x39>
  401382:	8b 05 64 2d 00 00    	mov    0x2d64(%rip),%eax        # 4040ec <global_value>
  401388:	89 c6                	mov    %eax,%esi
  40138a:	48 8d 05 af 0d 00 00 	lea    0xdaf(%rip),%rax        # 402140 <_IO_stdin_used+0x140>
  401391:	48 89 c7             	mov    %rax,%rdi
  401394:	b8 00 00 00 00       	mov    $0x0,%eax
  401399:	e8 f2 fc ff ff       	call   401090 <printf@plt>
  40139e:	eb 1c                	jmp    4013bc <bang+0x55>
  4013a0:	8b 05 46 2d 00 00    	mov    0x2d46(%rip),%eax        # 4040ec <global_value>
  4013a6:	89 c6                	mov    %eax,%esi
  4013a8:	48 8d 05 b6 0d 00 00 	lea    0xdb6(%rip),%rax        # 402165 <_IO_stdin_used+0x165>
  4013af:	48 89 c7             	mov    %rax,%rdi
  4013b2:	b8 00 00 00 00       	mov    $0x0,%eax
  4013b7:	e8 d4 fc ff ff       	call   401090 <printf@plt>
  4013bc:	bf 00 00 00 00       	mov    $0x0,%edi
  4013c1:	e8 5a fd ff ff       	call   401120 <exit@plt>

00000000004013c6 <test>:
  4013c6:	55                   	push   %rbp
  4013c7:	48 89 e5             	mov    %rsp,%rbp
  4013ca:	48 83 ec 30          	sub    $0x30,%rsp
  4013ce:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  4013d2:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  4013d9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4013dd:	8b 40 7c             	mov    0x7c(%rax),%eax
  4013e0:	85 c0                	test   %eax,%eax
  4013e2:	74 24                	je     401408 <test+0x42>
  4013e4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4013e8:	8b 40 7c             	mov    0x7c(%rax),%eax
  4013eb:	83 f8 01             	cmp    $0x1,%eax
  4013ee:	74 18                	je     401408 <test+0x42>
  4013f0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4013f4:	8b 40 7c             	mov    0x7c(%rax),%eax
  4013f7:	83 f8 02             	cmp    $0x2,%eax
  4013fa:	74 0c                	je     401408 <test+0x42>
  4013fc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401400:	8b 40 7c             	mov    0x7c(%rax),%eax
  401403:	83 f8 03             	cmp    $0x3,%eax
  401406:	75 75                	jne    40147d <test+0xb7>
  401408:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40140c:	48 8d 15 70 0d 00 00 	lea    0xd70(%rip),%rdx        # 402183 <_IO_stdin_used+0x183>
  401413:	48 89 d6             	mov    %rdx,%rsi
  401416:	48 89 c7             	mov    %rax,%rdi
  401419:	e8 e2 fc ff ff       	call   401100 <fopen@plt>
  40141e:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  401422:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  401427:	75 1d                	jne    401446 <test+0x80>
  401429:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40142d:	48 89 c6             	mov    %rax,%rsi
  401430:	48 8d 05 4e 0d 00 00 	lea    0xd4e(%rip),%rax        # 402185 <_IO_stdin_used+0x185>
  401437:	48 89 c7             	mov    %rax,%rdi
  40143a:	b8 00 00 00 00       	mov    $0x0,%eax
  40143f:	e8 4c fc ff ff       	call   401090 <printf@plt>
  401444:	eb 76                	jmp    4014bc <test+0xf6>
  401446:	48 8d 55 e4          	lea    -0x1c(%rbp),%rdx
  40144a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40144e:	48 89 d6             	mov    %rdx,%rsi
  401451:	48 89 c7             	mov    %rax,%rdi
  401454:	e8 44 03 00 00       	call   40179d <convert_to_byte_string>
  401459:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  40145d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401461:	48 89 c7             	mov    %rax,%rdi
  401464:	e8 07 fc ff ff       	call   401070 <fclose@plt>
  401469:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  40146c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401470:	89 d6                	mov    %edx,%esi
  401472:	48 89 c7             	mov    %rax,%rdi
  401475:	e8 d9 05 00 00       	call   401a53 <getbuf>
  40147a:	89 45 fc             	mov    %eax,-0x4(%rbp)
  40147d:	8b 05 65 2c 00 00    	mov    0x2c65(%rip),%eax        # 4040e8 <cookie>
  401483:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  401486:	75 1b                	jne    4014a3 <test+0xdd>
  401488:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40148b:	89 c6                	mov    %eax,%esi
  40148d:	48 8d 05 0d 0d 00 00 	lea    0xd0d(%rip),%rax        # 4021a1 <_IO_stdin_used+0x1a1>
  401494:	48 89 c7             	mov    %rax,%rdi
  401497:	b8 00 00 00 00       	mov    $0x0,%eax
  40149c:	e8 ef fb ff ff       	call   401090 <printf@plt>
  4014a1:	eb 19                	jmp    4014bc <test+0xf6>
  4014a3:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4014a6:	89 c6                	mov    %eax,%esi
  4014a8:	48 8d 05 0f 0d 00 00 	lea    0xd0f(%rip),%rax        # 4021be <_IO_stdin_used+0x1be>
  4014af:	48 89 c7             	mov    %rax,%rdi
  4014b2:	b8 00 00 00 00       	mov    $0x0,%eax
  4014b7:	e8 d4 fb ff ff       	call   401090 <printf@plt>
  4014bc:	c9                   	leave  
  4014bd:	c3                   	ret    

00000000004014be <save_char>:
  4014be:	55                   	push   %rbp
  4014bf:	48 89 e5             	mov    %rsp,%rbp
  4014c2:	89 f8                	mov    %edi,%eax
  4014c4:	88 45 fc             	mov    %al,-0x4(%rbp)
  4014c7:	8b 05 23 2c 00 00    	mov    0x2c23(%rip),%eax        # 4040f0 <gets_cnt>
  4014cd:	3d ff 03 00 00       	cmp    $0x3ff,%eax
  4014d2:	0f 8f 95 00 00 00    	jg     40156d <save_char+0xaf>
  4014d8:	0f b6 45 fc          	movzbl -0x4(%rbp),%eax
  4014dc:	c0 f8 04             	sar    $0x4,%al
  4014df:	0f be c0             	movsbl %al,%eax
  4014e2:	83 e0 0f             	and    $0xf,%eax
  4014e5:	89 c6                	mov    %eax,%esi
  4014e7:	8b 15 03 2c 00 00    	mov    0x2c03(%rip),%edx        # 4040f0 <gets_cnt>
  4014ed:	89 d0                	mov    %edx,%eax
  4014ef:	01 c0                	add    %eax,%eax
  4014f1:	8d 0c 10             	lea    (%rax,%rdx,1),%ecx
  4014f4:	48 63 c6             	movslq %esi,%rax
  4014f7:	48 8d 15 b2 2b 00 00 	lea    0x2bb2(%rip),%rdx        # 4040b0 <trans_char>
  4014fe:	0f b6 14 10          	movzbl (%rax,%rdx,1),%edx
  401502:	48 63 c1             	movslq %ecx,%rax
  401505:	48 8d 0d f4 2b 00 00 	lea    0x2bf4(%rip),%rcx        # 404100 <gets_buf>
  40150c:	88 14 08             	mov    %dl,(%rax,%rcx,1)
  40150f:	0f be 45 fc          	movsbl -0x4(%rbp),%eax
  401513:	83 e0 0f             	and    $0xf,%eax
  401516:	89 c6                	mov    %eax,%esi
  401518:	8b 15 d2 2b 00 00    	mov    0x2bd2(%rip),%edx        # 4040f0 <gets_cnt>
  40151e:	89 d0                	mov    %edx,%eax
  401520:	01 c0                	add    %eax,%eax
  401522:	01 d0                	add    %edx,%eax
  401524:	8d 48 01             	lea    0x1(%rax),%ecx
  401527:	48 63 c6             	movslq %esi,%rax
  40152a:	48 8d 15 7f 2b 00 00 	lea    0x2b7f(%rip),%rdx        # 4040b0 <trans_char>
  401531:	0f b6 14 10          	movzbl (%rax,%rdx,1),%edx
  401535:	48 63 c1             	movslq %ecx,%rax
  401538:	48 8d 0d c1 2b 00 00 	lea    0x2bc1(%rip),%rcx        # 404100 <gets_buf>
  40153f:	88 14 08             	mov    %dl,(%rax,%rcx,1)
  401542:	8b 15 a8 2b 00 00    	mov    0x2ba8(%rip),%edx        # 4040f0 <gets_cnt>
  401548:	89 d0                	mov    %edx,%eax
  40154a:	01 c0                	add    %eax,%eax
  40154c:	01 d0                	add    %edx,%eax
  40154e:	83 c0 02             	add    $0x2,%eax
  401551:	48 98                	cltq   
  401553:	48 8d 15 a6 2b 00 00 	lea    0x2ba6(%rip),%rdx        # 404100 <gets_buf>
  40155a:	c6 04 10 20          	movb   $0x20,(%rax,%rdx,1)
  40155e:	8b 05 8c 2b 00 00    	mov    0x2b8c(%rip),%eax        # 4040f0 <gets_cnt>
  401564:	83 c0 01             	add    $0x1,%eax
  401567:	89 05 83 2b 00 00    	mov    %eax,0x2b83(%rip)        # 4040f0 <gets_cnt>
  40156d:	90                   	nop
  40156e:	5d                   	pop    %rbp
  40156f:	c3                   	ret    

0000000000401570 <save_term>:
  401570:	55                   	push   %rbp
  401571:	48 89 e5             	mov    %rsp,%rbp
  401574:	8b 15 76 2b 00 00    	mov    0x2b76(%rip),%edx        # 4040f0 <gets_cnt>
  40157a:	89 d0                	mov    %edx,%eax
  40157c:	01 c0                	add    %eax,%eax
  40157e:	01 d0                	add    %edx,%eax
  401580:	48 98                	cltq   
  401582:	48 8d 15 77 2b 00 00 	lea    0x2b77(%rip),%rdx        # 404100 <gets_buf>
  401589:	c6 04 10 00          	movb   $0x0,(%rax,%rdx,1)
  40158d:	90                   	nop
  40158e:	5d                   	pop    %rbp
  40158f:	c3                   	ret    

0000000000401590 <Gets>:
  401590:	55                   	push   %rbp
  401591:	48 89 e5             	mov    %rsp,%rbp
  401594:	48 83 ec 20          	sub    $0x20,%rsp
  401598:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40159c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  4015a0:	89 55 ec             	mov    %edx,-0x14(%rbp)
  4015a3:	8b 45 ec             	mov    -0x14(%rbp),%eax
  4015a6:	48 63 d0             	movslq %eax,%rdx
  4015a9:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  4015ad:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4015b1:	48 89 ce             	mov    %rcx,%rsi
  4015b4:	48 89 c7             	mov    %rax,%rdi
  4015b7:	e8 04 fb ff ff       	call   4010c0 <memcpy@plt>
  4015bc:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4015c0:	c9                   	leave  
  4015c1:	c3                   	ret    

00000000004015c2 <main>:
  4015c2:	55                   	push   %rbp
  4015c3:	48 89 e5             	mov    %rsp,%rbp
  4015c6:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
  4015cd:	89 bd 7c ff ff ff    	mov    %edi,-0x84(%rbp)
  4015d3:	48 89 b5 70 ff ff ff 	mov    %rsi,-0x90(%rbp)
  4015da:	83 bd 7c ff ff ff 03 	cmpl   $0x3,-0x84(%rbp)
  4015e1:	7f 3a                	jg     40161d <main+0x5b>
  4015e3:	48 8b 85 70 ff ff ff 	mov    -0x90(%rbp),%rax
  4015ea:	48 8b 00             	mov    (%rax),%rax
  4015ed:	48 89 c6             	mov    %rax,%rsi
  4015f0:	48 8d 05 e9 0b 00 00 	lea    0xbe9(%rip),%rax        # 4021e0 <_IO_stdin_used+0x1e0>
  4015f7:	48 89 c7             	mov    %rax,%rdi
  4015fa:	b8 00 00 00 00       	mov    $0x0,%eax
  4015ff:	e8 8c fa ff ff       	call   401090 <printf@plt>
  401604:	48 8d 05 05 0c 00 00 	lea    0xc05(%rip),%rax        # 402210 <_IO_stdin_used+0x210>
  40160b:	48 89 c7             	mov    %rax,%rdi
  40160e:	e8 4d fa ff ff       	call   401060 <puts@plt>
  401613:	b8 00 00 00 00       	mov    $0x0,%eax
  401618:	e9 4e 01 00 00       	jmp    40176b <main+0x1a9>
  40161d:	48 8b 85 70 ff ff ff 	mov    -0x90(%rbp),%rax
  401624:	48 83 c0 08          	add    $0x8,%rax
  401628:	48 8b 00             	mov    (%rax),%rax
  40162b:	48 8d 55 80          	lea    -0x80(%rbp),%rdx
  40162f:	48 83 c2 64          	add    $0x64,%rdx
  401633:	48 89 c6             	mov    %rax,%rsi
  401636:	48 89 d7             	mov    %rdx,%rdi
  401639:	e8 02 fa ff ff       	call   401040 <strcpy@plt>
  40163e:	48 8b 85 70 ff ff ff 	mov    -0x90(%rbp),%rax
  401645:	48 83 c0 10          	add    $0x10,%rax
  401649:	48 8b 10             	mov    (%rax),%rdx
  40164c:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  401650:	48 89 d6             	mov    %rdx,%rsi
  401653:	48 89 c7             	mov    %rax,%rdi
  401656:	e8 e5 f9 ff ff       	call   401040 <strcpy@plt>
  40165b:	48 8b 85 70 ff ff ff 	mov    -0x90(%rbp),%rax
  401662:	48 83 c0 18          	add    $0x18,%rax
  401666:	48 8b 00             	mov    (%rax),%rax
  401669:	48 89 c7             	mov    %rax,%rdi
  40166c:	e8 9f fa ff ff       	call   401110 <atoi@plt>
  401671:	89 45 fc             	mov    %eax,-0x4(%rbp)
  401674:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  401678:	48 83 c0 64          	add    $0x64,%rax
  40167c:	48 89 c6             	mov    %rax,%rsi
  40167f:	48 8d 05 be 0b 00 00 	lea    0xbbe(%rip),%rax        # 402244 <_IO_stdin_used+0x244>
  401686:	48 89 c7             	mov    %rax,%rdi
  401689:	b8 00 00 00 00       	mov    $0x0,%eax
  40168e:	e8 fd f9 ff ff       	call   401090 <printf@plt>
  401693:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  401697:	48 83 c0 64          	add    $0x64,%rax
  40169b:	48 89 c7             	mov    %rax,%rdi
  40169e:	e8 ff 03 00 00       	call   401aa2 <gencookie>
  4016a3:	89 05 3f 2a 00 00    	mov    %eax,0x2a3f(%rip)        # 4040e8 <cookie>
  4016a9:	8b 05 39 2a 00 00    	mov    0x2a39(%rip),%eax        # 4040e8 <cookie>
  4016af:	89 c6                	mov    %eax,%esi
  4016b1:	48 8d 05 9b 0b 00 00 	lea    0xb9b(%rip),%rax        # 402253 <_IO_stdin_used+0x253>
  4016b8:	48 89 c7             	mov    %rax,%rdi
  4016bb:	b8 00 00 00 00       	mov    $0x0,%eax
  4016c0:	e8 cb f9 ff ff       	call   401090 <printf@plt>
  4016c5:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  4016c9:	48 89 c6             	mov    %rax,%rsi
  4016cc:	48 8d 05 90 0b 00 00 	lea    0xb90(%rip),%rax        # 402263 <_IO_stdin_used+0x263>
  4016d3:	48 89 c7             	mov    %rax,%rdi
  4016d6:	b8 00 00 00 00       	mov    $0x0,%eax
  4016db:	e8 b0 f9 ff ff       	call   401090 <printf@plt>
  4016e0:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4016e3:	89 c6                	mov    %eax,%esi
  4016e5:	48 8d 05 8e 0b 00 00 	lea    0xb8e(%rip),%rax        # 40227a <_IO_stdin_used+0x27a>
  4016ec:	48 89 c7             	mov    %rax,%rdi
  4016ef:	b8 00 00 00 00       	mov    $0x0,%eax
  4016f4:	e8 97 f9 ff ff       	call   401090 <printf@plt>
  4016f9:	48 8d 05 67 fc ff ff 	lea    -0x399(%rip),%rax        # 401367 <bang>
  401700:	48 89 c1             	mov    %rax,%rcx
  401703:	48 8d 05 09 fc ff ff 	lea    -0x3f7(%rip),%rax        # 401313 <fizz>
  40170a:	48 89 c2             	mov    %rax,%rdx
  40170d:	48 8d 05 e2 fb ff ff 	lea    -0x41e(%rip),%rax        # 4012f6 <smoke>
  401714:	48 89 c6             	mov    %rax,%rsi
  401717:	48 8d 05 6a 0b 00 00 	lea    0xb6a(%rip),%rax        # 402288 <_IO_stdin_used+0x288>
  40171e:	48 89 c7             	mov    %rax,%rdi
  401721:	b8 00 00 00 00       	mov    $0x0,%eax
  401726:	e8 65 f9 ff ff       	call   401090 <printf@plt>
  40172b:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  40172f:	48 83 c0 64          	add    $0x64,%rax
  401733:	48 89 c7             	mov    %rax,%rdi
  401736:	e8 eb fa ff ff       	call   401226 <initialize_bomb>
  40173b:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  40173f:	48 89 c7             	mov    %rax,%rdi
  401742:	e8 7f fc ff ff       	call   4013c6 <test>
  401747:	48 8d 45 80          	lea    -0x80(%rbp),%rax
  40174b:	48 83 c0 64          	add    $0x64,%rax
  40174f:	48 89 c6             	mov    %rax,%rsi
  401752:	48 8d 05 59 0b 00 00 	lea    0xb59(%rip),%rax        # 4022b2 <_IO_stdin_used+0x2b2>
  401759:	48 89 c7             	mov    %rax,%rdi
  40175c:	b8 00 00 00 00       	mov    $0x0,%eax
  401761:	e8 2a f9 ff ff       	call   401090 <printf@plt>
  401766:	b8 00 00 00 00       	mov    $0x0,%eax
  40176b:	c9                   	leave  
  40176c:	c3                   	ret    

000000000040176d <convert_to_hex_value>:
  40176d:	55                   	push   %rbp
  40176e:	48 89 e5             	mov    %rsp,%rbp
  401771:	48 83 ec 20          	sub    $0x20,%rsp
  401775:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401779:	48 8d 55 fc          	lea    -0x4(%rbp),%rdx
  40177d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401781:	48 8d 0d 38 0b 00 00 	lea    0xb38(%rip),%rcx        # 4022c0 <_IO_stdin_used+0x2c0>
  401788:	48 89 ce             	mov    %rcx,%rsi
  40178b:	48 89 c7             	mov    %rax,%rdi
  40178e:	b8 00 00 00 00       	mov    $0x0,%eax
  401793:	e8 48 f9 ff ff       	call   4010e0 <__isoc99_sscanf@plt>
  401798:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40179b:	c9                   	leave  
  40179c:	c3                   	ret    

000000000040179d <convert_to_byte_string>:
  40179d:	55                   	push   %rbp
  40179e:	48 89 e5             	mov    %rsp,%rbp
  4017a1:	53                   	push   %rbx
  4017a2:	48 83 ec 58          	sub    $0x58,%rsp
  4017a6:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  4017aa:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  4017ae:	48 89 e0             	mov    %rsp,%rax
  4017b1:	48 89 c3             	mov    %rax,%rbx
  4017b4:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  4017bb:	c7 45 d4 00 10 00 00 	movl   $0x1000,-0x2c(%rbp)
  4017c2:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4017c5:	48 63 d0             	movslq %eax,%rdx
  4017c8:	48 83 ea 01          	sub    $0x1,%rdx
  4017cc:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
  4017d0:	48 63 d0             	movslq %eax,%rdx
  4017d3:	49 89 d2             	mov    %rdx,%r10
  4017d6:	41 bb 00 00 00 00    	mov    $0x0,%r11d
  4017dc:	48 63 d0             	movslq %eax,%rdx
  4017df:	49 89 d0             	mov    %rdx,%r8
  4017e2:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  4017e8:	48 98                	cltq   
  4017ea:	ba 10 00 00 00       	mov    $0x10,%edx
  4017ef:	48 83 ea 01          	sub    $0x1,%rdx
  4017f3:	48 01 d0             	add    %rdx,%rax
  4017f6:	be 10 00 00 00       	mov    $0x10,%esi
  4017fb:	ba 00 00 00 00       	mov    $0x0,%edx
  401800:	48 f7 f6             	div    %rsi
  401803:	48 6b c0 10          	imul   $0x10,%rax,%rax
  401807:	48 89 c1             	mov    %rax,%rcx
  40180a:	48 81 e1 00 f0 ff ff 	and    $0xfffffffffffff000,%rcx
  401811:	48 89 e2             	mov    %rsp,%rdx
  401814:	48 29 ca             	sub    %rcx,%rdx
  401817:	48 39 d4             	cmp    %rdx,%rsp
  40181a:	74 12                	je     40182e <convert_to_byte_string+0x91>
  40181c:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
  401823:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
  40182a:	00 00 
  40182c:	eb e9                	jmp    401817 <convert_to_byte_string+0x7a>
  40182e:	48 89 c2             	mov    %rax,%rdx
  401831:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
  401837:	48 29 d4             	sub    %rdx,%rsp
  40183a:	48 89 c2             	mov    %rax,%rdx
  40183d:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
  401843:	48 85 d2             	test   %rdx,%rdx
  401846:	74 10                	je     401858 <convert_to_byte_string+0xbb>
  401848:	25 ff 0f 00 00       	and    $0xfff,%eax
  40184d:	48 83 e8 08          	sub    $0x8,%rax
  401851:	48 01 e0             	add    %rsp,%rax
  401854:	48 83 08 00          	orq    $0x0,(%rax)
  401858:	48 89 e0             	mov    %rsp,%rax
  40185b:	48 83 c0 00          	add    $0x0,%rax
  40185f:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
  401863:	c7 45 e8 00 04 00 00 	movl   $0x400,-0x18(%rbp)
  40186a:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
  401871:	bf 00 04 00 00       	mov    $0x400,%edi
  401876:	e8 55 f8 ff ff       	call   4010d0 <malloc@plt>
  40187b:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
  40187f:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
  401884:	0f 85 8c 01 00 00    	jne    401a16 <convert_to_byte_string+0x279>
  40188a:	b8 00 00 00 00       	mov    $0x0,%eax
  40188f:	e9 b6 01 00 00       	jmp    401a4a <convert_to_byte_string+0x2ad>
  401894:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  401898:	48 8d 15 24 0a 00 00 	lea    0xa24(%rip),%rdx        # 4022c3 <_IO_stdin_used+0x2c3>
  40189f:	48 89 d6             	mov    %rdx,%rsi
  4018a2:	48 89 c7             	mov    %rax,%rdi
  4018a5:	e8 f6 f7 ff ff       	call   4010a0 <strcmp@plt>
  4018aa:	85 c0                	test   %eax,%eax
  4018ac:	75 09                	jne    4018b7 <convert_to_byte_string+0x11a>
  4018ae:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  4018b2:	e9 5f 01 00 00       	jmp    401a16 <convert_to_byte_string+0x279>
  4018b7:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  4018bb:	48 8d 15 04 0a 00 00 	lea    0xa04(%rip),%rdx        # 4022c6 <_IO_stdin_used+0x2c6>
  4018c2:	48 89 d6             	mov    %rdx,%rsi
  4018c5:	48 89 c7             	mov    %rax,%rdi
  4018c8:	e8 d3 f7 ff ff       	call   4010a0 <strcmp@plt>
  4018cd:	85 c0                	test   %eax,%eax
  4018cf:	75 4a                	jne    40191b <convert_to_byte_string+0x17e>
  4018d1:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
  4018d5:	7f 3b                	jg     401912 <convert_to_byte_string+0x175>
  4018d7:	48 8b 05 e2 27 00 00 	mov    0x27e2(%rip),%rax        # 4040c0 <stderr@GLIBC_2.2.5>
  4018de:	48 8d 15 e1 09 00 00 	lea    0x9e1(%rip),%rdx        # 4022c6 <_IO_stdin_used+0x2c6>
  4018e5:	48 8d 0d dd 09 00 00 	lea    0x9dd(%rip),%rcx        # 4022c9 <_IO_stdin_used+0x2c9>
  4018ec:	48 89 ce             	mov    %rcx,%rsi
  4018ef:	48 89 c7             	mov    %rax,%rdi
  4018f2:	b8 00 00 00 00       	mov    $0x0,%eax
  4018f7:	e8 b4 f7 ff ff       	call   4010b0 <fprintf@plt>
  4018fc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401900:	48 89 c7             	mov    %rax,%rdi
  401903:	e8 28 f7 ff ff       	call   401030 <free@plt>
  401908:	b8 00 00 00 00       	mov    $0x0,%eax
  40190d:	e9 38 01 00 00       	jmp    401a4a <convert_to_byte_string+0x2ad>
  401912:	83 6d ec 01          	subl   $0x1,-0x14(%rbp)
  401916:	e9 fb 00 00 00       	jmp    401a16 <convert_to_byte_string+0x279>
  40191b:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
  40191f:	0f 85 f1 00 00 00    	jne    401a16 <convert_to_byte_string+0x279>
  401925:	e8 06 f8 ff ff       	call   401130 <__ctype_b_loc@plt>
  40192a:	48 8b 10             	mov    (%rax),%rdx
  40192d:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  401931:	0f b6 00             	movzbl (%rax),%eax
  401934:	48 0f be c0          	movsbq %al,%rax
  401938:	48 01 c0             	add    %rax,%rax
  40193b:	48 01 d0             	add    %rdx,%rax
  40193e:	0f b7 00             	movzwl (%rax),%eax
  401941:	0f b7 c0             	movzwl %ax,%eax
  401944:	25 00 10 00 00       	and    $0x1000,%eax
  401949:	85 c0                	test   %eax,%eax
  40194b:	74 35                	je     401982 <convert_to_byte_string+0x1e5>
  40194d:	e8 de f7 ff ff       	call   401130 <__ctype_b_loc@plt>
  401952:	48 8b 10             	mov    (%rax),%rdx
  401955:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  401959:	0f b6 40 01          	movzbl 0x1(%rax),%eax
  40195d:	48 0f be c0          	movsbq %al,%rax
  401961:	48 01 c0             	add    %rax,%rax
  401964:	48 01 d0             	add    %rdx,%rax
  401967:	0f b7 00             	movzwl (%rax),%eax
  40196a:	0f b7 c0             	movzwl %ax,%eax
  40196d:	25 00 10 00 00       	and    $0x1000,%eax
  401972:	85 c0                	test   %eax,%eax
  401974:	74 0c                	je     401982 <convert_to_byte_string+0x1e5>
  401976:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  40197a:	0f b6 40 02          	movzbl 0x2(%rax),%eax
  40197e:	84 c0                	test   %al,%al
  401980:	74 38                	je     4019ba <convert_to_byte_string+0x21d>
  401982:	48 8b 05 37 27 00 00 	mov    0x2737(%rip),%rax        # 4040c0 <stderr@GLIBC_2.2.5>
  401989:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
  40198d:	48 8d 0d 54 09 00 00 	lea    0x954(%rip),%rcx        # 4022e8 <_IO_stdin_used+0x2e8>
  401994:	48 89 ce             	mov    %rcx,%rsi
  401997:	48 89 c7             	mov    %rax,%rdi
  40199a:	b8 00 00 00 00       	mov    $0x0,%eax
  40199f:	e8 0c f7 ff ff       	call   4010b0 <fprintf@plt>
  4019a4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4019a8:	48 89 c7             	mov    %rax,%rdi
  4019ab:	e8 80 f6 ff ff       	call   401030 <free@plt>
  4019b0:	b8 00 00 00 00       	mov    $0x0,%eax
  4019b5:	e9 90 00 00 00       	jmp    401a4a <convert_to_byte_string+0x2ad>
  4019ba:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  4019be:	48 89 c7             	mov    %rax,%rdi
  4019c1:	e8 a7 fd ff ff       	call   40176d <convert_to_hex_value>
  4019c6:	88 45 bf             	mov    %al,-0x41(%rbp)
  4019c9:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  4019cc:	3b 45 e8             	cmp    -0x18(%rbp),%eax
  4019cf:	75 2c                	jne    4019fd <convert_to_byte_string+0x260>
  4019d1:	8b 45 e8             	mov    -0x18(%rbp),%eax
  4019d4:	01 c0                	add    %eax,%eax
  4019d6:	48 63 d0             	movslq %eax,%rdx
  4019d9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4019dd:	48 89 d6             	mov    %rdx,%rsi
  4019e0:	48 89 c7             	mov    %rax,%rdi
  4019e3:	e8 08 f7 ff ff       	call   4010f0 <realloc@plt>
  4019e8:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
  4019ec:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
  4019f1:	75 07                	jne    4019fa <convert_to_byte_string+0x25d>
  4019f3:	b8 00 00 00 00       	mov    $0x0,%eax
  4019f8:	eb 50                	jmp    401a4a <convert_to_byte_string+0x2ad>
  4019fa:	d1 65 e8             	shll   -0x18(%rbp)
  4019fd:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  401a00:	8d 50 01             	lea    0x1(%rax),%edx
  401a03:	89 55 e4             	mov    %edx,-0x1c(%rbp)
  401a06:	48 63 d0             	movslq %eax,%rdx
  401a09:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401a0d:	48 01 c2             	add    %rax,%rdx
  401a10:	0f b6 45 bf          	movzbl -0x41(%rbp),%eax
  401a14:	88 02                	mov    %al,(%rdx)
  401a16:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
  401a1a:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401a1e:	48 8d 0d 20 09 00 00 	lea    0x920(%rip),%rcx        # 402345 <_IO_stdin_used+0x345>
  401a25:	48 89 ce             	mov    %rcx,%rsi
  401a28:	48 89 c7             	mov    %rax,%rdi
  401a2b:	b8 00 00 00 00       	mov    $0x0,%eax
  401a30:	e8 1b f6 ff ff       	call   401050 <__isoc99_fscanf@plt>
  401a35:	85 c0                	test   %eax,%eax
  401a37:	0f 8f 57 fe ff ff    	jg     401894 <convert_to_byte_string+0xf7>
  401a3d:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
  401a41:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  401a44:	89 10                	mov    %edx,(%rax)
  401a46:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401a4a:	48 89 dc             	mov    %rbx,%rsp
  401a4d:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  401a51:	c9                   	leave  
  401a52:	c3                   	ret    

0000000000401a53 <getbuf>:
  401a53:	55                   	push   %rbp
  401a54:	48 89 e5             	mov    %rsp,%rbp
  401a57:	48 83 ec 50          	sub    $0x50,%rsp
  401a5b:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
  401a5f:	89 75 b4             	mov    %esi,-0x4c(%rbp)
  401a62:	48 b8 42 65 6c 69 65 	movabs $0x20657665696c6542,%rax
  401a69:	76 65 20 
  401a6c:	48 ba 69 6e 20 79 6f 	movabs $0x7372756f79206e69,%rdx
  401a73:	75 72 73 
  401a76:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  401a7a:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  401a7e:	c7 45 f0 65 6c 66 00 	movl   $0x666c65,-0x10(%rbp)
  401a85:	8b 55 b4             	mov    -0x4c(%rbp),%edx
  401a88:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
  401a8c:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  401a90:	48 89 ce             	mov    %rcx,%rsi
  401a93:	48 89 c7             	mov    %rax,%rdi
  401a96:	e8 f5 fa ff ff       	call   401590 <Gets>
  401a9b:	b8 01 00 00 00       	mov    $0x1,%eax
  401aa0:	c9                   	leave  
  401aa1:	c3                   	ret    

0000000000401aa2 <gencookie>:
  401aa2:	55                   	push   %rbp
  401aa3:	48 89 e5             	mov    %rsp,%rbp
  401aa6:	48 83 ec 20          	sub    $0x20,%rsp
  401aaa:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401aae:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401ab2:	48 89 c7             	mov    %rax,%rdi
  401ab5:	e8 c6 f5 ff ff       	call   401080 <strlen@plt>
  401aba:	48 83 f8 0a          	cmp    $0xa,%rax
  401abe:	74 19                	je     401ad9 <gencookie+0x37>
  401ac0:	48 8d 05 81 08 00 00 	lea    0x881(%rip),%rax        # 402348 <_IO_stdin_used+0x348>
  401ac7:	48 89 c7             	mov    %rax,%rdi
  401aca:	e8 91 f5 ff ff       	call   401060 <puts@plt>
  401acf:	b8 00 00 00 00       	mov    $0x0,%eax
  401ad4:	e9 8d 00 00 00       	jmp    401b66 <gencookie+0xc4>
  401ad9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401add:	0f b6 00             	movzbl (%rax),%eax
  401ae0:	3c 55                	cmp    $0x55,%al
  401ae2:	74 21                	je     401b05 <gencookie+0x63>
  401ae4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401ae8:	0f b6 00             	movzbl (%rax),%eax
  401aeb:	3c 75                	cmp    $0x75,%al
  401aed:	74 16                	je     401b05 <gencookie+0x63>
  401aef:	48 8d 05 71 08 00 00 	lea    0x871(%rip),%rax        # 402367 <_IO_stdin_used+0x367>
  401af6:	48 89 c7             	mov    %rax,%rdi
  401af9:	e8 62 f5 ff ff       	call   401060 <puts@plt>
  401afe:	b8 00 00 00 00       	mov    $0x0,%eax
  401b03:	eb 61                	jmp    401b66 <gencookie+0xc4>
  401b05:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401b0c:	eb 42                	jmp    401b50 <gencookie+0xae>
  401b0e:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401b11:	48 63 d0             	movslq %eax,%rdx
  401b14:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401b18:	48 01 d0             	add    %rdx,%rax
  401b1b:	0f b6 00             	movzbl (%rax),%eax
  401b1e:	3c 2f                	cmp    $0x2f,%al
  401b20:	7e 14                	jle    401b36 <gencookie+0x94>
  401b22:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401b25:	48 63 d0             	movslq %eax,%rdx
  401b28:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401b2c:	48 01 d0             	add    %rdx,%rax
  401b2f:	0f b6 00             	movzbl (%rax),%eax
  401b32:	3c 39                	cmp    $0x39,%al
  401b34:	7e 16                	jle    401b4c <gencookie+0xaa>
  401b36:	48 8d 05 45 08 00 00 	lea    0x845(%rip),%rax        # 402382 <_IO_stdin_used+0x382>
  401b3d:	48 89 c7             	mov    %rax,%rdi
  401b40:	e8 1b f5 ff ff       	call   401060 <puts@plt>
  401b45:	b8 00 00 00 00       	mov    $0x0,%eax
  401b4a:	eb 1a                	jmp    401b66 <gencookie+0xc4>
  401b4c:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  401b50:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
  401b54:	7e b8                	jle    401b0e <gencookie+0x6c>
  401b56:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401b5a:	48 83 c0 01          	add    $0x1,%rax
  401b5e:	48 89 c7             	mov    %rax,%rdi
  401b61:	e8 aa f5 ff ff       	call   401110 <atoi@plt>
  401b66:	c9                   	leave  
  401b67:	c3                   	ret    

0000000000401b68 <bang_hack>:
  401b68:	55                   	push   %rbp
  401b69:	48 89 e5             	mov    %rsp,%rbp
  401b6c:	b8 6f 13 0f 0c       	mov    $0xc0f136f,%eax
  401b71:	48 c7 c7 ec 40 40 00 	mov    $0x4040ec,%rdi
  401b78:	89 07                	mov    %eax,(%rdi)
  401b7a:	5d                   	pop    %rbp
  401b7b:	48 c7 04 24 67 13 40 	movq   $0x401367,(%rsp)
  401b82:	00 
  401b83:	c3                   	ret    

0000000000401b84 <boom_hack>:
  401b84:	b8 6f 13 0f 0c       	mov    $0xc0f136f,%eax
  401b89:	48 bd 80 e0 ff ff ff 	movabs $0x7fffffffe080,%rbp
  401b90:	7f 00 00 
  401b93:	48 c7 04 24 7a 14 40 	movq   $0x40147a,(%rsp)
  401b9a:	00 
  401b9b:	c3                   	ret    

Disassembly of section .fini:

0000000000401b9c <_fini>:
  401b9c:	f3 0f 1e fa          	endbr64 
  401ba0:	48 83 ec 08          	sub    $0x8,%rsp
  401ba4:	48 83 c4 08          	add    $0x8,%rsp
  401ba8:	c3                   	ret    
