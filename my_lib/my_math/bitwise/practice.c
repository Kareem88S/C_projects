

/*
1)
Extract the 3rd bit from the right (bit index 2)
unsigned char x = 0b10101100;
Solved by: 
if (x & 0b00000100) x = 1;
*/

/*
2)
unsigned char x = 0b11111111;
Clear bit 5 (zero it)
Solved by:
x &= 0b11011111;
(different then proposed solution. Any complications?)
*/

/*
3)
unsigned char x = 0b00000000;
// Set bit 3
Solved by:
1)	x |= 0b0001000;
2)	x |= (1 << 3)
Both seem to work Both correct?
*/

/*
4)
unsigned char x = 0b00001111;
// Flip bit 2
solution 1:
x = x ^ 0b00000100;
solution 2:
x ^= (1 << 2);
Solution 2 feels more flexible, but i feel less confident applying it.
*/

/*
5)
5. Left shift and wrap-around manually
unsigned char x = 0b10000001;
// Shift left by 1
// Then OR the result with (original x >> 7)
Solution 1:
int wrapper(unsigned char x)
{
	const char	size = (sizeof(x) * 8);
	char		seventh;

	seventh = 0;
	if (x & 1 << 7)
		seventh = 1;
	x = x << 1;
	x = x | seventh;
	return (x);
}
Solution 2:
	if (x & 0b10000000)
		x = (x << 1) | 0b1;
	else 
		x = (x << 1);

Is there an easier solution?
Solution 3 (chatGPT):
x = (x << 1) | ((x & 0x80) >> 7);
*/

/*
6)
6. Detect if x is a power of 2
unsigned char x = 8;
// Write code that sets a flag if x is power of two
Hint: A power of two has only one bit set → x & (x - 1) == 0

Solution (not my implementation but the provided suggestion - amazing && briliant)
	bool		pow_of_two;
	unsigned	char x = 8;

	pow_of_two = (x != 0) && ((x & (x - 1)) == 0);

*/


/*
7)
7. Count how many bits are set to 1
unsigned char x = 0b10101100;
// Write a loop to count the number of bits set
			My Solution:
	int bits_set;
	int bits;
	unsigned char x;

	x = 13;
	bits = 8;
	bits_set = 0;
	while (--bits >= 0)
		if (x & 1 << bits)
			bits_set++;

			GPT solution:
	while (x) 
	{
		bits_set += x & 1;
		x >>= 1;
	}

			Brian Kernighan’s algorithm solution:
	while (x) 
	{
		bits_set++;
		x &= (x - 1);
	}
*/


/*
8)
8. Extract lower nibble (last 4 bits)
unsigned char x = 0b11110011;
// Extract the lower 4 bits → expect 0011
solution 1:
	unsigned char x = 0b11110011;
	unsigned char y;

	y = x & 0b00001111;
solution 2:
Use x & 0x0F
	unsigned char x = 0b11110011;
	x = x & 0x0F;
*/

/*
9)
9. Extract upper nibble (first 4 bits)
unsigned char x = 0b11110011;
// Extract upper nibble → expect 1111
solution:
	unsigned char x = 0b11110011;
	unsigned char y;

	y = (x & 0xF0) >> 4;

*/

/*
10)
10. Reverse all 8 bits manually (no loop!!)
Write code that reverses all 8 bits of a number like:
unsigned char x = 0b10110000;
// Result: 00001101
*/
// int main ()
// {
// 	unsigned char x = 0b10110000;

// 	x = ((x & 0xF0) >> 4) | ((x & 0x0F) << 4);
// //			0b11110000			0b00001111
// 	x = ((x & 0xCC) >> 2) | ((x & 0x33) << 2);
// 	x = ((x & 0xAA) >> 1) | ((x & 0x55) << 1);

// 	return (0);
// }

int	main(void)
{
	char unsigned	x = 115;
	char			bits_set;


	x &= (x - 1);
	x = (x & (x - 1));
	x &= (x - 1);
	x &= (x - 1);
	x &= (x - 1);
	x &= (x - 1);
	
	// bits_set = 0;
	// while (x)
	// {
	// 	bits_set++;
	// 	x &= (x - 1);
	// }
}
