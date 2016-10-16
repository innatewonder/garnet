#pragma once

namespace Physics
{
  class PhysicsSystem : public System
  {
  public:
    PhysicsSystem();
    ~PhysicsSystem();

    virtual bool Initialize(ArgParser& args);
    virtual void Destroy();
    virtual void Test();
    virtual void Tick(f32 dt);
    virtual void HandleMessage(Message* msg);

    virtual void RegisterComponent(Component* comp);
    virtual void UnregisterComponent(Component* comp);

  private:
  };
}
