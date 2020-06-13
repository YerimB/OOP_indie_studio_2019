#include <Scenes/GameScene.hpp>
#include <GameManager.h>
#include <ECS/System/MoveSystem.h>
#include <Map/Map.h>
// Systems
#include <ECS/ECS.h>

// Components
#include <Components/Transform.h>

static void changeSceneToMenu(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::MENU);
}

GameScene::GameScene() : Scene(Scene::GAME)
{
}

GameScene::~GameScene()
{
}

void GameScene::LoadSystems(GameManager* gm)
{
    // Create
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());
    TextSystem* textSys = new TextSystem(gm->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gm->GetEntityManager());

    // Add
    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
    gm->GetEntityManager()->AddSystem(std::move(imageSys));
    gm->GetEntityManager()->AddSystem(std::move(textSys));
    gm->GetEntityManager()->AddSystem(std::move(renderSys));
}

void GameScene::LoadAssets(GameManager* gm)
{
    // Load textures
    this->AddTexture(gm->LoadTexture("Assets/sand.jpg"), "Sand");
    this->AddTexture(gm->LoadTexture("Assets/block.png"), "Block");
    this->AddTexture(gm->LoadTexture("Assets/star.jpeg"), "Star");
    this->AddTexture(gm->LoadTexture("Assets/pow.jpeg"), "Pow");
    this->AddTexture(gm->LoadTexture("Assets/btnHome.png"), "iconHome");

    // Load Meshes
    auto sm = gm->GetSceneManager();
    this->AddMesh(sm->getMesh("Assets/sydney.md2"), "Sydney");
    this->AddMesh(sm->getMesh("Assets/wall.md3"), "Wall");
}

// Load Entities & Components
void GameScene::LoadElements(GameManager* gm)
{
    { // Back to menu button
        // Create components and entity
        Entity e1("BackButton");
        Button* b1 = new Button(gm->GetGuiEnvironment());

        // Initialize component and set attributes then add it to entity
        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(this->GetTexture("iconHome"));
            b1->SetPosition({ 20, 20 });
            b1->SetSize(80, 80);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToMenu);
            e1.AddComponent(std::move(b1), Button::Id);
            // When done, add entity to the entity manager.
            gm->GetEntityManager()->AddEntity(e1);
        }
    }
    {
        Entity e2("AnimatedCharacter");
        Drawable* d1 = new Drawable(gm->GetSceneManager());
        Transform* t1 = new Transform();
        Animator* a1 = new Animator(gm->GetSceneManager());
        Collider* c1 = new Collider();

        if (t1->Initialize(0) && d1->Initialize(this->GetMesh("Sydney")) && \
            c1->Initialize() && a1->Initialize(d1->GetDrawable())) {
            a1->AddAnimation("idle", { 0, 13, 15 });
            a1->PlayAnimation("idle");
            e2.AddComponent(d1, Drawable::Id);
            e2.AddComponent(t1, Transform::Id);
            e2.AddComponent(a1, Animator::Id);
            e2.AddComponent(c1, Collider::Id);
            gm->GetEntityManager()->AddEntity(e2);
        }
    }
    {
        Entity e3("Wall");
        Drawable* d2 = new Drawable(gm->GetSceneManager());
        Transform* t2 = new Transform();
        Collider* c2 = new Collider();

        if (d2->Initialize(this->GetMesh("Wall")) && \
            t2->Initialize(nullptr) && c2->Initialize(nullptr))
        {
            t2->SetPosition({ 20, 0, 0 });
            e3.AddComponent(d2, d2->Id);
            e3.AddComponent(t2, t2->Id);
            e3.AddComponent(c2, c2->Id);
            gm->GetEntityManager()->AddEntity(e3);
        }
    }

    auto map = Map(gm);
    map.Initialize(20, this);
}

void GameScene::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    this->LoadSystems(gameManager);
    this->LoadAssets(gameManager);
    this->LoadElements(gameManager);

    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, { 50, 100, 150 }, { 0, 100, -50 });
}

void GameScene::Update(GameManager* gameManager)
{

}

void GameScene::Unload(void)
{

}