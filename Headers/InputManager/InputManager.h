#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <memory>

#include <Irrlicht/irrlicht.h>
#include <Bindable/Bindable.hpp>

using namespace irr;

class InputManager : public IEventReceiver
{
    public:
        InputManager(IrrlichtDevice *device);

    public:
        virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;
        void RunKeyboardManager();

    public:
        template<typename T>
        void AddBindable(IBindable* bindable);
        template<typename T>
        void AddBindable(std::unique_ptr<IBindable>& bindable);

    public:
        UniqueBindable& GetBindableByName(const std::string& name);

    private:
        std::unique_ptr<IrrlichtDevice> m_Device;
        std::vector<bool> m_KeyDown;
        SEvent::SJoystickEvent m_JoystickState;
        std::unordered_map<std::string, UniqueBindable> m_Bindables;
};

#include <InputManager/InputManager.inl>