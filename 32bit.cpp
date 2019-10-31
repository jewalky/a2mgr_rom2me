#include "stdafx.h"
#include <stdio.h>

void __declspec(naked) imp_32Bit_Check()
{
	__asm
	{
		cmp		[esp+0x28], esi
		jz		loc_4063C8
		pop		edi
		mov		eax, 1
		pop		esi
		add		esp, 0x34
		retn

loc_4063C8:
		mov		esi, 0x004063C8
		jmp		esi
	}
}

void __declspec(naked) imp_32Bit_DrawTile1()
{
	__asm
	{ // 4084D3
		lea		ecx, [ecx+edx*4-4]
		mov		edx, [ebp+0x10]
		mov		[ebp-0x1C], ecx
		mov		eax, 0x004084DD
		jmp		eax
	}
}

void __declspec(naked) imp_32Bit_DrawTile2()
{
	__asm
	{ // 40861C
		lea		eax, [eax+ecx*4]
		mov		[ebp-0x2C], ecx
		mov		[ebp+0x24], esi
		mov		[ebp-0x28], eax
		mov		edx, 0x00408628
		jmp		edx
	}
}

void __declspec(naked) imp_32Bit_DrawTile3()
{
	__asm
	{ // 4086D8
		mov		ax, [ebx+eax*2]
		mov		ebx, edx
		// ax = 16bit color (565)
		// expand to 32bit
		push	edx
		push	ebx
		// convert 16 to 32
		mov		edx, eax
		and		edx, 0xF800
		shl		edx, 8
		mov		ecx, eax
		and		ecx, 0x07E0
		shl		ecx, 5
		or		edx, ecx
		mov		ecx, eax
		and		ecx, 0x001F
		shl		ecx, 3
		or		edx, ecx
		or		edx, 0xFF000000
		mov		ecx, edx
		// restore state
		pop		ebx
		pop		edx
		mov		dword ptr [edi], ecx
		dec		[ebp+0x24]
		jnz		loc_4086B1
		mov		eax, 0x004086E6
		jmp		eax

loc_4086B1:
		mov		eax, 0x004086B1
		jmp		eax
	}
}

void __declspec(naked) imp_32Bit_DrawTile4()
{
	__asm
	{ // 408330
		lea		edx, [ebx+edx*4]
		mov		[ebp+0x1C], edx
		mov		edx, 0x00408344
		jmp		edx
	}
}

void __declspec(naked) imp_32Bit_DrawTile5()
{
	__asm
	{ // 4083CF
		mov		ax, [ebx+eax*2]
		push	edx
		push	ecx
		// convert 16 to 32
		mov		edx, eax
		and		eax, 0xF800
		shl		eax, 8
		mov		ebx, edx
		and		ebx, 0x07E0
		shl		ebx, 5
		or		eax, ebx
		mov		ebx, edx
		and		ebx, 0x001F
		shl		ebx, 3
		or		eax, ebx
		or		eax, 0xFF000000
		// restore state
		pop		ecx
		pop		edx
		mov		dword ptr [edi], eax
		dec		ecx
		jnz		loc_4083B4
		mov		eax, 0x004083D9
		jmp		eax

loc_4083B4:
		mov		eax, 0x004083B4
		jmp		eax
	}
}

void __declspec(naked) imp_32Bit_DrawTile6()
{
	__asm
	{ // 4083F0
		add		edx, 4
		cmp		eax, 0x20
		mov		ecx, 0x004083F6
		jmp		ecx
	}
}

void __declspec(naked) imp_32Bit_DrawLine1()
{
	__asm
	{ // 408154
		sar		ebp, 2
		imul	ebp, ebx
		mov		ebx, [esp+0x14]
		add		ebp, edi
		mov		di, [esp+0x38]
		push	eax
		push	edx
		push	ecx
		push	ebx
		// convert 16 to 32
		mov		eax, edi
		mov		edx, edi
		and		eax, 0xF800
		shl		eax, 8
		mov		ebx, edx
		and		ebx, 0x07E0
		shl		ebx, 5
		or		eax, ebx
		mov		ebx, edx
		and		ebx, 0x001F
		shl		ebx, 3
		or		eax, ebx
		or		eax, 0xFF000000
		// restore state
		pop		ebx
		pop		ecx
		pop		edx
		mov		dword ptr [ebx+ebp*4], eax
		pop		eax
		mov		edi, [esp+0x28]
		mov		ebx, esi
		push	0x0040816E
		ret
	}
}

