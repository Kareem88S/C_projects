/*
write a function setbits(x, p, n, y) that returns x
	with the n bits that begin at position p, set to the rightmost n bits of y,
	leaving the other bits unchanged. 
*/

/*
x == 0b 1100 0000
y == 0b 1001 1100

p == 3
n == 2

x == 0b  1100 0000
*/

/*
Replaces n-bits from position p in x, with the rightmost n-bits in y.
All other bits in x remain unchanged.
*/
/*
psuedo:
clear n @ p in x. (using mask)
create mask from y.
shift y's bits to p to align with cleared x-bits.
or (|) y into x.
*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask;
	
	mask = ~(~0 << n) << (p + 1 - n);
	x = x & ~mask;
	mask = (~(~0 << n) & y) << (p + 1 - n);
	x = x | mask;
	return (x);
	// return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

int main()
{
	int x = 0b00101101;
	int y = 0b11100011;
	int p = 5;
	int n = 3;
	x = setbits(x, p, n, y);
	return (0);
}
/*
*/

// unsigned setbits(unsigned x, int p, int n, unsigned y)
// {
// 	unsigned	temp;

// 	temp = ~(~0 << (p + 1 - n)) & x;
// 	y = y & ~(~0 << n);
// 	x = x >> (2 * n);
// 	x = x << n;
// 	x = x | y;
// 	x = x << n;
// 	x = x | temp;
// 	return (x);
// }