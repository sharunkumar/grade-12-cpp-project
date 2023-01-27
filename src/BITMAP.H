typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;

struct BMP {

	// BitMap File Header
	byte bfType[2]; /* 1 2 must always be set to 'BM' to declare that this is a .bmp file.*/
	dword bfSize; /* 3 4 specifies the size of the file in bytes.*/
	word bfReserved1; // 7 2 must always set to zero. */
	word bfReserved2; // 9 2 must always be set to zero.
	dword bfOffset; // 11 4 specifies the offset from the beginning of the file to bitmap data.

	// BitMap Image Header
	dword biSize; // 15 4 specifies the size of the BitMap Header structure, in bytes.
	dword biWidth; // 19 4 specifies the width of image, in pixels.
	dword biHeight; // 23 4 specifies the height of image, in pixels.
	word biPlanes; // 27 2 specifies the number of planes of the target device,must be set to 0
	word biBitCount; // 29 2 specifies the number of bits per pixel.
	dword biCompression; //31 4 Specifies the type of compression, usually set to 0 - No Compres
	dword biSizeImage; // 35 4 specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.
	dword biXPelsPerMeter; //39 4 specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.
	dword biYPelsPerMeter; // 43 4 specifies the the vertical pixels per meter on the designated targer device, usually set to zero
	dword biClrUsed; // 47 4 specifies the number of colors used in bitmap, if set to 0 number of colors is calculated using the biBitCount member.
	dword biClrImportant; // 51 4 specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.
};