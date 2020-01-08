#include "Worker.h"

void Worker::setUpAssets()
{

}

void Worker::wander()
{
	m_randomDirection = (rand() % 3) - 1;

	m_maxRotation = (rand() % 11);
	m_rotation = m_rotation + (m_maxRotation * m_randomDirection);

	m_magnitude = std::sqrt(std::pow(m_workerVelocity.x, 2) + std::pow(m_workerVelocity.y, 2));
	m_direction = sf::Vector2f(std::cos(m_rotation * (PI / 180)), std::sin(m_rotation) * (PI / 180));
	m_workerVelocity = m_magnitude * (sf::Vector2f(std::cos(m_rotation * (PI / 180)), std::sin(m_rotation * (PI / 180))));

	m_workerVelocity += m_direction;

	if (MAX_SPEED < m_magnitude)
	{
		m_workerVelocity = m_direction * MAX_SPEED;
	}
	m_WorkerSprite.setRotation(m_rotation);
}
