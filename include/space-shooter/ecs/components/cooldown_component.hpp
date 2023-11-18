#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

	struct CooldownComponent : Component {
 		
		sf::Time elapsed_time;
		sf::Time cooldown_duration;
		

		CooldownComponent(sf::Time cooldown_duration) : elapsed_time(sf::Time::Zero),cooldown_duration(cooldown_duration) {}

	};

} // namespace space_shooter::ecs