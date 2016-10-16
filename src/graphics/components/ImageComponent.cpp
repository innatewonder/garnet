#include "CommonPrecompiled.h"
#include "ImageComponent.h"
#include "TransformComponent.h"

namespace Graphics
{
  static const f32 squareVerts[] = {
    -0.5f,  0.5f, 0.0f, // tl
    -0.5f, -0.5f, 0.0f, // bl
    0.5f,   0.5f, 0.0f, // tr
    0.5f,  -0.5f, 0.0f, // br
  };

  ImageComponent::ImageComponent()
    : m_width(1), m_height(1), m_defaultColor(Math::LinearColor::VIOLET)
  {}

  ImageComponent::ImageComponent(u32 width, u32 height)
    : m_width(width), m_height(height), m_defaultColor(Math::LinearColor::VIOLET)
  {}

  ImageComponent::ImageComponent(u32 width, u32 height, const Math::LinearColor& color)
    : m_width(width), m_height(height), m_defaultColor(color)
  {}

  ImageComponent::~ImageComponent()
  {}

  void ImageComponent::SetColor(const Math::LinearColor& color)
  {
    m_defaultColor = color;
  }

  void ImageComponent::Draw(u32 shaderId)
  {
    assertion(m_parent);
    auto c = GetParent()->GetComponent(Comp::TransformComponent);
    assertion(c);
    Physics::TransformComponent* transform = RECAST(Physics::TransformComponent*, c);
    Math::Matrix model = transform->GetTransform();

    s32 loc = glGetUniformLocation(shaderId, "vModelMatrix");
    glUniformMatrix4fv(loc, 1, GL_FALSE, (model.v));

    loc = glGetUniformLocation(shaderId, "fColor");
    glUniform4fv(loc, 1, (m_defaultColor.v));

    loc = glGetAttribLocation(shaderId, "vPosition");
    glVertexAttribPointer(loc, 3, GL_FLOAT,
                          false, 0, squareVerts);
    glEnableVertexAttribArray(loc);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisableVertexAttribArray(loc);
  }
}