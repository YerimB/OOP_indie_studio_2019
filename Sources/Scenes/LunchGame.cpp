/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LunchGame
*/

#include <Scenes/LunchGame.hpp>
#include <GameManager.h>

// Systems
#include <ECS/System/ButtonSystem.h>
#include <ECS/ECS.h>

// Components
#include <Components/Transform.h>

static void changeSceneToGame(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::GAME);
}

static void changeSceneToMenu(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::MENU);
}

static void changeCharacterP1(GameManager* gameManager)
{
	gameManager->m_globalVars.playersData[0].characterID += 1;
    if (gameManager->m_globalVars.playersData[0].characterID > 5)
        gameManager->m_globalVars.playersData[0].characterID = 1;
    gameManager->m_globalVars.playersData[0].changedCharacterID = true;
}

static void changeCharacterP2(GameManager* gameManager)
{
	gameManager->m_globalVars.playersData[1].characterID += 1;
    if (gameManager->m_globalVars.playersData[1].characterID > 5)
        gameManager->m_globalVars.playersData[1].characterID = 1;
    gameManager->m_globalVars.playersData[1].changedCharacterID = true;
}

static void changeCharacterP3(GameManager* gameManager)
{
	gameManager->m_globalVars.playersData[2].characterID += 1;
    if (gameManager->m_globalVars.playersData[2].characterID > 5)
        gameManager->m_globalVars.playersData[2].characterID = 1;
    gameManager->m_globalVars.playersData[2].changedCharacterID = true;
}

static void changeCharacterP4(GameManager* gameManager)
{
	gameManager->m_globalVars.playersData[3].characterID += 1;
    if (gameManager->m_globalVars.playersData[3].characterID > 5)
        gameManager->m_globalVars.playersData[3].characterID = 1;
    gameManager->m_globalVars.playersData[3].changedCharacterID = true;
}

static void changeCharactertoAI1(GameManager* gm)
{
    Entity* e = gm->GetEntityManager()->GetEntity("B_P/IA1");
    std::string textureID;

    gm->m_globalVars.playersData[0].isActive = !(gm->m_globalVars.playersData[0].isActive);
    gm->m_globalVars.playersData[0].hasStatusChanged = true;
    textureID.assign(gm->m_globalVars.playersData[0].isActive ? "btnPlayer" : "btnAI");
    e->GetComponent<Button>()->SetTexture(gm->GetCurrentScene()->GetTexture(textureID));
}

static void changeCharactertoAI2(GameManager* gm)
{
    Entity* e = gm->GetEntityManager()->GetEntity("B_P/IA2");
    std::string textureID;

    gm->m_globalVars.playersData[1].isActive = !(gm->m_globalVars.playersData[1].isActive);
    gm->m_globalVars.playersData[1].hasStatusChanged = true;
    textureID.assign(gm->m_globalVars.playersData[1].isActive ? "btnPlayer" : "btnAI");
    e->GetComponent<Button>()->SetTexture(gm->GetCurrentScene()->GetTexture(textureID));
}

static void changeCharactertoAI3(GameManager* gm)
{
    Entity* e = gm->GetEntityManager()->GetEntity("B_P/IA3");
    std::string textureID;

    gm->m_globalVars.playersData[2].isActive = !(gm->m_globalVars.playersData[2].isActive);
    gm->m_globalVars.playersData[2].hasStatusChanged = true;
    textureID.assign(gm->m_globalVars.playersData[2].isActive ? "btnPlayer" : "btnAI");
    e->GetComponent<Button>()->SetTexture(gm->GetCurrentScene()->GetTexture(textureID));
}

static void changeCharactertoAI4(GameManager* gm)
{
    Entity* e = gm->GetEntityManager()->GetEntity("B_P/IA4");
    std::string textureID;

    gm->m_globalVars.playersData[3].isActive = !(gm->m_globalVars.playersData[3].isActive);
    gm->m_globalVars.playersData[3].hasStatusChanged = true;
    textureID.assign(gm->m_globalVars.playersData[3].isActive ? "btnPlayer" : "btnAI");
    e->GetComponent<Button>()->SetTexture(gm->GetCurrentScene()->GetTexture(textureID));
}

static void ChangeText(GameManager* gm)
{
    Entity *e = gm->GetEntityManager()->GetEntity("SizeMapBtn");
    Button *newBtn = e->GetComponent<Button>();

    if (gm->m_globalVars.mapSize < 20)
        gm->m_globalVars.mapSize += 4;
    if (gm->m_globalVars.mapSize == 16) newBtn->SetTexture(gm->GetCurrentScene()->GetTexture("size16"));
    else newBtn->SetTexture(gm->GetCurrentScene()->GetTexture("size20"));
}

