#ifndef __ASSEMBLY_H
#define __ASSEMBLY_H

#define colore_trasparente 20

int QUADWORDS = 16000;

unsigned char far * adaptor      = (unsigned char far *) 0xA0000000;
unsigned char far * fake_adaptor = (unsigned char far *) 0;
unsigned char far * adapted      = (unsigned char far *) 0;

unsigned char far * ctrlkeys     = (unsigned char far *) 0x00000417;
unsigned char far * video_mode   = (unsigned char far *) 0x00000449;
unsigned char far * timer_ticks  = (unsigned char far *) 0x0000046C;

void _320_200_256 () // inizializza grafica a 320x200x256 colori.
//initializes graphics 320x200x256 colors.
{
	asm {
		push ax
		mov ax, 0x13
		int 0x10
		pop ax
	}
}

/*
vga_X320Y240 label word
  db      0e3h    ; dot clock
  db      10      ; Number of CRTC Registers to update
  dw      00d06h  ; vertical total
  dw      03e07h  ; overflow (bit 8 of vertical counts)
  dw      04109h  ; cell height (2 to double-scan)
  dw      0ea10h  ; v sync start
  dw      0ac11h  ; v sync end and protect cr0-cr7
  dw      0df12h  ; vertical displayed
  dw      00014h  ; turn off dword mode
  dw      0e715h  ; v blank start
  dw      00616h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      320     ; width
  dw      240     ; height

vga_X360Y200 label word
  db      0e7h    ; dot clock
  db      08      ; Number of CRTC Registers to update
  dw      06b00h  ; horz total
  dw      05901h  ; horz displayed
  dw      05a02h  ; start horz blanking
  dw      08e03h  ; end horz blanking
  dw      05e04h  ; start h sync
  dw      08a05h  ; end h sync
  dw      00014h  ; turn off dword mode
  dw      0e317h  ; turn on byte mode
  dw      360     ; width
  dw      200     ; height

vga_X360Y240 label word
  db      0e7h    ; dot clock
  db      17      ; Number of CRTC Registers to update
  dw      06b00h  ; horz total
  dw      05901h  ; horz displayed
  dw      05a02h  ; start horz blanking
  dw      08e03h  ; end horz blanking
  dw      05e04h  ; start h sync
  dw      08a05h  ; end h sync
  dw      00d06h  ; vertical total
  dw      03e07h  ; overflow (bit 8 of vertical counts)
  dw      04109h  ; cell height (2 to double-scan)
  dw      0ea10h  ; v sync start
  dw      0ac11h  ; v sync end and protect cr0-cr7
  dw      0df12h  ; vertical displayed
  dw      02d13h  ; offset
  dw      00014h  ; turn off dword mode
  dw      0e715h  ; v blank start
  dw      00616h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      360
  dw      240

vga_X376Y282 label word
  db      0e7h
  db      18
  dw      06e00h  ; horz total
  dw      05d01h  ; horz displayed
  dw      05e02h  ; start horz blanking
  dw      09103h  ; end horz blanking
  dw      06204h  ; start h sync
  dw      08f05h  ; end h sync
  dw      06206h  ; vertical total
  dw      0f007h  ; overflow
  dw      06109h  ; cell height
  dw      0310fh  ;
  dw      03710h  ; v sync start
  dw      08911h  ; v sync end and protect cr0-cr7
  dw      03312h  ; vertical displayed
  dw      02f13h  ; offset
  dw      00014h  ; turn off dword mode
  dw      03c15h  ; v blank start
  dw      05c16h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      376
  dw      282

vga_X320Y400 label word
  db      0e3h    ; dot clock
  db      03      ; Number of CRTC Registers to update
  dw      04009h  ; cell height
  dw      00014h  ; turn off dword mode
  dw      0e317h  ; turn on byte mode
  dw      320     ; width
  dw      400     ; height

vga_X320Y480 label word
  db      0e3h    ; dotclock
  db      10      ; Number of CRTC Registers to update
  dw      00d06h  ; vertical total
  dw      03e07h  ; overflow (bit 8 of vertical counts)
  dw      04009h  ; cell height (2 to double-scan)
  dw      0ea10h  ; v sync start
  dw      0ac11h  ; v sync end and protect cr0-cr7
  dw      0df12h  ; vertical displayed
  dw      00014h  ; turn off dword mode
  dw      0e715h  ; v blank start
  dw      00616h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      320     ; width
  dw      480     ; height

vga_X360Y400 label word
  db      0e7h    ; dot clock
  db      09      ; Number of CRTC Registers to update
  dw      06b00h  ; horz total
  dw      05901h  ; horz displayed
  dw      05a02h  ; start horz blanking
  dw      08e03h  ; end horz blanking
  dw      05e04h  ; start h sync
  dw      08a05h  ; end h sync
  dw      04009h  ; cell height
  dw      00014h  ; turn off dword mode
  dw      0e317h  ; turn on byte mode
  dw      360     ; width
  dw      400     ; height

vga_X360Y480  label word
  db      0e7h
  db      17
  dw      06b00h  ; horz total
  dw      05901h  ; horz displayed
  dw      05a02h  ; start horz blanking
  dw      08e03h  ; end horz blanking
  dw      05e04h  ; start h sync
  dw      08a05h  ; end h sync
  dw      00d06h  ; vertical total
  dw      03e07h  ; overflow
  dw      04009h  ; cell height
  dw      0ea10h  ; v sync start
  dw      0ac11h  ; v sync end and protect cr0-cr7
  dw      0df12h  ; vertical displayed
  dw      02d13h  ; offset
  dw      00014h  ; turn off dword mode
  dw      0e715h  ; v blank start
  dw      00616h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      360     ; width
  dw      480     ; height

vga_X360Y360  label word
  db      0e7h
  db      15
  dw      06b00h  ; horz total
  dw      05901h  ; horz displayed
  dw      05a02h  ; start horz blanking
  dw      08e03h  ; end horz blanking
  dw      05e04h  ; start h sync
  dw      08a05h  ; end h sync
  dw      04009h  ; cell height
  dw      08810h  ; v sync start
  dw      08511h  ; v sync end and protect cr0-cr7
  dw      06712h  ; vertical displayed
  dw      02d13h  ; offset
  dw      00014h  ; turn off dword mode
  dw      06d15h  ; v blank start
  dw      0ba16h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      360     ; width
  dw      360     ; height

vga_X376Y308 label word
  db      0e7h
  db      18
  dw      06e00h  ; horz total
  dw      05d01h  ; horz displayed
  dw      05e02h  ; start horz blanking
  dw      09103h  ; end horz blanking
  dw      06204h  ; start h sync
  dw      08f05h  ; end h sync
  dw      06206h  ; vertical total
  dw      00f07h  ; overflow
  dw      04009h  ;
  dw      0310fh  ;
  dw      03710h  ; v sync start
  dw      08911h  ; v sync end and protect cr0-cr7
  dw      03312h  ; vertical displayed
  dw      02f13h  ; offset
  dw      00014h  ; turn off dword mode
  dw      03c15h  ; v blank start
  dw      05c16h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      376     ; width
  dw      308     ; height

vga_X376Y564 label word
  db      0e7h
  db      18
  dw      06e00h  ; horz total
  dw      05d01h  ; horz displayed
  dw      05e02h  ; start horz blanking
  dw      09103h  ; end horz blanking
  dw      06204h  ; start h sync
  dw      08f05h  ; end h sync
  dw      06206h  ; vertical total
  dw      0f007h  ; overflow
  dw      06009h  ;
  dw      0310fh  ;
  dw      03710h  ; v sync start
  dw      08911h  ; v sync end and protect cr0-cr7
  dw      03312h  ; vertical displayed
  dw      02f13h  ; offset
  dw      00014h  ; turn off dword mode
  dw      03c15h  ; v blank start
  dw      05c16h  ; v blank end
  dw      0e317h  ; turn on byte mode
  dw      376     ; width
  dw      564     ; height
*/

