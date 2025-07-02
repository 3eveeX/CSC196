#pragma once
#include <cstdlib>

namespace whermst {
	namespace random {
		/// <summary>
		/// Generates a random integer value.
		/// </summary>
		/// <returns> A pseudo-random integer value.</returns>
		inline int getRandomInt() { return rand(); }
		
		/// <summary>
		/// Generates a random integer in the range [0, max).
		/// </summary>
		/// <param name="max">The upper bound (exclusive) for the random integer.</param>
		/// <returns>A random integer greater than or equal to 0 and less than max.</returns>
		inline int getRandomInt(int max) { return rand() % max; }
		
		/// <summary>
		/// Generates a random integer in the range [min, max).
		/// </summary>
		/// <param name="max">The upper bound (inclusive) of the range.</param>
		/// <param name="min">The lower bound (inclusive) of te range.</param>
		/// <returns>A random integer between min and max, inclusive.</returns>
		inline int getRandomInt(int max, int min) { return min + getRandomInt(max - min + 1); }
		/// <summary>
		/// Generates a random floating-point number between 0.0 and 1.0.
		/// </summary>
		/// <returns>A random float value in the range [0.0, 1.0]</returns>
		inline float getRandomFloat() { return (float)rand() / RAND_MAX; }

	}
}