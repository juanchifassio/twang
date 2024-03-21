#include "Arduino.h"

class Boss
{
  public:
    void Spawn(int pos);
    void Hit();
    void Kill();
    bool Alive();
    int _pos;
    int _lives;
    int _ticks;
  private:
    bool _alive;
};

void Boss::Spawn(int pos){
    _pos = pos;
    _lives = 3;
    _alive = 1;
}

void Boss::Hit(){
    _lives --;
    if(_lives == 0) {
        Kill();
        return;
    }
    if(_lives == 2){
      if (_pos >= 500){
        _pos = 200; 
      } else {
        _pos = 800;
      }
    }else if(_lives == 1){
      if (_pos >= 500){
        _pos = 400; 
      } else {
        _pos = 600;
      }
    }
}

bool Boss::Alive(){
    return _alive;
}

void Boss::Kill(){
    _alive = 0;
}