/* Le seguenti tabelle sono una collezione di modalit video
   derivate dalla normale MCGA, altrimenti note come ModeX.
   Le tabelle sono pronte per essere passate alla funzione
   "tweakedVGA" per ottenere stili di visualizzazione diversi
   dallo standard MCGA, il quale sarebbe descritto come
   "Chained NTSC screen: 320x200", ma che non  incluso perch
    sufficiente aprire la normale modalit MCGA per ottenerlo...
 - Una modalit interessante  la tabella "X320Y200C4YPAL",
   che corregge il fastidioso rapporto d'aspetto "allungato"
   dovuto all'incongruenza fra gli standard PAL (256 linee)
   ed NTSC (200 linee), che rende i pixels non del tutto quadrati.
 - Per le modalit "unchained", bisogna procedere selezionando
   le bit-planes su cui operare prima di disegnare quattro o pi
   pixels consecutivi. E' opportuno quindi disegnare per colonne. */

/* The following tables are a collection of modes? video
    derived from normal MCGA, otherwise known as Modex.
    The tables are ready to be passed to the function
    "tweakedVGA" to get different visual styles
    the standard MCGA, which would be described as
    "Chained screen NTSC: 320x200", but that does not? included because?
    ?? Simply open the normal mode? MCGA to obtain ...
  - A mode? interesting? the table "X320Y200C4YPAL"
    that fixes the annoying aspect ratio "stretched"
    due to inconsistency between standards PAL (256 lines)
    and NTSC (200 lines), which makes the pixels not entirely square.
  - For mode? "unchained", you must do so by selecting
    the bit-planes to operate before drawing four or more?
    consecutive pixels. E 'therefore necessary to draw columns. */
    
unsigned X320Y200C4NNTS[5] = { /* Unchained NTSC screen: 320x200 */
	0x0001,	// Chain4 OFF
	0x00E3,	// Dot Clock
	0x0002,	// Number of CRTC Registers to update
	0x0014,	// -> turn off dword mode
	0xE317 	// -> turn on byte mode
};

unsigned X320Y200C4YPAL[4] = { /* Chained PAL screen: 320x200 */
	0x0000,	// Chain4 ON
	0x00E3,	// Dot Clock
	0x0001,	// Number of CRTC Registers to update
	0x4109 	// cell height (2 to double-scan)
};

void tweakedVGA (unsigned *regtable) // Inizializza grafica MCGA-X.
// Initialize MCGA graphics-X.
{
	// === Sequencer Registers ===

	#define Misc_Output 0x3C2
	#define Seq_Index   0x3C4
	#define CrtC_Index  0x3D4
	#define Graph_Index 0x3CE
	#define Attr_Index  0x3C0

	_BX = (unsigned) regtable;

asm {   // === Set normal Mode 13h ===
		mov     ax, 0x13
		int     0x10
		cmp	word ptr bx[0], 0		// Chain4 ON/OFF flag
		je	chain4
	// === Disable chain4 bit ===
		mov     dx, Seq_Index
		mov     al, 0x04
		out     dx, al
		inc     dx
		in      al, dx
		and     al, 11110111b
		or      al, 00000100b
		out     dx, al }
chain4:asm {	mov     ax, 0x0100
		out     dx, ax
	// === Set dot clock & scanning rate ===
		mov     dx, Misc_Output
		mov     ax, word ptr bx[2]	// Dot Clock parameter
		out     dx, al
		mov     dx, Seq_Index
		mov     ax, 0x0300
		out     dx, ax
	// === Remove write protection on various CrtC registers ===
		mov     dx, CrtC_Index
		mov     al, 0x11
		out     dx, al
		inc     dx
		in      al, dx
		and     al, 01111111b
		out     dx, al
	// === Initialize ModeX ===
		mov     dx, CrtC_Index
		mov     cx, word ptr bx[4]	// Number of entries
		mov	si, 6 }
ParamLoop:asm {	mov	ax, word ptr [bx+si]	// Load+Out index/data
		add	si, 2
		out     dx, ax
		loop    ParamLoop
	// === Set logical screenwidth ===
		mov     dx, CrtC_Index
		mov     al, 0x13
		mov     ah, 40
		out     dx,ax }
}

