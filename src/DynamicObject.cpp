#pragma once

#include "DynamicObject.h"

DynamicObject::DynamicObject() : m_speed(0)
{
}

bool DynamicObject::check_before_move(sf::Vector2f center)
{

	if ((abs(m_location.x - center.x) <= 3.f) && (abs(m_location.y - center.y) <= 3.f))
		return true;

	return false;
}
