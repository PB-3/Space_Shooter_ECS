#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

	struct ClockComponent : Component {

		sf::Time elapsed_time;
		sf::Time delta_time;

		ClockComponent(sf::Time delta_time) : elapsed_time(sf::Time::Zero), delta_time(delta_time) {}
		ClockComponent() : elapsed_time(sf::Time::Zero), delta_time(sf::milliseconds(8)){}

	};

} // namespace space_shooter::ecs