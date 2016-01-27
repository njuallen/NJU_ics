/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * name: Liu Zhigang userid: 141242022 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
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

// completed!
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
	/*use the Demogen rule*/
	return (~x) & (~y);
}

// completed!
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
	/* the key is to check whether all the higher 16 bits are the same with the 15th bit*/
	int a=(x<<16)>>16;
	int b=a^x;
	return !b;
}

// completed!
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
	int a= 0x55 + (0x55<<8);
	int mask=a+(a<<16);
	int b=x & mask;
	/* here, we do not need to check whether b is negative since mask is positive */
	int minus_1=(~1)+1;
	// if b==0, positive_flag=0; if b>0, positive_flag=1
	int positive_flag=((~((b+minus_1)>>31))) & 0x1;
	return positive_flag;
}

// completed!
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    // get the nth byte
	int a=((x>>(n<<3)) & 0xff)<<(m<<3);
	// get the mth byte
	int b=((x>>(m<<3)) & 0xff)<<(n<<3);
	x= x & (~(0xff<<(m<<3)));
	x= x & (~(0xff<<(n<<3)));
	x= x | a;
	x= x | b;
	return x;
}

// completed!
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	/*the key insight is this: it's much more easier to 
	  distinguish negative number from nonnegative numbers 
	  than to distinguish zero from positive numbers. 
	  What's more, 0-1 is a negative number and positive 
	  number minus 1 is a nonnegative number. We can use this
	  property to easily distinguish zero from positive numbers.*/
	// if x<0, negative=-1; else negative=0
	int negative= x>>31;
	// minus_1=-1
	int minus_1=(~1)+1;
	int a=x+minus_1;
	// if x==0, b=0; if x>0, b=1
	int b=(~(a>>31)) & 0x1;
	return negative | b;
}

// completed!
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {

	// shift c left to the desired position and make it a mask
	int a=c<<(n<<3);
	// set the desired the byte to be 0x0
	x= x & (~(0xff<<(n<<3)));
	x= x | a;
	return x;
}

// completed!
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
	int int_min=1<<31;
	int minus_1=int_min>>31;
	// deal with n==0
	// if n==0, zero_flag=0, else zero_flag is all 1
	int zero_flag=~((n+minus_1)>>31);
	// the mask sets all the low 32-n bits to all 1
	// if n==0, set all the bits to 0
	int mask=(int_min>>((n+minus_1)&zero_flag))&zero_flag;
	// shift a right and set the higher bits to all 0
	int a=(x>>n) & (~mask);
	// if n==0, do not shift left
	int left_shift_num=(~n+33)&zero_flag;
	int b=x<<left_shift_num;
	b=b & mask;
//	printf("mask:%X a:%X b:%X\n",mask,a,b);
	return a|b;
}

// completed!
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
	// a=5*x
	int a=(x<<2)+x;
	// if a<0, we should give it a bias of 4
	a=((a>>31) & 0x7) + a;
	a=a>>3;
	return a;
}

// completed! I copy this from Cao Yunhao, thanks!
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	int a=x^(x>>16);
	int b=a^(a>>8);
	int c=b^(b>>4);
	int d=c^(c>>2);
	int e=d^(d>>1);
	return e&0x1;
}

// completed!
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
	int y_complement=(~y)+1;
	int result=x+y_complement;
	int X=x>>31 ;
	int Y=y>>31;
	int S=result>>31;
	return (((X ^ Y) & (~(X ^ S))) | ~(X ^ Y)) & 0x1;
}

// Chen Zhi gives me the core idea, that is using binsearch!
// Thanks!
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int index=0;
	// check all the 32 bits
	int a=(x<<16)>>16;
	// if the high 16 bits are the same as the 15th bit
	// then b=00000000, else b=111111111
	int b=((!!(a^x))<<31)>>31;
	index+=b & 16;
	// if the high 16 bits are the same as the 15th bit
	// move them out
	x<<=(~b)&16;

	// check the remaining 16 bits
	a=(x<<8)>>8;
	b=((!!(a^x))<<31)>>31;
	index+=b&8;
	// if the high 8 bits are the same as the 7th bit
	// move them out
	x<<=(~b)&8;

	// check the remaining 8 bits
	a=(x<<4)>>4;
	b=((!!(a^x))<<31)>>31;
	index+=b&4;
	// if the high 4 bits are the same as the 3th bit
	// move them out
	x<<=(~b)&4;

	// check the remaining 4 bits
	a=(x<<2)>>2;
	b=((!!(a^x))<<31)>>31;
	index+=b&2;
	// if the high 2 bits are the same as the 1th bit
	// move them out
	x<<=(~b)&2;

	// check the remaining 2 bits
	a=(x<<1)>>1;
	b=((!!(a^x))<<31)>>31;
	index+=b&1;

	return index+1;
}

// completed!
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	if((((uf>>23)&255)==255) && uf<<9)
		return uf;
	return (~(1<<31)) & uf;
}

// completed!
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
	int a=1<<31;
	int sign=uf&a;
	int e=((uf>>23)&0xff)-127;
	// use these two bits to check for rounding
	int ret=uf;
	// set the higher bits of fraction to all 0
	int frac=((-1)^a>>8)&uf;
	// if uf==NaN or infinity
	if(e!=128)
	{
		// denormalized
		if(e==-127 || e==-126)
		{
			frac=frac>>1;
			// move the hidden 1 right
			if(e==-126)
				frac=frac | (1<<22);
			// rounding bits
			if((uf&0x3)==0x3)
				frac=frac+1;
			ret=frac | (0<<23);
			ret=sign | ret;
		}
		else
		{
			// normalized
			e=e+126;
			ret=frac | (e<<23);
			ret=sign | ret;
		}
	}
	return ret;
}


// completed!
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	int wrong=1<<31;
	int sign=((uf>>31)&0x1);
	int e=((uf>>23)&0xff)-127;
	int frac=uf;
	int mask=1<<23;
	if(e>31)
		return wrong;
	if(e<0)
		return 0;

	// put the hidden leading 1 back to its position
	frac=mask|frac;
	// set the higher bits to all 0
	frac=((-1)^wrong>>7)&frac;
	if(e>23)
	{
		frac=frac<<(e-23);
	}
	else if(e<23)
	{
		frac=frac>>(23-e);

	}
	// if negative
	if(sign)
		frac=(~frac)+1;
	return frac;
}
