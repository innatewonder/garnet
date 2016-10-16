#pragma once

namespace Core
{
  class ClickableComponent;
  class InputSystem : public System
  {
  public:
    InputSystem();
    ~InputSystem();

    virtual bool Initialize(ArgParser& args);
    virtual void Destroy();
    virtual void Test();
    virtual void HandleMessage(Message* msg);

    virtual void RegisterComponent(Component* comp);
    virtual void UnregisterComponent(Component* comp);

    virtual void Tick(f32 dt);

  private:
    Containers::List<ClickableComponent*> m_clickables;
  };

}