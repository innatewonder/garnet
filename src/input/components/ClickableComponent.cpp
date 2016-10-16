#include "CommonPrecompiled.h"
#include "ClickableComponent.h"

namespace Core
{
  void ClickableComponent::HandleMessage(Message* msg)
  {
    f32 x = *msg->GetFormatedData<f32>();
    f32 y = *msg->GetFormatedData<f32>();
    switch(msg->GetType())
    {
      case Message::MSG_MOUSE:
        LOG("drag x: " << x << " y: " << y);
      break;
      case Message::MSG_MOUSE_BUTTON:
        bool down = *msg->GetFormatedData<bool>();
        LOG("x: " << x << " y: " << y << down? " down" : " up");
      break;
    }
  }
}