static void ChangeTextLower(GameManager* gm)
{
    Entity *e = gm->GetEntityManager()->GetEntity("SizeMapBtn");
    Button *newBtn = e->GetComponent<Button>();

    if (gm->m_globalVars.mapSize > 12)
        gm->m_globalVars.mapSize -= 4;
    if (gm->m_globalVars.mapSize == 16) newBtn->SetTexture(gm->GetCurrentScene()->GetTexture("size16"));
    else newBtn->SetTexture(gm->GetCurrentScene()->GetTexture("size12"));
}

LunchGame::LunchGame() : Scene(Scene::LUNCH_GAME)
{
}

LunchGame::~LunchGame()
{
}

void LunchGame::LoadSystems(GameManager* gm)
{
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());
    TextSystem* textSys = new TextSystem(gm->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gm->GetEntityManager());

    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
    gm->GetEntityManager()->AddSystem(std::move(imageSys));
    gm->GetEntityManager()->AddSystem(std::move(textSys));
    gm->GetEntityManager()->AddSystem(std::move(renderSys));
}

void LunchGame::LoadAssets(GameManager* gm)
{
    gm->GetSoundManager()->AddSound(
        gm->GetSoundManager()->LoadSound("Assets/sound/menu_game.ogg"),
        "sndMenu",
        SoundManager::SoundType::MUSIC
    );

    this->AddTexture(gm->LoadTexture("Assets/textures/buttonChange.png"), "btnChange");
    this->AddTexture(gm->LoadTexture("Assets/textures/mario_bg.jpeg"), "Bg");
    this->AddTexture(gm->LoadTexture("Assets/textures/buttonAI.png"), "btnAI");
    this->AddTexture(gm->LoadTexture("Assets/textures/buttonPlayer.png"), "btnPlayer");
    this->AddTexture(gm->LoadTexture("Assets/textures/btnPlus.png"), "btnPlus");
    this->AddTexture(gm->LoadTexture("Assets/textures/btnMinus.png"), "btnMinus");
    this->AddTexture(gm->LoadTexture("Assets/textures/SwitchContainer.png"), "SwitchContainer");
    this->AddTexture(gm->LoadTexture("Assets/textures/random.png"), "ChangeMusic");
    this->AddTexture(gm->LoadTexture("Assets/textures/music-notes.png"), "ChangeMusic2");
    this->AddTexture(gm->LoadTexture("Assets/textures/btnHome.png"), "iconHome");
    this->AddTexture(gm->LoadTexture("Assets/textures/size12.png"), "size12");
    this->AddTexture(gm->LoadTexture("Assets/textures/size16.png"), "size16");
    this->AddTexture(gm->LoadTexture("Assets/textures/size20.png"), "size20");

    auto sm = gm->GetSceneManager();
    this->AddMesh(sm->getMesh("Assets/mario.b3d"), "Mario");
    this->AddMesh(sm->getMesh("Assets/luigi.b3d"), "Luigi");
    this->AddMesh(sm->getMesh("Assets/koopa.b3d"), "Koopa");
    this->AddMesh(sm->getMesh("Assets/star.b3d"), "Star");
    this->AddMesh(sm->getMesh("Assets/bob-omb.b3d"), "Bob-omb");
    this->AddMesh(sm->getMesh("Assets/blooper.b3d"), "Blooper");

    this->AddTexture(gm->LoadTexture("Assets/textures/game-controller.png"), "texGameController");
}

