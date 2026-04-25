
bomb：     文件格式 elf32-i386


Disassembly of section .init:

00001000 <_init>:
    1000:	f3 0f 1e fb          	endbr32 
    1004:	53                   	push   %ebx
    1005:	83 ec 08             	sub    $0x8,%esp
    1008:	e8 33 02 00 00       	call   1240 <__x86.get_pc_thunk.bx>
    100d:	81 c3 57 4f 00 00    	add    $0x4f57,%ebx
    1013:	8b 83 88 00 00 00    	mov    0x88(%ebx),%eax
    1019:	85 c0                	test   %eax,%eax
    101b:	74 02                	je     101f <_init+0x1f>
    101d:	ff d0                	call   *%eax
    101f:	83 c4 08             	add    $0x8,%esp
    1022:	5b                   	pop    %ebx
    1023:	c3                   	ret    

Disassembly of section .plt:

00001030 <strcmp@plt-0x10>:
    1030:	ff b3 04 00 00 00    	push   0x4(%ebx)
    1036:	ff a3 08 00 00 00    	jmp    *0x8(%ebx)
    103c:	00 00                	add    %al,(%eax)
	...

00001040 <strcmp@plt>:
    1040:	ff a3 0c 00 00 00    	jmp    *0xc(%ebx)
    1046:	68 00 00 00 00       	push   $0x0
    104b:	e9 e0 ff ff ff       	jmp    1030 <_init+0x30>

00001050 <__libc_start_main@plt>:
    1050:	ff a3 10 00 00 00    	jmp    *0x10(%ebx)
    1056:	68 08 00 00 00       	push   $0x8
    105b:	e9 d0 ff ff ff       	jmp    1030 <_init+0x30>

00001060 <read@plt>:
    1060:	ff a3 14 00 00 00    	jmp    *0x14(%ebx)
    1066:	68 10 00 00 00       	push   $0x10
    106b:	e9 c0 ff ff ff       	jmp    1030 <_init+0x30>

00001070 <fflush@plt>:
    1070:	ff a3 18 00 00 00    	jmp    *0x18(%ebx)
    1076:	68 18 00 00 00       	push   $0x18
    107b:	e9 b0 ff ff ff       	jmp    1030 <_init+0x30>

00001080 <fgets@plt>:
    1080:	ff a3 1c 00 00 00    	jmp    *0x1c(%ebx)
    1086:	68 20 00 00 00       	push   $0x20
    108b:	e9 a0 ff ff ff       	jmp    1030 <_init+0x30>

00001090 <signal@plt>:
    1090:	ff a3 20 00 00 00    	jmp    *0x20(%ebx)
    1096:	68 28 00 00 00       	push   $0x28
    109b:	e9 90 ff ff ff       	jmp    1030 <_init+0x30>

000010a0 <sleep@plt>:
    10a0:	ff a3 24 00 00 00    	jmp    *0x24(%ebx)
    10a6:	68 30 00 00 00       	push   $0x30
    10ab:	e9 80 ff ff ff       	jmp    1030 <_init+0x30>

000010b0 <alarm@plt>:
    10b0:	ff a3 28 00 00 00    	jmp    *0x28(%ebx)
    10b6:	68 38 00 00 00       	push   $0x38
    10bb:	e9 70 ff ff ff       	jmp    1030 <_init+0x30>

000010c0 <__stack_chk_fail@plt>:
    10c0:	ff a3 2c 00 00 00    	jmp    *0x2c(%ebx)
    10c6:	68 40 00 00 00       	push   $0x40
    10cb:	e9 60 ff ff ff       	jmp    1030 <_init+0x30>

000010d0 <strcpy@plt>:
    10d0:	ff a3 30 00 00 00    	jmp    *0x30(%ebx)
    10d6:	68 48 00 00 00       	push   $0x48
    10db:	e9 50 ff ff ff       	jmp    1030 <_init+0x30>

000010e0 <getenv@plt>:
    10e0:	ff a3 34 00 00 00    	jmp    *0x34(%ebx)
    10e6:	68 50 00 00 00       	push   $0x50
    10eb:	e9 40 ff ff ff       	jmp    1030 <_init+0x30>

000010f0 <puts@plt>:
    10f0:	ff a3 38 00 00 00    	jmp    *0x38(%ebx)
    10f6:	68 58 00 00 00       	push   $0x58
    10fb:	e9 30 ff ff ff       	jmp    1030 <_init+0x30>

00001100 <__memmove_chk@plt>:
    1100:	ff a3 3c 00 00 00    	jmp    *0x3c(%ebx)
    1106:	68 60 00 00 00       	push   $0x60
    110b:	e9 20 ff ff ff       	jmp    1030 <_init+0x30>

00001110 <exit@plt>:
    1110:	ff a3 40 00 00 00    	jmp    *0x40(%ebx)
    1116:	68 68 00 00 00       	push   $0x68
    111b:	e9 10 ff ff ff       	jmp    1030 <_init+0x30>

00001120 <strlen@plt>:
    1120:	ff a3 44 00 00 00    	jmp    *0x44(%ebx)
    1126:	68 70 00 00 00       	push   $0x70
    112b:	e9 00 ff ff ff       	jmp    1030 <_init+0x30>

00001130 <write@plt>:
    1130:	ff a3 48 00 00 00    	jmp    *0x48(%ebx)
    1136:	68 78 00 00 00       	push   $0x78
    113b:	e9 f0 fe ff ff       	jmp    1030 <_init+0x30>

00001140 <__isoc99_sscanf@plt>:
    1140:	ff a3 4c 00 00 00    	jmp    *0x4c(%ebx)
    1146:	68 80 00 00 00       	push   $0x80
    114b:	e9 e0 fe ff ff       	jmp    1030 <_init+0x30>

00001150 <fopen@plt>:
    1150:	ff a3 50 00 00 00    	jmp    *0x50(%ebx)
    1156:	68 88 00 00 00       	push   $0x88
    115b:	e9 d0 fe ff ff       	jmp    1030 <_init+0x30>

00001160 <__errno_location@plt>:
    1160:	ff a3 54 00 00 00    	jmp    *0x54(%ebx)
    1166:	68 90 00 00 00       	push   $0x90
    116b:	e9 c0 fe ff ff       	jmp    1030 <_init+0x30>

00001170 <__printf_chk@plt>:
    1170:	ff a3 58 00 00 00    	jmp    *0x58(%ebx)
    1176:	68 98 00 00 00       	push   $0x98
    117b:	e9 b0 fe ff ff       	jmp    1030 <_init+0x30>

00001180 <socket@plt>:
    1180:	ff a3 5c 00 00 00    	jmp    *0x5c(%ebx)
    1186:	68 a0 00 00 00       	push   $0xa0
    118b:	e9 a0 fe ff ff       	jmp    1030 <_init+0x30>

00001190 <__fprintf_chk@plt>:
    1190:	ff a3 60 00 00 00    	jmp    *0x60(%ebx)
    1196:	68 a8 00 00 00       	push   $0xa8
    119b:	e9 90 fe ff ff       	jmp    1030 <_init+0x30>

000011a0 <gethostbyname@plt>:
    11a0:	ff a3 64 00 00 00    	jmp    *0x64(%ebx)
    11a6:	68 b0 00 00 00       	push   $0xb0
    11ab:	e9 80 fe ff ff       	jmp    1030 <_init+0x30>

000011b0 <strtol@plt>:
    11b0:	ff a3 68 00 00 00    	jmp    *0x68(%ebx)
    11b6:	68 b8 00 00 00       	push   $0xb8
    11bb:	e9 70 fe ff ff       	jmp    1030 <_init+0x30>

000011c0 <connect@plt>:
    11c0:	ff a3 6c 00 00 00    	jmp    *0x6c(%ebx)
    11c6:	68 c0 00 00 00       	push   $0xc0
    11cb:	e9 60 fe ff ff       	jmp    1030 <_init+0x30>

000011d0 <close@plt>:
    11d0:	ff a3 70 00 00 00    	jmp    *0x70(%ebx)
    11d6:	68 c8 00 00 00       	push   $0xc8
    11db:	e9 50 fe ff ff       	jmp    1030 <_init+0x30>

000011e0 <__ctype_b_loc@plt>:
    11e0:	ff a3 74 00 00 00    	jmp    *0x74(%ebx)
    11e6:	68 d0 00 00 00       	push   $0xd0
    11eb:	e9 40 fe ff ff       	jmp    1030 <_init+0x30>

000011f0 <__sprintf_chk@plt>:
    11f0:	ff a3 78 00 00 00    	jmp    *0x78(%ebx)
    11f6:	68 d8 00 00 00       	push   $0xd8
    11fb:	e9 30 fe ff ff       	jmp    1030 <_init+0x30>

Disassembly of section .plt.got:

00001200 <__cxa_finalize@plt>:
    1200:	ff a3 84 00 00 00    	jmp    *0x84(%ebx)
    1206:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00001210 <_start>:
    1210:	f3 0f 1e fb          	endbr32 
    1214:	31 ed                	xor    %ebp,%ebp
    1216:	5e                   	pop    %esi
    1217:	89 e1                	mov    %esp,%ecx
    1219:	83 e4 f0             	and    $0xfffffff0,%esp
    121c:	50                   	push   %eax
    121d:	54                   	push   %esp
    121e:	52                   	push   %edx
    121f:	e8 18 00 00 00       	call   123c <_start+0x2c>
    1224:	81 c3 40 4d 00 00    	add    $0x4d40,%ebx
    122a:	6a 00                	push   $0x0
    122c:	6a 00                	push   $0x0
    122e:	51                   	push   %ecx
    122f:	56                   	push   %esi
    1230:	ff b3 94 00 00 00    	push   0x94(%ebx)
    1236:	e8 15 fe ff ff       	call   1050 <__libc_start_main@plt>
    123b:	f4                   	hlt    
    123c:	8b 1c 24             	mov    (%esp),%ebx
    123f:	c3                   	ret    

00001240 <__x86.get_pc_thunk.bx>:
    1240:	8b 1c 24             	mov    (%esp),%ebx
    1243:	c3                   	ret    
    1244:	66 90                	xchg   %ax,%ax
    1246:	66 90                	xchg   %ax,%ax
    1248:	66 90                	xchg   %ax,%ax
    124a:	66 90                	xchg   %ax,%ax
    124c:	66 90                	xchg   %ax,%ax
    124e:	66 90                	xchg   %ax,%ax

00001250 <deregister_tm_clones>:
    1250:	e8 e4 00 00 00       	call   1339 <__x86.get_pc_thunk.dx>
    1255:	81 c2 0f 4d 00 00    	add    $0x4d0f,%edx
    125b:	8d 8a bc 03 00 00    	lea    0x3bc(%edx),%ecx
    1261:	8d 82 bc 03 00 00    	lea    0x3bc(%edx),%eax
    1267:	39 c8                	cmp    %ecx,%eax
    1269:	74 1d                	je     1288 <deregister_tm_clones+0x38>
    126b:	8b 82 7c 00 00 00    	mov    0x7c(%edx),%eax
    1271:	85 c0                	test   %eax,%eax
    1273:	74 13                	je     1288 <deregister_tm_clones+0x38>
    1275:	55                   	push   %ebp
    1276:	89 e5                	mov    %esp,%ebp
    1278:	83 ec 14             	sub    $0x14,%esp
    127b:	51                   	push   %ecx
    127c:	ff d0                	call   *%eax
    127e:	83 c4 10             	add    $0x10,%esp
    1281:	c9                   	leave  
    1282:	c3                   	ret    
    1283:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1287:	90                   	nop
    1288:	c3                   	ret    
    1289:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00001290 <register_tm_clones>:
    1290:	e8 a4 00 00 00       	call   1339 <__x86.get_pc_thunk.dx>
    1295:	81 c2 cf 4c 00 00    	add    $0x4ccf,%edx
    129b:	55                   	push   %ebp
    129c:	89 e5                	mov    %esp,%ebp
    129e:	53                   	push   %ebx
    129f:	8d 8a bc 03 00 00    	lea    0x3bc(%edx),%ecx
    12a5:	8d 82 bc 03 00 00    	lea    0x3bc(%edx),%eax
    12ab:	83 ec 04             	sub    $0x4,%esp
    12ae:	29 c8                	sub    %ecx,%eax
    12b0:	89 c3                	mov    %eax,%ebx
    12b2:	c1 e8 1f             	shr    $0x1f,%eax
    12b5:	c1 fb 02             	sar    $0x2,%ebx
    12b8:	01 d8                	add    %ebx,%eax
    12ba:	d1 f8                	sar    %eax
    12bc:	74 14                	je     12d2 <register_tm_clones+0x42>
    12be:	8b 92 98 00 00 00    	mov    0x98(%edx),%edx
    12c4:	85 d2                	test   %edx,%edx
    12c6:	74 0a                	je     12d2 <register_tm_clones+0x42>
    12c8:	83 ec 08             	sub    $0x8,%esp
    12cb:	50                   	push   %eax
    12cc:	51                   	push   %ecx
    12cd:	ff d2                	call   *%edx
    12cf:	83 c4 10             	add    $0x10,%esp
    12d2:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    12d5:	c9                   	leave  
    12d6:	c3                   	ret    
    12d7:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    12de:	66 90                	xchg   %ax,%ax

000012e0 <__do_global_dtors_aux>:
    12e0:	f3 0f 1e fb          	endbr32 
    12e4:	55                   	push   %ebp
    12e5:	89 e5                	mov    %esp,%ebp
    12e7:	53                   	push   %ebx
    12e8:	e8 53 ff ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    12ed:	81 c3 77 4c 00 00    	add    $0x4c77,%ebx
    12f3:	83 ec 04             	sub    $0x4,%esp
    12f6:	80 bb bc 03 00 00 00 	cmpb   $0x0,0x3bc(%ebx)
    12fd:	75 27                	jne    1326 <__do_global_dtors_aux+0x46>
    12ff:	8b 83 84 00 00 00    	mov    0x84(%ebx),%eax
    1305:	85 c0                	test   %eax,%eax
    1307:	74 11                	je     131a <__do_global_dtors_aux+0x3a>
    1309:	83 ec 0c             	sub    $0xc,%esp
    130c:	ff b3 a0 00 00 00    	push   0xa0(%ebx)
    1312:	e8 e9 fe ff ff       	call   1200 <__cxa_finalize@plt>
    1317:	83 c4 10             	add    $0x10,%esp
    131a:	e8 31 ff ff ff       	call   1250 <deregister_tm_clones>
    131f:	c6 83 bc 03 00 00 01 	movb   $0x1,0x3bc(%ebx)
    1326:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    1329:	c9                   	leave  
    132a:	c3                   	ret    
    132b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    132f:	90                   	nop

00001330 <frame_dummy>:
    1330:	f3 0f 1e fb          	endbr32 
    1334:	e9 57 ff ff ff       	jmp    1290 <register_tm_clones>

00001339 <__x86.get_pc_thunk.dx>:
    1339:	8b 14 24             	mov    (%esp),%edx
    133c:	c3                   	ret    

