#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

	struct TimerComponent : Component {

		sf::Time Timer;


		TimerComponent(sf::Time time) : Timer(time) {}


	};

} // namespace space_shooter::ecs