/*

	Editor per oggetti poligonali complessi.
	----------------------------------------
	Strettamente personale, mi servir� per varie cose.
	I programmi di PolyVert non sono scherzi, tutt'altro che
	giocattolini, richiedono un computer che come minimo deve avere
	un Pentium: qualsiasi velocit� di clock, anche 60, ma un Pentium.
	Questo perch� tutto il livello di dettaglio si basa sul numero di
	poligoni usati: niente dettagli superficiali o effetti particolari
	di rimescolamento dei pixels, tutti sani poligoni indipendenti
	come piacciono a me.

	Elenco comandi da mouse:

		Spostamento del mouse: cambio angolazione.
		Click Sinistro + Spostamento: cambio coords. x/y origine.
		Click Destro + Spostamento: allontana / avvicina l'oggetto.

	Elenco comandi da tastiera:

		Cursore: sposta il cursore 3d su x/y.
		Ctrl+CrUp,CrDown: aumenta/diminuisce passo di griglia.
		Pag Up/Dn.: sposta il cursore 3d su z.
		Ctrl+Pag Up/Dn.: sposta l'origine su z.
		Barra spaziatrice: fissa un vertice.
		Backspace: cancella un vertice o un poligono.
		Invio: fissa un poligono.
		+: incrementa intensit� del colore.
		-: decrem. intensit� colore.
		c: riduce contrasto di colori.
		C: aumenta contrasto colori.
		l: riduce luminosit� colori.
		L: aumenta luminosit� colori.
		Shift+Invio: salva l'oggetto sul file "POLYVERT.NCC".
		Barra rovescia: sposta il cursore sul vertice pi� vicino,
				d� inoltre la possibilit� di spostare tutti
				i vertici ad esso sovrapposti tramite lo
				spostamento del cursore.
		p: porta in primopiano il poligono selezionato,
		   ovvero in fondo alla lista (viene disegnato per ultimo).
		b: porta in sfondo il poligono selezionato,
		   ovvero in cima alla lista (viene disegnato per primo).
		t: porta tutti i poligoni a tre vertici, aggiungendo quelli
		   che servono per dividere quelli a 4 vertici;
		   � utile per approssimare forme "piegate" a 4 vertici,
		   per poi poterle far tracciare al codice 3d correttamente
		   sotto forma di due poligoni a 3 vertici.
		s: seleziona il poligono pi� vicino al cursore,
		   e lo evidenzia in giallo: da ora in poi, lo si potr�
		   spostare solidalmente al cursore.
		   se un poligono � selezionato, lo deseleziona.
		punto (.): porta al cursore il colore del poligono
			   selezionato.
		duepunti (:): porta al poligono selezionato il colore
			      del cursore.
		h: da chiarire a cosa serva.
		   mi � stato utile per portare un oggetto studiato con
		   una certa origine dal punto 0;0;0 al punto in cui si
		   trovava il cursore; per questo � servito, ma se lo
		   ripeto, ovviamente, mi si risposta di crx;cry;crz
		   unit� di misura.
		o: fissa l'origine (intesa come riferimento nella
		   rotazione di comodit� dell'oggetto) sul cursore.
		q: abbandona il programma (quit). prima salvare!

	Descrizione del formato NCC:

		La sigla sta per Numero vertici, Coordinate, Colore.
		Struttura del file:

	  Inizio-> 2 bytes: n=numero di poligoni di cui � composto l'ogg.
		   n bytes: nr. vertici per ogni poligono.
		   16 * n:  coordinata x di ogni vertice. max. 4 vertici.
		   16 * n:  y (16 * n = 4 vertici * 4 bytes * n).
		   16 * n:  z.
		   n bytes: intensit� colore di ogni poligono (da 1 a 62).
	  Fine->   Eof.

*/