void __declspec(naked) imp_32Bit_DrawLine2()
{
	__asm
	{ // 40822E
		mov		ebx, [esp+0x14]
		sar		ecx, 2
		imul	ecx, esi
		mov		di, [esp+0x38]
		push	eax
		push	ebx
		push	edx
		push	ecx
		// convert 16 to 32
		mov		eax, edi
		mov		edx, eax
		and		eax, 0xF800
		shl		eax, 8
		mov		ebx, edx
		and		ebx, 0x07E0
		shl		ebx, 5
		or		eax, ebx
		mov		ebx, edx
		and		ebx, 0x001F
		shl		ebx, 3
		or		eax, ebx
		or		eax, 0xFF000000
		// restore state
		pop		ecx
		pop		edx
		pop		ebx
		add		ecx, edx
		mov		dword ptr [ebx+ecx*4], eax
		pop		eax
		//
		push	0x00408242
		ret
	}
}

void __declspec(naked) imp_32Bit_DrawLine3()
{
	__asm
	{ // 4081C8
		sar		ecx, 2
		imul	ecx, esi
		mov		di, [esp+0x38]
		push	eax
		push	ebx
		push	edx
		push	ecx
		// convert 16 to 32
		mov		eax, edi
		mov		edx, edi
		and		eax, 0xF800
		shl		eax, 8
		mov		ebx, edx
		and		ebx, 0x07E0
		shl		ebx, 5
		or		eax, ebx
		mov		ebx, edx
		and		ebx, 0x001F
		shl		ebx, 3
		or		eax, ebx
		or		eax, 0xFF000000
		// restore state
		pop		ecx
		pop		edx
		pop		ebx
		add		ecx, edx
		mov		[ebx+ecx*4], eax
		pop		eax
		push	0x004081D8
		ret
	}
}

inline static void SpriteAddIXIY(int& ix, int& iy, int w, int add)
{
    int x = ix;
    int y = iy;
    for (int i = 0; i < add; i++)
    {
        x++;
        if (x >= w)
        {
            y++;
            x = x - (int)w;
        }
    }

    ix = x;
    iy = y;
}

void __stdcall Draw256(int x, int y, int w, int h, const char* sprite, unsigned short* palette, bool trans, int offset)
{
	offset = offset * h / 65535;

	unsigned char* DDTerrainBuffer = *(unsigned char**)(0x0049C7E4);
	unsigned long DDRowByteWidth = *(unsigned long*)(0x0049C7D0);
	unsigned long DDLeft = *(unsigned long*)(0x0049C5C0);
	unsigned long DDRight = *(unsigned long*)(0x0049C5C8);
	unsigned long DDTop = *(unsigned long*)(0x0049C5C4);
	unsigned long DDBottom = *(unsigned long*)(0x0049C5CC);

	if (x+w < DDLeft || y+h < DDTop) return;
	if (x > DDRight || y > DDBottom) return;

	//
	int ix = 0;
	int iy = 0;

	unsigned char* dst = DDTerrainBuffer + x*4 + DDRowByteWidth*y;

	while (ix < w && iy < h)
	{
		unsigned short ipx = *sprite++;
		ipx |= (ipx << 8);
		ipx &= 0xC03F;
		
		if (ipx & 0xC000)
		{
			if ((ipx & 0xC000) == 0x4000)
			{
				ipx &= 0x3F;
				SpriteAddIXIY(ix, iy, w, ipx*w);
			}
			else
			{
				ipx &= 0x3F;
				SpriteAddIXIY(ix, iy, w, ipx);
			}
		}
		else
		{
			ipx &= 0x3F;
			if (iy+y >= DDTop && iy+y < DDBottom)
			{
				int xoffs = x+((h-iy) * offset / h);
				unsigned long* buf = (unsigned long*)(DDTerrainBuffer+(ix+xoffs)*4+(iy+y)*DDRowByteWidth);
				for (int i = 0; i < ipx; i++)
				{
					unsigned char idx = *sprite++;
					if (ix+xoffs+i >= DDLeft && ix+xoffs+i < DDRight)
					{
						unsigned long color = (palette ? palette[idx] : 0x0000);
						unsigned long color32 = ((color & 0xF800) << 8) | ((color & 0x07E0) << 5) | ((color & 0x001F) << 3) | 0xFF000000;
						// а а2 точно делает именно так?
						// в оригинале там какая-то ссылка на палитру, которая не работает
						if (trans)
						{
							unsigned long currentcolor32 = (*buf >> 1) & 0x00FEFEFE;
							color32 = ((color32 >> 1) & 0x00FEFEFE);
							color32 = ((color32+currentcolor32) >> 1) & 0x00FEFEFE;
							// 0.25 shadows, not 0.5 (is this correct?)
							color32 = color32+currentcolor32;
						}
						*buf = color32;
					}
					buf++;
				}
			} else sprite += ipx;
			SpriteAddIXIY(ix, iy, w, ipx);
		}
	}
	
}

