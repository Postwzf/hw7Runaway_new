#include "runaway/GameWorld/GameWorld.hpp"

#include "runaway/Framework/TextBase.hpp"
#include "runaway/GameObject/Background.hpp"
#include "runaway/GameObject/Player.hpp"
#include "runaway/GameObject/Enemies.hpp"
#include "runaway/GameObject/Projectiles.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
    Instantiate(std::make_shared<Background>(shared_from_this()));
    // YOUR CODE HERE
    Instantiate(std::make_shared<Player>(shared_from_this()));
    scoreText = new TextBase(WINDOW_WIDTH - 160, 8, "Score: 0", 1, 1, 1, true);
    HPText = new TextBase(WINDOW_WIDTH - 160, 25, "HP: 3", 1, 1, 1, true);
    //怎么显示分数？？
    // Instantiate(std::shared_ptr<GameObject>(scoreText));
}

LevelStatus GameWorld::Update()
{
    // YOUR CODE HERE
    clock++;
    if (clock % 240 == 0)
    {
        //生成哥布林
        // Instantiate(std::make_shared<Enemies>(WINDOW_WIDTH - 1, 120, shared_from_this()));
    }
    for (auto& gameobeject : m_gameObjects)
    {
        gameobeject->Update();
    }

    //检测碰撞（未做）



    // scoreText->SetText("Score: " + std::to_string(score));

    for (auto& gameobeject : m_gameObjects)
    {
        //删除
        if (!gameobeject->IsAlive())
        {
            m_gameObjects.remove(gameobeject);
        }
    }

    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    // YOUR CODE HERE
    m_gameObjects.clear();

    // 删除分数文本




}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    m_gameObjects.push_back(newGameObject);
}
