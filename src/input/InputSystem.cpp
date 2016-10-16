#include "CommonPrecompiled.h"
#include "InputSystem.h"

#include "ClickableComponent.h"

namespace Core
{
  InputSystem::InputSystem()
  {

  }

  InputSystem::~InputSystem()
  {

  }

  bool InputSystem::Initialize(ArgParser& args)
  {

  }

  void InputSystem::Destroy()
  {

  }

  void InputSystem::Test()
  {

  }

  void InputSystem::HandleMessage(Message* msg)
  {
    switch(msg->GetType())
    {
      case Message::MSG_MOUSE:
      case Message::MSG_MOUSE_BUTTON:
        for(auto click : m_clickables) 
        {
          click->HandleMessage(msg);
        }
      break;
    }
  }

  void InputSystem::Tick(f32 dt)
  {

  }

  void InputSystem::RegisterComponent(Component* comp)
  {
    System::RegisterComponent(comp);
    ClickableComponent* clickable = RECAST(ClickableComponent*, comp);
    m_clickables.push_back(clickable);
  }

  void InputSystem::UnregisterComponent(Component* comp)
  {
    System::UnregisterComponent(comp);
    ClickableComponent* click = RECAST(ClickableComponent*, comp);
    if(click)
    {
      m_clickables.remove(click);
    }
  }
}