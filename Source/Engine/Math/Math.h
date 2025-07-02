#pragma once
#include <algorithm>

namespace whermst {
	namespace math {
		constexpr float pi = 3.141592653589793238462643383279502f;
		constexpr float twoPi = 2 * pi;
		constexpr float halfPi = pi / 2;

		/// <summary>
		/// Converts radians to degrees.
		/// </summary>
		/// <param name="rad">The radian measure to convert.</param>
		/// <returns>The degree equivalent of the radian measure.</returns>
		constexpr float radToDeg(float rad) { return rad * 180 / pi; }
		/// <summary>
		/// Converts degrees to radians.
		/// </summary>
		/// <param name="deg">The degree measure to convert.</param>
		/// <returns>The radian equivalent of the degree measure.</returns>
		constexpr float degToRad(float deg) { return deg * pi / 180; }

		using std::min;
		using std::max;
		using std::clamp;
	}
}