void LunchGame::LoadElements(GameManager* gameManager)
{
    { // Play button
        Entity playBtnEntity("playBtn");
        Button* btnPlay = new Button(gameManager->GetGuiEnvironment());
        if (btnPlay->Initialize(nullptr))
        {
            btnPlay->SetButtonID(Button::ButtonID::PLAY);
            btnPlay->SetTexture(gameManager->LoadTexture("Assets/textures/btnPlay.png"));
            btnPlay->SetSize(398, 131);
            btnPlay->SetPosition({ 780, 850 });
            btnPlay->SetOnPress(changeSceneToGame);
            playBtnEntity.AddComponent(std::move(btnPlay), Button::Id);
            gameManager->GetEntityManager()->AddEntity(playBtnEntity);
        }
    }

    { // Player01
        Entity e1("Player01");
        Drawable* d1 = new Drawable(gameManager->GetSceneManager());
        Transform* t1 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player1);
        Button* b1 = new Button(gameManager->GetGuiEnvironment());
        Animator* a = new Animator(gameManager->GetSceneManager());

        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::BUTTON_CHANGE_1);
            b1->SetTexture(this->GetTexture("btnChange"));
            b1->SetPosition({ 1500, 700 });
            b1->SetSize(240, 80);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeCharacterP1);
            e1.AddComponent(std::move(b1), Button::Id);
        }
        if (t1->Initialize(0) && d1->Initialize(this->GetMesh("Mario")) && \
        a->Initialize(d1->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e1.AddComponent(a, Animator::Id);
            e1.AddComponent(d1, Drawable::Id);
            e1.AddComponent(newCollider, Drawable::Id);
            e1.AddComponent(t1, Transform::Id);
            d1->SetScale(Vector3f(0.3, 0.3, 0.3));
            d1->SetPosition({-9, -2, 0});
            d1->SetRotation(Vector3f(0, 200, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e1);
    }

    { // Change IA/Player button1 
        Entity e("B_P/IA1");
        Button* b = new Button(gameManager->GetGuiEnvironment());

        if (b->Initialize(nullptr)) {
            b->SetButtonID(Button::ButtonID::CHANGE_P_AI_1);
            b->SetTexture(this->GetTexture("btnAI"));
            b->SetPosition({ 1500, 250 });
            b->SetSize(240, 80);
            b->SetTextureToFit(true);
            b->SetOnPress(changeCharactertoAI1);
            e.AddComponent(std::move(b), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e);
    }

    { // Player02
        Entity e2("Player02");
        Drawable* d2 = new Drawable(gameManager->GetSceneManager());
        Transform* t2 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player2);
        Button* b2 = new Button(gameManager->GetGuiEnvironment());
        Animator* a = new Animator(gameManager->GetSceneManager());

        if (b2->Initialize(nullptr)) {
            b2->SetButtonID(Button::ButtonID::BUTTON_CHANGE_2);
            b2->SetTexture(this->GetTexture("btnChange"));
            b2->SetPosition({ 1020, 700 });
            b2->SetSize(240, 80);
            b2->SetTextureToFit(true);
            b2->SetOnPress(changeCharacterP2);
            e2.AddComponent(std::move(b2), Button::Id);
        }

        if (t2->Initialize(0) && d2->Initialize(this->GetMesh("Luigi")) && \
        a->Initialize(d2->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e2.AddComponent(a, Animator::Id);
            e2.AddComponent(d2, Drawable::Id);
            e2.AddComponent(t2, Transform::Id);
            e2.AddComponent(newCollider, Drawable::Id);
            d2->SetRotation(Vector3f(0, 200, 0));
            d2->SetScale(Vector3f(0.3, 0.3, 0.3));
            d2->SetPosition(Vector3f(-3,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e2);
    }

    { // Change IA/Player button2
        Entity e("B_P/IA2");
        Button* b = new Button(gameManager->GetGuiEnvironment());

        if (b->Initialize(nullptr)) {
            b->SetButtonID(Button::ButtonID::CHANGE_P_AI_2);
            b->SetTexture(this->GetTexture("btnAI"));
            b->SetPosition({ 1010, 250 });
            b->SetSize(240, 80);
            b->SetTextureToFit(true);
            b->SetOnPress(changeCharactertoAI2);
            e.AddComponent(std::move(b), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e);
    }

    { // Player03
        Entity e3("Player03");
        Drawable* d3 = new Drawable(gameManager->GetSceneManager());
        Transform* t3 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player3);
        Button* b3 = new Button(gameManager->GetGuiEnvironment());
        Animator* a = new Animator(gameManager->GetSceneManager());

        if (b3->Initialize(nullptr)) {
            b3->SetButtonID(Button::ButtonID::BUTTON_CHANGE_3);
            b3->SetTexture(this->GetTexture("btnChange"));
            b3->SetPosition({ 600, 700 });
            b3->SetSize(240, 80);
            b3->SetTextureToFit(true);
            b3->SetOnPress(changeCharacterP3);
            e3.AddComponent(std::move(b3), Button::Id);
        }

        if (t3->Initialize(0) && d3->Initialize(this->GetMesh("Koopa")) && \
        a->Initialize(d3->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e3.AddComponent(a, Animator::Id);
            e3.AddComponent(d3, Drawable::Id);
            e3.AddComponent(t3, Transform::Id);
            e3.AddComponent(newCollider, Drawable::Id);
            d3->SetRotation(Vector3f(0, 140, 0));
            d3->SetScale(Vector3f(0.3, 0.3, 0.3));
            d3->SetPosition(Vector3f(3,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e3);
    }

    { // Change IA/Player button3
        Entity e("B_P/IA3");
        Button* b = new Button(gameManager->GetGuiEnvironment());

        if (b->Initialize(nullptr)) {
            b->SetButtonID(Button::ButtonID::CHANGE_P_AI_3);
            b->SetTexture(this->GetTexture("btnAI"));
            b->SetPosition({ 600, 250 });
            b->SetSize(240, 80);
            b->SetTextureToFit(true);
            b->SetOnPress(changeCharactertoAI3);
            e.AddComponent(std::move(b), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e);
    }

    { // Player04
        Entity e4("Player04");
        Drawable* d4 = new Drawable(gameManager->GetSceneManager());
        Transform* t4 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player4);
        Button* b4 = new Button(gameManager->GetGuiEnvironment());
        Animator* a = new Animator(gameManager->GetSceneManager());

        if (b4->Initialize(nullptr)) {
            b4->SetButtonID(Button::ButtonID::BUTTON_CHANGE_4);
            b4->SetTexture(this->GetTexture("btnChange"));
            b4->SetPosition({ 100, 700 });
            b4->SetSize(240, 80);
            b4->SetTextureToFit(true);
            b4->SetOnPress(changeCharacterP4);
            e4.AddComponent(std::move(b4), Button::Id);
        }

        if (t4->Initialize(0) && d4->Initialize(this->GetMesh("Star")) && \
        a->Initialize(d4->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e4.AddComponent(a, Animator::Id);
            e4.AddComponent(d4, Drawable::Id);
            e4.AddComponent(t4, Transform::Id);
            e4.AddComponent(newCollider, Drawable::Id);
            d4->SetRotation(Vector3f(0, 140, 0));
            d4->SetScale(Vector3f(0.3, 0.3, 0.3));
            d4->SetPosition(Vector3f(10,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e4);
    }

    { // Change IA/Player button4
        Entity e("B_P/IA4");
        Button* b = new Button(gameManager->GetGuiEnvironment());

        if (b->Initialize(nullptr)) {
            b->SetButtonID(Button::ButtonID::CHANGE_P_AI_4);
            b->SetTexture(this->GetTexture("btnAI"));
            b->SetPosition({ 100, 250 });
            b->SetSize(240, 80);
            b->SetTextureToFit(true);
            b->SetOnPress(changeCharactertoAI4);
            e.AddComponent(std::move(b), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e);
    }

    {
        Entity e11("Bob-omb");
        Drawable* d10 = new Drawable(gameManager->GetSceneManager());
        Transform* t10 = new Transform();
        Collider *newCollider = new Collider();

        if (t10->Initialize(0) && d10->Initialize(this->GetMesh("Bob-omb")))
        {
            e11.AddComponent(d10, Drawable::Id);
            e11.AddComponent(t10, Transform::Id);
            e11.AddComponent(newCollider, Drawable::Id);
            d10->SetRotation(Vector3f(10, 0, 90));
            d10->SetScale(Vector3f(0.3, 0.3, 0.3));
            d10->SetPosition(Vector3f(-10,5, -1));
        }
        gameManager->GetEntityManager()->AddEntity(e11);
    }

    {
        Entity e12("Bob-omb2");
        Drawable* d11 = new Drawable(gameManager->GetSceneManager());
        Transform* t11 = new Transform();
        Collider *newCollider = new Collider();

        if (t11->Initialize(0) && d11->Initialize(this->GetMesh("Bob-omb")))
        {
            e12.AddComponent(d11, Drawable::Id);
            e12.AddComponent(t11, Transform::Id);
            e12.AddComponent(newCollider, Drawable::Id);
            d11->SetRotation(Vector3f(10, 0, 90));
            d11->SetScale(Vector3f(0.3, 0.3, 0.3));
            d11->SetPosition(Vector3f(15,-4, -3));
        }
        gameManager->GetEntityManager()->AddEntity(e12);
    }

    {
        Entity e8("SizeMap");
        Button* b3 = new Button(gameManager->GetGuiEnvironment());

        if (b3->Initialize(nullptr)) {
            b3->SetButtonID(Button::ButtonID::UPPERSIZEMAP);
            b3->SetTexture(this->GetTexture("btnPlus"));
            b3->SetPosition({ 1000, 100 });
            b3->SetSize(120, 60);
            b3->SetTextureToFit(true);
            b3->SetOnPress(ChangeText);
            e8.AddComponent(std::move(b3), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e8);
    }
    {
        Entity SizeMapBtn("SizeMapBtn");
        Button* btnMap = new Button(gameManager->GetGuiEnvironment());

        if (btnMap->Initialize(nullptr)) {
            btnMap->SetButtonID(Button::ButtonID::UPPERSIZEMAP);
            btnMap->SetTexture(this->GetTexture("size16"));
            btnMap->SetPosition({ 850, 110 });
            btnMap->SetSize(120, 60);
            btnMap->SetTextureToFit(true);
            btnMap->SetOnPress(ChangeText);
            SizeMapBtn.AddComponent(std::move(btnMap), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(SizeMapBtn);
    }

    {
        Entity e9("SizeMap2");

        Button* b4 = new Button(gameManager->GetGuiEnvironment());
        if (b4->Initialize(nullptr)) {
            b4->SetButtonID(Button::ButtonID::LOWERSIZEMAP);
            b4->SetTexture(this->GetTexture("btnMinus"));
            b4->SetPosition({ 700, 100 });
            b4->SetSize(120, 60);
            b4->SetTextureToFit(true);
            b4->SetOnPress(ChangeTextLower);
            e9.AddComponent(std::move(b4), Button::Id);
        }

        gameManager->GetEntityManager()->AddEntity(e9);
    }

    {
        Entity e10("SwitchContainer");

        Button* b4 = new Button(gameManager->GetGuiEnvironment());
        if (b4->Initialize(nullptr)) {
            b4->SetButtonID(Button::ButtonID::UNDEFINED);
            b4->SetTexture(this->GetTexture("SwitchContainer"));
            b4->SetPosition({ 860, 60 });
            b4->SetSize(100, 40);
            b4->SetTextureToFit(true);
            e10.AddComponent(std::move(b4), Button::Id);
        }

        gameManager->GetEntityManager()->AddEntity(e10);
    }

    { // Back to menu button
        Entity e14("BackButton");
        Button* b1 = new Button(gameManager->GetGuiEnvironment());

        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(this->GetTexture("iconHome"));
            b1->SetPosition({ 20, 20 });
            b1->SetSize(80, 80);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToMenu);
            e14.AddComponent(std::move(b1), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e14);
    }

}

void LunchGame::Load(GameManager* gameManager)
{
    srand(time(NULL));
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    // Load Entities & Components
    this->LoadSystems(gameManager);
    this->LoadAssets(gameManager);
    this->LoadElements(gameManager);

    // Music
	gameManager->GetSoundManager()->setLoop("sndMenu", (-1));
    gameManager->GetSoundManager()->PlaySound("sndMenu");

    // gameManager->GetSoundManager()->GetSound("sndMenu");

    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 0, 10), { 0, 0, 0 });
}

void LunchGame::Update(GameManager* gm)
{
    std::string pstr("Player0");

    for (int idx = 1; idx <= 4; ++idx)
    {
        if (gm->m_globalVars.playersData[idx - 1].changedCharacterID)
        {
            Entity* e = gm->GetEntityManager()->GetEntity(pstr.append(std::to_string(idx)));
            Drawable *d = e->GetComponent<Drawable>();
            Animator *a = e->GetComponent<Animator>();
            size_t meshID = gm->m_globalVars.playersData[idx - 1].characterID;
            AMesh *mesh = this->GetMesh(gm->m_globalVars.meshIDMap.at(meshID));

            mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            static_cast<AMeshNode *>(d->GetDrawable())->setMesh(mesh);
            a->PlayAnimation("Idle");
            gm->m_globalVars.playersData[idx - 1].changedCharacterID = false;
        }
    }
    Entity* e1 = gm->GetEntityManager()->GetEntity("Bob-omb");
    Drawable *d1 = e1->GetComponent<Drawable>();
    Entity* e2 = gm->GetEntityManager()->GetEntity("Bob-omb2");
    Drawable *d2 = e2->GetComponent<Drawable>();
    d1->SetPosition(Vector3f(d1->GetPosition().X + 0.05, d1->GetPosition().Y, d1->GetPosition().Z));
    int r  = (rand() % 2 + 1);
    int r1 = (rand() % 2 + 1);
    d1->SetRotation(Vector3f(d1->GetRotation().X + r, d1->GetRotation().Y + r1, d1->GetRotation().Z));

    if (d1->GetPosition().X > 16)
    {
        d1->SetPosition(Vector3f(-15, rand() % 5 - 5, d1->GetPosition().Z));
    }

    d2->SetPosition(Vector3f(d2->GetPosition().X - 0.03, d2->GetPosition().Y, d2->GetPosition().Z));
    d2->SetRotation(Vector3f(d2->GetRotation().X + r1, d2->GetRotation().Y + r1, d2->GetRotation().Z));

    if (d2->GetPosition().X < -18)
    {
        d2->SetPosition(Vector3f(18, rand() % 5 - 5, d2->GetPosition().Z));
    }

}

void LunchGame::Unload(void)
{

}