 #include "Worker.h"



Worker::Worker(): 
	m_workerVelocity{ -2.0f,0.0f },
	m_randomDirection{ 0.0f },
	m_rotation{ 0.0f },
	m_maxRotation{ 0.0f },
	m_magnitude{ 0.0f } 
{
	m_workerPosition = { random,random };
}

void Worker::wander()
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
	m_WorkerSprite.setRotation(m_rotation);
	
}

void Worker::move()
{
	if (m_magnitude > MAX_SPEED)
	{
		m_workerVelocity = m_direction * MAX_SPEED;
	}

	m_workerPosition = m_workerPosition + m_workerVelocity;
	m_WorkerSprite.setPosition(m_workerPosition);
}

void Worker::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_WorkerSprite);
}

void Worker::setSprite()
{
	if (!m_WorkerTexture.loadFromFile("ASSETS\\IMAGES\\worker.png"))
	{
		std::cout << "problem loading worker" << std::endl;
	}
	m_WorkerSprite.setTexture(m_WorkerTexture);
	m_WorkerSprite.setOrigin(m_WorkerTexture.getSize().x / 2, m_WorkerTexture.getSize().y / 2);
	
}


