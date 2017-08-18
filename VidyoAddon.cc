// VidyoAddon.cc
#include <node.h>
#include "Lmi/VidyoClient/VidyoClientElectron.h"
#include "Lmi/Os/LmiMallocAllocator.h"
#include <string>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void VidyoAddonInit(const FunctionCallbackInfo<Value>& args)
{
  Isolate* isolate = args.GetIsolate();

  if (VidyoClientElectronInit())
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Succeed"));
  else
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Fail"));
}

void VidyoAddonUninit(const FunctionCallbackInfo<Value>& args)
{
  VidyoClientElectronUninit();
}

void VidyoAddonDispatch(const FunctionCallbackInfo<Value>& args)
{
  Isolate* isolate = args.GetIsolate();
  String::Utf8Value data(args[0]->ToString());
  std::string request(*data);
  LmiString requestSt;
  LmiString responseSt;
  LmiAllocator *alloc;

  alloc = LmiMallocAllocatorGetDefault(); 
  LmiStringConstructCStr(&requestSt, request.c_str(), alloc);
  LmiStringConstructDefault(&responseSt, alloc);
  VidyoClientElectronDispatch(&requestSt, &responseSt);

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, LmiStringCStr(&responseSt)));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "VidyoAddonInit", VidyoAddonInit);
  NODE_SET_METHOD(exports, "VidyoAddonUninit", VidyoAddonUninit);
  NODE_SET_METHOD(exports, "VidyoAddonDispatch", VidyoAddonDispatch);
}

NODE_MODULE(VidyoAddon, init)

