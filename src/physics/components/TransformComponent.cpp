#include "CommonPrecompiled.h"
#include "TransformComponent.h"

namespace Physics
{
  TransformComponent::TransformComponent(const Math::Point4& pos, 
                                         const Math::Scale& scale,
                                         const Math::Quaternion& rot)
    : m_pos(pos), m_scale(scale), m_rot(rot), m_dirty(true)
  {}

  TransformComponent::~TransformComponent()
  {}

  void TransformComponent::SetPos(const Math::Point4& pos)
  {
    m_dirty = true;
    m_pos = pos;
  }

  void TransformComponent::Translate(const Math::Point4& delta)
  {
    m_dirty = true;
    m_pos += delta;
  }

  Math::Point4 TransformComponent::GetTranslation() const
  {
    return m_pos;
  }

  void TransformComponent::SetScale(const Math::Scale& scale)
  {
    m_dirty = true;
    m_scale = scale;
  }

  void TransformComponent::Scale(const Math::Scale& delta)
  {
    m_dirty = true;
    m_scale *= delta;
  }

  Math::Scale TransformComponent::GetScale() const
  {
    return m_scale;
  }

  void TransformComponent::SetRotation(const Math::Quaternion& rot)
  {
    m_dirty = true;
    m_rot = rot;
  }

  void TransformComponent::Rotate(const Math::Vector4& delta)
  {
    m_dirty = true;
    TODO("Quaternion magic");
    // m_rot.
  }

  Math::Quaternion TransformComponent::GetRoation() const
  {
    return m_rot;
  }

  Math::Matrix TransformComponent::GetTransform()
  {
    if(m_dirty)
    {
      // m_transform = Math::TransformMatrix::Build(m_pos, m_rot, m_scale);
      m_transform = Math::TranslationMatrix(m_pos) * Math::ScaleMatrix(m_scale);
      m_dirty = false;
    }
    return m_transform;
  }
}
