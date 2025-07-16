#pragma once
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Transform.h"
#include <vector>

namespace whermst{
	class Model {
	public:
		Model() = default;

		Model(const std::vector<vec2>& points, const vec3& colour = {1.0f, 1.0f, 1.0f}) 
			: _points(points)
			, _colour(colour) 
		{}

		void Draw(class Renderer& renderer, const vec2& position, float rotation, float scale = 1.0f);
		void Draw(class Renderer& renderer, const Transform& transform);
	private:
		std::vector<vec2> _points;
		vec3 _colour{1.0f, 1.0f, 1.0f};
	};

}