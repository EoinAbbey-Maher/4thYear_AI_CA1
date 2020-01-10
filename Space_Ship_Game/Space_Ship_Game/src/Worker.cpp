#include "Worker.h"



Worker::Worker(float posX, float posY)
{
	if (!m_WorkerTexture.loadFromFile("ASSETS\\IMAGES\\worker.png"))
	{
		std::cout << "problem loading worker" << std::endl;
	}
	m_WorkerSprite.setTexture(m_WorkerTexture);
	m_WorkerSprite.setOrigin(m_WorkerTexture.getSize().x / 2, m_WorkerTexture.getSize().y / 2);
	m_WorkerSprite.setPosition(posX, posY);
	m_workerPosition = m_WorkerSprite.getPosition();
}

void Worker::run(std::vector <Worker>& w)
{
	wander(w);
	move(w);
}


void Worker::wander(std::vector <Worker>& w)
{

	m_randomDirection = (rand() % 3) - 1;

	m_maxRotation = (rand() % 14);
	m_rotation = m_rotation + (m_maxRotation * m_randomDirection);

	m_magnitude = std::sqrt(std::pow(m_workerVelocity.x, 2) + std::pow(m_workerVelocity.y, 2));
	m_direction = sf::Vector2f(std::cos(m_rotation * (PI / 180)), std::sin(m_rotation) * (PI / 180));
	m_workerVelocity = m_magnitude * (sf::Vector2f(std::cos(m_rotation * (PI / 180)), std::sin(m_rotation * (PI / 180))));

	for (int i = 0; i < w.size(); i++)
	{
		w[i].m_workerVelocity += w[i].m_direction;

		if (MAX_SPEED < w[i].m_magnitude)
		{
			w[i].m_workerVelocity = w[i].m_direction * MAX_SPEED;
		}
		w[i].m_WorkerSprite.setRotation(w[i].m_rotation);
	}

}

void Worker::move(std::vector <Worker>& w)
{
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i].m_magnitude > MAX_SPEED)
		{
			w[i].m_workerVelocity = w[i].m_direction * MAX_SPEED;
		}

		w[i].m_workerPosition = w[i].m_workerPosition + w[i].m_workerVelocity;
		w[i].m_WorkerSprite.setPosition(w[i].m_workerPosition);
	}
}


