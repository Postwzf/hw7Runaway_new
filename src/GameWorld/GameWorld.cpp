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
    if (clock % 240 == 0)
    {
        //生成哥布林
        Instantiate(std::make_shared<Enemies>(WINDOW_WIDTH - 1, 120, shared_from_this()));
    }
    clock++;

    for (auto gameobeject : m_gameObjects)
    {
        gameobeject->Update();
    }

    //检测碰撞（未做）
    // if 如何如何，调用碰撞的函数
    //子弹哥布林
    // if ((Enemies.GetX()-Bullet.GetX()) <= 15) && abs(Bullet.GetY() - Enemies.GetY()) <= 29)
    // {
    //     Bullet->OnCollision(Enemies);
    // }
    for (auto gameObject1 : m_gameObjects)
    {
        for (auto gameObject2 : m_gameObjects)
        {
            if (gameObject1 != gameObject2)
            {
                // 子弹和哥布林
                if (gameObject1->GetType() == GameObject::Type::ProjectilePlayer && gameObject2->GetType() == GameObject::Type::Enemy){
                    if (abs(gameObject1->GetX() - gameObject2->GetX()) <= 15 && abs(gameObject1->GetY() - gameObject2->GetY()) <= 29){
                        gameObject1->OnCollision(gameObject2);
                    }
                }
                //斧头和玩家
                if (gameObject1->GetType() == GameObject::Type::ProjectileEnemy && gameObject2->GetType() == GameObject::Type::Player){
                    if (abs(gameObject1->GetX() - gameObject2->GetX()) <= 22.5 && abs(gameObject1->GetY() - gameObject2->GetY()) <= 36.5){
                        gameObject1->OnCollision(gameObject2);
                    }
                }
                //哥布林和玩家
                if (gameObject1->GetType() == GameObject::Type::Enemy && gameObject2->GetType() == GameObject::Type::Player){
                    if (abs(gameObject1->GetX() - gameObject2->GetX()) <= 20 && abs(gameObject1->GetY() - gameObject2->GetY()) <= 48){
                        gameObject1->OnCollision(gameObject2);
                    }
                }
            }
        }
    }


    // scoreText->SetText("Score: " + std::to_string(score));
    // HPText->SetText("HP: " + std::to_string(current_hp));

    // for (auto gameobeject : m_gameObjects)
    // {
    //     //删除
    //     if (!gameobeject->IsAlive())
    //     {
    //         m_gameObjects.remove(gameobeject);
    //     }
    // }
    m_gameObjects.remove_if([](const std::shared_ptr<GameObject>& obj) {
        return !obj->IsAlive();
    });

    //判断玩家是否死亡，更新文本显示



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
