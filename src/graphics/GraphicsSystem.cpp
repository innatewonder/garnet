#include "CommonPrecompiled.h"
#include "GraphicsSystem.h"
#include "Shader.h"
#include "RenderableComponent.h"

#include "ShaderDef.h"

namespace Graphics
{
  Semaphore startSync;
  Semaphore endSync;

  GraphicsSystem* gSystem;
  GraphicsSystem::GraphicsSystem()
  {
    gSystem = this;
  }

  GraphicsSystem::~GraphicsSystem()
  {
    gSystem = nullptr;
  }

  bool GraphicsSystem::Initialize(ArgParser& args)
  {
    m_front = 1.0f;
    return true;
  }

  void GraphicsSystem::Destroy()
  {}

  void GraphicsSystem::Test()
  {
    Object* obj = Factory::MakeObject();
    auto trans = obj->AddComponent(Comp::TransformComponent);
    auto img = obj->AddComponent(Comp::ImageComponent);
    obj->AddComponent(Comp::ClickableComponent);
    Core::gCore->RegisterObject(obj);
  }

  void GraphicsSystem::Tick(f32 dt)
  {
    startSync.Notify();
    endSync.Wait();
  }

  void GraphicsSystem::HandleMessage(Message* msg)
  {
    switch(msg->GetType()) 
    {
      case Message::MSG_RESIZE:
        m_width = *msg->GetFormatedData<int>();
        m_height = *msg->GetFormatedData<int>();
      break;
    }
  }

  void GraphicsSystem::RegisterComponent(Component* comp)
  {
    System::RegisterComponent(comp);
    RenderableComponent* render = RECAST(RenderableComponent*, comp);
    if(render)
    {
      m_renderables.push_back(render);
    }
  }

  void GraphicsSystem::UnregisterComponent(Component* comp)
  {
    System::UnregisterComponent(comp);
    RenderableComponent* render = RECAST(RenderableComponent*, comp);
    if(render)
    {
      m_renderables.remove(render);
    }
  }

  Containers::List<RenderableComponent*>& GraphicsSystem::GetRenderables()
  {
    return m_renderables;
  }

  Math::Matrix GraphicsSystem::GetVPMatrix()
  {
    Math::Matrix view = m_camera.MakeView();
    return view;
  }

  void GraphicsSystem::SetShader(Shader* shader)
  {
    if(m_defaultShader)
      delete m_defaultShader;
    m_defaultShader = shader;
  }

  Shader* GraphicsSystem::GetShader() const
  {
    return m_defaultShader;
  }

  void Create()
  {
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
    glClearColor(0.3f, 0.3f, 0.3f, 1.f);

    Shader* shader = new Shader(vertexShaderCode, fragmentShaderCode);
    shader->Link();
    gSystem->SetShader(shader);
  }

  static s32 gwidth, gheight;
  void Update(s32 width, s32 height)
  {
    gwidth = width;
    gheight = height;
    glViewport(0, 0, width, height);
  }

  void Frame()
  {
    startSync.Wait();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, gwidth, gheight);
    Math::Matrix view = gSystem->GetVPMatrix();

    f32 fov = Math::PI / 3.f;
    f32 aspect = (f32)gwidth / (f32)gheight;
    Math::Matrix proj = Math::PerspectiveMatrix::Build(fov, aspect, 1.f, 1000.0f);
    
    Shader* shader = gSystem->GetShader();
    shader->Bind(proj, view);
    u32 shaderID = shader->GetID();

    Containers::List<RenderableComponent*>& toRender = gSystem->GetRenderables();
    for(auto r : toRender)
    {
      r->Draw(shaderID);
    }
    
    shader->UnBind();

    endSync.Notify();
  }
}