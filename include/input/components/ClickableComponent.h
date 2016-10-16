#pragma once

namespace Core
{
  class ClickableComponent : public Component
  {
  public:
    void HandleMessage(Message* msg);
  };
}