void initgraph (unsigned char modo) // inizializza grafica boh?.
//initializes graphics boh?.
{
	asm {
		push ax
		mov al, modo
		xor ah, ah
		int 0x10
		pop ax
	}
}

void vesa_640_480_256 () // inizializza grafica a 640x480x256 colori, vesa.
//initializes graphics 640x480x256 colors, vesa.
{
	asm {
		push ax
		mov ax, 0x69
		int 0x10
		pop ax
	}
}

void _640_480_16 () // inizializza grafica a 640x480x16 colori.
//initializes graphics 640x480x16 colors.
{
	asm {
		push ax
		mov ax, 0x12
		int 0x10
		pop ax
	}
}

/*
unsigned char VgaInfoBlock[256];
unsigned char ModeInfoBlock[256];
long 	      VRAM_granularity = 65536;
long 	      VRAM_total = 65536;
long	      VRAM_pages = 1;

char video_page_select (char videopage) // Seleziona la pagina indicata.
//Select the page indicated.
{
	asm {   mov dl, videopage
		mov ax, 0x4f05
		xor dh, dh
		mov bx, 1
		int 0x10 }

	return (_AL);
}

char openvesa (unsigned mode_code)
{
	char vesa_err = 0;

	asm {   push	es
		push	ds
		pop	es
		lea	di, VgaInfoBlock
		mov	ax, 0x4F00
		int	0x10
		pop	es
		cmp	al, 0x4F
		je 	vib_ok
		mov	vesa_err, 1 }
vib_ok: if (vesa_err) return (0);
	if ( VgaInfoBlock[0]!='V' ||
	     VgaInfoBlock[1]!='E' ||
	     VgaInfoBlock[2]!='S' ||
	     VgaInfoBlock[3]!='A' ) return (0);

	VRAM_total   = (unsigned int)VgaInfoBlock[18];
	VRAM_total <<= 16;

	asm {   push	es
		push	ds
		pop	es
		lea	di, ModeInfoBlock
		mov	cx, mode_code
		mov	ax, 0x4F01
		int	0x10
		pop	es
		cmp	al, 0x4F
		je 	mib_ok
		mov	vesa_err, 1 }
mib_ok: if (vesa_err) return (0);

	VRAM_granularity   = (unsigned int)ModeInfoBlock[4];
	VRAM_granularity <<= 10;

	asm {	mov	bx, mode_code
		mov	ax, 0x4F02
		int	0x10
		cmp	al, 0x4F
		je 	gphxok
		mov	vesa_err, 1 }
gphxok: if (vesa_err) return (0);

	switch (mode_code) {
		case 0x105: VRAM_pages = 1024L*768L; break;
		case 0x117: VRAM_pages = 2048L*768L; break;
		default:    VRAM_pages = 65536L;     break;
	}
	if (VRAM_pages > VRAM_total) VRAM_pages = VRAM_total;
	VRAM_pages /= VRAM_granularity;

	if (video_page_select(0) != 0x4F)
		return (0);
	else
		return (1);
}

void MCGA2VESA (unsigned char huge *source,
		unsigned display_x, unsigned display_y,
		unsigned physical_scanline_width,
		unsigned physical_alignment,
		unsigned logical_scanline_width,
		unsigned long framesize)
{
	unsigned long location = ((unsigned long)display_y * (unsigned long)logical_scanline_width) + display_x;

	unsigned v_align = logical_scanline_width - physical_scanline_width;
	unsigned page = location / VRAM_granularity;
	unsigned ofs = location % VRAM_granularity;
	unsigned VRG = VRAM_granularity;

	video_page_select (page);

	asm {	pusha
		pushf
		push	es
		push	ds
		cld
		les	di, adaptor
		lds	si, source
		add	di, ofs
		mov	cx, physical_scanline_width }
slcopy:	asm {	mov	al, [si]
		mov	es:[di], al
		add	si, 1
		jnc	samesg
		mov	ax, ds
		add	ax, 0x1000
		mov	ds, ax }
samesg:	asm {	add	di, 1
		jc      endpg
		cmp	VRG, 0
		je	samepg
		cmp	di, word ptr VRG
		jnb	endpg
		jmp	samepg }
endpg:	asm {   sub	di, word ptr VRG
		inc	page
		mov	dx, page
		mov	ax, 0x4F05
		mov	bx, 1
		int	0x10 }
samepg:	asm {   db 0x66; dec word ptr framesize
		jz	endfr
		dec	cx
		jnz	slcopy
		add	si, physical_alignment
		jnc	samesgV
		mov	ax, ds
		add	ax, 0x1000
		mov	ds, ax }
samesgV:asm {	add	di, v_align
		jc	endpgV
		cmp	VRG, 0
		je	samepgV
		cmp	di, word ptr VRG
		jnb	endpgV
		jmp	samepgV }
endpgV:	asm {	sub	di, word ptr VRG
		inc	page
		mov	dx, page
		mov	ax, 0x4F05
		mov	bx, 1
		int	0x10 }
samepgV:asm {	mov	cx, physical_scanline_width
		jmp	slcopy }
endfr:	asm {	pop	ds
		pop	es
		popf
		popa }
}*/

