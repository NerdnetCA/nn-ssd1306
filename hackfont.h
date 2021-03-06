/** hackfont.h
 * by NerdnetCA
 * 
 * 16 pixel font for ssd1306.
 * This was made by rendering Hack into 127 small bitmaps.
 * The bitmaps are oriented for convenience in rendering to the
 * vertically-oriented bytes of the display.
 * 
 * There is a lot of free space in the low bytes for custom glyphs.
 * 
 */

#ifndef HACKFONT_H
#define HACKFONT_H

#define GLYPHWIDTH      10


static const DATAMEM uint8_t font_data[][20] = {
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xfe, 0x1d, 0xfe, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x3, 0x30, 0x1b, 0xf0, 0x1f, 0xfc, 0x3, 0x3e, 0x13, 0x32, 0x1f, 0xf8, 0x7, 0x7e, 0x3, 0x32, 0x3, 0x30, 0x0},
    {0x0, 0x0, 0x70, 0xc, 0xf8, 0x8, 0xc8, 0x18, 0xfe, 0x7f, 0xce, 0x79, 0x88, 0x1f, 0x98, 0xf, 0x0, 0x2, 0x0, 0x0},
    {0x18, 0x2, 0x7c, 0x1, 0x66, 0x1, 0xe6, 0x1, 0xbc, 0x0, 0x80, 0xe, 0x40, 0x1b, 0x40, 0x1b, 0x20, 0x1f, 0x0, 0x4},
    {0x0, 0x7, 0x80, 0xf, 0xfc, 0x1c, 0x7e, 0x18, 0xe6, 0x19, 0x86, 0x1b, 0x6, 0xf, 0x0, 0x1e, 0x80, 0x1f, 0x0, 0x10},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0xc0, 0x3, 0xf8, 0x1f, 0x3e, 0x7e, 0x6, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x40, 0xe, 0x70, 0xfc, 0x3f, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x30, 0x0, 0x20, 0x3, 0xe0, 0x1, 0xfc, 0x0, 0xf0, 0x0, 0xa0, 0x3, 0x20, 0x2, 0x30, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0xf8, 0xf, 0xf8, 0xf, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0xb8, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x1c, 0x0, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x20, 0x0, 0x38, 0x0, 0xf, 0xc0, 0x3, 0xf0, 0x0, 0x3c, 0x0, 0xe, 0x0, 0x2, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xf8, 0x7, 0xfc, 0xf, 0xe, 0x1c, 0xe6, 0x19, 0x6, 0x18, 0xfe, 0x1f, 0xfc, 0xf, 0xe0, 0x1, 0x0, 0x0},
    {0x0, 0x0, 0x10, 0x18, 0x38, 0x18, 0xc, 0x18, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x0},
    {0x0, 0x0, 0xc, 0x1c, 0x6, 0x1e, 0x6, 0x1f, 0x86, 0x1b, 0xc6, 0x19, 0xfe, 0x18, 0x7c, 0x18, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xe, 0x1c, 0x6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xfe, 0x1f, 0xbc, 0xf, 0x0, 0x6, 0x0, 0x0},
    {0x0, 0x0, 0x80, 0x3, 0xe0, 0x3, 0x30, 0x3, 0x1c, 0x3, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x3, 0x0, 0x0},
    {0x0, 0x0, 0x80, 0x1c, 0x7e, 0x18, 0x66, 0x18, 0x66, 0x18, 0x66, 0x18, 0xc6, 0x1f, 0xc6, 0xf, 0x0, 0x3, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0x7, 0xfc, 0xf, 0xce, 0x1f, 0x66, 0x18, 0x66, 0x18, 0xe6, 0x1c, 0xc6, 0xf, 0x88, 0x7, 0x0, 0x0},
    {0x0, 0x0, 0x6, 0x0, 0x6, 0x10, 0x6, 0x1e, 0x86, 0x1f, 0xf6, 0x3, 0xfe, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x18, 0xf, 0xfc, 0xf, 0xee, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xfe, 0x1d, 0xbc, 0xf, 0x0, 0x6, 0x0, 0x0},
    {0x0, 0x0, 0xf8, 0x4, 0xfc, 0x18, 0x86, 0x19, 0x86, 0x19, 0x86, 0x19, 0xfe, 0xf, 0xfc, 0x7, 0xe0, 0x1, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x8, 0x70, 0x1c, 0x70, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x88, 0x70, 0xdc, 0x70, 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xc0, 0x0, 0xe0, 0x1, 0xe0, 0x1, 0x20, 0x1, 0x30, 0x3, 0x30, 0x3, 0x18, 0x6, 0x18, 0x6, 0x0, 0x0},
    {0x0, 0x0, 0x60, 0x6, 0x60, 0x6, 0x60, 0x6, 0x60, 0x6, 0x60, 0x6, 0x60, 0x6, 0x60, 0x6, 0x60, 0x6, 0x0, 0x0},
    {0x0, 0x0, 0x18, 0x6, 0x18, 0x2, 0x30, 0x3, 0x30, 0x3, 0xa0, 0x1, 0xe0, 0x1, 0xe0, 0x0, 0xc0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0xc, 0x0, 0x6, 0x8, 0xc6, 0x1d, 0xc6, 0x18, 0x3e, 0x0, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0xe0, 0x7, 0xf8, 0x1f, 0x1c, 0x38, 0xce, 0x33, 0xe6, 0x6f, 0x66, 0x6c, 0x66, 0x6c, 0xdc, 0x66, 0xf8, 0x2f, 0x0, 0x0},
    {0x0, 0x10, 0x0, 0x1f, 0xf0, 0x1f, 0xfe, 0x3, 0x1e, 0x3, 0x3e, 0x3, 0xfc, 0x7, 0xc0, 0x1f, 0x0, 0x1c, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xfe, 0x19, 0xfc, 0x1f, 0x18, 0xf, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0x3, 0xfc, 0xf, 0xfc, 0xf, 0x6, 0x18, 0x6, 0x18, 0x6, 0x18, 0xe, 0x1c, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0x6, 0x18, 0x6, 0x18, 0x6, 0x18, 0x3c, 0xf, 0xfc, 0xf, 0xf0, 0x3, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0x6, 0x18, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0xc6, 0x0, 0xc6, 0x0, 0xc6, 0x0, 0xc6, 0x0, 0x6, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0x3, 0xfc, 0xf, 0x1e, 0x1e, 0x6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x1f, 0xc8, 0xf, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x0},
    {0x0, 0x0, 0x6, 0x18, 0x6, 0x18, 0x6, 0x18, 0xfe, 0x1f, 0xfe, 0x1f, 0x6, 0x18, 0x6, 0x18, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x1c, 0x0, 0x18, 0x6, 0x18, 0x6, 0x18, 0x6, 0x1c, 0xfe, 0xf, 0xfe, 0x7, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xe0, 0x1, 0xf0, 0x0, 0xf8, 0x3, 0x9e, 0xf, 0xe, 0x1e, 0x2, 0x18, 0x0, 0x10},
    {0x0, 0x0, 0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0x7e, 0x0, 0xe0, 0x1, 0xf0, 0x1, 0x1e, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0x3e, 0x0, 0xf0, 0x0, 0x80, 0x7, 0x0, 0x1e, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x0},
    {0x0, 0x0, 0xf8, 0x7, 0xfc, 0xf, 0xe, 0x1c, 0x6, 0x18, 0x6, 0x18, 0x3e, 0x1f, 0xfc, 0xf, 0xf0, 0x3, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0x86, 0x1, 0x86, 0x1, 0xce, 0x1, 0xfc, 0x0, 0x78, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0xf, 0xf8, 0x1f, 0x1c, 0x38, 0xc, 0x30, 0xc, 0x30, 0x7c, 0xfe, 0xf8, 0xdf, 0xe0, 0x87, 0x0, 0x80},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xc6, 0x0, 0xc6, 0x0, 0xc6, 0x1, 0xfe, 0xf, 0x7c, 0x1f, 0x18, 0x18, 0x0, 0x10},
    {0x0, 0x0, 0x38, 0xc, 0x7c, 0x18, 0xe6, 0x18, 0xe6, 0x18, 0xc6, 0x18, 0xc6, 0x1f, 0x8e, 0xf, 0x0, 0x7, 0x0, 0x0},
    {0x0, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0xf, 0xfe, 0xf, 0x0, 0x1c, 0x0, 0x18, 0x0, 0x18, 0xfe, 0x1f, 0xfe, 0xf, 0xfe, 0x7, 0x0, 0x0},
    {0x2, 0x0, 0x3e, 0x0, 0xfe, 0x3, 0xe0, 0x1f, 0x0, 0x1c, 0x0, 0x1f, 0xf8, 0x1f, 0xfe, 0x0, 0xe, 0x0, 0x0, 0x0},
    {0x1e, 0x0, 0xfe, 0x1f, 0xc0, 0x1f, 0xc0, 0x1f, 0xf0, 0x0, 0xf0, 0x3, 0x0, 0x1f, 0xfc, 0x1f, 0xfe, 0x7, 0x2, 0x0},
    {0x2, 0x10, 0x6, 0x18, 0x1e, 0x1e, 0xfc, 0x7, 0xf0, 0x3, 0xf0, 0x3, 0x3c, 0xf, 0xe, 0x1c, 0x2, 0x18, 0x0, 0x0},
    {0x2, 0x0, 0xe, 0x0, 0x3e, 0x0, 0xf8, 0x0, 0xe0, 0x1f, 0xf0, 0x1f, 0x7c, 0x0, 0x1e, 0x0, 0x6, 0x0, 0x2, 0x0},
    {0x0, 0x0, 0x6, 0x1c, 0x6, 0x1f, 0x86, 0x1f, 0xe6, 0x19, 0xf6, 0x18, 0x3e, 0x18, 0x1e, 0x18, 0x6, 0x18, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0xff, 0x7f, 0xff, 0x7f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x2, 0x0, 0xe, 0x0, 0x78, 0x0, 0xe0, 0x1, 0x80, 0x7, 0x0, 0x1e, 0x0, 0x38, 0x0, 0x20, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0xff, 0x7f, 0xff, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x20, 0x0, 0x20, 0x0, 0x38, 0x0, 0x1c, 0x0, 0xe, 0x0, 0xe, 0x0, 0x1c, 0x0, 0x30, 0x0, 0x20, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x3, 0x0, 0x6, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x40, 0xf, 0xb0, 0x1f, 0xb0, 0x19, 0xb0, 0x19, 0xb0, 0x19, 0xf0, 0xf, 0xe0, 0x1f, 0xc0, 0x1f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xe0, 0xe, 0x30, 0x18, 0x30, 0x18, 0x70, 0x1c, 0xe0, 0xf, 0xc0, 0x7, 0x0, 0x0},
    {0x0, 0x0, 0xc0, 0x7, 0xe0, 0xf, 0xf0, 0x1e, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x70, 0x1c, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xe0, 0xf, 0xf0, 0x1f, 0x30, 0x18, 0x30, 0x18, 0x20, 0x8, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xc0, 0xf, 0xe0, 0xf, 0xb0, 0x19, 0xb0, 0x19, 0xb0, 0x19, 0xf0, 0x19, 0xe0, 0x19, 0xc0, 0xd, 0x0, 0x0},
    {0x0, 0x0, 0x30, 0x0, 0x30, 0x0, 0xfc, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0x36, 0x0, 0x36, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xe0, 0xf, 0xf0, 0xdf, 0x70, 0xdc, 0x30, 0xd8, 0x30, 0xd8, 0xf0, 0xff, 0xf0, 0x7f, 0xf0, 0x1f, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0x30, 0x0, 0x30, 0x0, 0xf0, 0x1f, 0xe0, 0x1f, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x30, 0x0, 0x30, 0x0, 0xfe, 0x7, 0xfe, 0x1f, 0xfe, 0x1f, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xe0, 0xfe, 0xff, 0xfe, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x1f, 0xfe, 0x1f, 0xfe, 0x1f, 0xc0, 0x1, 0xe0, 0x7, 0x70, 0xf, 0x30, 0x1c, 0x10, 0x10, 0x0, 0x0},
    {0x0, 0x0, 0x6, 0x0, 0x6, 0x0, 0xfe, 0xf, 0xfe, 0x1f, 0x0, 0x1c, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0x1f, 0xe0, 0x1f, 0x30, 0x0, 0xf0, 0x1f, 0xe0, 0x1f, 0x30, 0x0, 0xf0, 0x1f, 0xe0, 0x1f, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0x1f, 0xf0, 0x1f, 0xe0, 0x1f, 0x30, 0x0, 0x30, 0x0, 0xf0, 0x1f, 0xe0, 0x1f, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xc0, 0x7, 0xe0, 0xf, 0x70, 0x1c, 0x30, 0x18, 0x30, 0x18, 0xf0, 0x1e, 0xe0, 0xf, 0xc0, 0x7, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0xff, 0xf0, 0xff, 0xe0, 0xe, 0x30, 0x18, 0x30, 0x18, 0x70, 0x1c, 0xe0, 0xf, 0xc0, 0x7, 0x0, 0x0},
    {0x0, 0x0, 0xe0, 0xf, 0xf0, 0x1f, 0x30, 0x18, 0x30, 0x18, 0x20, 0x8, 0xf0, 0xff, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0xf0, 0x1f, 0xf0, 0x1f, 0x60, 0x0, 0x30, 0x0, 0x30, 0x0, 0x30, 0x0, 0x70, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x40, 0xc, 0xe0, 0x19, 0xf0, 0x19, 0xb0, 0x19, 0x30, 0x19, 0x30, 0x1f, 0x70, 0xe, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x18, 0x0, 0x18, 0x0, 0xff, 0x7, 0xff, 0xf, 0x18, 0xc, 0x18, 0xc, 0x18, 0xc, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0xf0, 0x7, 0xf0, 0x1f, 0xf0, 0x1f, 0x0, 0x18, 0x0, 0x8, 0xf0, 0x1f, 0xf0, 0x1f, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x70, 0x0, 0xf0, 0x3, 0xc0, 0x1f, 0x0, 0x1c, 0x0, 0x1f, 0xe0, 0xf, 0xf0, 0x1, 0x30, 0x0, 0x0, 0x0},
    {0x70, 0x0, 0xf0, 0xf, 0x0, 0x1f, 0x0, 0x1f, 0xc0, 0x3, 0xc0, 0x7, 0x0, 0x1c, 0xc0, 0x1f, 0xf0, 0x3, 0x10, 0x0},
    {0x0, 0x10, 0x10, 0x18, 0x70, 0x1c, 0xf0, 0xe, 0xc0, 0x7, 0xe0, 0x7, 0xf0, 0x1e, 0x30, 0x18, 0x10, 0x10, 0x0, 0x0},
    {0x0, 0x0, 0x30, 0xc0, 0xf0, 0xc1, 0xc0, 0xef, 0x0, 0x7f, 0x0, 0x3f, 0xe0, 0x7, 0xf0, 0x1, 0x30, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x30, 0x18, 0x30, 0x1c, 0x30, 0x1e, 0xb0, 0x1b, 0xf0, 0x19, 0xf0, 0x18, 0x70, 0x18, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x3, 0x0, 0x3, 0xf8, 0x3f, 0xfe, 0xff, 0x7e, 0xf8, 0x6, 0xc0, 0x6, 0xc0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0xff, 0xfe, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0x0, 0x0, 0x0, 0x6, 0xc0, 0x6, 0xc0, 0xfe, 0xfc, 0xfc, 0xff, 0x80, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x0},
    {0x0, 0x0, 0x80, 0x3, 0xc0, 0x1, 0xc0, 0x0, 0xc0, 0x1, 0x80, 0x3, 0x0, 0x3, 0xc0, 0x3, 0xc0, 0x1, 0x0, 0x0},
    {0x0, 0x0, 0xfe, 0x7f, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0x2, 0x40, 0xfe, 0x7f, 0x0, 0x0}
};


#endif