0000133d <main>:
    133d:	8d 4c 24 04          	lea    0x4(%esp),%ecx
    1341:	83 e4 f0             	and    $0xfffffff0,%esp
    1344:	ff 71 fc             	push   -0x4(%ecx)
    1347:	55                   	push   %ebp
    1348:	89 e5                	mov    %esp,%ebp
    134a:	56                   	push   %esi
    134b:	53                   	push   %ebx
    134c:	51                   	push   %ecx
    134d:	83 ec 0c             	sub    $0xc,%esp
    1350:	e8 eb fe ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1355:	81 c3 0f 4c 00 00    	add    $0x4c0f,%ebx
    135b:	8b 01                	mov    (%ecx),%eax
    135d:	8b 71 04             	mov    0x4(%ecx),%esi
    1360:	83 f8 01             	cmp    $0x1,%eax
    1363:	0f 84 13 01 00 00    	je     147c <main+0x13f>
    1369:	83 f8 02             	cmp    $0x2,%eax
    136c:	0f 85 3c 01 00 00    	jne    14ae <main+0x171>
    1372:	83 ec 08             	sub    $0x8,%esp
    1375:	8d 83 a4 d0 ff ff    	lea    -0x2f5c(%ebx),%eax
    137b:	50                   	push   %eax
    137c:	ff 76 04             	push   0x4(%esi)
    137f:	e8 cc fd ff ff       	call   1150 <fopen@plt>
    1384:	89 83 c0 03 00 00    	mov    %eax,0x3c0(%ebx)
    138a:	83 c4 10             	add    $0x10,%esp
    138d:	85 c0                	test   %eax,%eax
    138f:	0f 84 fa 00 00 00    	je     148f <main+0x152>
    1395:	e8 87 07 00 00       	call   1b21 <initialize_bomb>
    139a:	83 ec 0c             	sub    $0xc,%esp
    139d:	8d 83 28 d1 ff ff    	lea    -0x2ed8(%ebx),%eax
    13a3:	50                   	push   %eax
    13a4:	e8 47 fd ff ff       	call   10f0 <puts@plt>
    13a9:	8d 83 64 d1 ff ff    	lea    -0x2e9c(%ebx),%eax
    13af:	89 04 24             	mov    %eax,(%esp)
    13b2:	e8 39 fd ff ff       	call   10f0 <puts@plt>
    13b7:	e8 a4 08 00 00       	call   1c60 <read_line>
    13bc:	89 04 24             	mov    %eax,(%esp)
    13bf:	e8 09 01 00 00       	call   14cd <phase_1>
    13c4:	e8 b6 09 00 00       	call   1d7f <phase_defused>
    13c9:	8d 83 90 d1 ff ff    	lea    -0x2e70(%ebx),%eax
    13cf:	89 04 24             	mov    %eax,(%esp)
    13d2:	e8 19 fd ff ff       	call   10f0 <puts@plt>
    13d7:	e8 84 08 00 00       	call   1c60 <read_line>
    13dc:	89 04 24             	mov    %eax,(%esp)
    13df:	e8 1b 01 00 00       	call   14ff <phase_2>
    13e4:	e8 96 09 00 00       	call   1d7f <phase_defused>
    13e9:	8d 83 dd d0 ff ff    	lea    -0x2f23(%ebx),%eax
    13ef:	89 04 24             	mov    %eax,(%esp)
    13f2:	e8 f9 fc ff ff       	call   10f0 <puts@plt>
    13f7:	e8 64 08 00 00       	call   1c60 <read_line>
    13fc:	89 04 24             	mov    %eax,(%esp)
    13ff:	e8 75 01 00 00       	call   1579 <phase_3>
    1404:	e8 76 09 00 00       	call   1d7f <phase_defused>
    1409:	8d 83 fb d0 ff ff    	lea    -0x2f05(%ebx),%eax
    140f:	89 04 24             	mov    %eax,(%esp)
    1412:	e8 d9 fc ff ff       	call   10f0 <puts@plt>
    1417:	e8 44 08 00 00       	call   1c60 <read_line>
    141c:	89 04 24             	mov    %eax,(%esp)
    141f:	e8 30 03 00 00       	call   1754 <phase_4>
    1424:	e8 56 09 00 00       	call   1d7f <phase_defused>
    1429:	8d 83 bc d1 ff ff    	lea    -0x2e44(%ebx),%eax
    142f:	89 04 24             	mov    %eax,(%esp)
    1432:	e8 b9 fc ff ff       	call   10f0 <puts@plt>
    1437:	e8 24 08 00 00       	call   1c60 <read_line>
    143c:	89 04 24             	mov    %eax,(%esp)
    143f:	e8 94 03 00 00       	call   17d8 <phase_5>
    1444:	e8 36 09 00 00       	call   1d7f <phase_defused>
    1449:	8d 83 0a d1 ff ff    	lea    -0x2ef6(%ebx),%eax
    144f:	89 04 24             	mov    %eax,(%esp)
    1452:	e8 99 fc ff ff       	call   10f0 <puts@plt>
    1457:	e8 04 08 00 00       	call   1c60 <read_line>
    145c:	89 04 24             	mov    %eax,(%esp)
    145f:	e8 ce 03 00 00       	call   1832 <phase_6>
    1464:	e8 16 09 00 00       	call   1d7f <phase_defused>
    1469:	83 c4 10             	add    $0x10,%esp
    146c:	b8 00 00 00 00       	mov    $0x0,%eax
    1471:	8d 65 f4             	lea    -0xc(%ebp),%esp
    1474:	59                   	pop    %ecx
    1475:	5b                   	pop    %ebx
    1476:	5e                   	pop    %esi
    1477:	5d                   	pop    %ebp
    1478:	8d 61 fc             	lea    -0x4(%ecx),%esp
    147b:	c3                   	ret    
    147c:	8b 83 8c 00 00 00    	mov    0x8c(%ebx),%eax
    1482:	8b 00                	mov    (%eax),%eax
    1484:	89 83 c0 03 00 00    	mov    %eax,0x3c0(%ebx)
    148a:	e9 06 ff ff ff       	jmp    1395 <main+0x58>
    148f:	ff 76 04             	push   0x4(%esi)
    1492:	ff 36                	push   (%esi)
    1494:	8d 83 a6 d0 ff ff    	lea    -0x2f5a(%ebx),%eax
    149a:	50                   	push   %eax
    149b:	6a 01                	push   $0x1
    149d:	e8 ce fc ff ff       	call   1170 <__printf_chk@plt>
    14a2:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
    14a9:	e8 62 fc ff ff       	call   1110 <exit@plt>
    14ae:	83 ec 04             	sub    $0x4,%esp
    14b1:	ff 36                	push   (%esi)
    14b3:	8d 83 c3 d0 ff ff    	lea    -0x2f3d(%ebx),%eax
    14b9:	50                   	push   %eax
    14ba:	6a 01                	push   $0x1
    14bc:	e8 af fc ff ff       	call   1170 <__printf_chk@plt>
    14c1:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
    14c8:	e8 43 fc ff ff       	call   1110 <exit@plt>

000014cd <phase_1>:
    14cd:	53                   	push   %ebx
    14ce:	83 ec 10             	sub    $0x10,%esp
    14d1:	e8 6a fd ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    14d6:	81 c3 8e 4a 00 00    	add    $0x4a8e,%ebx
    14dc:	8d 83 e0 d1 ff ff    	lea    -0x2e20(%ebx),%eax
    14e2:	50                   	push   %eax
    14e3:	ff 74 24 1c          	push   0x1c(%esp)
    14e7:	e8 dd 05 00 00       	call   1ac9 <strings_not_equal>
    14ec:	83 c4 10             	add    $0x10,%esp
    14ef:	85 c0                	test   %eax,%eax
    14f1:	75 05                	jne    14f8 <phase_1+0x2b>
    14f3:	83 c4 08             	add    $0x8,%esp
    14f6:	5b                   	pop    %ebx
    14f7:	c3                   	ret    
    14f8:	e8 e4 06 00 00       	call   1be1 <explode_bomb>
    14fd:	eb f4                	jmp    14f3 <phase_1+0x26>

000014ff <phase_2>:
    14ff:	57                   	push   %edi
    1500:	56                   	push   %esi
    1501:	53                   	push   %ebx
    1502:	83 ec 28             	sub    $0x28,%esp
    1505:	e8 36 fd ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    150a:	81 c3 5a 4a 00 00    	add    $0x4a5a,%ebx
    1510:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    1516:	89 44 24 24          	mov    %eax,0x24(%esp)
    151a:	31 c0                	xor    %eax,%eax
    151c:	8d 44 24 0c          	lea    0xc(%esp),%eax
    1520:	50                   	push   %eax
    1521:	ff 74 24 3c          	push   0x3c(%esp)
    1525:	e8 ec 06 00 00       	call   1c16 <read_six_numbers>
    152a:	83 c4 10             	add    $0x10,%esp
    152d:	83 7c 24 04 00       	cmpl   $0x0,0x4(%esp)
    1532:	78 0b                	js     153f <phase_2+0x40>
    1534:	be 01 00 00 00       	mov    $0x1,%esi
    1539:	8d 7c 24 04          	lea    0x4(%esp),%edi
    153d:	eb 0f                	jmp    154e <phase_2+0x4f>
    153f:	e8 9d 06 00 00       	call   1be1 <explode_bomb>
    1544:	eb ee                	jmp    1534 <phase_2+0x35>
    1546:	83 c6 01             	add    $0x1,%esi
    1549:	83 fe 06             	cmp    $0x6,%esi
    154c:	74 12                	je     1560 <phase_2+0x61>
    154e:	89 f0                	mov    %esi,%eax
    1550:	03 44 b7 fc          	add    -0x4(%edi,%esi,4),%eax
    1554:	39 04 b7             	cmp    %eax,(%edi,%esi,4)
    1557:	74 ed                	je     1546 <phase_2+0x47>
    1559:	e8 83 06 00 00       	call   1be1 <explode_bomb>
    155e:	eb e6                	jmp    1546 <phase_2+0x47>
    1560:	8b 44 24 1c          	mov    0x1c(%esp),%eax
    1564:	65 2b 05 14 00 00 00 	sub    %gs:0x14,%eax
    156b:	75 07                	jne    1574 <phase_2+0x75>
    156d:	83 c4 20             	add    $0x20,%esp
    1570:	5b                   	pop    %ebx
    1571:	5e                   	pop    %esi
    1572:	5f                   	pop    %edi
    1573:	c3                   	ret    
    1574:	e8 77 14 00 00       	call   29f0 <__stack_chk_fail_local>

00001579 <phase_3>:
    1579:	53                   	push   %ebx
    157a:	83 ec 24             	sub    $0x24,%esp
    157d:	e8 be fc ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1582:	81 c3 e2 49 00 00    	add    $0x49e2,%ebx
    1588:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    158e:	89 44 24 18          	mov    %eax,0x18(%esp)
    1592:	31 c0                	xor    %eax,%eax
    1594:	8d 44 24 14          	lea    0x14(%esp),%eax
    1598:	50                   	push   %eax
    1599:	8d 44 24 13          	lea    0x13(%esp),%eax
    159d:	50                   	push   %eax
    159e:	8d 44 24 18          	lea    0x18(%esp),%eax
    15a2:	50                   	push   %eax
    15a3:	8d 83 3a d2 ff ff    	lea    -0x2dc6(%ebx),%eax
    15a9:	50                   	push   %eax
    15aa:	ff 74 24 3c          	push   0x3c(%esp)
    15ae:	e8 8d fb ff ff       	call   1140 <__isoc99_sscanf@plt>
    15b3:	83 c4 20             	add    $0x20,%esp
    15b6:	83 f8 02             	cmp    $0x2,%eax
    15b9:	7e 1a                	jle    15d5 <phase_3+0x5c>
    15bb:	83 7c 24 04 07       	cmpl   $0x7,0x4(%esp)
    15c0:	0f 87 07 01 00 00    	ja     16cd <.L18+0x1b>
    15c6:	8b 44 24 04          	mov    0x4(%esp),%eax
    15ca:	89 da                	mov    %ebx,%edx
    15cc:	03 94 83 5c d2 ff ff 	add    -0x2da4(%ebx,%eax,4),%edx
    15d3:	ff e2                	jmp    *%edx
    15d5:	e8 07 06 00 00       	call   1be1 <explode_bomb>
    15da:	eb df                	jmp    15bb <phase_3+0x42>

000015dc <.L26>:
    15dc:	b8 76 00 00 00       	mov    $0x76,%eax
    15e1:	81 7c 24 08 42 02 00 	cmpl   $0x242,0x8(%esp)
    15e8:	00 
    15e9:	0f 84 e8 00 00 00    	je     16d7 <.L18+0x25>
    15ef:	e8 ed 05 00 00       	call   1be1 <explode_bomb>
    15f4:	b8 76 00 00 00       	mov    $0x76,%eax
    15f9:	e9 d9 00 00 00       	jmp    16d7 <.L18+0x25>

000015fe <.L25>:
    15fe:	b8 79 00 00 00       	mov    $0x79,%eax
    1603:	81 7c 24 08 cf 03 00 	cmpl   $0x3cf,0x8(%esp)
    160a:	00 
    160b:	0f 84 c6 00 00 00    	je     16d7 <.L18+0x25>
    1611:	e8 cb 05 00 00       	call   1be1 <explode_bomb>
    1616:	b8 79 00 00 00       	mov    $0x79,%eax
    161b:	e9 b7 00 00 00       	jmp    16d7 <.L18+0x25>

00001620 <.L24>:
    1620:	b8 79 00 00 00       	mov    $0x79,%eax
    1625:	81 7c 24 08 91 02 00 	cmpl   $0x291,0x8(%esp)
    162c:	00 
    162d:	0f 84 a4 00 00 00    	je     16d7 <.L18+0x25>
    1633:	e8 a9 05 00 00       	call   1be1 <explode_bomb>
    1638:	b8 79 00 00 00       	mov    $0x79,%eax
    163d:	e9 95 00 00 00       	jmp    16d7 <.L18+0x25>

00001642 <.L23>:
    1642:	b8 79 00 00 00       	mov    $0x79,%eax
    1647:	81 7c 24 08 8e 03 00 	cmpl   $0x38e,0x8(%esp)
    164e:	00 
    164f:	0f 84 82 00 00 00    	je     16d7 <.L18+0x25>
    1655:	e8 87 05 00 00       	call   1be1 <explode_bomb>
    165a:	b8 79 00 00 00       	mov    $0x79,%eax
    165f:	eb 76                	jmp    16d7 <.L18+0x25>

00001661 <.L22>:
    1661:	b8 6e 00 00 00       	mov    $0x6e,%eax
    1666:	81 7c 24 08 f6 00 00 	cmpl   $0xf6,0x8(%esp)
    166d:	00 
    166e:	74 67                	je     16d7 <.L18+0x25>
    1670:	e8 6c 05 00 00       	call   1be1 <explode_bomb>
    1675:	b8 6e 00 00 00       	mov    $0x6e,%eax
    167a:	eb 5b                	jmp    16d7 <.L18+0x25>

0000167c <.L21>:
    167c:	b8 6c 00 00 00       	mov    $0x6c,%eax
    1681:	81 7c 24 08 8e 02 00 	cmpl   $0x28e,0x8(%esp)
    1688:	00 
    1689:	74 4c                	je     16d7 <.L18+0x25>
    168b:	e8 51 05 00 00       	call   1be1 <explode_bomb>
    1690:	b8 6c 00 00 00       	mov    $0x6c,%eax
    1695:	eb 40                	jmp    16d7 <.L18+0x25>