void _80_25_C () // modo grafico 80x25 testo a colori.
//graphically 80x25 color text.
{
	asm {
		push ax
		mov ax, 3
		int 0x10
		pop ax
	}
}

int attendi_pressione_tasto () // aspetta un tasto e d qual'.
//wait for keypress()
//expects a key and d? what '?.
{
	unsigned char ritorno;

	asm {
		push ax
		mov ah, 8
		int 0x21
		mov ritorno, al
		pop ax
	}

	return (ritorno);
}

int tasto_premuto () // torna 1 se c' un tasto premuto da estrarre.
//key pressed()
//returns 1 if c '? a key is pressed to extract.
{
	asm {
		push ax
		mov ah, 0xb
		int 0x21
		cmp al, 0xff
		pop ax
		jne Stop
	}

	return (1);

	Stop:
	return (0);
}

void cancella_video_grafico (unsigned char colore_da_usare) // Chiaro, no?
//delete video graphic()
// char color to be used
//Clear, no?
{
	asm {
		push es
		push si
		push cx
		mov si, 0xA000
		mov es, si
		xor si, si
		mov cl, colore_da_usare
	}
	ripeti:
	asm {
		mov byte ptr es:si, cl
		inc si
		cmp si, 64000
		jb ripeti
		pop cx
		pop si
		pop es
	}
}

void muovi_cursore (unsigned char col, unsigned char riga)
//move cursor()
{
	asm {
		push bx
		push dx
		push ax
		mov bh, 0
		mov dl, col
		mov dh, riga
		mov ah, 2
		int 0x10
		pop ax
		pop dx
		pop bx
	}
}

char temptesto[256];
//temp text[]
void messaggio (char *testo)
//message()
{
	int c;
	for (c=0; c<256; c++) {
		if (testo[c])
			temptesto[c] = testo[c];
		else
			temptesto[c] = '$';
	}

	asm {
		push ax
		push dx
		mov ah, 9
		mov dx, offset temptesto
		int 0x21
		pop dx
		pop ax
	}
}

unsigned char range8088[64*3] = {
 0,  0,  0,
 1,  1,  1,
 2,  2,  2,
 3,  3,  3,
 4,  4,  4,
 5,  5,  5,
 6,  6,  6,
 7,  7,  7,
 8,  8,  8,
 9,  9,  9,
10, 10, 10,
11, 11, 11,
12, 12, 12,
13, 13, 13,
14, 14, 14,
15, 15, 15,
16, 16, 16,
17, 17, 17,
18, 18, 18,
19, 19, 19,
20, 20, 20,
21, 21, 21,
22, 22, 22,
23, 23, 23,
24, 24, 24,
25, 25, 25,
26, 26, 26,
27, 27, 27,
28, 28, 28,
29, 29, 29,
30, 30, 30,
31, 31, 31,
32, 32, 32,
33, 33, 33,
34, 34, 34,
35, 35, 35,
36, 36, 36,
37, 37, 37,
38, 38, 38,
39, 39, 39,
40, 40, 40,
41, 41, 41,
42, 42, 42,
43, 43, 43,
44, 44, 44,
45, 45, 45,
46, 46, 46,
47, 47, 47,
48, 48, 48,
49, 49, 49,
50, 50, 50,
51, 51, 51,
52, 52, 52,
53, 53, 53,
54, 54, 54,
55, 55, 55,
56, 56, 56,
57, 57, 57,
58, 58, 58,
59, 59, 59,
60, 60, 60,
61, 61, 61,
62, 62, 62,
63, 63, 63 };

unsigned char tmppal[1024];

void tavola_colori (unsigned char *nuova_tavolozza,
		    unsigned colore_di_partenza, unsigned nr_colori,
		    char filtro_rosso, char filtro_verde, char filtro_blu)
//color tables()
// unsigned char new palette
// unsigned starting color
// unsigned no color
// char red filter
// char green filter
// char blue filter

{
	int c, cc = 0;
	unsigned temp;
	nr_colori *= 3;
	colore_di_partenza *= 3;

	c = colore_di_partenza;
	while (cc<nr_colori) {
		tmppal[c] = nuova_tavolozza[cc];
		cc++;
		c++;
	}

	c = colore_di_partenza;
	while (c<nr_colori+colore_di_partenza) {
		temp = tmppal[c];
		temp *= filtro_rosso;
		temp /= 63;
                if (temp > 63) temp = 63;
		tmppal[c] = temp;
		c++;
		temp = tmppal[c];
		temp *= filtro_verde;
		temp /= 63;
		if (temp > 63) temp = 63;
		tmppal[c] = temp;
		c++;
		temp = tmppal[c];
		temp *= filtro_blu;
		temp /= 63;
		if (temp > 63) temp = 63;
		tmppal[c] = temp;
		c++;
	}

	asm {
		push si
		push ax
		push cx
		push dx
		mov cx, colore_di_partenza
		add cx, nr_colori
		lea si, tmppal
		mov ax, seg tmppal
		mov ds, ax
		mov dx, 0x3c8
		mov al, 0
		out dx, al
		inc dx
	}
dzap:	asm {
		mov al, [si]
		out dx, al
		inc si
		loop dzap
		pop dx
		pop cx
		pop ax
		pop si
	}
}

void termina_exe ()
//exe ends
{
	asm {
		mov ah, 0x4C
		int 0x21
	}
}

int lstri (char *stri) // misura una stringa e la copia su temptesto.
// measure a string and copy temptesto.
{
	int c;

	for (c=0; c<256; c++) {
		if (stri[c])
			temptesto[c] = stri[c];
		else {
			temptesto[c] = '\0';
			return (c);
		}
	}

	return (0);
}

