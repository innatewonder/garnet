#pragma once

#include "Camera.h"

namespace Graphics
{
  extern Semaphore startSync;
  extern Semaphore endSync;

  void Create();
  void Update(s32 width, s32 height);
  void Frame();

  class Shader;
  class RenderableComponent;
  class GraphicsSystem : public System
  {
  public:
    GraphicsSystem();
    ~GraphicsSystem();

    virtual bool Initialize(ArgParser& args);
    virtual void Destroy();
    virtual void Test();
    virtual void Tick(f32 dt);
    virtual void HandleMessage(Message* msg);

    virtual void RegisterComponent(Component* comp);
    virtual void UnregisterComponent(Component* comp);

    // for render thread
    Containers::List<RenderableComponent*>& GetRenderables();
    Math::Matrix GetVPMatrix();
    void SetShader(Shader* shader);
    Shader* GetShader() const;

  private:
    Containers::List<RenderableComponent*> m_renderables;

    Shader* m_defaultShader;
    Camera m_camera;

    f32 m_front;
    s32 m_height, m_width;
  };

  extern GraphicsSystem* gSystem;
}