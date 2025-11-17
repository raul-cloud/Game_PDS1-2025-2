#pragma once
#define MAX_W 22
#define MAX_H 11

class Cidade {
  private:
    int cidade[MAX_H][MAX_W];
  Cidade();
  public:
  
  void DrawCity (int** cidade);
  
  void LoadSprite ();
  void LoadMusica ();

  void SetNPC ();

}
