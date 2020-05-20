#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "text_renderer.h"
#include "route_planner.h"
#include "model.h"
#include "camera.h"
#include "game_object.h"    
#include "terrain.h"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_PAUSED,
    GAME_WIN,
    GAME_LOSS
};

enum CameraState {
  FIRST_PERSON,
  THIRD_PERSON,
  BIRD_VIEW
};

class Game {
  public:
    bool keys[1024];
    unsigned int score;
    float flashlight = false;
    GameState state;
    RoutePlanner route;
    Camera camera = Camera(glm::vec3(0.0f, 10.0f, 0.0f));

    void init();
    void update(float dt);
    void processInput(float dt);
    void render();
    void renderEndScreen();
  private:
    int view = 0;
    Model lamp;
    Model tree;
    Model player;
    std::vector<GameObject> objects;
    Terrain terrain;
    
    Shader shader;
    Shader skyboxShader;
    TextRenderer text;
    
    void displayScore();
    void setLighting();
    void setUpTransformations();
    void checkCollision(float dt);
    void drawPlayer();
    void drawTrees();
    void drawLamps();
    void setTrees();
    void setLamps();
    std::vector<glm::vec3> treePos;
    std::vector<glm::vec3> lampPos;
};

#endif