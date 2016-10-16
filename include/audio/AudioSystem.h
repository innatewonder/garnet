#pragma once

namespace Audio
{
  class AudioSystem : public System
  {
  public:
    AudioSystem();
    ~AudioSystem();

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