00001697 <.L20>:
    1697:	b8 76 00 00 00       	mov    $0x76,%eax
    169c:	81 7c 24 08 c3 02 00 	cmpl   $0x2c3,0x8(%esp)
    16a3:	00 
    16a4:	74 31                	je     16d7 <.L18+0x25>
    16a6:	e8 36 05 00 00       	call   1be1 <explode_bomb>
    16ab:	b8 76 00 00 00       	mov    $0x76,%eax
    16b0:	eb 25                	jmp    16d7 <.L18+0x25>

000016b2 <.L18>:
    16b2:	b8 77 00 00 00       	mov    $0x77,%eax
    16b7:	81 7c 24 08 39 03 00 	cmpl   $0x339,0x8(%esp)
    16be:	00 
    16bf:	74 16                	je     16d7 <.L18+0x25>
    16c1:	e8 1b 05 00 00       	call   1be1 <explode_bomb>
    16c6:	b8 77 00 00 00       	mov    $0x77,%eax
    16cb:	eb 0a                	jmp    16d7 <.L18+0x25>
    16cd:	e8 0f 05 00 00       	call   1be1 <explode_bomb>
    16d2:	b8 63 00 00 00       	mov    $0x63,%eax
    16d7:	38 44 24 03          	cmp    %al,0x3(%esp)
    16db:	75 12                	jne    16ef <.L18+0x3d>
    16dd:	8b 44 24 0c          	mov    0xc(%esp),%eax
    16e1:	65 2b 05 14 00 00 00 	sub    %gs:0x14,%eax
    16e8:	75 0c                	jne    16f6 <.L18+0x44>
    16ea:	83 c4 18             	add    $0x18,%esp
    16ed:	5b                   	pop    %ebx
    16ee:	c3                   	ret    
    16ef:	e8 ed 04 00 00       	call   1be1 <explode_bomb>
    16f4:	eb e7                	jmp    16dd <.L18+0x2b>
    16f6:	e8 f5 12 00 00       	call   29f0 <__stack_chk_fail_local>

000016fb <func4>:
    16fb:	53                   	push   %ebx
    16fc:	83 ec 08             	sub    $0x8,%esp
    16ff:	8b 44 24 10          	mov    0x10(%esp),%eax
    1703:	8b 4c 24 18          	mov    0x18(%esp),%ecx
    1707:	89 ca                	mov    %ecx,%edx
    1709:	2b 54 24 14          	sub    0x14(%esp),%edx
    170d:	89 d3                	mov    %edx,%ebx
    170f:	c1 eb 1f             	shr    $0x1f,%ebx
    1712:	01 d3                	add    %edx,%ebx
    1714:	d1 fb                	sar    %ebx
    1716:	03 5c 24 14          	add    0x14(%esp),%ebx
    171a:	39 c3                	cmp    %eax,%ebx
    171c:	7f 09                	jg     1727 <func4+0x2c>
    171e:	7c 1f                	jl     173f <func4+0x44>
    1720:	89 d8                	mov    %ebx,%eax
    1722:	83 c4 08             	add    $0x8,%esp
    1725:	5b                   	pop    %ebx
    1726:	c3                   	ret    
    1727:	83 ec 04             	sub    $0x4,%esp
    172a:	8d 53 ff             	lea    -0x1(%ebx),%edx
    172d:	52                   	push   %edx
    172e:	ff 74 24 1c          	push   0x1c(%esp)
    1732:	50                   	push   %eax
    1733:	e8 c3 ff ff ff       	call   16fb <func4>
    1738:	83 c4 10             	add    $0x10,%esp
    173b:	01 c3                	add    %eax,%ebx
    173d:	eb e1                	jmp    1720 <func4+0x25>
    173f:	83 ec 04             	sub    $0x4,%esp
    1742:	51                   	push   %ecx
    1743:	8d 53 01             	lea    0x1(%ebx),%edx
    1746:	52                   	push   %edx
    1747:	50                   	push   %eax
    1748:	e8 ae ff ff ff       	call   16fb <func4>
    174d:	83 c4 10             	add    $0x10,%esp
    1750:	01 c3                	add    %eax,%ebx
    1752:	eb cc                	jmp    1720 <func4+0x25>

00001754 <phase_4>:
    1754:	53                   	push   %ebx
    1755:	83 ec 18             	sub    $0x18,%esp
    1758:	e8 e3 fa ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    175d:	81 c3 07 48 00 00    	add    $0x4807,%ebx
    1763:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    1769:	89 44 24 0c          	mov    %eax,0xc(%esp)
    176d:	31 c0                	xor    %eax,%eax
    176f:	8d 44 24 08          	lea    0x8(%esp),%eax
    1773:	50                   	push   %eax
    1774:	8d 44 24 08          	lea    0x8(%esp),%eax
    1778:	50                   	push   %eax
    1779:	8d 83 cb d3 ff ff    	lea    -0x2c35(%ebx),%eax
    177f:	50                   	push   %eax
    1780:	ff 74 24 2c          	push   0x2c(%esp)
    1784:	e8 b7 f9 ff ff       	call   1140 <__isoc99_sscanf@plt>
    1789:	83 c4 10             	add    $0x10,%esp
    178c:	83 f8 02             	cmp    $0x2,%eax
    178f:	75 07                	jne    1798 <phase_4+0x44>
    1791:	83 7c 24 04 0e       	cmpl   $0xe,0x4(%esp)
    1796:	76 05                	jbe    179d <phase_4+0x49>
    1798:	e8 44 04 00 00       	call   1be1 <explode_bomb>
    179d:	83 ec 04             	sub    $0x4,%esp
    17a0:	6a 0e                	push   $0xe
    17a2:	6a 00                	push   $0x0
    17a4:	ff 74 24 10          	push   0x10(%esp)
    17a8:	e8 4e ff ff ff       	call   16fb <func4>
    17ad:	83 c4 10             	add    $0x10,%esp
    17b0:	83 f8 1b             	cmp    $0x1b,%eax
    17b3:	75 07                	jne    17bc <phase_4+0x68>
    17b5:	83 7c 24 08 1b       	cmpl   $0x1b,0x8(%esp)
    17ba:	74 05                	je     17c1 <phase_4+0x6d>
    17bc:	e8 20 04 00 00       	call   1be1 <explode_bomb>
    17c1:	8b 44 24 0c          	mov    0xc(%esp),%eax
    17c5:	65 2b 05 14 00 00 00 	sub    %gs:0x14,%eax
    17cc:	75 05                	jne    17d3 <phase_4+0x7f>
    17ce:	83 c4 18             	add    $0x18,%esp
    17d1:	5b                   	pop    %ebx
    17d2:	c3                   	ret    
    17d3:	e8 18 12 00 00       	call   29f0 <__stack_chk_fail_local>

000017d8 <phase_5>:
    17d8:	57                   	push   %edi
    17d9:	56                   	push   %esi
    17da:	53                   	push   %ebx
    17db:	e8 60 fa ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    17e0:	81 c3 84 47 00 00    	add    $0x4784,%ebx
    17e6:	8b 74 24 10          	mov    0x10(%esp),%esi
    17ea:	83 ec 0c             	sub    $0xc,%esp
    17ed:	56                   	push   %esi
    17ee:	e8 b8 02 00 00       	call   1aab <string_length>
    17f3:	83 c4 10             	add    $0x10,%esp
    17f6:	83 f8 06             	cmp    $0x6,%eax
    17f9:	75 29                	jne    1824 <phase_5+0x4c>
    17fb:	89 f0                	mov    %esi,%eax
    17fd:	83 c6 06             	add    $0x6,%esi
    1800:	b9 00 00 00 00       	mov    $0x0,%ecx
    1805:	8d bb 7c d2 ff ff    	lea    -0x2d84(%ebx),%edi
    180b:	0f b6 10             	movzbl (%eax),%edx
    180e:	83 e2 0f             	and    $0xf,%edx
    1811:	03 0c 97             	add    (%edi,%edx,4),%ecx
    1814:	83 c0 01             	add    $0x1,%eax
    1817:	39 f0                	cmp    %esi,%eax
    1819:	75 f0                	jne    180b <phase_5+0x33>
    181b:	83 f9 26             	cmp    $0x26,%ecx
    181e:	75 0b                	jne    182b <phase_5+0x53>
    1820:	5b                   	pop    %ebx
    1821:	5e                   	pop    %esi
    1822:	5f                   	pop    %edi
    1823:	c3                   	ret    
    1824:	e8 b8 03 00 00       	call   1be1 <explode_bomb>
    1829:	eb d0                	jmp    17fb <phase_5+0x23>
    182b:	e8 b1 03 00 00       	call   1be1 <explode_bomb>
    1830:	eb ee                	jmp    1820 <phase_5+0x48>

00001832 <phase_6>:
    1832:	55                   	push   %ebp
    1833:	57                   	push   %edi
    1834:	56                   	push   %esi
    1835:	53                   	push   %ebx
    1836:	83 ec 64             	sub    $0x64,%esp
    1839:	e8 02 fa ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    183e:	81 c3 26 47 00 00    	add    $0x4726,%ebx
    1844:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    184a:	89 44 24 54          	mov    %eax,0x54(%esp)
    184e:	31 c0                	xor    %eax,%eax
    1850:	8d 74 24 24          	lea    0x24(%esp),%esi
    1854:	56                   	push   %esi
    1855:	ff 74 24 7c          	push   0x7c(%esp)
    1859:	e8 b8 03 00 00       	call   1c16 <read_six_numbers>
    185e:	89 74 24 18          	mov    %esi,0x18(%esp)
    1862:	83 c4 10             	add    $0x10,%esp
    1865:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
    186c:	00 
    186d:	89 f5                	mov    %esi,%ebp
    186f:	eb 23                	jmp    1894 <phase_6+0x62>
    1871:	e8 6b 03 00 00       	call   1be1 <explode_bomb>
    1876:	eb 30                	jmp    18a8 <phase_6+0x76>
    1878:	83 c6 01             	add    $0x1,%esi
    187b:	83 fe 06             	cmp    $0x6,%esi
    187e:	74 0f                	je     188f <phase_6+0x5d>
    1880:	8b 44 b5 00          	mov    0x0(%ebp,%esi,4),%eax
    1884:	39 07                	cmp    %eax,(%edi)
    1886:	75 f0                	jne    1878 <phase_6+0x46>
    1888:	e8 54 03 00 00       	call   1be1 <explode_bomb>
    188d:	eb e9                	jmp    1878 <phase_6+0x46>
    188f:	83 44 24 08 04       	addl   $0x4,0x8(%esp)
    1894:	8b 44 24 08          	mov    0x8(%esp),%eax
    1898:	89 c7                	mov    %eax,%edi
    189a:	8b 00                	mov    (%eax),%eax
    189c:	89 44 24 0c          	mov    %eax,0xc(%esp)
    18a0:	83 e8 01             	sub    $0x1,%eax
    18a3:	83 f8 05             	cmp    $0x5,%eax
    18a6:	77 c9                	ja     1871 <phase_6+0x3f>
    18a8:	83 44 24 04 01       	addl   $0x1,0x4(%esp)
    18ad:	8b 74 24 04          	mov    0x4(%esp),%esi
    18b1:	83 fe 05             	cmp    $0x5,%esi
    18b4:	7e ca                	jle    1880 <phase_6+0x4e>
    18b6:	be 00 00 00 00       	mov    $0x0,%esi
    18bb:	89 f7                	mov    %esi,%edi
    18bd:	8b 4c b4 1c          	mov    0x1c(%esp,%esi,4),%ecx
    18c1:	b8 01 00 00 00       	mov    $0x1,%eax
    18c6:	8d 93 68 01 00 00    	lea    0x168(%ebx),%edx
    18cc:	83 f9 01             	cmp    $0x1,%ecx
    18cf:	7e 0a                	jle    18db <phase_6+0xa9>
    18d1:	8b 52 08             	mov    0x8(%edx),%edx
    18d4:	83 c0 01             	add    $0x1,%eax
    18d7:	39 c8                	cmp    %ecx,%eax
    18d9:	75 f6                	jne    18d1 <phase_6+0x9f>
    18db:	89 54 bc 34          	mov    %edx,0x34(%esp,%edi,4)
    18df:	83 c6 01             	add    $0x1,%esi
    18e2:	83 fe 06             	cmp    $0x6,%esi
    18e5:	75 d4                	jne    18bb <phase_6+0x89>
    18e7:	8b 74 24 34          	mov    0x34(%esp),%esi
    18eb:	8b 44 24 38          	mov    0x38(%esp),%eax
    18ef:	89 46 08             	mov    %eax,0x8(%esi)
    18f2:	8b 54 24 3c          	mov    0x3c(%esp),%edx
    18f6:	89 50 08             	mov    %edx,0x8(%eax)
    18f9:	8b 44 24 40          	mov    0x40(%esp),%eax
    18fd:	89 42 08             	mov    %eax,0x8(%edx)
    1900:	8b 54 24 44          	mov    0x44(%esp),%edx
    1904:	89 50 08             	mov    %edx,0x8(%eax)
    1907:	8b 44 24 48          	mov    0x48(%esp),%eax
    190b:	89 42 08             	mov    %eax,0x8(%edx)
    190e:	c7 40 08 00 00 00 00 	movl   $0x0,0x8(%eax)
    1915:	bf 05 00 00 00       	mov    $0x5,%edi
    191a:	eb 08                	jmp    1924 <phase_6+0xf2>
    191c:	8b 76 08             	mov    0x8(%esi),%esi
    191f:	83 ef 01             	sub    $0x1,%edi
    1922:	74 10                	je     1934 <phase_6+0x102>
    1924:	8b 46 08             	mov    0x8(%esi),%eax
    1927:	8b 00                	mov    (%eax),%eax
    1929:	39 06                	cmp    %eax,(%esi)
    192b:	7d ef                	jge    191c <phase_6+0xea>
    192d:	e8 af 02 00 00       	call   1be1 <explode_bomb>
    1932:	eb e8                	jmp    191c <phase_6+0xea>
    1934:	8b 44 24 4c          	mov    0x4c(%esp),%eax
    1938:	65 2b 05 14 00 00 00 	sub    %gs:0x14,%eax
    193f:	75 08                	jne    1949 <phase_6+0x117>
    1941:	83 c4 5c             	add    $0x5c,%esp
    1944:	5b                   	pop    %ebx
    1945:	5e                   	pop    %esi
    1946:	5f                   	pop    %edi
    1947:	5d                   	pop    %ebp
    1948:	c3                   	ret    
    1949:	e8 a2 10 00 00       	call   29f0 <__stack_chk_fail_local>

