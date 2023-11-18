#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

	struct TagComponent : Component {
		const std::string TagName;
		TagComponent() = default;
		TagComponent(std::string tag) : TagName{tag} {}
	};

} // namespace space_shooter::ecs