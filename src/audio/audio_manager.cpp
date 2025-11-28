#include "audio/audio_manager.h"

#include <SFML/Audio.hpp>

namespace AudioManager
{
	sf::SoundBuffer clickBuffer("res/audio/cactus.wav");
	sf::Sound clickSound(clickBuffer);
}