/*

Editor for complex polygon objects.
----------------------------------------
Strictly personal, I serve? for various things.
Programs PolyVert are not jokes, anything but
toys, require a computer which as a minimum must have
a Pentium: any speed? clock, also 60, but a Pentium.
This is because? any level of detail is based on the number of
polygons used: no surface detail or special effects
mixing of pixels, all healthy polygons independent
as I like.

List mouse commands:

Moving the mouse: change angle.
Left Click + Shift: Change coords. x / y origin.
Shift + Right Click: away / close the object.

List of keyboard commands:

Cursor: Moves the cursor 3d of x / y.
Ctrl + croup, CrDown: Increase / decrease grid spacing.
Page Up / Dn.: Moves the cursor 3d z.
Ctrl + Page Up / Dn.: Move the origin to z.
Spacebar: fixed a vertex.
Backspace: Deletes a vertex or a polygon.
Enter: fixed a polygon.
+: Increases intensity? of color.
-: Decreases. intensity? color.
c: reduces color contrast.
C: increases contrast colors.
l reduces brightness? colors.
L: increases brightness? colors.
Shift + Enter: save the object to the file "POLYVERT.NCC."
Backslash: Moves the cursor to the most? close
d? also the possibility?? to move all
the top of it overlapped with the
move the cursor.
p: port in the foreground the selected polygon,
or bottom of the list (it is designed to last).
b: port in the background polygon,
or at the top (is drawn first).
t: brings all the polygons with three vertices, adding the
that serve to divide those vertices to 4;
?? useful to approximate forms "bent" to 4 vertices,
then be able to make the code draw 3d properly
in the form of two polygons to 3 vertices.
s: select the polygon pi? next to the cursor,
and highlights it in yellow: from now on, you potr?
jointly move the cursor.
if a polygon?? selected, deselects it.
dot (.) leads to the cursor color of the polygon
selected.
colon (:): switches to the selected polygon color
of the cursor.
h: unclear what it's for.
I? was useful to bring an object studied
a certain point from the origin 0, 0, 0 to the point where it
the cursor was, why? served, but if you
I repeat, of course, I will answer crx, cry, crz
unit? measurement.
or: Set the origin (as a reference in
rotation of convenience?? object) on the cursor.
q: Quit the program (quit). first save!

Description of the format NCC:

The acronym stands for the top number, coordinates, color.
File structure:

Start-> 2 bytes: n = number of polygons that? made the OGG.
n bytes: nr. vertices for each polygon.
16 * n: x-coordinate of each vertex. max. 4 vertices.
16 * n: y (16 * n = 4 vertices * 4 bytes * n).
16 * n: z.
n bytes: intensity? color of each polygon (1 to 62).
Fine-> Eof.

*/

#define larghezza 250 //width

#include <assembly.h>
#include <tdpolygs.h>

#include <stdio.h>
#include <time.h>
#include <gfx.h>
#include <io.h>

int n = 0;
float aux;

float far *x, *y, *z;
unsigned char far *nv, *color;