void __declspec(naked) imp_32Bit_Draw256()
{
	__asm
	{ // 407600, 406C80
		push	ebp
		mov		ebp, esp
		push	edi
		push	esi
		push	eax
		push	ebx
		push	ecx
		push	edx

		// call custom 
		push	0
		push	0
		push	[ebp+0x1C]
		push	[ebp+0x18]
		push	[ebp+0x14]
		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp+0x08]
		call	Draw256

		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		pop		esi
		pop		edi
		mov		esp, ebp
		pop		ebp
		retn
	}
}

void __declspec(naked) imp_32Bit_Draw256B()
{
	__asm
	{ // 407AB0, 4070F0
		push	ebp
		mov		ebp, esp
		push	edi
		push	esi
		push	eax
		push	ebx
		push	ecx
		push	edx

		// call custom 
		// тут а2 рисует полупрозрачную часть спрайта. [ebp+0x1C] это ссылка на палитру и она не работает
		/*push	0
		push	1
		push	0
		push	[ebp+0x18]
		push	[ebp+0x14]
		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp+0x08]
		call	Draw256*/

		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		pop		esi
		pop		edi
		cld
		mov		esp, ebp
		pop		ebp
		retn
	}
}

void __declspec(naked) imp_32Bit_Draw256B2()
{
	__asm
	{ // 407860, 406EC0
		push	ebp
		mov		ebp, esp
		push	edi
		push	esi
		push	eax
		push	ebx
		push	ecx
		push	edx

		// call custom 
		// тут а2 рисует полупрозрачную часть спрайта. [ebp+0x1C] это ссылка на палитру и она не работает
		/*push	0
		push	1
		push	0
		push	[ebp+0x18]
		push	[ebp+0x14]
		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp+0x08]
		call	Draw256*/

		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		pop		esi
		pop		edi
		cld
		mov		esp, ebp
		pop		ebp
		retn
	}
}

void __declspec(naked) imp_32Bit_Draw256Shadow()
{
	__asm
	{ // 407860, 406EC0
		push	ebp
		mov		ebp, esp
		push	edi
		push	esi
		push	eax
		push	ebx
		push	ecx
		push	edx

		// call custom 
		push	[ebp+0x20] // offset
		push	1 // trans
		push	0 // palette
		push	[ebp+0x18] // sprite
		push	[ebp+0x14] // h
		push	[ebp+0x10] // w
		push	[ebp+0x0C] // y
		push	[ebp+0x08] // x
		call	Draw256

		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		pop		esi
		pop		edi
		cld
		mov		esp, ebp
		pop		ebp
		retn
	}
}