0000194e <fun7>:
    194e:	53                   	push   %ebx
    194f:	83 ec 08             	sub    $0x8,%esp
    1952:	8b 54 24 10          	mov    0x10(%esp),%edx
    1956:	8b 4c 24 14          	mov    0x14(%esp),%ecx
    195a:	85 d2                	test   %edx,%edx
    195c:	74 3a                	je     1998 <fun7+0x4a>
    195e:	8b 1a                	mov    (%edx),%ebx
    1960:	39 cb                	cmp    %ecx,%ebx
    1962:	7f 0c                	jg     1970 <fun7+0x22>
    1964:	b8 00 00 00 00       	mov    $0x0,%eax
    1969:	75 18                	jne    1983 <fun7+0x35>
    196b:	83 c4 08             	add    $0x8,%esp
    196e:	5b                   	pop    %ebx
    196f:	c3                   	ret    
    1970:	83 ec 08             	sub    $0x8,%esp
    1973:	51                   	push   %ecx
    1974:	ff 72 04             	push   0x4(%edx)
    1977:	e8 d2 ff ff ff       	call   194e <fun7>
    197c:	83 c4 10             	add    $0x10,%esp
    197f:	01 c0                	add    %eax,%eax
    1981:	eb e8                	jmp    196b <fun7+0x1d>
    1983:	83 ec 08             	sub    $0x8,%esp
    1986:	51                   	push   %ecx
    1987:	ff 72 08             	push   0x8(%edx)
    198a:	e8 bf ff ff ff       	call   194e <fun7>
    198f:	83 c4 10             	add    $0x10,%esp
    1992:	8d 44 00 01          	lea    0x1(%eax,%eax,1),%eax
    1996:	eb d3                	jmp    196b <fun7+0x1d>
    1998:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    199d:	eb cc                	jmp    196b <fun7+0x1d>

0000199f <secret_phase>:
    199f:	56                   	push   %esi
    19a0:	53                   	push   %ebx
    19a1:	83 ec 04             	sub    $0x4,%esp
    19a4:	e8 97 f8 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    19a9:	81 c3 bb 45 00 00    	add    $0x45bb,%ebx
    19af:	e8 ac 02 00 00       	call   1c60 <read_line>
    19b4:	83 ec 04             	sub    $0x4,%esp
    19b7:	6a 0a                	push   $0xa
    19b9:	6a 00                	push   $0x0
    19bb:	50                   	push   %eax
    19bc:	e8 ef f7 ff ff       	call   11b0 <strtol@plt>
    19c1:	89 c6                	mov    %eax,%esi
    19c3:	8d 40 ff             	lea    -0x1(%eax),%eax
    19c6:	83 c4 10             	add    $0x10,%esp
    19c9:	3d e8 03 00 00       	cmp    $0x3e8,%eax
    19ce:	77 32                	ja     1a02 <secret_phase+0x63>
    19d0:	83 ec 08             	sub    $0x8,%esp
    19d3:	56                   	push   %esi
    19d4:	8d 83 14 01 00 00    	lea    0x114(%ebx),%eax
    19da:	50                   	push   %eax
    19db:	e8 6e ff ff ff       	call   194e <fun7>
    19e0:	83 c4 10             	add    $0x10,%esp
    19e3:	83 f8 05             	cmp    $0x5,%eax
    19e6:	75 21                	jne    1a09 <secret_phase+0x6a>
    19e8:	83 ec 0c             	sub    $0xc,%esp
    19eb:	8d 83 14 d2 ff ff    	lea    -0x2dec(%ebx),%eax
    19f1:	50                   	push   %eax
    19f2:	e8 f9 f6 ff ff       	call   10f0 <puts@plt>
    19f7:	e8 83 03 00 00       	call   1d7f <phase_defused>
    19fc:	83 c4 14             	add    $0x14,%esp
    19ff:	5b                   	pop    %ebx
    1a00:	5e                   	pop    %esi
    1a01:	c3                   	ret    
    1a02:	e8 da 01 00 00       	call   1be1 <explode_bomb>
    1a07:	eb c7                	jmp    19d0 <secret_phase+0x31>
    1a09:	e8 d3 01 00 00       	call   1be1 <explode_bomb>
    1a0e:	eb d8                	jmp    19e8 <secret_phase+0x49>

00001a10 <sig_handler>:
    1a10:	53                   	push   %ebx
    1a11:	83 ec 14             	sub    $0x14,%esp
    1a14:	e8 27 f8 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1a19:	81 c3 4b 45 00 00    	add    $0x454b,%ebx
    1a1f:	8d 83 bc d2 ff ff    	lea    -0x2d44(%ebx),%eax
    1a25:	50                   	push   %eax
    1a26:	e8 c5 f6 ff ff       	call   10f0 <puts@plt>
    1a2b:	c7 04 24 03 00 00 00 	movl   $0x3,(%esp)
    1a32:	e8 69 f6 ff ff       	call   10a0 <sleep@plt>
    1a37:	83 c4 08             	add    $0x8,%esp
    1a3a:	8d 83 7e d3 ff ff    	lea    -0x2c82(%ebx),%eax
    1a40:	50                   	push   %eax
    1a41:	6a 01                	push   $0x1
    1a43:	e8 28 f7 ff ff       	call   1170 <__printf_chk@plt>
    1a48:	83 c4 04             	add    $0x4,%esp
    1a4b:	8b 83 90 00 00 00    	mov    0x90(%ebx),%eax
    1a51:	ff 30                	push   (%eax)
    1a53:	e8 18 f6 ff ff       	call   1070 <fflush@plt>
    1a58:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1a5f:	e8 3c f6 ff ff       	call   10a0 <sleep@plt>
    1a64:	8d 83 86 d3 ff ff    	lea    -0x2c7a(%ebx),%eax
    1a6a:	89 04 24             	mov    %eax,(%esp)
    1a6d:	e8 7e f6 ff ff       	call   10f0 <puts@plt>
    1a72:	c7 04 24 10 00 00 00 	movl   $0x10,(%esp)
    1a79:	e8 92 f6 ff ff       	call   1110 <exit@plt>

00001a7e <invalid_phase>:
    1a7e:	53                   	push   %ebx
    1a7f:	83 ec 0c             	sub    $0xc,%esp
    1a82:	e8 b9 f7 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1a87:	81 c3 dd 44 00 00    	add    $0x44dd,%ebx
    1a8d:	ff 74 24 14          	push   0x14(%esp)
    1a91:	8d 83 8e d3 ff ff    	lea    -0x2c72(%ebx),%eax
    1a97:	50                   	push   %eax
    1a98:	6a 01                	push   $0x1
    1a9a:	e8 d1 f6 ff ff       	call   1170 <__printf_chk@plt>
    1a9f:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
    1aa6:	e8 65 f6 ff ff       	call   1110 <exit@plt>

00001aab <string_length>:
    1aab:	8b 54 24 04          	mov    0x4(%esp),%edx
    1aaf:	80 3a 00             	cmpb   $0x0,(%edx)
    1ab2:	74 0f                	je     1ac3 <string_length+0x18>
    1ab4:	b8 00 00 00 00       	mov    $0x0,%eax
    1ab9:	83 c0 01             	add    $0x1,%eax
    1abc:	80 3c 02 00          	cmpb   $0x0,(%edx,%eax,1)
    1ac0:	75 f7                	jne    1ab9 <string_length+0xe>
    1ac2:	c3                   	ret    
    1ac3:	b8 00 00 00 00       	mov    $0x0,%eax
    1ac8:	c3                   	ret    

00001ac9 <strings_not_equal>:
    1ac9:	57                   	push   %edi
    1aca:	56                   	push   %esi
    1acb:	53                   	push   %ebx
    1acc:	8b 5c 24 10          	mov    0x10(%esp),%ebx
    1ad0:	8b 74 24 14          	mov    0x14(%esp),%esi
    1ad4:	53                   	push   %ebx
    1ad5:	e8 d1 ff ff ff       	call   1aab <string_length>
    1ada:	89 c7                	mov    %eax,%edi
    1adc:	89 34 24             	mov    %esi,(%esp)
    1adf:	e8 c7 ff ff ff       	call   1aab <string_length>
    1ae4:	83 c4 04             	add    $0x4,%esp
    1ae7:	89 c2                	mov    %eax,%edx
    1ae9:	b8 01 00 00 00       	mov    $0x1,%eax
    1aee:	39 d7                	cmp    %edx,%edi
    1af0:	75 2b                	jne    1b1d <strings_not_equal+0x54>
    1af2:	0f b6 03             	movzbl (%ebx),%eax
    1af5:	84 c0                	test   %al,%al
    1af7:	74 18                	je     1b11 <strings_not_equal+0x48>
    1af9:	38 06                	cmp    %al,(%esi)
    1afb:	75 1b                	jne    1b18 <strings_not_equal+0x4f>
    1afd:	83 c3 01             	add    $0x1,%ebx
    1b00:	83 c6 01             	add    $0x1,%esi
    1b03:	0f b6 03             	movzbl (%ebx),%eax
    1b06:	84 c0                	test   %al,%al
    1b08:	75 ef                	jne    1af9 <strings_not_equal+0x30>
    1b0a:	b8 00 00 00 00       	mov    $0x0,%eax
    1b0f:	eb 0c                	jmp    1b1d <strings_not_equal+0x54>
    1b11:	b8 00 00 00 00       	mov    $0x0,%eax
    1b16:	eb 05                	jmp    1b1d <strings_not_equal+0x54>
    1b18:	b8 01 00 00 00       	mov    $0x1,%eax
    1b1d:	5b                   	pop    %ebx
    1b1e:	5e                   	pop    %esi
    1b1f:	5f                   	pop    %edi
    1b20:	c3                   	ret    

00001b21 <initialize_bomb>:
    1b21:	53                   	push   %ebx
    1b22:	83 ec 10             	sub    $0x10,%esp
    1b25:	e8 16 f7 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1b2a:	81 c3 3a 44 00 00    	add    $0x443a,%ebx
    1b30:	8d 83 ac ba ff ff    	lea    -0x4554(%ebx),%eax
    1b36:	50                   	push   %eax
    1b37:	6a 02                	push   $0x2
    1b39:	e8 52 f5 ff ff       	call   1090 <signal@plt>
    1b3e:	83 c4 18             	add    $0x18,%esp
    1b41:	5b                   	pop    %ebx
    1b42:	c3                   	ret    

00001b43 <initialize_bomb_solve>:
    1b43:	c3                   	ret    

00001b44 <blank_line>:
    1b44:	57                   	push   %edi
    1b45:	56                   	push   %esi
    1b46:	53                   	push   %ebx
    1b47:	e8 f4 f6 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1b4c:	81 c3 18 44 00 00    	add    $0x4418,%ebx
    1b52:	8b 7c 24 10          	mov    0x10(%esp),%edi
    1b56:	0f b6 37             	movzbl (%edi),%esi
    1b59:	89 f0                	mov    %esi,%eax
    1b5b:	84 c0                	test   %al,%al
    1b5d:	74 1d                	je     1b7c <blank_line+0x38>
    1b5f:	e8 7c f6 ff ff       	call   11e0 <__ctype_b_loc@plt>
    1b64:	83 c7 01             	add    $0x1,%edi
    1b67:	89 f2                	mov    %esi,%edx
    1b69:	0f be f2             	movsbl %dl,%esi
    1b6c:	8b 00                	mov    (%eax),%eax
    1b6e:	f6 44 70 01 20       	testb  $0x20,0x1(%eax,%esi,2)
    1b73:	75 e1                	jne    1b56 <blank_line+0x12>
    1b75:	b8 00 00 00 00       	mov    $0x0,%eax
    1b7a:	eb 05                	jmp    1b81 <blank_line+0x3d>
    1b7c:	b8 01 00 00 00       	mov    $0x1,%eax
    1b81:	5b                   	pop    %ebx
    1b82:	5e                   	pop    %esi
    1b83:	5f                   	pop    %edi
    1b84:	c3                   	ret    

00001b85 <skip>:
    1b85:	55                   	push   %ebp
    1b86:	57                   	push   %edi
    1b87:	56                   	push   %esi
    1b88:	53                   	push   %ebx
    1b89:	83 ec 0c             	sub    $0xc,%esp
    1b8c:	e8 af f6 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1b91:	81 c3 d3 43 00 00    	add    $0x43d3,%ebx
    1b97:	8d bb c0 03 00 00    	lea    0x3c0(%ebx),%edi
    1b9d:	8d b3 3c 04 00 00    	lea    0x43c(%ebx),%esi
    1ba3:	83 ec 04             	sub    $0x4,%esp
    1ba6:	ff 37                	push   (%edi)
    1ba8:	6a 50                	push   $0x50
    1baa:	8b 83 2c 04 00 00    	mov    0x42c(%ebx),%eax
    1bb0:	8d 04 80             	lea    (%eax,%eax,4),%eax
    1bb3:	c1 e0 04             	shl    $0x4,%eax
    1bb6:	01 f0                	add    %esi,%eax
    1bb8:	50                   	push   %eax
    1bb9:	e8 c2 f4 ff ff       	call   1080 <fgets@plt>
    1bbe:	89 c5                	mov    %eax,%ebp
    1bc0:	83 c4 10             	add    $0x10,%esp
    1bc3:	85 c0                	test   %eax,%eax
    1bc5:	74 10                	je     1bd7 <skip+0x52>
    1bc7:	83 ec 0c             	sub    $0xc,%esp
    1bca:	50                   	push   %eax
    1bcb:	e8 74 ff ff ff       	call   1b44 <blank_line>
    1bd0:	83 c4 10             	add    $0x10,%esp
    1bd3:	85 c0                	test   %eax,%eax
    1bd5:	75 cc                	jne    1ba3 <skip+0x1e>
    1bd7:	89 e8                	mov    %ebp,%eax
    1bd9:	83 c4 0c             	add    $0xc,%esp
    1bdc:	5b                   	pop    %ebx
    1bdd:	5e                   	pop    %esi
    1bde:	5f                   	pop    %edi
    1bdf:	5d                   	pop    %ebp
    1be0:	c3                   	ret    

00001be1 <explode_bomb>:
    1be1:	53                   	push   %ebx
    1be2:	83 ec 14             	sub    $0x14,%esp
    1be5:	e8 56 f6 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1bea:	81 c3 7a 43 00 00    	add    $0x437a,%ebx
    1bf0:	8d 83 9f d3 ff ff    	lea    -0x2c61(%ebx),%eax
    1bf6:	50                   	push   %eax
    1bf7:	e8 f4 f4 ff ff       	call   10f0 <puts@plt>
    1bfc:	8d 83 a8 d3 ff ff    	lea    -0x2c58(%ebx),%eax
    1c02:	89 04 24             	mov    %eax,(%esp)
    1c05:	e8 e6 f4 ff ff       	call   10f0 <puts@plt>
    1c0a:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
    1c11:	e8 fa f4 ff ff       	call   1110 <exit@plt>

