#pragma once


#include<iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include "Bomberman.h"
#include "MuroMetal.h"
#include "MapGenerator.h"
#include "system/KeyboardInput.h"
#include "TilesGraph.h"
//-------------------------------------------------------------------------------------------------
#include "SceneManager.h"
#include "AssetManager.h"
#include <memory>
//-------------------------------------------------------------------------------------------------
using namespace std;


class GameManager
{
private:
    //-------------------------------------------------------------------------------------------------
    //Lo que añadí
    SceneManager* sceneManager = nullptr; // scene manager
    AssetManager* assetManager = nullptr; // asset manager
    bool isRunning;

    int SCREEN_WIDTH = 850;
    int SCREEN_HEIGHT = 510;

    //-------------------------------------------------------------------------------------------------


    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

    //Current displayed texture
    SDL_Texture* gTexture = nullptr;

    vector<GameObject*> actoresJuego;
    MapGenerator* generadorMapa;
    KeyboardInput* keyboardInput;


    SDL_Event evento;
    bool enEjecucion;

    TilesGraph* tilesGraphGM;

    SDL_Rect camera;
    Uint32 lastTickTime = 0;


public:
    // Constructores & destructores
    GameManager();

    // Metodos especializados
    bool onInit();
    bool loadContent();
    int onExecute();
    void onEvent(SDL_Event* _event);
    void onLoop();
    void onRender();
    void close();

    //---------------------------------------------------------------------------------------------
    //Métodos que añadí
    void stop();
    int getWindowWidth() const;
    int getWindowHeight() const;
    SDL_Renderer* getRenderer() const;
    SceneManager* getSceneManager() const;
    AssetManager* getAssetManager() const;
    //-------------------------------------------------------------------------------------------------

};
