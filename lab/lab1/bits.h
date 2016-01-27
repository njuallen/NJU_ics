/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
int bitNor(int, int);
int test_bitNor(int, int);
int fitsShort(int);
int test_fitsShort(int);
int anyEvenBit();
int test_anyEvenBit();
int byteSwap(int, int, int);
int test_byteSwap(int, int, int);
int sign(int);
int test_sign(int);
int replaceByte(int, int, int);
int test_replaceByte(int, int, int);
int rotateRight(int, int);
int test_rotateRight(int, int);
int multFiveEighths(int);
int test_multFiveEighths(int);
int bitParity(int);
int test_bitParity(int);
int subOK(int, int);
int test_subOK(int, int);
int howManyBits(int);
int test_howManyBits(int);
unsigned float_abs(unsigned);
unsigned test_float_abs(unsigned);
unsigned float_half(unsigned);
unsigned test_float_half(unsigned);
int float_f2i(unsigned);
int test_float_f2i(unsigned);
