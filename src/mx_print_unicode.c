#include "libmx.h"

void mx_print_unicode(wchar_t c) {

  if (c < 128)
      write(1, &c, 1);
  else
  {
    char bytes[4];

    if (c < 2048)
    {
      bytes[0] = (c >> 6 & 31) | 192;
      bytes[1] = (c >> 0 & 63) | 128;
      write(1, &bytes, 2);
    }
    else if (c < 65526)
    {
        bytes[0] = (c >> 12 & 15) | 224;
        bytes[1] = (c >> 6 & 63) | 128;
        bytes[2] = (c >> 0 & 63) | 128;
        write(1, &bytes, 3);
    }
    else
    {
        bytes[0] = (c >> 18 & 7) | 240;
        bytes[1] = (c >> 12 & 63) | 128;
        bytes[2] = (c >> 6 & 63) | 128;
        bytes[3] = (c >> 0 & 63) | 128;
        write(1, &bytes, 4);
    }

  }

}
