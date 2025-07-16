#pragma once
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include <vector>

namespace whermst{
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2>& points, const vec3& colour = vec3(1, 1, 1))
			: _points(points)
			, _colour(colour) 
		{}

		void Draw(class Renderer& renderer);

		
	private:
		std::vector <vec2> _points;
		vec3 _colour{1.0f, 1.0f, 1.0f};
	};

}