/* Lettura del mouse e ritorno nelle variabili indicate.
	mdltx = delta-x (in mikeys)
	mdlty = delta-y (in mikeys)
	mpul  = pulsanti premuti
		(0 = nessuno, 1 = sinistro, 2 = destro, 3 = entrambi)
		(mpul dev'essere azzerata prima di chiamare "mouse_input"
		se  necessario che la variabile non "ricordi" l'ultima
		lettura del mouse, perch a volte questo fatto serve)
	mx;my = posizione attuale del cursore: di per s non ha limiti
		e per cui, se la si vuole limitare, lo si deve fare
		dal programma principale.  espressa in mickeys.
		(mx, my, mdltx ed mdlty possono anche assumere valori
		negativi, e sono dichiarate come interi a 16 bit) */

/* Reading the mouse and return in the specified variable.
	mdltx = delta-x (in mikeys)
	mdlty = delta-y (in mikeys)
	mpul = button presses
		(0 = none, 1 = left, 2 = right, 3 = both)
		(mpul must be cleared before calling "mouse_input"
		if? necessary that the variable does not "remember" the last
		reading of the mouse, why? sometimes this is done)
mx, my = current cursor position is: in s? has no limits
		and so, if you want to limit, it must be done
		the main program. ?? expressed in mickeys.
		(mx, my, and mdltx mdlty can also take values
		negative, and are declared as 16-bit) */

int mdltx = 0, mdlty = 0, mx = 0, my = 0, mpul = 0;

void mouse_input ()
{
	asm {
		push ax
		push bx
		push cx
		push dx
		mov ax, 0xb
		int 0x33
		push cx
		push dx
		mov ax, 5
		int 0x33
		pop dx
		pop cx
		mov mdltx, cx
		mov mdlty, dx
		add mx, cx
		add my, dx
		cmp ax, 0
		je  non_imp
		mov mpul, ax
	}
non_imp:asm {
		pop dx
		pop cx
		pop bx
		pop ax
	}
}

// Verifica della presenza del mouse (o del supporto per esso).
// Ed inizializzazione del driver (svuotamento del buffer dei movimenti).

// Check the presence of the mouse (or support for it).
// And initialization of the driver (buffer underrun movements).

char test_and_init_mouse ()
{
	asm {
		xor ax, ax
		int 33h
		cmp ax, 0
		jne ok
	}

	return (0);

ok:	asm {
		pusha
		mov ax, 0xb
		int 0x33
		mov ax, 5
		int 0x33
		popa
	}

	return (1);
}

// Accensione/variazione del bleeper.
// Power on / change the bleeper.
unsigned ufrq;

void snd (unsigned frq)
{
	ufrq = frq;

	asm {
		push dx
		push ax
		push bx
		mov bx, frq
		mov dx, 12h
		mov ax, 34ddh
		div bx
		mov bx, ax
		in al, 61h
		test al, 3
		jne neq
		or al, 3
		out 61h, al
		mov al, 0b6h
		out 43h, al
	}
neq:    asm {
		mov al, bl
		out 42h, al
		mov al, bh
		out 42h, al
		pop bx
		pop ax
		pop dx
	}
}

// Spegnimento del bleeper.
// Turning off the bleeper.

void nsnd ()
{
	asm {
		push ax
		in al, 61h
		and al, 0fch
		out 61h, al
		pop ax
	}
}

// Ultraveloce copia di pagina grafica.
// Ultra-page copy graphics.
// Ultra fast page copy graphics.

void pcopy (unsigned char far *dest, unsigned char far *sorg)
{
	asm {
		push ds
		push es
		mov cx, QUADWORDS
		lds si, dword ptr sorg
		les di, dword ptr dest
		db 0xf3 // macro: rep movsd
		db 0x66
		db 0xa5
		pop es
		pop ds
	}
}

// Copia reciproca (scambia due pagine).
// Copy to each other (exchange two pages).
void pswap (unsigned char far *dest, unsigned char far *sorg)
{
	asm {	push ds
		push es
		mov cx, QUADWORDS
		lds si, dword ptr sorg
		les di, dword ptr dest }
swap:	asm {	db 0x66; mov ax, [si]
		db 0x66; mov bx, es:[di]
		db 0x66; mov es:[di], ax
		db 0x66; mov [si], bx
		add si, 4
		add di, 4
		dec cx
		jnz swap
		pop es
		pop ds }
}

// Copia un'area rettangolare.
// Esegue tutti i clipping necessari per l'MCGA.
// O si specificano X2 ed Y2, o si specificano L ed H:
// in ogni modo, i valori non usati vanno lasciati a zero.

// Copy a rectangular area.
// Execute all clipping required for MCGA.
// Or specify X2 and Y2, or specify L and H:
// In any way, the values ​​are not used they should be left at zero.

void areacopy (unsigned char far *dest, unsigned char far *sorg,
	       int x, int y, int x2, int y2, int l, int h)
{
	unsigned p;

	if (x<0) x = 0;
	if (y<0) y = 0;

	if (x2>=320) x2 = 319;
	if (y2>=200) y2 = 199;

	if (x2>0) l = x2 - x;
	if (y2>0) h = y2 - y;

	if (x+l>=320) l = 320 - x;
	if (y+h>=200) h = 200 - y;

	if (l<1 || h<1) return;

	p = 320 * y + x;

	asm {	push ds
		push es
		pusha
		pushf
		cld
		lds si, dword ptr sorg
		les di, dword ptr dest
		add si, p
		add di, p }
ac_nextl: asm {	push si
		push di
		mov cx, l
		shr cx, 2
		jcxz ac_bytes
		db 0xf3 // rep movsd
		db 0x66
		db 0xa5 }
ac_bytes: asm { mov cx, l
		and cx, 3
		jcxz ac_endl
		rep movsb }
ac_endl:  asm { pop di
		pop si
		add si, 320
		add di, 320
		dec h
		jnz ac_nextl
		popf
		popa
		pop es
		pop ds }
}

