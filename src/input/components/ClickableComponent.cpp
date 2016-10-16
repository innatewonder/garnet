#include "CommonPrecompiled.h"
#include "ClickableComponent.h"

#include "TransformComponent.h"

namespace Core
{
  void ClickableComponent::HandleMessage(Message* msg)
  {
    static f32 lastX = 0.f;
    static f32 lastY = 0.f;

    assertion(m_parent);
    auto c = GetParent()->GetComponent(Comp::TransformComponent);
    assertion(c);
    Physics::TransformComponent* transform = RECAST(Physics::TransformComponent*, c);

    Math::Point4 pos;
    f32 x = *msg->GetFormatedData<f32>();
    f32 y = *msg->GetFormatedData<f32>();
    TODO("this is temp");
    switch(msg->GetType())
    {
      case Message::MSG_MOUSE:
        LOG("drag x: " << x << " y: " << y);
        LOG("delta x: " << x - lastX << " y: " << y - lastY);
        transform->Translate(Math::Point4(x - lastX, y - lastY));
        pos = transform->GetTranslation();
        if(pos.x > 2.f) pos.x = 2.f;
        if(pos.x < -2.f) pos.x = -2.f;
        if(pos.y > 4.f) pos.y = 4.f;
        if(pos.y < -4.f) pos.y = -4.f;
        transform->SetPos(pos);
      break;
      case Message::MSG_MOUSE_BUTTON:
        bool down = *msg->GetFormatedData<bool>();
        lastX = x;
        lastY = y;
        LOG("x: " << x << " y: " << y << (down ? " down" : " up"));
        transform->Scale(Math::Scale((down ? 1.5f : 0.666666f)));
      break;
    }
  }
}