00001c16 <read_six_numbers>:
    1c16:	53                   	push   %ebx
    1c17:	83 ec 08             	sub    $0x8,%esp
    1c1a:	e8 21 f6 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1c1f:	81 c3 45 43 00 00    	add    $0x4345,%ebx
    1c25:	8b 44 24 14          	mov    0x14(%esp),%eax
    1c29:	8d 50 14             	lea    0x14(%eax),%edx
    1c2c:	52                   	push   %edx
    1c2d:	8d 50 10             	lea    0x10(%eax),%edx
    1c30:	52                   	push   %edx
    1c31:	8d 50 0c             	lea    0xc(%eax),%edx
    1c34:	52                   	push   %edx
    1c35:	8d 50 08             	lea    0x8(%eax),%edx
    1c38:	52                   	push   %edx
    1c39:	8d 50 04             	lea    0x4(%eax),%edx
    1c3c:	52                   	push   %edx
    1c3d:	50                   	push   %eax
    1c3e:	8d 83 bf d3 ff ff    	lea    -0x2c41(%ebx),%eax
    1c44:	50                   	push   %eax
    1c45:	ff 74 24 2c          	push   0x2c(%esp)
    1c49:	e8 f2 f4 ff ff       	call   1140 <__isoc99_sscanf@plt>
    1c4e:	83 c4 20             	add    $0x20,%esp
    1c51:	83 f8 05             	cmp    $0x5,%eax
    1c54:	7e 05                	jle    1c5b <read_six_numbers+0x45>
    1c56:	83 c4 08             	add    $0x8,%esp
    1c59:	5b                   	pop    %ebx
    1c5a:	c3                   	ret    
    1c5b:	e8 81 ff ff ff       	call   1be1 <explode_bomb>

00001c60 <read_line>:
    1c60:	57                   	push   %edi
    1c61:	56                   	push   %esi
    1c62:	53                   	push   %ebx
    1c63:	e8 d8 f5 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1c68:	81 c3 fc 42 00 00    	add    $0x42fc,%ebx
    1c6e:	e8 12 ff ff ff       	call   1b85 <skip>
    1c73:	85 c0                	test   %eax,%eax
    1c75:	74 47                	je     1cbe <read_line+0x5e>
    1c77:	8b b3 2c 04 00 00    	mov    0x42c(%ebx),%esi
    1c7d:	8d 04 b6             	lea    (%esi,%esi,4),%eax
    1c80:	c1 e0 04             	shl    $0x4,%eax
    1c83:	8d bc 03 3c 04 00 00 	lea    0x43c(%ebx,%eax,1),%edi
    1c8a:	83 ec 0c             	sub    $0xc,%esp
    1c8d:	57                   	push   %edi
    1c8e:	e8 8d f4 ff ff       	call   1120 <strlen@plt>
    1c93:	83 c4 10             	add    $0x10,%esp
    1c96:	83 f8 4e             	cmp    $0x4e,%eax
    1c99:	0f 8f a4 00 00 00    	jg     1d43 <read_line+0xe3>
    1c9f:	8d 14 b6             	lea    (%esi,%esi,4),%edx
    1ca2:	c1 e2 04             	shl    $0x4,%edx
    1ca5:	01 d0                	add    %edx,%eax
    1ca7:	c6 84 03 3b 04 00 00 	movb   $0x0,0x43b(%ebx,%eax,1)
    1cae:	00 
    1caf:	83 c6 01             	add    $0x1,%esi
    1cb2:	89 b3 2c 04 00 00    	mov    %esi,0x42c(%ebx)
    1cb8:	89 f8                	mov    %edi,%eax
    1cba:	5b                   	pop    %ebx
    1cbb:	5e                   	pop    %esi
    1cbc:	5f                   	pop    %edi
    1cbd:	c3                   	ret    
    1cbe:	8d 93 c0 03 00 00    	lea    0x3c0(%ebx),%edx
    1cc4:	8b 83 8c 00 00 00    	mov    0x8c(%ebx),%eax
    1cca:	8b 00                	mov    (%eax),%eax
    1ccc:	39 02                	cmp    %eax,(%edx)
    1cce:	74 20                	je     1cf0 <read_line+0x90>
    1cd0:	83 ec 0c             	sub    $0xc,%esp
    1cd3:	8d 83 ef d3 ff ff    	lea    -0x2c11(%ebx),%eax
    1cd9:	50                   	push   %eax
    1cda:	e8 01 f4 ff ff       	call   10e0 <getenv@plt>
    1cdf:	83 c4 10             	add    $0x10,%esp
    1ce2:	85 c0                	test   %eax,%eax
    1ce4:	74 25                	je     1d0b <read_line+0xab>
    1ce6:	83 ec 0c             	sub    $0xc,%esp
    1ce9:	6a 00                	push   $0x0
    1ceb:	e8 20 f4 ff ff       	call   1110 <exit@plt>
    1cf0:	83 ec 0c             	sub    $0xc,%esp
    1cf3:	8d 83 d1 d3 ff ff    	lea    -0x2c2f(%ebx),%eax
    1cf9:	50                   	push   %eax
    1cfa:	e8 f1 f3 ff ff       	call   10f0 <puts@plt>
    1cff:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
    1d06:	e8 05 f4 ff ff       	call   1110 <exit@plt>
    1d0b:	8b 83 8c 00 00 00    	mov    0x8c(%ebx),%eax
    1d11:	8b 10                	mov    (%eax),%edx
    1d13:	8d 83 c0 03 00 00    	lea    0x3c0(%ebx),%eax
    1d19:	89 10                	mov    %edx,(%eax)
    1d1b:	e8 65 fe ff ff       	call   1b85 <skip>
    1d20:	85 c0                	test   %eax,%eax
    1d22:	0f 85 4f ff ff ff    	jne    1c77 <read_line+0x17>
    1d28:	83 ec 0c             	sub    $0xc,%esp
    1d2b:	8d 83 d1 d3 ff ff    	lea    -0x2c2f(%ebx),%eax
    1d31:	50                   	push   %eax
    1d32:	e8 b9 f3 ff ff       	call   10f0 <puts@plt>
    1d37:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
    1d3e:	e8 cd f3 ff ff       	call   1110 <exit@plt>
    1d43:	83 ec 0c             	sub    $0xc,%esp
    1d46:	8d 83 fa d3 ff ff    	lea    -0x2c06(%ebx),%eax
    1d4c:	50                   	push   %eax
    1d4d:	e8 9e f3 ff ff       	call   10f0 <puts@plt>
    1d52:	8b 83 2c 04 00 00    	mov    0x42c(%ebx),%eax
    1d58:	8d 50 01             	lea    0x1(%eax),%edx
    1d5b:	89 93 2c 04 00 00    	mov    %edx,0x42c(%ebx)
    1d61:	6b c0 50             	imul   $0x50,%eax,%eax
    1d64:	8d 84 03 3c 04 00 00 	lea    0x43c(%ebx,%eax,1),%eax
    1d6b:	8d b3 15 d4 ff ff    	lea    -0x2beb(%ebx),%esi
    1d71:	b9 04 00 00 00       	mov    $0x4,%ecx
    1d76:	89 c7                	mov    %eax,%edi
    1d78:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
    1d7a:	e8 62 fe ff ff       	call   1be1 <explode_bomb>

00001d7f <phase_defused>:
    1d7f:	53                   	push   %ebx
    1d80:	83 ec 68             	sub    $0x68,%esp
    1d83:	e8 b8 f4 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1d88:	81 c3 dc 41 00 00    	add    $0x41dc,%ebx
    1d8e:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    1d94:	89 44 24 5c          	mov    %eax,0x5c(%esp)
    1d98:	31 c0                	xor    %eax,%eax
    1d9a:	83 bb 2c 04 00 00 06 	cmpl   $0x6,0x42c(%ebx)
    1da1:	74 16                	je     1db9 <phase_defused+0x3a>
    1da3:	8b 44 24 5c          	mov    0x5c(%esp),%eax
    1da7:	65 2b 05 14 00 00 00 	sub    %gs:0x14,%eax
    1dae:	0f 85 88 00 00 00    	jne    1e3c <phase_defused+0xbd>
    1db4:	83 c4 68             	add    $0x68,%esp
    1db7:	5b                   	pop    %ebx
    1db8:	c3                   	ret    
    1db9:	83 ec 0c             	sub    $0xc,%esp
    1dbc:	8d 44 24 18          	lea    0x18(%esp),%eax
    1dc0:	50                   	push   %eax
    1dc1:	8d 44 24 18          	lea    0x18(%esp),%eax
    1dc5:	50                   	push   %eax
    1dc6:	8d 44 24 18          	lea    0x18(%esp),%eax
    1dca:	50                   	push   %eax
    1dcb:	8d 83 25 d4 ff ff    	lea    -0x2bdb(%ebx),%eax
    1dd1:	50                   	push   %eax
    1dd2:	8d 83 2c 05 00 00    	lea    0x52c(%ebx),%eax
    1dd8:	50                   	push   %eax
    1dd9:	e8 62 f3 ff ff       	call   1140 <__isoc99_sscanf@plt>
    1dde:	83 c4 20             	add    $0x20,%esp
    1de1:	83 f8 03             	cmp    $0x3,%eax
    1de4:	74 14                	je     1dfa <phase_defused+0x7b>
    1de6:	83 ec 0c             	sub    $0xc,%esp
    1de9:	8d 83 54 d3 ff ff    	lea    -0x2cac(%ebx),%eax
    1def:	50                   	push   %eax
    1df0:	e8 fb f2 ff ff       	call   10f0 <puts@plt>
    1df5:	83 c4 10             	add    $0x10,%esp
    1df8:	eb a9                	jmp    1da3 <phase_defused+0x24>
    1dfa:	83 ec 08             	sub    $0x8,%esp
    1dfd:	8d 83 2e d4 ff ff    	lea    -0x2bd2(%ebx),%eax
    1e03:	50                   	push   %eax
    1e04:	8d 44 24 18          	lea    0x18(%esp),%eax
    1e08:	50                   	push   %eax
    1e09:	e8 bb fc ff ff       	call   1ac9 <strings_not_equal>
    1e0e:	83 c4 10             	add    $0x10,%esp
    1e11:	85 c0                	test   %eax,%eax
    1e13:	75 d1                	jne    1de6 <phase_defused+0x67>
    1e15:	83 ec 0c             	sub    $0xc,%esp
    1e18:	8d 83 f4 d2 ff ff    	lea    -0x2d0c(%ebx),%eax
    1e1e:	50                   	push   %eax
    1e1f:	e8 cc f2 ff ff       	call   10f0 <puts@plt>
    1e24:	8d 83 1c d3 ff ff    	lea    -0x2ce4(%ebx),%eax
    1e2a:	89 04 24             	mov    %eax,(%esp)
    1e2d:	e8 be f2 ff ff       	call   10f0 <puts@plt>
    1e32:	e8 68 fb ff ff       	call   199f <secret_phase>
    1e37:	83 c4 10             	add    $0x10,%esp
    1e3a:	eb aa                	jmp    1de6 <phase_defused+0x67>
    1e3c:	e8 af 0b 00 00       	call   29f0 <__stack_chk_fail_local>

00001e41 <sigalrm_handler>:
    1e41:	53                   	push   %ebx
    1e42:	83 ec 08             	sub    $0x8,%esp
    1e45:	e8 f6 f3 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1e4a:	81 c3 1a 41 00 00    	add    $0x411a,%ebx
    1e50:	6a 00                	push   $0x0
    1e52:	8d 83 84 d4 ff ff    	lea    -0x2b7c(%ebx),%eax
    1e58:	50                   	push   %eax
    1e59:	6a 01                	push   $0x1
    1e5b:	8b 83 80 00 00 00    	mov    0x80(%ebx),%eax
    1e61:	ff 30                	push   (%eax)
    1e63:	e8 28 f3 ff ff       	call   1190 <__fprintf_chk@plt>
    1e68:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1e6f:	e8 9c f2 ff ff       	call   1110 <exit@plt>

00001e74 <rio_readlineb>:
    1e74:	55                   	push   %ebp
    1e75:	57                   	push   %edi
    1e76:	56                   	push   %esi
    1e77:	53                   	push   %ebx
    1e78:	83 ec 1c             	sub    $0x1c,%esp
    1e7b:	e8 c0 f3 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1e80:	81 c3 e4 40 00 00    	add    $0x40e4,%ebx
    1e86:	89 d5                	mov    %edx,%ebp
    1e88:	83 f9 01             	cmp    $0x1,%ecx
    1e8b:	0f 86 87 00 00 00    	jbe    1f18 <rio_readlineb+0xa4>
    1e91:	89 c6                	mov    %eax,%esi
    1e93:	8d 44 0a ff          	lea    -0x1(%edx,%ecx,1),%eax
    1e97:	89 44 24 0c          	mov    %eax,0xc(%esp)
    1e9b:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1ea2:	00 
    1ea3:	8d 7e 0c             	lea    0xc(%esi),%edi
    1ea6:	eb 51                	jmp    1ef9 <rio_readlineb+0x85>
    1ea8:	e8 b3 f2 ff ff       	call   1160 <__errno_location@plt>
    1ead:	83 38 04             	cmpl   $0x4,(%eax)
    1eb0:	75 50                	jne    1f02 <rio_readlineb+0x8e>
    1eb2:	83 ec 04             	sub    $0x4,%esp
    1eb5:	68 00 20 00 00       	push   $0x2000
    1eba:	57                   	push   %edi
    1ebb:	ff 36                	push   (%esi)
    1ebd:	e8 9e f1 ff ff       	call   1060 <read@plt>
    1ec2:	89 46 04             	mov    %eax,0x4(%esi)
    1ec5:	83 c4 10             	add    $0x10,%esp
    1ec8:	85 c0                	test   %eax,%eax
    1eca:	78 dc                	js     1ea8 <rio_readlineb+0x34>
    1ecc:	74 39                	je     1f07 <rio_readlineb+0x93>
    1ece:	89 7e 08             	mov    %edi,0x8(%esi)
    1ed1:	8b 56 08             	mov    0x8(%esi),%edx
    1ed4:	0f b6 0a             	movzbl (%edx),%ecx
    1ed7:	83 c2 01             	add    $0x1,%edx
    1eda:	89 56 08             	mov    %edx,0x8(%esi)
    1edd:	83 e8 01             	sub    $0x1,%eax
    1ee0:	89 46 04             	mov    %eax,0x4(%esi)
    1ee3:	83 c5 01             	add    $0x1,%ebp
    1ee6:	88 4d ff             	mov    %cl,-0x1(%ebp)
    1ee9:	80 f9 0a             	cmp    $0xa,%cl
    1eec:	74 38                	je     1f26 <rio_readlineb+0xb2>
    1eee:	83 44 24 08 01       	addl   $0x1,0x8(%esp)
    1ef3:	3b 6c 24 0c          	cmp    0xc(%esp),%ebp
    1ef7:	74 29                	je     1f22 <rio_readlineb+0xae>
    1ef9:	8b 46 04             	mov    0x4(%esi),%eax
    1efc:	85 c0                	test   %eax,%eax
    1efe:	7e b2                	jle    1eb2 <rio_readlineb+0x3e>
    1f00:	eb cf                	jmp    1ed1 <rio_readlineb+0x5d>
    1f02:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1f07:	85 c0                	test   %eax,%eax
    1f09:	75 2b                	jne    1f36 <rio_readlineb+0xc2>
    1f0b:	83 7c 24 08 01       	cmpl   $0x1,0x8(%esp)
    1f10:	75 14                	jne    1f26 <rio_readlineb+0xb2>
    1f12:	89 44 24 08          	mov    %eax,0x8(%esp)
    1f16:	eb 12                	jmp    1f2a <rio_readlineb+0xb6>
    1f18:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1f1f:	00 
    1f20:	eb 04                	jmp    1f26 <rio_readlineb+0xb2>
    1f22:	8b 6c 24 0c          	mov    0xc(%esp),%ebp
    1f26:	c6 45 00 00          	movb   $0x0,0x0(%ebp)
    1f2a:	8b 44 24 08          	mov    0x8(%esp),%eax
    1f2e:	83 c4 1c             	add    $0x1c,%esp
    1f31:	5b                   	pop    %ebx
    1f32:	5e                   	pop    %esi
    1f33:	5f                   	pop    %edi
    1f34:	5d                   	pop    %ebp
    1f35:	c3                   	ret    
    1f36:	c7 44 24 08 ff ff ff 	movl   $0xffffffff,0x8(%esp)
    1f3d:	ff 
    1f3e:	eb ea                	jmp    1f2a <rio_readlineb+0xb6>

