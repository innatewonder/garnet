#include "CommonPrecompiled.h"
#include <jni.h>

void on_surface_created(JNIEnv* env, jclass cls)
{
  static bool created = false;

  if(!created) 
  {
    ArgParser parser(0, nullptr);
    Run(parser);
    Graphics::Create();
    created = true;
  }
}

void on_surface_changed(JNIEnv* env, jclass cls, jint width, jint height)
{
  Message* m = MESSAGE(Message::MSG_RESIZE);
  m->AddData(DAT(width));
  m->AddData(DAT(height));
  Core::gCore->SendMessage(m);

  Graphics::Update(width, height);
}

void on_draw_frame(JNIEnv* env, jclass cls)
{
  Graphics::Frame();
}

void handleTouchPress(JNIEnv* env, jclass cls, jfloat x, jfloat y)
{
  Message* m = MESSAGE(Message::MSG_MOUSE_BUTTON);
  m->AddData(DAT(x));
  m->AddData(DAT(y));
  m->AddData(true);
  Core::gCore->SendMessage(m);
}

void handleTouchRelease(JNIEnv* env, jclass cls, jfloat x, jfloat y)
{
  Message* m = MESSAGE(Message::MSG_MOUSE_BUTTON);
  m->AddData(DAT(x));
  m->AddData(DAT(y));
  m->AddData(false);
  Core::gCore->SendMessage(m);
}

void handleTouchDrag(JNIEnv* env, jclass cls, jfloat x, jfloat y)
{
  Message* m = MESSAGE(Message::MSG_MOUSE);
  m->AddData(DAT(x));
  m->AddData(DAT(y));
  Core::gCore->SendMessage(m);
}

static JNINativeMethod methodTable[] = {
  {"on_surface_created", "()V", (void *) on_surface_created},
  {"on_surface_changed", "(II)V", (void *) on_surface_changed},
  {"on_draw_frame", "()V", (void *) on_draw_frame},
  {"handleTouchPress", "(FF)V", (void *) handleTouchPress},
  {"handleTouchRelease", "(FF)V", (void *) handleTouchRelease},
  {"handleTouchDrag", "(FF)V", (void *) handleTouchDrag},
};

static JNIEnv* env;
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}
    env->RegisterNatives(env->FindClass("io/projektiris/silver/JNIWrapper"),
                        methodTable,
                        sizeof(methodTable) / sizeof(methodTable[0]));
    return JNI_VERSION_1_6;
}
