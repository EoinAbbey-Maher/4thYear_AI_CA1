 #include "Worker.h"



Worker::Worker()
{	
}

void Worker::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_workerShape);
}

void Worker::setBody(sf::Texture* t_texture, sf::Vector2f t_position)
{
	m_workerPosition = t_position;
	m_workerShape.setTexture(t_texture);
	m_workerShape.setPosition(t_position);
	m_workerShape.setSize(m_size);
	m_workerShape.setOrigin(m_size.x * .5, m_size.y * .5);
	
}

void Worker::update(RoomBuilder& m_roombuilder)
{
	m_lastPosition = m_workerPosition;
	wander(m_roombuilder);
	m_workerShape.setPosition(m_workerPosition);
	
}


void Worker::wander(RoomBuilder& m_roombuilder)
{
	m_randomDirection = (rand() % 3) - 1;

	m_maxRotation = (rand() % 14);
	m_rotation = m_rotation + (m_maxRotation * m_randomDirection);

	m_magnitude = std::sqrt(std::pow(m_workerVelocity.x, 2) + std::pow(m_workerVelocity.y, 2));
	m_direction = sf::Vector2f(std::cos(m_rotation * (PI / 180)), std::sin(m_rotation) * (PI / 180));
	m_workerVelocity = m_magnitude * (sf::Vector2f(std::cos(m_rotation * (PI / 180)), std::sin(m_rotation * (PI / 180))));

	m_workerVelocity += m_direction;

	if (MAX_SPEED < m_magnitude)
	{
		m_workerVelocity = m_direction * MAX_SPEED;
	}
	m_workerShape.setRotation(m_rotation);

	if (m_magnitude > MAX_SPEED)
	{
		m_workerVelocity = m_direction * MAX_SPEED;
	}

	m_workerPosition = m_workerPosition + m_workerVelocity;
	m_workerShape.setPosition(m_workerPosition);

	checkCollisions(m_roombuilder);
}


void Worker::checkCollisions(RoomBuilder& t_roombuilder)
{
	for each (Tile & tile in t_roombuilder.m_tiles)
	{
		if (m_workerShape.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds()) && tile.m_type == TileType::WALL)
		{
			m_workerPosition = m_lastPosition;
			m_workerVelocity.x *= -.1;
			m_workerVelocity.y *= -.1;
		}
	}
}






