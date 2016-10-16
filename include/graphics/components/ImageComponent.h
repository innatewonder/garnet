#pragma once

#include "RenderableComponent.h"

namespace Graphics
{
  class ImageComponent : public RenderableComponent
  {
  public:
    ImageComponent();
    ImageComponent(u32 width, u32 height);
    ImageComponent(u32 width, u32 height, const Math::LinearColor& color);
    ~ImageComponent();

    void SetColor(const Math::LinearColor& color);

    void Draw(u32 shaderId);

  private:
    void CreateBuffers();

    u32 m_width, m_height;
    Math::LinearColor m_defaultColor;
  };
}
