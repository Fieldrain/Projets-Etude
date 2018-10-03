#ifndef SCENE_H
#define SCENE_H

#include <map>
#include "Object.h"
#include "Ifs.h"
#include "LecteurOption.h"

using namespace std;

class Scene{
private:
    map<string,Ifs*> ifsScene;
    Shader* shader;  

public:
    OptionScene options;
    
    void AddIfs(string label,Ifs* ifs);
    Ifs* GetIfs(string label);
    
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