00001f40 <submitr>:
    1f40:	55                   	push   %ebp
    1f41:	57                   	push   %edi
    1f42:	56                   	push   %esi
    1f43:	53                   	push   %ebx
    1f44:	8d 84 24 00 60 ff ff 	lea    -0xa000(%esp),%eax
    1f4b:	81 ec 00 10 00 00    	sub    $0x1000,%esp
    1f51:	83 0c 24 00          	orl    $0x0,(%esp)
    1f55:	39 c4                	cmp    %eax,%esp
    1f57:	75 f2                	jne    1f4b <submitr+0xb>
    1f59:	83 ec 60             	sub    $0x60,%esp
    1f5c:	e8 df f2 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    1f61:	81 c3 03 40 00 00    	add    $0x4003,%ebx
    1f67:	8b b4 24 74 a0 00 00 	mov    0xa074(%esp),%esi
    1f6e:	8b 84 24 7c a0 00 00 	mov    0xa07c(%esp),%eax
    1f75:	89 44 24 08          	mov    %eax,0x8(%esp)
    1f79:	8b 84 24 80 a0 00 00 	mov    0xa080(%esp),%eax
    1f80:	89 44 24 0c          	mov    %eax,0xc(%esp)
    1f84:	8b 84 24 84 a0 00 00 	mov    0xa084(%esp),%eax
    1f8b:	89 44 24 10          	mov    %eax,0x10(%esp)
    1f8f:	8b 84 24 88 a0 00 00 	mov    0xa088(%esp),%eax
    1f96:	89 44 24 04          	mov    %eax,0x4(%esp)
    1f9a:	8b 84 24 8c a0 00 00 	mov    0xa08c(%esp),%eax
    1fa1:	89 44 24 14          	mov    %eax,0x14(%esp)
    1fa5:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    1fab:	89 84 24 50 a0 00 00 	mov    %eax,0xa050(%esp)
    1fb2:	31 c0                	xor    %eax,%eax
    1fb4:	c7 44 24 30 00 00 00 	movl   $0x0,0x30(%esp)
    1fbb:	00 
    1fbc:	6a 00                	push   $0x0
    1fbe:	6a 01                	push   $0x1
    1fc0:	6a 02                	push   $0x2
    1fc2:	e8 b9 f1 ff ff       	call   1180 <socket@plt>
    1fc7:	83 c4 10             	add    $0x10,%esp
    1fca:	85 c0                	test   %eax,%eax
    1fcc:	0f 88 2b 01 00 00    	js     20fd <submitr+0x1bd>
    1fd2:	89 c5                	mov    %eax,%ebp
    1fd4:	83 ec 0c             	sub    $0xc,%esp
    1fd7:	56                   	push   %esi
    1fd8:	e8 c3 f1 ff ff       	call   11a0 <gethostbyname@plt>
    1fdd:	83 c4 10             	add    $0x10,%esp
    1fe0:	85 c0                	test   %eax,%eax
    1fe2:	0f 84 67 01 00 00    	je     214f <submitr+0x20f>
    1fe8:	8d 74 24 30          	lea    0x30(%esp),%esi
    1fec:	c7 44 24 30 00 00 00 	movl   $0x0,0x30(%esp)
    1ff3:	00 
    1ff4:	c7 44 24 34 00 00 00 	movl   $0x0,0x34(%esp)
    1ffb:	00 
    1ffc:	c7 44 24 38 00 00 00 	movl   $0x0,0x38(%esp)
    2003:	00 
    2004:	c7 44 24 3c 00 00 00 	movl   $0x0,0x3c(%esp)
    200b:	00 
    200c:	66 c7 44 24 30 02 00 	movw   $0x2,0x30(%esp)
    2013:	6a 0c                	push   $0xc
    2015:	ff 70 0c             	push   0xc(%eax)
    2018:	8b 40 10             	mov    0x10(%eax),%eax
    201b:	ff 30                	push   (%eax)
    201d:	8d 44 24 40          	lea    0x40(%esp),%eax
    2021:	50                   	push   %eax
    2022:	e8 d9 f0 ff ff       	call   1100 <__memmove_chk@plt>
    2027:	0f b7 84 24 84 a0 00 	movzwl 0xa084(%esp),%eax
    202e:	00 
    202f:	66 c1 c0 08          	rol    $0x8,%ax
    2033:	66 89 44 24 42       	mov    %ax,0x42(%esp)
    2038:	83 c4 0c             	add    $0xc,%esp
    203b:	6a 10                	push   $0x10
    203d:	56                   	push   %esi
    203e:	55                   	push   %ebp
    203f:	e8 7c f1 ff ff       	call   11c0 <connect@plt>
    2044:	83 c4 10             	add    $0x10,%esp
    2047:	85 c0                	test   %eax,%eax
    2049:	0f 88 70 01 00 00    	js     21bf <submitr+0x27f>
    204f:	83 ec 0c             	sub    $0xc,%esp
    2052:	ff 74 24 0c          	push   0xc(%esp)
    2056:	e8 c5 f0 ff ff       	call   1120 <strlen@plt>
    205b:	83 c4 04             	add    $0x4,%esp
    205e:	89 c6                	mov    %eax,%esi
    2060:	ff 74 24 10          	push   0x10(%esp)
    2064:	e8 b7 f0 ff ff       	call   1120 <strlen@plt>
    2069:	83 c4 04             	add    $0x4,%esp
    206c:	89 44 24 20          	mov    %eax,0x20(%esp)
    2070:	ff 74 24 14          	push   0x14(%esp)
    2074:	e8 a7 f0 ff ff       	call   1120 <strlen@plt>
    2079:	83 c4 04             	add    $0x4,%esp
    207c:	89 c7                	mov    %eax,%edi
    207e:	ff 74 24 18          	push   0x18(%esp)
    2082:	e8 99 f0 ff ff       	call   1120 <strlen@plt>
    2087:	83 c4 10             	add    $0x10,%esp
    208a:	89 c2                	mov    %eax,%edx
    208c:	8b 44 24 14          	mov    0x14(%esp),%eax
    2090:	8d 84 38 80 00 00 00 	lea    0x80(%eax,%edi,1),%eax
    2097:	01 d0                	add    %edx,%eax
    2099:	8d 14 76             	lea    (%esi,%esi,2),%edx
    209c:	01 d0                	add    %edx,%eax
    209e:	3d 00 20 00 00       	cmp    $0x2000,%eax
    20a3:	0f 87 78 01 00 00    	ja     2221 <submitr+0x2e1>
    20a9:	8d 94 24 4c 40 00 00 	lea    0x404c(%esp),%edx
    20b0:	b9 00 08 00 00       	mov    $0x800,%ecx
    20b5:	b8 00 00 00 00       	mov    $0x0,%eax
    20ba:	89 d7                	mov    %edx,%edi
    20bc:	f3 ab                	rep stos %eax,%es:(%edi)
    20be:	83 ec 0c             	sub    $0xc,%esp
    20c1:	8b 74 24 0c          	mov    0xc(%esp),%esi
    20c5:	56                   	push   %esi
    20c6:	e8 55 f0 ff ff       	call   1120 <strlen@plt>
    20cb:	83 c4 10             	add    $0x10,%esp
    20ce:	85 c0                	test   %eax,%eax
    20d0:	0f 84 6c 02 00 00    	je     2342 <submitr+0x402>
    20d6:	8d bc 24 4c 40 00 00 	lea    0x404c(%esp),%edi
    20dd:	8d 8b 8e d5 ff ff    	lea    -0x2a72(%ebx),%ecx
    20e3:	89 4c 24 18          	mov    %ecx,0x18(%esp)
    20e7:	8d 8c 24 4c 80 00 00 	lea    0x804c(%esp),%ecx
    20ee:	89 4c 24 1c          	mov    %ecx,0x1c(%esp)
    20f2:	89 6c 24 14          	mov    %ebp,0x14(%esp)
    20f6:	89 c5                	mov    %eax,%ebp
    20f8:	e9 b8 01 00 00       	jmp    22b5 <submitr+0x375>
    20fd:	8b 44 24 10          	mov    0x10(%esp),%eax
    2101:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    2107:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
    210e:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
    2115:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
    211c:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
    2123:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
    212a:	c7 40 18 63 72 65 61 	movl   $0x61657263,0x18(%eax)
    2131:	c7 40 1c 74 65 20 73 	movl   $0x73206574,0x1c(%eax)
    2138:	c7 40 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%eax)
    213f:	66 c7 40 24 74 00    	movw   $0x74,0x24(%eax)
    2145:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    214a:	e9 80 04 00 00       	jmp    25cf <submitr+0x68f>
    214f:	8b 44 24 10          	mov    0x10(%esp),%eax
    2153:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    2159:	c7 40 04 72 3a 20 44 	movl   $0x44203a72,0x4(%eax)
    2160:	c7 40 08 4e 53 20 69 	movl   $0x6920534e,0x8(%eax)
    2167:	c7 40 0c 73 20 75 6e 	movl   $0x6e752073,0xc(%eax)
    216e:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
    2175:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
    217c:	c7 40 18 72 65 73 6f 	movl   $0x6f736572,0x18(%eax)
    2183:	c7 40 1c 6c 76 65 20 	movl   $0x2065766c,0x1c(%eax)
    218a:	c7 40 20 73 65 72 76 	movl   $0x76726573,0x20(%eax)
    2191:	c7 40 24 65 72 20 61 	movl   $0x61207265,0x24(%eax)
    2198:	c7 40 28 64 64 72 65 	movl   $0x65726464,0x28(%eax)
    219f:	66 c7 40 2c 73 73    	movw   $0x7373,0x2c(%eax)
    21a5:	c6 40 2e 00          	movb   $0x0,0x2e(%eax)
    21a9:	83 ec 0c             	sub    $0xc,%esp
    21ac:	55                   	push   %ebp
    21ad:	e8 1e f0 ff ff       	call   11d0 <close@plt>
    21b2:	83 c4 10             	add    $0x10,%esp
    21b5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    21ba:	e9 10 04 00 00       	jmp    25cf <submitr+0x68f>
    21bf:	8b 44 24 10          	mov    0x10(%esp),%eax
    21c3:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    21c9:	c7 40 04 72 3a 20 55 	movl   $0x55203a72,0x4(%eax)
    21d0:	c7 40 08 6e 61 62 6c 	movl   $0x6c62616e,0x8(%eax)
    21d7:	c7 40 0c 65 20 74 6f 	movl   $0x6f742065,0xc(%eax)
    21de:	c7 40 10 20 63 6f 6e 	movl   $0x6e6f6320,0x10(%eax)
    21e5:	c7 40 14 6e 65 63 74 	movl   $0x7463656e,0x14(%eax)
    21ec:	c7 40 18 20 74 6f 20 	movl   $0x206f7420,0x18(%eax)
    21f3:	c7 40 1c 74 68 65 20 	movl   $0x20656874,0x1c(%eax)
    21fa:	c7 40 20 73 65 72 76 	movl   $0x76726573,0x20(%eax)
    2201:	66 c7 40 24 65 72    	movw   $0x7265,0x24(%eax)
    2207:	c6 40 26 00          	movb   $0x0,0x26(%eax)
    220b:	83 ec 0c             	sub    $0xc,%esp
    220e:	55                   	push   %ebp
    220f:	e8 bc ef ff ff       	call   11d0 <close@plt>
    2214:	83 c4 10             	add    $0x10,%esp
    2217:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    221c:	e9 ae 03 00 00       	jmp    25cf <submitr+0x68f>
    2221:	8b 44 24 10          	mov    0x10(%esp),%eax
    2225:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    222b:	c7 40 04 72 3a 20 52 	movl   $0x52203a72,0x4(%eax)
    2232:	c7 40 08 65 73 75 6c 	movl   $0x6c757365,0x8(%eax)
    2239:	c7 40 0c 74 20 73 74 	movl   $0x74732074,0xc(%eax)
    2240:	c7 40 10 72 69 6e 67 	movl   $0x676e6972,0x10(%eax)
    2247:	c7 40 14 20 74 6f 6f 	movl   $0x6f6f7420,0x14(%eax)
    224e:	c7 40 18 20 6c 61 72 	movl   $0x72616c20,0x18(%eax)
    2255:	c7 40 1c 67 65 2e 20 	movl   $0x202e6567,0x1c(%eax)
    225c:	c7 40 20 49 6e 63 72 	movl   $0x72636e49,0x20(%eax)
    2263:	c7 40 24 65 61 73 65 	movl   $0x65736165,0x24(%eax)
    226a:	c7 40 28 20 53 55 42 	movl   $0x42555320,0x28(%eax)
    2271:	c7 40 2c 4d 49 54 52 	movl   $0x5254494d,0x2c(%eax)
    2278:	c7 40 30 5f 4d 41 58 	movl   $0x58414d5f,0x30(%eax)
    227f:	c7 40 34 42 55 46 00 	movl   $0x465542,0x34(%eax)
    2286:	83 ec 0c             	sub    $0xc,%esp
    2289:	55                   	push   %ebp
    228a:	e8 41 ef ff ff       	call   11d0 <close@plt>
    228f:	83 c4 10             	add    $0x10,%esp
    2292:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2297:	e9 33 03 00 00       	jmp    25cf <submitr+0x68f>
    229c:	3c 5f                	cmp    $0x5f,%al
    229e:	75 7e                	jne    231e <submitr+0x3de>
    22a0:	88 07                	mov    %al,(%edi)
    22a2:	8d 7f 01             	lea    0x1(%edi),%edi
    22a5:	83 c6 01             	add    $0x1,%esi
    22a8:	8b 04 24             	mov    (%esp),%eax
    22ab:	01 e8                	add    %ebp,%eax
    22ad:	39 c6                	cmp    %eax,%esi
    22af:	0f 84 89 00 00 00    	je     233e <submitr+0x3fe>
    22b5:	0f b6 06             	movzbl (%esi),%eax
    22b8:	8d 50 d6             	lea    -0x2a(%eax),%edx
    22bb:	80 fa 0f             	cmp    $0xf,%dl
    22be:	77 dc                	ja     229c <submitr+0x35c>
    22c0:	b9 d9 ff 00 00       	mov    $0xffd9,%ecx
    22c5:	0f a3 d1             	bt     %edx,%ecx
    22c8:	72 d6                	jb     22a0 <submitr+0x360>
    22ca:	3c 5f                	cmp    $0x5f,%al
    22cc:	74 d2                	je     22a0 <submitr+0x360>
    22ce:	8d 50 e0             	lea    -0x20(%eax),%edx
    22d1:	80 fa 5f             	cmp    $0x5f,%dl
    22d4:	76 08                	jbe    22de <submitr+0x39e>
    22d6:	3c 09                	cmp    $0x9,%al
    22d8:	0f 85 f1 03 00 00    	jne    26cf <submitr+0x78f>
    22de:	83 ec 0c             	sub    $0xc,%esp
    22e1:	0f b6 c0             	movzbl %al,%eax
    22e4:	50                   	push   %eax
    22e5:	ff 74 24 28          	push   0x28(%esp)
    22e9:	6a 08                	push   $0x8
    22eb:	6a 01                	push   $0x1
    22ed:	ff 74 24 38          	push   0x38(%esp)
    22f1:	e8 fa ee ff ff       	call   11f0 <__sprintf_chk@plt>
    22f6:	0f b6 84 24 6c 80 00 	movzbl 0x806c(%esp),%eax
    22fd:	00 
    22fe:	88 07                	mov    %al,(%edi)
    2300:	0f b6 84 24 6d 80 00 	movzbl 0x806d(%esp),%eax
    2307:	00 
    2308:	88 47 01             	mov    %al,0x1(%edi)
    230b:	0f b6 84 24 6e 80 00 	movzbl 0x806e(%esp),%eax
    2312:	00 
    2313:	88 47 02             	mov    %al,0x2(%edi)
    2316:	83 c4 20             	add    $0x20,%esp
    2319:	8d 7f 03             	lea    0x3(%edi),%edi
    231c:	eb 87                	jmp    22a5 <submitr+0x365>
    231e:	89 c2                	mov    %eax,%edx
    2320:	83 e2 df             	and    $0xffffffdf,%edx
    2323:	83 ea 41             	sub    $0x41,%edx
    2326:	80 fa 19             	cmp    $0x19,%dl
    2329:	0f 86 71 ff ff ff    	jbe    22a0 <submitr+0x360>
    232f:	3c 20                	cmp    $0x20,%al
    2331:	75 9b                	jne    22ce <submitr+0x38e>
    2333:	c6 07 2b             	movb   $0x2b,(%edi)
    2336:	8d 7f 01             	lea    0x1(%edi),%edi
    2339:	e9 67 ff ff ff       	jmp    22a5 <submitr+0x365>
    233e:	8b 6c 24 14          	mov    0x14(%esp),%ebp
    2342:	8d 84 24 4c 40 00 00 	lea    0x404c(%esp),%eax
    2349:	50                   	push   %eax
    234a:	ff 74 24 10          	push   0x10(%esp)
    234e:	ff 74 24 10          	push   0x10(%esp)
    2352:	ff 74 24 10          	push   0x10(%esp)
    2356:	8d 83 1c d5 ff ff    	lea    -0x2ae4(%ebx),%eax
    235c:	50                   	push   %eax
    235d:	68 00 20 00 00       	push   $0x2000
    2362:	6a 01                	push   $0x1
    2364:	8d b4 24 68 20 00 00 	lea    0x2068(%esp),%esi
    236b:	56                   	push   %esi
    236c:	e8 7f ee ff ff       	call   11f0 <__sprintf_chk@plt>
    2371:	83 c4 14             	add    $0x14,%esp
    2374:	56                   	push   %esi
    2375:	e8 a6 ed ff ff       	call   1120 <strlen@plt>
    237a:	83 c4 10             	add    $0x10,%esp
    237d:	89 c6                	mov    %eax,%esi
    237f:	8d bc 24 4c 20 00 00 	lea    0x204c(%esp),%edi
    2386:	85 c0                	test   %eax,%eax
    2388:	0f 85 20 01 00 00    	jne    24ae <submitr+0x56e>
    238e:	89 6c 24 40          	mov    %ebp,0x40(%esp)
    2392:	c7 44 24 44 00 00 00 	movl   $0x0,0x44(%esp)
    2399:	00 
    239a:	8d 44 24 40          	lea    0x40(%esp),%eax
    239e:	8d 54 24 4c          	lea    0x4c(%esp),%edx
    23a2:	89 54 24 48          	mov    %edx,0x48(%esp)
    23a6:	8d 94 24 4c 20 00 00 	lea    0x204c(%esp),%edx
    23ad:	b9 00 20 00 00       	mov    $0x2000,%ecx
    23b2:	e8 bd fa ff ff       	call   1e74 <rio_readlineb>
    23b7:	85 c0                	test   %eax,%eax
    23b9:	0f 8e 16 01 00 00    	jle    24d5 <submitr+0x595>
    23bf:	83 ec 0c             	sub    $0xc,%esp
    23c2:	8d 84 24 58 80 00 00 	lea    0x8058(%esp),%eax
    23c9:	50                   	push   %eax
    23ca:	8d 44 24 3c          	lea    0x3c(%esp),%eax
    23ce:	50                   	push   %eax
    23cf:	8d 84 24 60 60 00 00 	lea    0x6060(%esp),%eax
    23d6:	50                   	push   %eax
    23d7:	8d 83 95 d5 ff ff    	lea    -0x2a6b(%ebx),%eax
    23dd:	50                   	push   %eax
    23de:	8d 84 24 68 20 00 00 	lea    0x2068(%esp),%eax
    23e5:	50                   	push   %eax
    23e6:	e8 55 ed ff ff       	call   1140 <__isoc99_sscanf@plt>
    23eb:	8b 44 24 4c          	mov    0x4c(%esp),%eax
    23ef:	83 c4 20             	add    $0x20,%esp
    23f2:	3d c8 00 00 00       	cmp    $0xc8,%eax
    23f7:	0f 85 52 01 00 00    	jne    254f <submitr+0x60f>
    23fd:	8d bb a6 d5 ff ff    	lea    -0x2a5a(%ebx),%edi
    2403:	8d b4 24 4c 20 00 00 	lea    0x204c(%esp),%esi
    240a:	83 ec 08             	sub    $0x8,%esp
    240d:	57                   	push   %edi
    240e:	56                   	push   %esi
    240f:	e8 2c ec ff ff       	call   1040 <strcmp@plt>
    2414:	83 c4 10             	add    $0x10,%esp
    2417:	85 c0                	test   %eax,%eax
    2419:	0f 84 63 01 00 00    	je     2582 <submitr+0x642>
    241f:	8d 44 24 40          	lea    0x40(%esp),%eax
    2423:	b9 00 20 00 00       	mov    $0x2000,%ecx
    2428:	89 f2                	mov    %esi,%edx
    242a:	e8 45 fa ff ff       	call   1e74 <rio_readlineb>
    242f:	85 c0                	test   %eax,%eax
    2431:	7f d7                	jg     240a <submitr+0x4ca>
    2433:	8b 44 24 10          	mov    0x10(%esp),%eax
    2437:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    243d:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
    2444:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
    244b:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
    2452:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
    2459:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
    2460:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
    2467:	c7 40 1c 20 68 65 61 	movl   $0x61656820,0x1c(%eax)
    246e:	c7 40 20 64 65 72 73 	movl   $0x73726564,0x20(%eax)
    2475:	c7 40 24 20 66 72 6f 	movl   $0x6f726620,0x24(%eax)
    247c:	c7 40 28 6d 20 73 65 	movl   $0x6573206d,0x28(%eax)
    2483:	c7 40 2c 72 76 65 72 	movl   $0x72657672,0x2c(%eax)
    248a:	c6 40 30 00          	movb   $0x0,0x30(%eax)
    248e:	83 ec 0c             	sub    $0xc,%esp
    2491:	55                   	push   %ebp
    2492:	e8 39 ed ff ff       	call   11d0 <close@plt>
    2497:	83 c4 10             	add    $0x10,%esp
    249a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    249f:	e9 2b 01 00 00       	jmp    25cf <submitr+0x68f>
    24a4:	01 c7                	add    %eax,%edi
    24a6:	29 c6                	sub    %eax,%esi
    24a8:	0f 84 e0 fe ff ff    	je     238e <submitr+0x44e>
    24ae:	83 ec 04             	sub    $0x4,%esp
    24b1:	56                   	push   %esi
    24b2:	57                   	push   %edi
    24b3:	55                   	push   %ebp
    24b4:	e8 77 ec ff ff       	call   1130 <write@plt>
    24b9:	83 c4 10             	add    $0x10,%esp
    24bc:	85 c0                	test   %eax,%eax
    24be:	7f e4                	jg     24a4 <submitr+0x564>
    24c0:	e8 9b ec ff ff       	call   1160 <__errno_location@plt>
    24c5:	83 38 04             	cmpl   $0x4,(%eax)
    24c8:	0f 85 9b 01 00 00    	jne    2669 <submitr+0x729>
    24ce:	b8 00 00 00 00       	mov    $0x0,%eax
    24d3:	eb cf                	jmp    24a4 <submitr+0x564>
    24d5:	8b 44 24 10          	mov    0x10(%esp),%eax
    24d9:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    24df:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
    24e6:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
    24ed:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
    24f4:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
    24fb:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
    2502:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
    2509:	c7 40 1c 20 66 69 72 	movl   $0x72696620,0x1c(%eax)
    2510:	c7 40 20 73 74 20 68 	movl   $0x68207473,0x20(%eax)
    2517:	c7 40 24 65 61 64 65 	movl   $0x65646165,0x24(%eax)
    251e:	c7 40 28 72 20 66 72 	movl   $0x72662072,0x28(%eax)
    2525:	c7 40 2c 6f 6d 20 73 	movl   $0x73206d6f,0x2c(%eax)
    252c:	c7 40 30 65 72 76 65 	movl   $0x65767265,0x30(%eax)
    2533:	66 c7 40 34 72 00    	movw   $0x72,0x34(%eax)
    2539:	83 ec 0c             	sub    $0xc,%esp
    253c:	55                   	push   %ebp
    253d:	e8 8e ec ff ff       	call   11d0 <close@plt>
    2542:	83 c4 10             	add    $0x10,%esp
    2545:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    254a:	e9 80 00 00 00       	jmp    25cf <submitr+0x68f>
    254f:	83 ec 08             	sub    $0x8,%esp
    2552:	8d 94 24 54 80 00 00 	lea    0x8054(%esp),%edx
    2559:	52                   	push   %edx
    255a:	50                   	push   %eax
    255b:	8d 83 a8 d4 ff ff    	lea    -0x2b58(%ebx),%eax
    2561:	50                   	push   %eax
    2562:	6a ff                	push   $0xffffffff
    2564:	6a 01                	push   $0x1
    2566:	ff 74 24 2c          	push   0x2c(%esp)
    256a:	e8 81 ec ff ff       	call   11f0 <__sprintf_chk@plt>
    256f:	83 c4 14             	add    $0x14,%esp
    2572:	55                   	push   %ebp
    2573:	e8 58 ec ff ff       	call   11d0 <close@plt>
    2578:	83 c4 10             	add    $0x10,%esp
    257b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2580:	eb 4d                	jmp    25cf <submitr+0x68f>
    2582:	8d 94 24 4c 20 00 00 	lea    0x204c(%esp),%edx
    2589:	8d 44 24 40          	lea    0x40(%esp),%eax
    258d:	b9 00 20 00 00       	mov    $0x2000,%ecx
    2592:	e8 dd f8 ff ff       	call   1e74 <rio_readlineb>
    2597:	85 c0                	test   %eax,%eax
    2599:	7e 53                	jle    25ee <submitr+0x6ae>
    259b:	83 ec 08             	sub    $0x8,%esp
    259e:	8d 84 24 54 20 00 00 	lea    0x2054(%esp),%eax
    25a5:	50                   	push   %eax
    25a6:	8b 7c 24 1c          	mov    0x1c(%esp),%edi
    25aa:	57                   	push   %edi
    25ab:	e8 20 eb ff ff       	call   10d0 <strcpy@plt>
    25b0:	89 2c 24             	mov    %ebp,(%esp)
    25b3:	e8 18 ec ff ff       	call   11d0 <close@plt>
    25b8:	83 c4 08             	add    $0x8,%esp
    25bb:	8d 83 a9 d5 ff ff    	lea    -0x2a57(%ebx),%eax
    25c1:	50                   	push   %eax
    25c2:	57                   	push   %edi
    25c3:	e8 78 ea ff ff       	call   1040 <strcmp@plt>
    25c8:	83 c4 10             	add    $0x10,%esp
    25cb:	f7 d8                	neg    %eax
    25cd:	19 c0                	sbb    %eax,%eax
    25cf:	8b 94 24 4c a0 00 00 	mov    0xa04c(%esp),%edx
    25d6:	65 2b 15 14 00 00 00 	sub    %gs:0x14,%edx
    25dd:	0f 85 37 01 00 00    	jne    271a <submitr+0x7da>
    25e3:	81 c4 5c a0 00 00    	add    $0xa05c,%esp
    25e9:	5b                   	pop    %ebx
    25ea:	5e                   	pop    %esi
    25eb:	5f                   	pop    %edi
    25ec:	5d                   	pop    %ebp
    25ed:	c3                   	ret    
    25ee:	8b 44 24 10          	mov    0x10(%esp),%eax
    25f2:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    25f8:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
    25ff:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
    2606:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
    260d:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
    2614:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
    261b:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
    2622:	c7 40 1c 20 73 74 61 	movl   $0x61747320,0x1c(%eax)
    2629:	c7 40 20 74 75 73 20 	movl   $0x20737574,0x20(%eax)
    2630:	c7 40 24 6d 65 73 73 	movl   $0x7373656d,0x24(%eax)
    2637:	c7 40 28 61 67 65 20 	movl   $0x20656761,0x28(%eax)
    263e:	c7 40 2c 66 72 6f 6d 	movl   $0x6d6f7266,0x2c(%eax)
    2645:	c7 40 30 20 73 65 72 	movl   $0x72657320,0x30(%eax)
    264c:	c7 40 34 76 65 72 00 	movl   $0x726576,0x34(%eax)
    2653:	83 ec 0c             	sub    $0xc,%esp
    2656:	55                   	push   %ebp
    2657:	e8 74 eb ff ff       	call   11d0 <close@plt>
    265c:	83 c4 10             	add    $0x10,%esp
    265f:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2664:	e9 66 ff ff ff       	jmp    25cf <submitr+0x68f>
    2669:	8b 44 24 10          	mov    0x10(%esp),%eax
    266d:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
    2673:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
    267a:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
    2681:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
    2688:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
    268f:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
    2696:	c7 40 18 77 72 69 74 	movl   $0x74697277,0x18(%eax)
    269d:	c7 40 1c 65 20 74 6f 	movl   $0x6f742065,0x1c(%eax)
    26a4:	c7 40 20 20 74 68 65 	movl   $0x65687420,0x20(%eax)
    26ab:	c7 40 24 20 73 65 72 	movl   $0x72657320,0x24(%eax)
    26b2:	c7 40 28 76 65 72 00 	movl   $0x726576,0x28(%eax)
    26b9:	83 ec 0c             	sub    $0xc,%esp
    26bc:	55                   	push   %ebp
    26bd:	e8 0e eb ff ff       	call   11d0 <close@plt>
    26c2:	83 c4 10             	add    $0x10,%esp
    26c5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    26ca:	e9 00 ff ff ff       	jmp    25cf <submitr+0x68f>
    26cf:	8b 6c 24 14          	mov    0x14(%esp),%ebp
    26d3:	8b 83 d8 d4 ff ff    	mov    -0x2b28(%ebx),%eax
    26d9:	8b 4c 24 10          	mov    0x10(%esp),%ecx
    26dd:	89 01                	mov    %eax,(%ecx)
    26df:	8b 83 17 d5 ff ff    	mov    -0x2ae9(%ebx),%eax
    26e5:	89 41 3f             	mov    %eax,0x3f(%ecx)
    26e8:	89 c8                	mov    %ecx,%eax
    26ea:	8d 79 04             	lea    0x4(%ecx),%edi
    26ed:	83 e7 fc             	and    $0xfffffffc,%edi
    26f0:	29 f8                	sub    %edi,%eax
    26f2:	8d b3 d8 d4 ff ff    	lea    -0x2b28(%ebx),%esi
    26f8:	29 c6                	sub    %eax,%esi
    26fa:	83 c0 43             	add    $0x43,%eax
    26fd:	c1 e8 02             	shr    $0x2,%eax
    2700:	89 c1                	mov    %eax,%ecx
    2702:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
    2704:	83 ec 0c             	sub    $0xc,%esp
    2707:	55                   	push   %ebp
    2708:	e8 c3 ea ff ff       	call   11d0 <close@plt>
    270d:	83 c4 10             	add    $0x10,%esp
    2710:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2715:	e9 b5 fe ff ff       	jmp    25cf <submitr+0x68f>
    271a:	e8 d1 02 00 00       	call   29f0 <__stack_chk_fail_local>

