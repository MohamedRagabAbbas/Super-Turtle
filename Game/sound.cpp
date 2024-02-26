#include "sound.h"

Sound::Sound()
{
    //Music_Of_Game();
}
void Sound::Music_Of_Game()
{
    music.setSource(QUrl::fromLocalFile("Startgame.wav"));
    music.setLoopCount(QSoundEffect::Infinite); // Mode of playing
    music.setVolume(15); // Setting Volume
    music.play(); // Play

}

void Sound::Music_Shooting()
{
    music.setSource(QUrl::fromLocalFile("shooting.wav"));
    music.setLoopCount(1); // Mode of playing (only one ofter winning)
    music.setVolume(17); // Setting Volume
    music.play(); // Play

}


void Sound::Music_Win() //After passing the three levels before the last part
{
    music.setSource(QUrl::fromLocalFile("win_first.wav"));
    music.setLoopCount(1); // Mode of playing (only one ofter winning)
    music.setVolume(15); // Setting Volume
    music.play(); // Play
}

void Sound::Music_Win_The_Game() //Win the Game after the last part
{
    music.setSource(QUrl::fromLocalFile("Win.wav"));
    music.setLoopCount(1); // Mode of playing (only one ofter winning)
    music.setVolume(15); // Setting Volume
    music.play(); // Play
}


void Sound::Music_Lose() //Losing health (one heart)
{
    music.setSource(QUrl::fromLocalFile("Lose_Health.wav")); //
    music.setLoopCount(1); // Mode of playing
    music.setVolume(15); // Setting Volume
    music.play(); // Play
}

 void Sound:: Music_Game_Over() //Game over and start from the beginning again
{
     music.setSource(QUrl::fromLocalFile("GameOver.wav")); //
     music.setLoopCount(1); // Mode of playing
     music.setVolume(15); // Setting Volume
     music.play(); // Play
}
 void Sound::Toggle_Music()
 {

     music.setMuted(!music.isMuted());

     // More detailed code of the previous functionality
 //    if (music.isMuted())
 //        music.setMuted(false);
 //    else
     //music.setMuted(true);
 }

bool Sound:: on_off_music()
 {
     if(!music.isMuted())
         return false;
     else
         return true;
 }


//QSoundEffect Sound::music;
