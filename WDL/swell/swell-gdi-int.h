#ifndef _SWELL_GDI_INT_H_
#define _SWELL_GDI_INT_H_

#define TYPE_PEN 1
#define TYPE_BRUSH 2
#define TYPE_FONT 3
#define TYPE_BITMAP 4

typedef struct 
{
  int type;
  CGColorRef color;
  int wid;
  NSImage *bitmapptr;  
  
  // only used if HFONT and using NSString to draw text
  NSMutableDictionary *fontdict;
  NSMutableParagraphStyle *fontparagraphinfo; // dont release this, it's owned by fontdict
  
  // only used if HFONT and using ATSU to draw text (faster)
  ATSUStyle font_style;
  float font_rotation;
} GDP_OBJECT;

typedef struct {
  CGContextRef ctx; 
  void *ownedData;
  GDP_OBJECT *curpen;
  GDP_OBJECT *curbrush;
  GDP_OBJECT *curfont;
  
  NSColor *curtextcol;
  CGColorRef curcgtextcol;
  int cur_text_color_int; // text color as int
  
  int curbkcol;
  int curbkmode;
  CGImageRef bitmapimagecache;
  bool bitmapimagecache_dirty;
  float lastpos_x,lastpos_y;
  
} GDP_CTX;

#endif