0000271f <init_timeout>:
    271f:	56                   	push   %esi
    2720:	53                   	push   %ebx
    2721:	83 ec 04             	sub    $0x4,%esp
    2724:	e8 17 eb ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    2729:	81 c3 3b 38 00 00    	add    $0x383b,%ebx
    272f:	8b 74 24 10          	mov    0x10(%esp),%esi
    2733:	85 f6                	test   %esi,%esi
    2735:	75 06                	jne    273d <init_timeout+0x1e>
    2737:	83 c4 04             	add    $0x4,%esp
    273a:	5b                   	pop    %ebx
    273b:	5e                   	pop    %esi
    273c:	c3                   	ret    
    273d:	83 ec 08             	sub    $0x8,%esp
    2740:	8d 83 dd be ff ff    	lea    -0x4123(%ebx),%eax
    2746:	50                   	push   %eax
    2747:	6a 0e                	push   $0xe
    2749:	e8 42 e9 ff ff       	call   1090 <signal@plt>
    274e:	85 f6                	test   %esi,%esi
    2750:	b8 00 00 00 00       	mov    $0x0,%eax
    2755:	0f 48 f0             	cmovs  %eax,%esi
    2758:	89 34 24             	mov    %esi,(%esp)
    275b:	e8 50 e9 ff ff       	call   10b0 <alarm@plt>
    2760:	83 c4 10             	add    $0x10,%esp
    2763:	eb d2                	jmp    2737 <init_timeout+0x18>

