#include "CommonPrecompiled.h"
#include <jni.h>

void on_surface_created(JNIEnv* env, jclass cls)
{
  ArgParser parser(0, nullptr);
  Run(parser);
  Graphics::Create();
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

static JNINativeMethod methodTable[] = {
  {"on_surface_created", "()V", (void *) on_surface_created},
  {"on_surface_changed", "(II)V", (void *) on_surface_changed},
  {"on_draw_frame", "()V", (void *) on_draw_frame},
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
