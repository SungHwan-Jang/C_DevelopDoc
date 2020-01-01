                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.9.0 #11195 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module test
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _printf
                                     13 	.globl _sleep
                                     14 ;--------------------------------------------------------
                                     15 ; special function registers
                                     16 ;--------------------------------------------------------
                                     17 	.area RSEG    (ABS,DATA)
      000000                         18 	.org 0x0000
                                     19 ;--------------------------------------------------------
                                     20 ; special function bits
                                     21 ;--------------------------------------------------------
                                     22 	.area RSEG    (ABS,DATA)
      000000                         23 	.org 0x0000
                                     24 ;--------------------------------------------------------
                                     25 ; overlayable register banks
                                     26 ;--------------------------------------------------------
                                     27 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         28 	.ds 8
                                     29 ;--------------------------------------------------------
                                     30 ; internal ram data
                                     31 ;--------------------------------------------------------
                                     32 	.area DSEG    (DATA)
                                     33 ;--------------------------------------------------------
                                     34 ; overlayable items in internal ram 
                                     35 ;--------------------------------------------------------
                                     36 	.area	OSEG    (OVR,DATA)
                                     37 ;--------------------------------------------------------
                                     38 ; Stack segment in internal ram 
                                     39 ;--------------------------------------------------------
                                     40 	.area	SSEG
      000040                         41 __start__stack:
      000040                         42 	.ds	1
                                     43 
                                     44 ;--------------------------------------------------------
                                     45 ; indirectly addressable internal ram data
                                     46 ;--------------------------------------------------------
                                     47 	.area ISEG    (DATA)
                                     48 ;--------------------------------------------------------
                                     49 ; absolute internal ram data
                                     50 ;--------------------------------------------------------
                                     51 	.area IABS    (ABS,DATA)
                                     52 	.area IABS    (ABS,DATA)
                                     53 ;--------------------------------------------------------
                                     54 ; bit data
                                     55 ;--------------------------------------------------------
                                     56 	.area BSEG    (BIT)
                                     57 ;--------------------------------------------------------
                                     58 ; paged external ram data
                                     59 ;--------------------------------------------------------
                                     60 	.area PSEG    (PAG,XDATA)
                                     61 ;--------------------------------------------------------
                                     62 ; external ram data
                                     63 ;--------------------------------------------------------
                                     64 	.area XSEG    (XDATA)
                                     65 ;--------------------------------------------------------
                                     66 ; absolute external ram data
                                     67 ;--------------------------------------------------------
                                     68 	.area XABS    (ABS,XDATA)
                                     69 ;--------------------------------------------------------
                                     70 ; external initialized ram data
                                     71 ;--------------------------------------------------------
                                     72 	.area XISEG   (XDATA)
                                     73 	.area HOME    (CODE)
                                     74 	.area GSINIT0 (CODE)
                                     75 	.area GSINIT1 (CODE)
                                     76 	.area GSINIT2 (CODE)
                                     77 	.area GSINIT3 (CODE)
                                     78 	.area GSINIT4 (CODE)
                                     79 	.area GSINIT5 (CODE)
                                     80 	.area GSINIT  (CODE)
                                     81 	.area GSFINAL (CODE)
                                     82 	.area CSEG    (CODE)
                                     83 ;--------------------------------------------------------
                                     84 ; interrupt vector 
                                     85 ;--------------------------------------------------------
                                     86 	.area HOME    (CODE)
      000000                         87 __interrupt_vect:
      000000 02 00 06         [24]   88 	ljmp	__sdcc_gsinit_startup
                                     89 ;--------------------------------------------------------
                                     90 ; global & static initialisations
                                     91 ;--------------------------------------------------------
                                     92 	.area HOME    (CODE)
                                     93 	.area GSINIT  (CODE)
                                     94 	.area GSFINAL (CODE)
                                     95 	.area GSINIT  (CODE)
                                     96 	.globl __sdcc_gsinit_startup
                                     97 	.globl __sdcc_program_startup
                                     98 	.globl __start__stack
                                     99 	.globl __mcs51_genXINIT
                                    100 	.globl __mcs51_genXRAMCLEAR
                                    101 	.globl __mcs51_genRAMCLEAR
                                    102 	.area GSFINAL (CODE)
      00005F 02 00 03         [24]  103 	ljmp	__sdcc_program_startup
                                    104 ;--------------------------------------------------------
                                    105 ; Home
                                    106 ;--------------------------------------------------------
                                    107 	.area HOME    (CODE)
                                    108 	.area HOME    (CODE)
      000003                        109 __sdcc_program_startup:
      000003 02 00 62         [24]  110 	ljmp	_main
                                    111 ;	return from main will return to caller
                                    112 ;--------------------------------------------------------
                                    113 ; code
                                    114 ;--------------------------------------------------------
                                    115 	.area CSEG    (CODE)
                                    116 ;------------------------------------------------------------
                                    117 ;Allocation info for local variables in function 'main'
                                    118 ;------------------------------------------------------------
                                    119 ;age                       Allocated to registers 
                                    120 ;height                    Allocated to registers 
                                    121 ;tmpName                   Allocated to registers 
                                    122 ;a                         Allocated to registers 
                                    123 ;------------------------------------------------------------
                                    124 ;	test.c:8: void main(void){
                                    125 ;	-----------------------------------------
                                    126 ;	 function main
                                    127 ;	-----------------------------------------
      000062                        128 _main:
                           000007   129 	ar7 = 0x07
                           000006   130 	ar6 = 0x06
                           000005   131 	ar5 = 0x05
                           000004   132 	ar4 = 0x04
                           000003   133 	ar3 = 0x03
                           000002   134 	ar2 = 0x02
                           000001   135 	ar1 = 0x01
                           000000   136 	ar0 = 0x00
                                    137 ;	test.c:13: char *tmpName = "JANG Sung Hwan";
                                    138 ;	test.c:16: printf("Age : %d\n", age);
      000062 74 21            [12]  139 	mov	a,#0x21
      000064 C0 E0            [24]  140 	push	acc
      000066 E4               [12]  141 	clr	a
      000067 C0 E0            [24]  142 	push	acc
      000069 74 42            [12]  143 	mov	a,#___str_1
      00006B C0 E0            [24]  144 	push	acc
      00006D 74 0A            [12]  145 	mov	a,#(___str_1 >> 8)
      00006F C0 E0            [24]  146 	push	acc
      000071 74 80            [12]  147 	mov	a,#0x80
      000073 C0 E0            [24]  148 	push	acc
      000075 12 01 30         [24]  149 	lcall	_printf
      000078 E5 81            [12]  150 	mov	a,sp
      00007A 24 FB            [12]  151 	add	a,#0xfb
      00007C F5 81            [12]  152 	mov	sp,a
                                    153 ;	test.c:17: printf("Height : %d\n", height);
      00007E 74 AD            [12]  154 	mov	a,#0xad
      000080 C0 E0            [24]  155 	push	acc
      000082 E4               [12]  156 	clr	a
      000083 C0 E0            [24]  157 	push	acc
      000085 74 4C            [12]  158 	mov	a,#___str_2
      000087 C0 E0            [24]  159 	push	acc
      000089 74 0A            [12]  160 	mov	a,#(___str_2 >> 8)
      00008B C0 E0            [24]  161 	push	acc
      00008D 74 80            [12]  162 	mov	a,#0x80
      00008F C0 E0            [24]  163 	push	acc
      000091 12 01 30         [24]  164 	lcall	_printf
      000094 E5 81            [12]  165 	mov	a,sp
      000096 24 FB            [12]  166 	add	a,#0xfb
      000098 F5 81            [12]  167 	mov	sp,a
                                    168 ;	test.c:18: printf("%s\n", tmpName);
      00009A 74 33            [12]  169 	mov	a,#___str_0
      00009C C0 E0            [24]  170 	push	acc
      00009E 74 0A            [12]  171 	mov	a,#(___str_0 >> 8)
      0000A0 C0 E0            [24]  172 	push	acc
      0000A2 74 80            [12]  173 	mov	a,#0x80
      0000A4 C0 E0            [24]  174 	push	acc
      0000A6 74 59            [12]  175 	mov	a,#___str_3
      0000A8 C0 E0            [24]  176 	push	acc
      0000AA 74 0A            [12]  177 	mov	a,#(___str_3 >> 8)
      0000AC C0 E0            [24]  178 	push	acc
      0000AE 74 80            [12]  179 	mov	a,#0x80
      0000B0 C0 E0            [24]  180 	push	acc
      0000B2 12 01 30         [24]  181 	lcall	_printf
      0000B5 E5 81            [12]  182 	mov	a,sp
      0000B7 24 FA            [12]  183 	add	a,#0xfa
      0000B9 F5 81            [12]  184 	mov	sp,a
                                    185 ;	test.c:19: printf("Age: %d Height: %d tmpName: %d char : %d\n", sizeof(age), sizeof(height), sizeof(tmpName), sizeof(a));
      0000BB 74 01            [12]  186 	mov	a,#0x01
      0000BD C0 E0            [24]  187 	push	acc
      0000BF E4               [12]  188 	clr	a
      0000C0 C0 E0            [24]  189 	push	acc
      0000C2 74 03            [12]  190 	mov	a,#0x03
      0000C4 C0 E0            [24]  191 	push	acc
      0000C6 E4               [12]  192 	clr	a
      0000C7 C0 E0            [24]  193 	push	acc
      0000C9 74 02            [12]  194 	mov	a,#0x02
      0000CB C0 E0            [24]  195 	push	acc
      0000CD E4               [12]  196 	clr	a
      0000CE C0 E0            [24]  197 	push	acc
      0000D0 74 02            [12]  198 	mov	a,#0x02
      0000D2 C0 E0            [24]  199 	push	acc
      0000D4 E4               [12]  200 	clr	a
      0000D5 C0 E0            [24]  201 	push	acc
      0000D7 74 5D            [12]  202 	mov	a,#___str_4
      0000D9 C0 E0            [24]  203 	push	acc
      0000DB 74 0A            [12]  204 	mov	a,#(___str_4 >> 8)
      0000DD C0 E0            [24]  205 	push	acc
      0000DF 74 80            [12]  206 	mov	a,#0x80
      0000E1 C0 E0            [24]  207 	push	acc
      0000E3 12 01 30         [24]  208 	lcall	_printf
      0000E6 E5 81            [12]  209 	mov	a,sp
      0000E8 24 F5            [12]  210 	add	a,#0xf5
      0000EA F5 81            [12]  211 	mov	sp,a
                                    212 ;	test.c:21: sleep(10000);
      0000EC 90 27 10         [24]  213 	mov	dptr,#0x2710
      0000EF 12 00 F8         [24]  214 	lcall	_sleep
                                    215 ;	test.c:23: sleep(10000);
      0000F2 90 27 10         [24]  216 	mov	dptr,#0x2710
                                    217 ;	test.c:27: }
      0000F5 02 00 F8         [24]  218 	ljmp	_sleep
                                    219 ;------------------------------------------------------------
                                    220 ;Allocation info for local variables in function 'sleep'
                                    221 ;------------------------------------------------------------
                                    222 ;tick                      Allocated to registers 
                                    223 ;------------------------------------------------------------
                                    224 ;	test.c:29: void sleep(int tick){
                                    225 ;	-----------------------------------------
                                    226 ;	 function sleep
                                    227 ;	-----------------------------------------
      0000F8                        228 _sleep:
      0000F8 AE 82            [24]  229 	mov	r6,dpl
      0000FA AF 83            [24]  230 	mov	r7,dph
                                    231 ;	test.c:30: while(tick){
      0000FC                        232 00101$:
      0000FC EE               [12]  233 	mov	a,r6
      0000FD 4F               [12]  234 	orl	a,r7
      0000FE 60 07            [24]  235 	jz	00104$
                                    236 ;	test.c:31: tick--;
      000100 1E               [12]  237 	dec	r6
      000101 BE FF 01         [24]  238 	cjne	r6,#0xff,00116$
      000104 1F               [12]  239 	dec	r7
      000105                        240 00116$:
      000105 80 F5            [24]  241 	sjmp	00101$
      000107                        242 00104$:
                                    243 ;	test.c:33: }
      000107 22               [24]  244 	ret
                                    245 	.area CSEG    (CODE)
                                    246 	.area CONST   (CODE)
                                    247 	.area CONST   (CODE)
      000A33                        248 ___str_0:
      000A33 4A 41 4E 47 20 53 75   249 	.ascii "JANG Sung Hwan"
             6E 67 20 48 77 61 6E
      000A41 00                     250 	.db 0x00
                                    251 	.area CSEG    (CODE)
                                    252 	.area CONST   (CODE)
      000A42                        253 ___str_1:
      000A42 41 67 65 20 3A 20 25   254 	.ascii "Age : %d"
             64
      000A4A 0A                     255 	.db 0x0a
      000A4B 00                     256 	.db 0x00
                                    257 	.area CSEG    (CODE)
                                    258 	.area CONST   (CODE)
      000A4C                        259 ___str_2:
      000A4C 48 65 69 67 68 74 20   260 	.ascii "Height : %d"
             3A 20 25 64
      000A57 0A                     261 	.db 0x0a
      000A58 00                     262 	.db 0x00
                                    263 	.area CSEG    (CODE)
                                    264 	.area CONST   (CODE)
      000A59                        265 ___str_3:
      000A59 25 73                  266 	.ascii "%s"
      000A5B 0A                     267 	.db 0x0a
      000A5C 00                     268 	.db 0x00
                                    269 	.area CSEG    (CODE)
                                    270 	.area CONST   (CODE)
      000A5D                        271 ___str_4:
      000A5D 41 67 65 3A 20 25 64   272 	.ascii "Age: %d Height: %d tmpName: %d char : %d"
             20 48 65 69 67 68 74
             3A 20 25 64 20 74 6D
             70 4E 61 6D 65 3A 20
             25 64 20 63 68 61 72
             20 3A 20 25 64
      000A85 0A                     273 	.db 0x0a
      000A86 00                     274 	.db 0x00
                                    275 	.area CSEG    (CODE)
                                    276 	.area XINIT   (CODE)
                                    277 	.area CABS    (ABS,CODE)