00002765 <init_driver>:
    2765:	55                   	push   %ebp
    2766:	57                   	push   %edi
    2767:	56                   	push   %esi
    2768:	53                   	push   %ebx
    2769:	83 ec 34             	sub    $0x34,%esp
    276c:	e8 cf ea ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    2771:	81 c3 f3 37 00 00    	add    $0x37f3,%ebx
    2777:	8b 7c 24 48          	mov    0x48(%esp),%edi
    277b:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    2781:	89 44 24 24          	mov    %eax,0x24(%esp)
    2785:	31 c0                	xor    %eax,%eax
    2787:	6a 01                	push   $0x1
    2789:	6a 0d                	push   $0xd
    278b:	e8 00 e9 ff ff       	call   1090 <signal@plt>
    2790:	83 c4 08             	add    $0x8,%esp
    2793:	6a 01                	push   $0x1
    2795:	6a 1d                	push   $0x1d
    2797:	e8 f4 e8 ff ff       	call   1090 <signal@plt>
    279c:	83 c4 08             	add    $0x8,%esp
    279f:	6a 01                	push   $0x1
    27a1:	6a 1d                	push   $0x1d
    27a3:	e8 e8 e8 ff ff       	call   1090 <signal@plt>
    27a8:	83 c4 0c             	add    $0xc,%esp
    27ab:	6a 00                	push   $0x0
    27ad:	6a 01                	push   $0x1
    27af:	6a 02                	push   $0x2
    27b1:	e8 ca e9 ff ff       	call   1180 <socket@plt>
    27b6:	83 c4 10             	add    $0x10,%esp
    27b9:	85 c0                	test   %eax,%eax
    27bb:	0f 88 ac 00 00 00    	js     286d <init_driver+0x108>
    27c1:	89 c6                	mov    %eax,%esi
    27c3:	83 ec 0c             	sub    $0xc,%esp
    27c6:	8d 83 ac d5 ff ff    	lea    -0x2a54(%ebx),%eax
    27cc:	50                   	push   %eax
    27cd:	e8 ce e9 ff ff       	call   11a0 <gethostbyname@plt>
    27d2:	83 c4 10             	add    $0x10,%esp
    27d5:	85 c0                	test   %eax,%eax
    27d7:	0f 84 db 00 00 00    	je     28b8 <init_driver+0x153>
    27dd:	8d 6c 24 0c          	lea    0xc(%esp),%ebp
    27e1:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
    27e8:	00 
    27e9:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
    27f0:	00 
    27f1:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
    27f8:	00 
    27f9:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%esp)
    2800:	00 
    2801:	66 c7 44 24 0c 02 00 	movw   $0x2,0xc(%esp)
    2808:	6a 0c                	push   $0xc
    280a:	ff 70 0c             	push   0xc(%eax)
    280d:	8b 40 10             	mov    0x10(%eax),%eax
    2810:	ff 30                	push   (%eax)
    2812:	8d 44 24 1c          	lea    0x1c(%esp),%eax
    2816:	50                   	push   %eax
    2817:	e8 e4 e8 ff ff       	call   1100 <__memmove_chk@plt>
    281c:	66 c7 44 24 1e 3b 6e 	movw   $0x6e3b,0x1e(%esp)
    2823:	83 c4 0c             	add    $0xc,%esp
    2826:	6a 10                	push   $0x10
    2828:	55                   	push   %ebp
    2829:	56                   	push   %esi
    282a:	e8 91 e9 ff ff       	call   11c0 <connect@plt>
    282f:	83 c4 10             	add    $0x10,%esp
    2832:	85 c0                	test   %eax,%eax
    2834:	0f 88 ea 00 00 00    	js     2924 <init_driver+0x1bf>
    283a:	83 ec 0c             	sub    $0xc,%esp
    283d:	56                   	push   %esi
    283e:	e8 8d e9 ff ff       	call   11d0 <close@plt>
    2843:	66 c7 07 4f 4b       	movw   $0x4b4f,(%edi)
    2848:	c6 47 02 00          	movb   $0x0,0x2(%edi)
    284c:	83 c4 10             	add    $0x10,%esp
    284f:	b8 00 00 00 00       	mov    $0x0,%eax
    2854:	8b 54 24 1c          	mov    0x1c(%esp),%edx
    2858:	65 2b 15 14 00 00 00 	sub    %gs:0x14,%edx
    285f:	0f 85 f0 00 00 00    	jne    2955 <init_driver+0x1f0>
    2865:	83 c4 2c             	add    $0x2c,%esp
    2868:	5b                   	pop    %ebx
    2869:	5e                   	pop    %esi
    286a:	5f                   	pop    %edi
    286b:	5d                   	pop    %ebp
    286c:	c3                   	ret    
    286d:	c7 07 45 72 72 6f    	movl   $0x6f727245,(%edi)
    2873:	c7 47 04 72 3a 20 43 	movl   $0x43203a72,0x4(%edi)
    287a:	c7 47 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%edi)
    2881:	c7 47 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%edi)
    2888:	c7 47 10 61 62 6c 65 	movl   $0x656c6261,0x10(%edi)
    288f:	c7 47 14 20 74 6f 20 	movl   $0x206f7420,0x14(%edi)
    2896:	c7 47 18 63 72 65 61 	movl   $0x61657263,0x18(%edi)
    289d:	c7 47 1c 74 65 20 73 	movl   $0x73206574,0x1c(%edi)
    28a4:	c7 47 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%edi)
    28ab:	66 c7 47 24 74 00    	movw   $0x74,0x24(%edi)
    28b1:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    28b6:	eb 9c                	jmp    2854 <init_driver+0xef>
    28b8:	c7 07 45 72 72 6f    	movl   $0x6f727245,(%edi)
    28be:	c7 47 04 72 3a 20 44 	movl   $0x44203a72,0x4(%edi)
    28c5:	c7 47 08 4e 53 20 69 	movl   $0x6920534e,0x8(%edi)
    28cc:	c7 47 0c 73 20 75 6e 	movl   $0x6e752073,0xc(%edi)
    28d3:	c7 47 10 61 62 6c 65 	movl   $0x656c6261,0x10(%edi)
    28da:	c7 47 14 20 74 6f 20 	movl   $0x206f7420,0x14(%edi)
    28e1:	c7 47 18 72 65 73 6f 	movl   $0x6f736572,0x18(%edi)
    28e8:	c7 47 1c 6c 76 65 20 	movl   $0x2065766c,0x1c(%edi)
    28ef:	c7 47 20 73 65 72 76 	movl   $0x76726573,0x20(%edi)
    28f6:	c7 47 24 65 72 20 61 	movl   $0x61207265,0x24(%edi)
    28fd:	c7 47 28 64 64 72 65 	movl   $0x65726464,0x28(%edi)
    2904:	66 c7 47 2c 73 73    	movw   $0x7373,0x2c(%edi)
    290a:	c6 47 2e 00          	movb   $0x0,0x2e(%edi)
    290e:	83 ec 0c             	sub    $0xc,%esp
    2911:	56                   	push   %esi
    2912:	e8 b9 e8 ff ff       	call   11d0 <close@plt>
    2917:	83 c4 10             	add    $0x10,%esp
    291a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    291f:	e9 30 ff ff ff       	jmp    2854 <init_driver+0xef>
    2924:	83 ec 0c             	sub    $0xc,%esp
    2927:	8d 83 ac d5 ff ff    	lea    -0x2a54(%ebx),%eax
    292d:	50                   	push   %eax
    292e:	8d 83 68 d5 ff ff    	lea    -0x2a98(%ebx),%eax
    2934:	50                   	push   %eax
    2935:	6a ff                	push   $0xffffffff
    2937:	6a 01                	push   $0x1
    2939:	57                   	push   %edi
    293a:	e8 b1 e8 ff ff       	call   11f0 <__sprintf_chk@plt>
    293f:	83 c4 14             	add    $0x14,%esp
    2942:	56                   	push   %esi
    2943:	e8 88 e8 ff ff       	call   11d0 <close@plt>
    2948:	83 c4 10             	add    $0x10,%esp
    294b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2950:	e9 ff fe ff ff       	jmp    2854 <init_driver+0xef>
    2955:	e8 96 00 00 00       	call   29f0 <__stack_chk_fail_local>

0000295a <driver_post>:
    295a:	56                   	push   %esi
    295b:	53                   	push   %ebx
    295c:	83 ec 04             	sub    $0x4,%esp
    295f:	e8 dc e8 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    2964:	81 c3 00 36 00 00    	add    $0x3600,%ebx
    296a:	8b 54 24 10          	mov    0x10(%esp),%edx
    296e:	8b 44 24 18          	mov    0x18(%esp),%eax
    2972:	8b 74 24 1c          	mov    0x1c(%esp),%esi
    2976:	85 c0                	test   %eax,%eax
    2978:	75 18                	jne    2992 <driver_post+0x38>
    297a:	85 d2                	test   %edx,%edx
    297c:	74 05                	je     2983 <driver_post+0x29>
    297e:	80 3a 00             	cmpb   $0x0,(%edx)
    2981:	75 37                	jne    29ba <driver_post+0x60>
    2983:	66 c7 06 4f 4b       	movw   $0x4b4f,(%esi)
    2988:	c6 46 02 00          	movb   $0x0,0x2(%esi)
    298c:	83 c4 04             	add    $0x4,%esp
    298f:	5b                   	pop    %ebx
    2990:	5e                   	pop    %esi
    2991:	c3                   	ret    
    2992:	83 ec 04             	sub    $0x4,%esp
    2995:	ff 74 24 18          	push   0x18(%esp)
    2999:	8d 83 ba d5 ff ff    	lea    -0x2a46(%ebx),%eax
    299f:	50                   	push   %eax
    29a0:	6a 01                	push   $0x1
    29a2:	e8 c9 e7 ff ff       	call   1170 <__printf_chk@plt>
    29a7:	66 c7 06 4f 4b       	movw   $0x4b4f,(%esi)
    29ac:	c6 46 02 00          	movb   $0x0,0x2(%esi)
    29b0:	83 c4 10             	add    $0x10,%esp
    29b3:	b8 00 00 00 00       	mov    $0x0,%eax
    29b8:	eb d2                	jmp    298c <driver_post+0x32>
    29ba:	83 ec 04             	sub    $0x4,%esp
    29bd:	56                   	push   %esi
    29be:	ff 74 24 1c          	push   0x1c(%esp)
    29c2:	8d 83 d1 d5 ff ff    	lea    -0x2a2f(%ebx),%eax
    29c8:	50                   	push   %eax
    29c9:	52                   	push   %edx
    29ca:	8d 83 d9 d5 ff ff    	lea    -0x2a27(%ebx),%eax
    29d0:	50                   	push   %eax
    29d1:	68 6e 3b 00 00       	push   $0x3b6e
    29d6:	8d 83 ac d5 ff ff    	lea    -0x2a54(%ebx),%eax
    29dc:	50                   	push   %eax
    29dd:	e8 5e f5 ff ff       	call   1f40 <submitr>
    29e2:	83 c4 20             	add    $0x20,%esp
    29e5:	eb a5                	jmp    298c <driver_post+0x32>
    29e7:	66 90                	xchg   %ax,%ax
    29e9:	66 90                	xchg   %ax,%ax
    29eb:	66 90                	xchg   %ax,%ax
    29ed:	66 90                	xchg   %ax,%ax
    29ef:	90                   	nop

000029f0 <__stack_chk_fail_local>:
    29f0:	f3 0f 1e fb          	endbr32 
    29f4:	53                   	push   %ebx
    29f5:	e8 46 e8 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    29fa:	81 c3 6a 35 00 00    	add    $0x356a,%ebx
    2a00:	83 ec 08             	sub    $0x8,%esp
    2a03:	e8 b8 e6 ff ff       	call   10c0 <__stack_chk_fail@plt>

Disassembly of section .fini:

00002a08 <_fini>:
    2a08:	f3 0f 1e fb          	endbr32 
    2a0c:	53                   	push   %ebx
    2a0d:	83 ec 08             	sub    $0x8,%esp
    2a10:	e8 2b e8 ff ff       	call   1240 <__x86.get_pc_thunk.bx>
    2a15:	81 c3 4f 35 00 00    	add    $0x354f,%ebx
    2a1b:	83 c4 08             	add    $0x8,%esp
    2a1e:	5b                   	pop    %ebx
    2a1f:	c3                   	ret    
