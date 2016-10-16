#pragma once

namespace Graphics
{
  class Shader
  {
  public:
    Shader(const std::string& vs, const std::string& fs);
    ~Shader();
    void Bind(const Math::Matrix& ProjMatrix, const Math::Matrix& ViewMat);
    void UnBind();
    s32  GetID();

    void AddCode(const std::string& code, s32 type);
    void Link();

  private:
    s32 m_id;
  };
}

#if PLATFORM == PLAT_WINDOWS
#define CHECK_GL_ERR \
{ \
int err = glGetError(); \
if(err) { \
    fprintf(stderr, "OpenGL error (at line %d in %s): %i\n", \
    __LINE__, __FILE__, err); \
    __debugbreak(); } \
}
#elif PLATFORM != PLAT_ANDROID
#define CHECK_GL_ERR \
{ \
  int err = glGetError();\
  if (err) { \
    fprintf(stderr, "OpenGL error (at line %d in %s): %s\n", \
      __LINE__, __FILE__, gluErrorString(err)); \
    exit(-1); } \
}
#else
#define CHECK_GL_ERR
#endif
