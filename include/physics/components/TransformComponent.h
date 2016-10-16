#pragma once

namespace Physics
{
  class TransformComponent : public Component
  {
  public:
    TransformComponent(const Math::Point4& pos = Math::Point4::ORIGIN,
                       const Math::Scale& scale = Math::Scale::IDENTITY,
                       const Math::Quaternion& rot = Math::Quaternion::IDENTITY);
    ~TransformComponent();

    void SetPos(const Math::Point4& pos);
    void Translate(const Math::Point4& delta);
    Math::Point4 GetTranslation() const;

    void SetScale(const Math::Scale& scale);
    void Scale(const Math::Scale& delta);
    Math::Scale GetScale() const;

    void SetRotation(const Math::Quaternion& rot);
    void Rotate(const Math::Vector4& delta);
    Math::Quaternion GetRoation() const;

    Math::Matrix GetTransform();

  private:
    bool m_dirty;

    Math::Point4 m_pos;
    Math::Scale m_scale;
    Math::Quaternion m_rot;

    Math::Matrix m_transform;
  };
}
