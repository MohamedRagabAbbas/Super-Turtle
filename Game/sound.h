#ifndef SOUND_H
#define SOUND_H

#include <QtMultimedia>
#include <QSoundEffect>


class Sound
{ private:
    QSoundEffect music;

public:
    Sound();
    void  Music_Of_Game() ;
    void  Music_Shooting();
    void  Music_Win();
    void  Music_Win_The_Game();
    void  Music_Lose();
    void  Music_Game_Over();
    void  Toggle_Music();
    bool  on_off_music();

};

#endif // SOUND_H