void __stdcall Draw16(int x, int y, int w, int h, const char* sprite, unsigned short* palette)
{
	unsigned char* DDTerrainBuffer = *(unsigned char**)(0x0049C7E4);
	unsigned long DDRowByteWidth = *(unsigned long*)(0x0049C7D0);
	unsigned long DDLeft = *(unsigned long*)(0x0049C5C0);
	unsigned long DDRight = *(unsigned long*)(0x0049C5C8);
	unsigned long DDTop = *(unsigned long*)(0x0049C5C4);
	unsigned long DDBottom = *(unsigned long*)(0x0049C5CC);

	if (x+w < DDLeft || y+h < DDTop) return;
	if (x > DDRight || y > DDBottom) return;

	//
	int ix = 0;
	int iy = 0;

	while (ix < w && iy < h)
	{
		unsigned short ipx = *sprite++;
		ipx |= (ipx << 8);
		ipx &= 0xC03F;
		
		if (ipx & 0xC000)
		{
			if ((ipx & 0xC000) == 0x4000)
			{
				ipx &= 0x3F;
				SpriteAddIXIY(ix, iy, w, ipx*w);
			}
			else
			{
				ipx &= 0x3F;
				SpriteAddIXIY(ix, iy, w, ipx);
			}
		}
		else
		{
			ipx &= 0x3F;
			int add_pixels = ipx*2;
			int radd = 0;
			if (iy+y >= DDTop && iy+y < DDBottom)
			{
				unsigned long* buf = (unsigned long*)(DDTerrainBuffer+(ix+x)*4+(iy+y)*DDRowByteWidth);
				int ioffs = 0;
				for (int i = 0; i < ipx; i++)
				{
					unsigned char idx = *sprite++;
					unsigned char alpha1 = (idx & 0x0F) | ((idx & 0x0F) << 4);
					unsigned char alpha2 = (idx & 0xF0) | ((idx & 0xF0) >> 4);

					if (ix+ioffs+x >= DDLeft && ix+ioffs+x < DDRight && alpha1)
					{
						unsigned long color = (palette ? palette[alpha1>>4] : 0x0000);
						unsigned char cr1 = (color & 0xF800) >> 8;
						unsigned char cg1 = (color & 0x07E0) >> 3;
						unsigned char cb1 = (color & 0x001F) << 3;
						unsigned char br1 = *(unsigned char*)(buf+3);
						unsigned char bg1 = *(unsigned char*)(buf+2);
						unsigned char bb1 = *(unsigned char*)(buf+1);
						unsigned char rr1 = (cr1 * alpha1 / 256) + (br1 * (255-alpha1) / 256);
						unsigned char rg1 = (cg1 * alpha1 / 256) + (bg1 * (255-alpha1) / 256);
						unsigned char rb1 = (cb1 * alpha1 / 256) + (bb1 * (255-alpha1) / 256);
						*buf = (rr1 << 16) | (rg1 << 8) | rb1 | 0xFF000000;
					}

					ioffs++;
					buf++;
					radd++;

					if (i != ipx-1 || alpha2)
					{
						if (ix+ioffs+x >= DDLeft && ix+ioffs+x < DDRight && alpha2)
						{
							unsigned long color = (palette ? palette[alpha2>>4] : 0x0000);
							unsigned char cr1 = (color & 0xF800) >> 8;
							unsigned char cg1 = (color & 0x07E0) >> 3;
							unsigned char cb1 = (color & 0x001F) << 3;
							unsigned char br1 = *(unsigned char*)(buf+3);
							unsigned char bg1 = *(unsigned char*)(buf+2);
							unsigned char bb1 = *(unsigned char*)(buf+1);
							unsigned char rr1 = (cr1 * alpha2 / 256) + (br1 * (255-alpha2) / 256);
							unsigned char rg1 = (cg1 * alpha2 / 256) + (bg1 * (255-alpha2) / 256);
							unsigned char rb1 = (cb1 * alpha2 / 256) + (bb1 * (255-alpha2) / 256);
							*buf = (rr1 << 16) | (rg1 << 8) | rb1 | 0xFF000000;
						}

						ioffs++;
						buf++;
						radd++;
					}
				}
			} else sprite += ipx;
			SpriteAddIXIY(ix, iy, w, radd);
		}
	}
	
}

