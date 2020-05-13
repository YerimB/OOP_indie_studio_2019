#include <InputManager/InputManager.hpp>

using namespace irr;

InputManager::InputManager(IrrlichtDevice* device)
{
    m_Device = std::unique_ptr<IrrlichtDevice>(device);
    m_KeyDown = std::vector<bool>(KEY_KEY_CODES_COUNT);

    std::fill(m_KeyDown.begin(), m_KeyDown.end(), false);
}

bool InputManager::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        m_KeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }

    return false;
}

bool InputManager::IsKeyDown(EKEY_CODE keyCode) const
{
    return m_KeyDown[keyCode];
}

Unique<IBindable>& InputManager::GetBindableByName(const std::string& name)
{
    for (auto& bindable : m_Bindables)
    {
        if (bindable.first == name)
            return bindable.second;
    }

    throw;
}

void InputManager::RunKeyboardManager()
{

    while (m_Device->run())
    {
        if (IsKeyDown(irr::KEY_KEY_Z)) {
            auto& bindable = GetBindableByName("PlayerPosition");
            auto& value = bindable->GetValue<Vector2f>();

            value.Y += 10;
            bindable->SetValue(value);
        }
    }
}