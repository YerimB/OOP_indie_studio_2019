/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerAI
*/

#include <Components/PlayerAI.h>

PlayerAI::PlayerAI(SceneManager *manager) : Player::Player(manager) {}

void PlayerAI::Update(const float& dT, GameManager* gm)
{
    Entity &e = gm->GetEntityManager()->GetEntity(this->m_EntityId);
    Transform *transform = e.GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    this->GetMovements(gm->GetInputManager(), e);
}

void PlayerAI::GetMovements(InputManager *im, Entity &self)
{

}