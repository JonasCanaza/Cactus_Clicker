#pragma once

namespace sf
{
	class RenderWindow;
}

namespace BackgroundManager
{
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
}