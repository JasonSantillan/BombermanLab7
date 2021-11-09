#include <algorithm>

#include "Scene.h"


Scene::Scene(GameManager* _game)
{
    this->game = _game;
    // set camera to up-left position
    //camera = {0, 0, 0, 0};
}

Scene::~Scene() {}

void Scene::addObject(GameObject* object)
{
    objects.push_back(std::move(object));
}

void Scene::insertObject(GameObject* object, int position)
{
    objects.insert(objects.begin() + position, object);
}

void Scene::removeObject(GameObject* object)
{
    objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

//void Scene::setCamera(const int x, const int y)
//{
//    camera.x = x;
//    camera.y = y;
//}

void Scene::onEnter() {}

void Scene::onExit() {}

void Scene::onEvent(const SDL_Event& /*event*/) {}

void Scene::update(const unsigned int delta)
{
    for (auto& object : objects)
    {
        object->update(delta);
    }
}
//-------------------------------------------------------------------------------------------------------------
void Scene::draw(SDL_Rect& _camera) const
{
    for (const auto& object : objects)
    {
        object->render(_camera);
    }
}
//-------------------------------------------------------------------------------------------------------------
