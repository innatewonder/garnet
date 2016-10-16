namespace Graphics
{
  static const String vertexShaderCode =
    "attribute vec4 vPosition; \
    uniform mat4 vProjMatrix; \
    uniform mat4 vViewMatrix; \
    uniform mat4 vModelMatrix; \
    void main() { \
      gl_Position = vProjMatrix * vViewMatrix * vModelMatrix * vPosition; \
    }";

  static const String fragmentShaderCode =
    "precision mediump float; \
    uniform vec4 fColor; \
    void main() { \
      gl_FragColor = fColor; \
    }";
}

// #version 400

// in vec4 vertex;
// in vec2 vertexTexture;

// out vec2 texture;

// void main () 
// {
//   gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vertex;
//   texture = vec2(vertexTexture.x, -vertexTexture.y);
// };