void __declspec(naked) imp_32Bit_Draw16()
{
	__asm
	{ // 406A10
		push	ebp
		mov		ebp, esp
		push	edi
		push	esi
		push	eax
		push	ebx
		push	ecx
		push	edx

		// call custom 
		push	[ebp+0x1C] // palette?
		push	[ebp+0x18] // sprite
		push	[ebp+0x14] // h
		push	[ebp+0x10] // w
		push	[ebp+0x0C] // y
		push	[ebp+0x08] // x
		call	Draw16

		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		pop		esi
		pop		edi
		cld
		mov		esp, ebp
		pop		ebp
		retn
	}
}

void __stdcall DrawMiniMap(int x, int y, int in_x, int in_y, int in_w, int in_h, unsigned short* pixels, int w, int h)
{
	unsigned char* DDTerrainBuffer = *(unsigned char**)(0x0049C7E4);
	unsigned long DDRowByteWidth = *(unsigned long*)(0x0049C7D0);
	unsigned long DDLeft = *(unsigned long*)(0x0049C5C0);
	unsigned long DDRight = *(unsigned long*)(0x0049C5C8);
	unsigned long DDTop = *(unsigned long*)(0x0049C5C4);
	unsigned long DDBottom = *(unsigned long*)(0x0049C5CC);

	if (x+in_w < DDLeft || y+in_w < DDTop) return;
	if (x > DDRight || y > DDBottom) return;

	if (x < DDLeft)
	{
		int difference = (DDLeft - x);
		x = 0;
		in_x += difference;
		in_w -= difference;
	}

	if (y < DDTop)
	{
		int difference = (DDTop - y);
		y = 0;
		in_y += difference;
		in_h -= difference;
	}

	if (x+in_w > DDRight)
	{
		in_w = (DDRight-x);
	}

	if (y+in_h > DDBottom)
	{
		in_h = (DDBottom-y);
	}

	pixels += in_y;
	for (int iy = 0; iy < in_h; iy++)
	{
		unsigned long* buf = (unsigned long*)(DDTerrainBuffer + (iy+y)*DDRowByteWidth + x*4);
		unsigned short* pixelbuf = pixels+(iy+in_y)*w+in_x;
		for (int ix = 0; ix < in_w; ix++)
		{
			if (x+ix >= DDLeft && x+ix < DDRight && in_x+ix >= 0 && in_x+ix < w)
			{
				unsigned short color = *pixelbuf;
				unsigned long color32 = ((color & 0xF800) << 8) | ((color & 0x07E0) << 5) | ((color & 0x001F) << 3) | 0xFF000000;
				*buf = color32;
			}

			pixelbuf++;
			buf++;
		}
	}
}

void __declspec(naked) imp_32Bit_DrawMiniMap()
{
	__asm
	{ // 00406510
		push	ebp
		mov		ebp, esp
		push	edi
		push	esi
		push	eax
		push	ebx
		push	ecx
		push	edx

		// call custom
		push	[ebp+0x28]
		push	[ebp+0x24]
		push	[ebp+0x20]
		push	[ebp+0x1C]
		push	[ebp+0x18]
		push	[ebp+0x14]
		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp+0x08]
		call	DrawMiniMap

		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		pop		esi
		pop		edi
		cld
		mov		esp, ebp
		pop		ebp
		retn
	}
}

void __declspec(naked) imp_32Bit_UnitPreview1()
{
	__asm
	{ // 403160
		imul	ebp, [esp+0x94]
		shl		ebp, 2
		push	0x0040316A
		ret
	}
}

void __declspec(naked) imp_32Bit_UnitPreview2()
{
	__asm
	{ // 40319A
		mov		eax, [esp+0x9C]
		mov		ecx, esi
		shl		ecx, 2
		push	0x004031A4
		ret
	}
}

void __declspec(naked) imp_32Bit_UnitPreview3()
{
	__asm
	{ // 4031BF
		mov		eax, 0xFF088263
		shr		ecx, 2
		push	0x004031C7
		ret
	}
}