// Ultraveloce cancella pagina grafica.
// Ultra clear graphics page.
// Ultra fast deletes page graphics.

void pclear (unsigned char far *target, unsigned char pattern)
{
	asm {
		push di
		push es
		push cx
		push ax
		les di, dword ptr target
		mov cx, QUADWORDS
		mov al, pattern
		mov ah, pattern
		db 0x66 // macro: shl eax, 16
		db 0xc1
		db 0xe0
		db 0x10
		mov al, pattern
		mov ah, pattern
		db 0xf3 // macro: rep stosd
		db 0x66
		db 0xab
		pop ax
		pop cx
		pop es
		pop di
	}
}

// Cancella un'area rettangolare.
// Esegue tutti i clipping necessari per l'MCGA.
// O si specificano X2 ed Y2, o si specificano L ed H:
// in ogni modo, i valori non usati vanno lasciati a zero.

// Clear a rectangular area.
// Execute all clipping required for MCGA.
// Or specify X2 and Y2, or specify L and H:
// In any way, the values ​​are not used they should be left at zero.

void areaclear (unsigned char far *dest, int x, int y,
		int x2, int y2, int l, int h, unsigned char pattern)
{
	unsigned p;

	if (x<0) x = 0;
	if (y<0) y = 0;

	if (x2>=320) x2 = 319;
	if (y2>=200) y2 = 199;

	if (x2>0) l = x2 - x;
	if (y2>0) h = y2 - y;

	if (x+l>=320) l = 320 - x;
	if (y+h>=200) h = 200 - y;

	if (l<1 || h<1) return;

	p = 320 * y + x;

	asm {	push es
		pusha
		pushf
		cld
		les di, dword ptr dest
		add di, p
		mov al, pattern
		db 0x66; shl ax, 8
		mov al, pattern
		db 0x66; shl ax, 8
		mov al, pattern
		db 0x66; shl ax, 8
		mov al, pattern }
ac_nextl: asm {	push di
		mov cx, l
		shr cx, 2
		jcxz ac_bytes
		db 0xf3 // rep stosd
		db 0x66
		db 0xab }
ac_bytes: asm { mov cx, l
		and cx, 3
		jcxz ac_endl
		rep stosb }
ac_endl:  asm { pop di
		add di, 320
		dec h
		jnz ac_nextl
		popf
		popa
		pop es }
}

/*

	Altro gioiellino: smussa lo schermo, attenuando il contrasto dei
	bordi con un procedimento di media su 4 x 4 pixels.
	Occhio al trucco: normalmente ci sarebbero 16 addizioni e una
	divisione (per 16) da fare, per ogni punto.
	Col trucco, invece, bastano quattro addizioni a 32 bit,
	altre quattro a 8 bit, pi un paio di shifts ed un and logico su edx.

	Normale: 16 + 42 = 58 cicli.
	Truccato: 8 + 4 = 12 cicli.

	Piuttosto ovvio: la tavola dei colori dev'essere una sfumatura unica
	e compatta, da far rientrare nei primi 64 registri del video DAC;
	il colore zero  il pi tenue, il 63 quello pi brillante.

	Nota: la procedura pu essere reiterata per ottenere
	      una maggiore attenuazione.

*/

/*
Another gem: it blunts the screen, reducing the contrast of
edges with a procedure average of 4 x 4 pixels.
Eye makeup: normally there would be 16 additions and
division (for 16) to make, for each point.
Col trick, instead, just four additions to 32 bits,
four other 8-bit, more? a couple of shifts and a bitwise of edx.

Normal: 16 + 42 = 58 cycles.
Rigged: 8 + 4 = 12 cycles.

Pretty obvious: the color table must be a gradient only
and compact, to include in the first 64 registers of the video DAC;
the color zero? the most? small intestine, more than 63? brilliant.

Note: The procedure can? be repeated to obtain
a greater attenuation.
*/

void psmooth_grays (unsigned char far *target)
{
	asm {
		pusha
		push es
		mov cx, QUADWORDS
		shl cx, 2
		mov ax, 320
		shl ax, 2
		sub cx, ax
		les di, dword ptr target
		add di, 320
	}
smooth: asm {	db 0x66; mov dx, es:[di-320]
		db 0x66; add dx, es:[di]
		db 0x66; add dx, es:[di+320]
		db 0x66; add dx, es:[di+640]
		/* and edx, 11111100111111001111110011111100b */
		db 0x66, 0x81, 0xE2, 0xFC, 0xFC, 0xFC, 0xFC
		db 0x66; shr dx, 2
		mov al, dl
		add al, dh
		db 0x66; shr dx, 16
		add al, dl
		add al, dh
		shr al, 2
		mov es:[di], al
		inc di
		dec cx
		jnz smooth
		pop es
		popa
	}
}

/*

	Versione a colori della precedente: 64 livelli in 4 sfumature.
	I primi 2 bits (pi significativi) di ogni punto video selezionano
	il colore da usare, mentre gli altri 6 l'intensit della tinta.
	Pu essere anche usata con la sfumatura dei primi 64 colori
	come "psmooth_grays", ma in genere  pi leggera di quest'ultima,
	in quanto la media  applicata su cella 2 x 2.
	Ah, non si pu fare su adaptor, cos com': il segmento deve avere
	offset pari a 4, come quelli di tipo far o huge allocati dal c.

	Il segshift serve per spostare di qualche paragrafo pi avanti la
	zona su cui operare, ed assieme alla normale variabile QUADWORDS
	pu definire con precisione l'area ove operare.

	Una cosa interessante: per aumentare la velocit ho fatto il ciclo
	al contrario, ma mi sono dimenticato di correggere l'eleborazione
	della media. Se si vuole correggere perch sia normale, basta
	aumentare incondizionatamente il segshift nella prima parte della
	funzione con l'istruzione "add segshift, 20" e poi mettere al posto
	dell'istruzione:

		mov bx, [di+324]

	quest'altra:

		mov bx, [di-324].

	Perch non l'ho fatto? Perch cos due punti su quattro, per ogni
	ciclo, subiscono una doppia media (1 x 2 + 2 x 2), lasciando un
	suggestivo "effetto aura".

*/