void main ()
{
	int c, p, v = 0, i = 0, ink = 32;
	int fh, d = 5, psel = -1;
	int mp = -1, mv = -1;

	float rx, ry, rz, k;
	float orx = 0, ory = 0, orz = 0;
	float crx = 0, cry = 0, crz = 0;
	float pcrx = 0, pcry = 0, pcrz = 0;
	float vx[4], vy[4], vz[4], chase = 300;

	int mx2d = 160, my2d = 100;
	float dx, dy, md;

	adapted = (unsigned char far *) farmalloc (64000);

	x = (float far *) farmalloc (16000);
	y = (float far *) farmalloc (16000);
	z = (float far *) farmalloc (16000);

	nv = (unsigned char far *) farmalloc (1000);
	color = (unsigned char far *) farmalloc (1000);

	_320_200_256 ();

	initscanlines ();

	tavola_colori (range8088,   0, 64,  0, 63,  0); //color table
	tavola_colori (range8088,  64, 64, 63,  0,  0);
	tavola_colori (range8088, 128, 64, 63, 63,  0);
	tavola_colori (range8088, 192, 64,  8, 16, 63);

	fh = _open ("POLYVERT.NCC", 0);
	if (fh>-1) {
		_read (fh, &n, 2);
		_read (fh, nv, n);
		_read (fh, x, 16*n);
		_read (fh, y, 16*n);
		_read (fh, z, 16*n);
		_read (fh, color, n);
		_close (fh);
	}

	uneg = 1;

	do {
		pclear (adapted, 32);
		mpul = 0; mouse_input ();
		if (mpul) {
			if (mpul==1) {
				beta -= mdltx;
				alfa -= mdlty;
				change_angle_of_view ();
			}
			else {
				chase += mdltx;
				chase += mdlty;
				if (chase<0) chase = 0;
			}
		}
		else {
			mx2d += mdltx;
			my2d += mdlty;
			if (mx2d < 0) mx2d = 0;
			if (my2d < 0) my2d = 0;
			if (mx2d > 319) mx2d = 319;
			if (my2d > 199) my2d = 199;
		}
		cam_x = orx;
		cam_y = ory;
		cam_z = orz;
		Forward (-chase);
		for (c=0, p=0; p<n; c+=4, p++) {
			if (p!=psel)
				poly3d (x+c, y+c, z+c, nv[p], color[p]);
			else
				poly3d (x+c, y+c, z+c, nv[p], 254);
		}
		for (c=0; c<v; c++) {
			vx[0] = x[n*4+c]; vy[0] = y[n*4+c]-1; vz[0] = z[n*4+c];
			vx[1] = x[n*4+c]-1; vy[1] = y[n*4+c]; vz[1] = z[n*4+c];
			vx[2] = x[n*4+c]; vy[2] = y[n*4+c]+1; vz[2] = z[n*4+c];
			vx[3] = x[n*4+c]+1; vy[3] = y[n*4+c]; vz[3] = z[n*4+c];
			poly3d (vx, vy, vz, 4, 193 - (clock()%4) * 16);
		}
		if (mp>-1) {
			vx[0] = x[mp*4+mv]; vy[0] = y[mp*4+mv]-3; vz[0] = z[mp*4+mv];
			vx[1] = x[mp*4+mv]-3; vy[1] = y[mp*4+mv]; vz[1] = z[mp*4+mv];
			vx[2] = x[mp*4+mv]; vy[2] = y[mp*4+mv]+3; vz[2] = z[mp*4+mv];
			vx[3] = x[mp*4+mv]+3; vy[3] = y[mp*4+mv]; vz[3] = z[mp*4+mv];
			poly3d (vx, vy, vz, 4, 254 - (clock()%4) * 8);
		}
		vx[0] = crx; vy[0] = cry; vz[0] = crz;
		vx[1] = crx+10; vy[1] = cry+8; vz[1] = crz-10;
		vx[2] = crx+4; vy[2] = cry+14; vz[2] = crz-4;
		poly3d (vx, vy, vz, 3, 64+ink);
		if (tasto_premuto()) { // key pressed
			pcrx = crx;
			pcry = cry;
			pcrz = crz;
			i = attendi_pressione_tasto(); // wait for keypress
			if (i==0) {
				i = attendi_pressione_tasto();
				switch (i) {
					case 77: crx+=d; break;
					case 75: crx-=d; break;
					case 80: cry+=d; break;
					case 72: cry-=d; break;
					case 73: crz+=d; break;
					case 81: crz-=d; break;
					case 141: if (d<5) d++; break;
					case 145: if (d>1) d--; break;
					case 0x84: orz+=d; break;
					case 0x76: orz-=d; break;
				}
				i = 0;
			}
			else {
				switch (i) {
					case 'v':c = mp;
						 mp = -1;
						 mv = -1;
						 if (c>-1) break;
						 md = 1000;
						 for (c=0; c<n; c++) {
							for (p=0; p<nv[c]; p++) {
								if (getcoords (x[4*c+p], y[4*c+p], z[4*c+p])) {
									dx = mx2d - _x_;
									dy = my2d - _y_;
									dx = sqrt (dx*dx+dy*dy);
									if (dx < md) {
										md = dx;
										mp = c;
										mv = p;
									}
								}
							}
						 }
						 crx = x[4*mp+mv];
						 cry = y[4*mp+mv];
						 crz = z[4*mp+mv];
						 break;
					case 'o':orx = crx;
						 ory = cry;
						 orz = crz;
						 break;
					case 'h':for (c=0; c<n; c++) {
							for (p=0; p<nv[c]; p++) {
								x[4*c+p] += crx;
								y[4*c+p] += cry;
								z[4*c+p] += crz;
							}
						 }
						 break;
					case 'p':if (psel>-1&&psel<n-1) {
							for (p=0; p<4; p++) {
								x[4*n+p] = x[4*psel+p];
								y[4*n+p] = y[4*psel+p];
								z[4*n+p] = z[4*psel+p];
							}
							nv[n] = nv[psel];
							color[n] = color[psel];
							for (c=psel; c<n; c++) {
								for (p=0; p<4; p++) {
									asm finit; // boh? ma lo sapete che non vuol saperne di funzionare
										   // se non lo inizializzo, il coprocessore?
										   // che gli ci sia rimasto qualche flag alterato?
										   // mah. un'ora ci ho perso a cercare un errore.
										   // un errore che non c'�.
										   // dio tribudellone.
										   
										   // boh? but you know that does not want to work
										   // if not initialize, the coprocessor?
										   // that there remained some flag altered?
										   // mah. I've lost an hour to find an error.
										   // an error that c '?.
										   // tribudellone god.
									x[4*c+p] = x[4*(c+1)+p];
									y[4*c+p] = y[4*(c+1)+p];
									z[4*c+p] = z[4*(c+1)+p];
								}
								nv[c] = nv[c+1];
								color[c] = color[c+1];
							}
						 }
						 psel = n-1;
						 break;
					case 'b':if (psel>0) {
							for (p=0; p<4; p++) {
								x[4*n+p] = x[4*psel+p];
								y[4*n+p] = y[4*psel+p];
								z[4*n+p] = z[4*psel+p];
							}
							nv[n] = nv[psel];
							color[n] = color[psel];
							for (c=psel; c>0; c--) {
								for (p=0; p<4; p++) {
									x[4*c+p] = x[4*(c-1)+p];
									y[4*c+p] = y[4*(c-1)+p];
									z[4*c+p] = z[4*(c-1)+p];
								}
								nv[c] = nv[c-1];
								color[c] = color[c-1];
							}
							for (p=0; p<4; p++) {
								x[p] = x[4*n+p];
								y[p] = y[4*n+p];
								z[p] = z[4*n+p];
							}
							nv[0] = nv[n];
							color[0] = color[n];
						 }
						 psel = 0;
						 break;
					case '+':if (ink<62) ink++; break;
					case '-':if (ink>1) ink--; break;
					case 32: if (v<4) {
							 x[n*4+v] = crx;
							 y[n*4+v] = cry;
							 z[n*4+v] = crz;
							 v++;
						 }
						 break;
					case 92: c = mp;
						 mp = -1;
						 mv = -1;
						 if (c>-1) break;
						 k = 1E99;
						 for (c=0; c<n; c++) {
							for (p=0; p<nv[c]; p++) {
								rx = x[4*c+p] - crx;
								ry = y[4*c+p] - cry;
								rz = z[4*c+p] - crz;
								rx = rx*rx + ry*ry + rz*rz;
								if (rx<k) {
									k = rx;
									mp = c;
									mv = p;
								}
							}
						 }
						 crx = x[4*mp+mv];
						 cry = y[4*mp+mv];
						 crz = z[4*mp+mv];
						 break;
					case  8: if (v)
							v--;
						 else {
							 if (n) {
								if (n==psel) psel = -1;
								n--;
							 }
						 }
						 break;
					case 13: if (ctrlkeys[0]&3) {
							fh = _creat ("POLYVERT.NCC", 0);
							if (fh>-1) {
								_write (fh, &n, 2);
								_write (fh, nv, n);
								_write (fh, x, 16*n);
								_write (fh, y, 16*n);
								_write (fh, z, 16*n);
								_write (fh, color, n);
								_close (fh);
							}
						 }
						 else {
							 if (n==1000) break;
							 if (v<3) break;
							 nv[n] = v;
							 color[n] = ink;
							 v = 0;
							 n++;
						 }
						 break;
					case 'C':for (c=0; c<n; c++) {
							aux = color[c] - 32;
							aux *= 1.1;
							aux += 32;
							if (aux<1) aux = 1;
							if (aux>62) aux = 62;
							color[c] = aux;
						 }
						 break;
					case 'c':for (c=0; c<n; c++) {
							aux = color[c] - 32;
							aux *= 0.9;
							aux += 32;
							if (aux<1) aux = 1;
							if (aux>62) aux = 62;
							color[c] = aux;
						 }
						 break;
					case 'L':for (c=0; c<n; c++) {
							aux = color[c];
							aux ++;
							if (aux>62) aux = 62;
							color[c] = aux;
						 }
						 break;
					case 'l':for (c=0; c<n; c++) {
							aux = color[c];
							aux --;
							if (aux<1) aux = 1;
							color[c] = aux;
						 }
						 break;
					case 's':if (psel>-1) { psel = -1; break; }
						 k = 1E9;
						 psel = -1;
						 for (c=0; c<n; c++) {
							rx = 0; ry = 0; rz = 0;
							for (p=0; p<nv[c]; p++) {
								rx += x[4*c+p];
								ry += y[4*c+p];
								rz += z[4*c+p];
							}
							rx /= nv[c];
							ry /= nv[c];
							rz /= nv[c];
							xx = rx - crx;
							yy = ry - cry;
							zz = rz - crz;
							if (xx*xx+yy*yy+zz*zz<k) {
								k = xx*xx+yy*yy+zz*zz;
								psel = c;
							}
						 }
						 break;
					case '.':if (psel>-1) ink = color[psel];
						 break;
					case ':':if (psel>-1) color[psel] = ink;
						 break;
					case 't':for (c=0; c<n; c++) {
							if (nv[c]==4&&n<1000) {
								nv[c] = 3;
								for (p=n; p>c; p--) {
									color[p+1] = color[p];
									x[4*p+4] = x[4*p+0];
									x[4*p+5] = x[4*p+1];
									x[4*p+6] = x[4*p+2];
									x[4*p+7] = x[4*p+3];
									y[4*p+4] = y[4*p+0];
									y[4*p+5] = y[4*p+1];
									y[4*p+6] = y[4*p+2];
									y[4*p+7] = y[4*p+3];
									z[4*p+4] = z[4*p+0];
									z[4*p+5] = z[4*p+1];
									z[4*p+6] = z[4*p+2];
									z[4*p+7] = z[4*p+3];
									nv[p+1] = nv[p];
								}
								c++;
								n++;
								color[c] = color[c-1];
								x[4*c+0] = x[4*c-2];
								x[4*c+1] = x[4*c-1];
								x[4*c+2] = x[4*c-4];
								y[4*c+0] = y[4*c-2];
								y[4*c+1] = y[4*c-1];
								y[4*c+2] = y[4*c-4];
								z[4*c+0] = z[4*c-2];
								z[4*c+1] = z[4*c-1];
								z[4*c+2] = z[4*c-4];
								nv[c] = 3;
							}
						 }
						 break;
				}
			}
			if (mp>-1) {
				rx = x[4*mp+mv];
				ry = y[4*mp+mv];
				rz = z[4*mp+mv];
				x[4*mp+mv] = crx;
				y[4*mp+mv] = cry;
				z[4*mp+mv] = crz;
				if (!(ctrlkeys[0]&64)) {
					for (c=0; c<n; c++) {
						for (p=0; p<nv[c]; p++) {
							if (x[4*c+p]==rx) {
							 if (y[4*c+p]==ry) {
							  if (z[4*c+p]==rz) {
								x[4*c+p] = crx;
								y[4*c+p] = cry;
								z[4*c+p] = crz;
							  }
							 }
							}
						}
					}
				}
			}
			if (psel>-1) {
				xx = crx - pcrx;
				yy = cry - pcry;
				zz = crz - pcrz;
				for (p=0; p<nv[psel]; p++) {
					x[4*psel+p] += xx;
					y[4*psel+p] += yy;
					z[4*psel+p] += zz;
				}
			}
		}
		sprintf (temptesto, "CRH %d; %d; %d", (int)crx, (int)cry, (int)crz);
		Testo (5, 5, temptesto, 127, NORMALE); // testo == text
		sprintf (temptesto, "PLG %d;", psel);
		Testo (5, 15, temptesto, 127, NORMALE);
		if (mp>-1) {
			rx = x[4*mp+mv];
			ry = y[4*mp+mv];
			rz = z[4*mp+mv];
			k = 25;
			for (c=0; c<n; c++) {
				for (p=0; p<nv[c]; p++) {
					if (x[4*c+p]==rx) {
					 if (y[4*c+p]==ry) {
					  if (z[4*c+p]==rz) {
						sprintf (temptesto, "VTX %d OF PLG %d", p, c);
						Testo (5, k, temptesto, 127, NORMALE);
						k += 10;
					  }
					 }
					}
				}
			}
		}
		pcopy (adaptor, adapted);  //adapter
		adaptor[320*my2d + mx2d] = 0;
	} while (i!='q');

	_80_25_C ();
}
