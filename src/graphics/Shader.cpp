#include "CommonPrecompiled.h"
#include <fstream>
#include "Shader.h"

namespace Graphics
{
  Shader::Shader(const std::string& vs, const std::string& fs)
  {
    m_id = glCreateProgram();

    AddCode(vs, GL_VERTEX_SHADER);
    AddCode(fs, GL_FRAGMENT_SHADER);

    glBindAttribLocation(m_id, 0, "vPosition");
    // glBindAttribLocation(m_id, 1, "vertexNormal");
    // glBindAttribLocation(m_id, 2, "vertexTexture");
    CHECK_GL_ERR;
  }

  Shader::~Shader()
  {
    glDeleteProgram(m_id);
    m_id = 0;
  }

  void Shader::Bind(const Math::Matrix& projMatrix, const Math::Matrix& viewMat)
  {
    glUseProgram(m_id);
    CHECK_GL_ERR;

    int loc = glGetUniformLocation(m_id, "vProjMatrix");
    CHECK_GL_ERR;
    glUniformMatrix4fv(loc, 1, GL_FALSE, (projMatrix.v));

    loc = glGetUniformLocation(m_id, "vViewMatrix");
    CHECK_GL_ERR;
    glUniformMatrix4fv(loc, 1, GL_FALSE, (viewMat.v));
    CHECK_GL_ERR;
  }

  void Shader::UnBind()
  {
    glUseProgram(0);
    CHECK_GL_ERR;
  }

  s32 Shader::GetID()
  {
    return m_id;
  }

  void Shader::AddCode(const std::string& code, s32 type)
  {
    LOG("Adding code to shader " << m_id);

    s32 current = glCreateShader(type);
    const char* constCode = code.c_str();
    glShaderSource(current, 1, &constCode, NULL);
    glCompileShader(current);
    CHECK_GL_ERR;

    // Get the compilation status
    int status = 0;
    glGetShaderiv(current, GL_COMPILE_STATUS, &status);

    // If compilation status is not OK, get and print the log message.
    if(status != 1) {
      WARN("Failure");
      int length = 0;
      glGetShaderiv(current, GL_INFO_LOG_LENGTH, &length);
      char* buffer = new char[length];
      glGetShaderInfoLog(current, length, NULL, buffer);
      LOG("Compile log:\n" << buffer);
      delete buffer;
    }
    else
    {
      LOG("Success");
      glAttachShader(m_id, current);
    }
    CHECK_GL_ERR;
  }

  void Shader::Link()
  {
    LOG("Linking Shader " << m_id);
    glLinkProgram(m_id);
    int status;
    glGetProgramiv(m_id, GL_LINK_STATUS, &status);
    CHECK_GL_ERR;

    // If link failed, get and print log
    if(status != 1) {
      WARN("Failure");
      int length;
      glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &length);
      char* buffer = new char[length];
      glGetProgramInfoLog(m_id, length, NULL, buffer);
      LOG("Link log:\n" << buffer);
      delete buffer;
    }
    else
    {
      LOG("Success");
    }
    CHECK_GL_ERR;
  }
}