/*
Color version of the above: 64 levels in 4 shades.
The first 2 bits (pi? Significant) of each point selected video
the color to be used, while the other 6 the intensity? the color.
Pu? also be used with the gradient of the first 64 colors
as "psmooth_grays", but in general? more? Light of the latter,
since the average? applied on cell 2 x 2.
Ah, you can not? do on adapter, so? com '?: the segment must have
offset of 4, such as the type to huge or allocated by c.

The segshift need to move more than a few paragraphs? forward
area on which to operate, and with normal variable QUADWORDS
can? accurately define the area in which to operate.

One interesting thing: to increase the speed? I did the cycle
on the contrary, but I forgot to correct the elaboration
average. If you want to correct why? is normal, just
increase unconditionally segshift the first part of
function with the instruction "add segshift, 20" and then put in place
education:

mov bx, [to +324]

this one:

mov bx, [by-324].

Why? I did not? Why? so? two points on four, for each
cycle, undergo a double Average (1 x 2 + 2 x 2), leaving a
suggestive "aura effect".
*/

void psmooth_64levels (unsigned char far *target, unsigned segshift)
{
	asm {   pusha
		push ds
		mov di, QUADWORDS
		sub di, 80
		shl di, 2
		lds ax, dword ptr target
		mov ax, ds
		add ax, segshift
		mov ds, ax }
smooth: asm {   mov bx, [di+324]
		mov dx, [di+4]
		and bx, 0011111100111111b
		mov al, dl
		and dx, 0011111100111111b
		add bl, bh
		add dl, dh
		and al, 11000000b
		add dl, bl
		shr dl, 2
		or  dl, al
		dec di
		mov [di+5], dl
		jnz smooth
		pop ds
		popa }
}

// Versione normale della precedente: a volte serve liscia.
// Normal version of the above: you need to actually smooth.

void forward_psmooth_64levels (unsigned char far *target, unsigned segshift)
{
	asm {   pusha
		push ds
		mov cx, QUADWORDS
		sub cx, 80
		shl cx, 2
		lds ax, dword ptr target
		mov ax, ds
		add ax, segshift
		mov ds, ax
		xor di, di }
smooth: asm {   mov bx, [di+324] // Non accoppiabili.
		mov dx, [di+4]   //
		and bx, 0011111100111111b
		and dx, 0011111100111111b
		add bl, bh
		add dl, dh
		and byte ptr [di+4], 11000000b
		add dl, bl
		shr dl, 2	 // Non accoppiabili.
		or [di+4], dl    //
		inc di
		dec cx
		jnz smooth
		pop ds
		popa }
}

void psmooth_6444 (unsigned char far *target, unsigned segshift)
{
	asm {   pusha
		push ds
		mov cx, QUADWORDS
		sub cx, 80
		shl cx, 2
		lds ax, dword ptr target
		mov ax, ds
		add ax, segshift
		mov ds, ax
		xor di, di }
smooth: asm {   db 0x66; mov bx, [di+4]
		/* and ebx, 00111111001111110011111100111111b */
		db 0x66, 0x81, 0xE3, 0x3F, 0x3F, 0x3F, 0x3F
		add bl, bh
		inc di
		mov al, bl
		db 0x66; shr bx, 16
		add bl, bh
		add al, bl
		and byte ptr [di+3], 11000000b
		shr al, 2
		mov bl, byte ptr [di+323]
		and bl, 0x3f
		add al, bl
		mov bl, byte ptr [di+643]
		and bl, 0x3f
		add al, bl
		mov bl, byte ptr [di+963]
		and bl, 0x3f
		add al, bl
		shr al, 2
		or [di+3], al
		dec cx
		jnz smooth
		pop ds
		popa }
}

void mask_pixels (unsigned char far *target, unsigned char mask)
{
	asm {   pusha
		push ds
		mov bl, mask
		mov bh, mask
		db 0x66; shl bx, 16
		mov bl, mask
		mov bh, mask
		mov ax, 0x3F3F
		db 0x66; shl ax, 16
		mov ax, 0x3F3F
		mov cx, QUADWORDS
		lds di, target }
mloop:  asm {	db 0x66; and word ptr [di], ax
		db 0x66; add word ptr [di], bx
		add di, 4
		dec cx
		jnz mloop
		pop ds
		popa }
}

// Indirizzo del psp.
// Address psp.

unsigned char far *pspa;

unsigned char far *psp ()
{
	asm {
		push ax
		push bx
		mov ah, 0x62
		int 0x21
		mov ax, bx
		lea bx, pspa
		mov [bx+2], ax
		xor ax, ax
		mov [bx], ax
		pop bx
		pop ax
	}

	return (pspa);
}

