#ifndef SCENE_H
#define SCENE_H

#include <map>
#include "Object.h"

using namespace std;

class Scene{
private:
    map<string,Object*> objectScene;
    Shader* shader;  

public:
    
    void AddObject(string label,Object* o);
    Object* GetObject(string label);
    
    void Clear();
    void Affiche();
    void AfficheRepere();
    void Update();
    void InitShader(vector<string> uniformShader);
    Shader* GetShader();

    Scene();
    ~Scene();
};

#endif