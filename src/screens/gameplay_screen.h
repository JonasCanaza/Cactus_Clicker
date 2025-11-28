#pragma once

namespace sf
{
	class RenderWindow;
}

namespace Gameplay
{
	void Init();
	void Input();
	void Update();
	void Draw(sf::RenderWindow& window);
}