/* Ritorna lo stato completo della tastiera: tasto in ingresso, esteso o
   normale (ingresso anche asincrono), pi il byte di stato per i tasti
   di controllo dislocato a ctrlkeys[0].
   La funzione azzera anche qualsiasi altro tentativo d'intercettare i tasti,
   perch svuota il buffer di tastiera.
   Lo scancode hardware tradotto  relativo al tasto che SI STA PREMENDO.
   Tuttavia, questa funzione non permette di eliminare l'ottusit nel bios
   di non consentire la ripresa dei tasti quando non sono rilasciati:
   ad esempio, se si preme left cr e, tenendolo premuto, si preme up cr,
   si otterr immediatamente la registrazione del tasto up cr ma, quando si
   rilascier solo up cr, non si potr ottenere di nuovo la registrazione
   della pressione di left cr se prima non si rilascer anche questo.
   Se, per esempio ad un platform, serve anche la ripresa di questi tasti,
   si dovr intercettare l'int 9 generata dal microprocessorino della
   tastiera, ovvero l'i8084, per rimpiazzare l'interrupt bios che infila
   i tasti nel buffer di tastiera. Purtroppo, questo comporta che il bios
   non tradurr gli scancode hardware, che continueranno ad esser tali
   e dovranno essere opportunamente interpretati (non saranno pi gli ascii
   normali o estesi, in soldoni). Di questo, comunque, si occupano le
   funzioni seguenti a questa. */

/*
Returns the complete state of the keyboard key input, extended, or
normal (input also asynchronous) pi? the status byte for the keys
control displaced to ctrlkeys [0].
The function also clears any attempt to intercept the keys,
why? clears the keyboard buffer.
The hardware scancode translated? relative to the button that you press.
However, this function does not remove the ottusit? in bios
not to allow the resumption of keys when they are released:
For example, if you press left and cr, holding it down, press up cr
you will get? immediately the registration button up cr but when
rilascier?? only up cr, not potr?? get back the recording
pressure cr left before they will release it? that too.
If, for example, to a platform, also serves the recovery of these keys,
you will have? intercept the int 9 generated by the microprocessorino
keyboard, or the i8084, to replace the bios interrupt that puts
keys in the keyboard buffer. Unfortunately, this implies that the bios
not tradurr?? the hardware scancode, which will continue to be such
and must be appropriately interpreted (will not be pi?'s ascii
normal or extended, in a nutshell). This, however, deal with the
following functions to this.
*/

unsigned char scancode = 0, extended_scancode = 0, status_byte = 0;
unsigned char hardware_scancode = 0;

void stato_tastiera ()
//keyboard status()
{
	scancode = 0;
	extended_scancode = 0;

	asm {
		push es
		push ax
		push bx
		push si
		mov ax, 0x40
		mov es, ax
		mov bx, 0x17
		mov al, es:[bx]
		mov status_byte, al
		mov bx, 0x1A
		mov ax, es:[bx]
		mov si, ax
		mov ax, es:[si]
		mov scancode, al
		mov extended_scancode, ah
		mov ax, es:[0x1E]
		mov hardware_scancode, al
		xor ax, ax
		mov es:[si], ax
		mov ax, es:[0x1A]
		mov es:[0x1C], ax
		pop si
		pop bx
		pop ax
		pop es
	}
}

// Non  una funzione: non chiamare,  solo un buffer sul segmento di codice.
// Not? a function: do not call,? only a buffer on the code segment.
void key_status_marker ()
{
	asm {
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
		dd 0x80808080
	}
};

// Viene sostituita alla normale ruotine d'intercettazione dei tasti.
// Replaced the normal wheels-off of the keys.

void int9_control ()
{
	asm {
		pushf
		push cx
		push bx
		push ax
		push es
		mov ax, 0x40
		mov es, ax
		in al, 0x60
		mov ah, al
		mov cl, al
		and ah, 0x80
		and cl, 0x7F
		xor ch, ch
		mov bx, offset key_status_marker
		add bx, cx
		mov cs:[bx], ah
		mov es:[0x1E], ax
		in al, 0x61
		mov ah, al
		or al, 0x80
		out 0x61, al
		mov al, ah
		out 0x61, al
		mov al, 0x20
		out 0x20, al
		pop es
		pop ax
		pop bx
		pop cx
		popf
		iret
	}
}

#define CATCH	0
#define RELEASE 1

unsigned int9_segment;
unsigned int9_offset;

// chiamare con CATCH per inziare il controllo, con RELEASE per terminarlo.
// call to CATCH it, then start checking with RELEASE to finish.

void int9_manager (char work)
{
	asm {
		cmp work, CATCH
		je _catch
		cmp work, RELEASE
		je release
		jmp _ret
	}
_catch: asm {
		push ax
		push es
		xor ax, ax
		mov es, ax
		mov ax, es:[0x24]
		mov int9_offset, ax
		mov ax, es:[0x26]
		mov int9_segment, ax
		mov ax, offset int9_control
		mov es:[0x24], ax
		mov ax, cs
		mov es:[0x26], ax
		pop es
		pop ax
		jmp _ret
	}
release:asm {
		push ax
		push es
		xor ax, ax
		mov es, ax
		mov ax, int9_offset
		mov es:[0x24], ax
		mov ax, int9_segment
		mov es:[0x26], ax
		pop es
		pop ax
		jmp _ret
	}
_ret:
}

// Indica se il tasto "SCANCODE"  attualmente ABBASSATO.
// Indicates whether the "scancode"? currently DOWN.

char keyhold (unsigned scancode)
{
	char retval = 1;

	asm {
		mov bx, offset key_status_marker
		add bx, scancode
		mov al, cs:[bx]
		cmp al, 0
		je premuto
		mov retval, 0
	}

	premuto:
	return (retval);
}

/*

	Attiva o disattiva il ctrl-break via DOS.
	Enable or disable the ctrl-break via DOS.

*/

void ctrl_break (char on_off)
{
	asm {
		pusha
		mov ax, 0x3301
		mov dl, on_off
		int 0x21
		popa
	}
}

void varia_cursore (char prima_scanline, char ultima_scanline)
//varies cursore()
// char first scanline
// char last scanline
{
	asm {
		mov ah, 1
		xor bh, bh
		mov ch, prima_scanline
		mov cl, ultima_scanline
		int 0x10
	}
}

#endif
