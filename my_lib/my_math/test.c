#include <stdio.h>

typedef union {
	double				d;
	unsigned long long	u;
}	t_double;

int	main(void)
{
// bitwise testing

	char x = 0;
	printf("size: %li\n", sizeof(x));
	
	x <<= 20;
	x = ~x;

	printf("size: %li\n", sizeof(x));
	// if ( x == (0b1 ^ 0b10 ^ 0b101 ^ 0b11111111))
	// 	printf("haha\n");
}

	// t_double	val;

// 	val.d = -3.14;

// 	printf("Original: %f\n", val.d);
// 	printf("Bits (hex): 0x%llx\n", val.u);

// 	val.u &= 0x7FFFFFFFFFFFFFFF; // Clear sign bit
	
// 	printf("Absolute: %f\n", val.d);
// 	printf("Bits (hex): 0x%llx\n", val.u);
	
// 	val.u &= 0x7FFFFFFFFFFFFFFF; // Clear sign bit
	
// 	printf("Absolute: %f\n", val.d);
// 	printf("Bits (hex): 0x%llx\n", val.u);
	
// 	val.u = 0x7FFFFFFFFFFFFFFF; // Clear sign bit
	
// 	printf("Absolute: %f\n", val.d);
// 	printf("Bits (hex): 0x%llx\n", val.u);
	
// 	return (0);
// }
