// VidyoAddon.cc
#include <nan.h>
#include "Lmi/VidyoClient/VidyoClientElectron.h"
#include "Lmi/Os/LmiMallocAllocator.h"
#include <string>

void VidyoAddonInit(const Nan::FunctionCallbackInfo<v8::Value>& args)
{
    // v8::Local<v8::Context> context = args.GetIsolate()->GetCurrentContext();
    if (VidyoClientElectronInit())
        args.GetReturnValue().Set(Nan::New(true));
    else
        args.GetReturnValue().Set(Nan::New(false));
}
//
void VidyoAddonUninit(const Nan::FunctionCallbackInfo<v8::Value>& args)
{
    VidyoClientElectronUninit();
}
//
void VidyoAddonDispatch(const Nan::FunctionCallbackInfo<v8::Value>& args)
{
  // v8::Isolate* isolate = args.GetIsolate();
  // v8::String::Utf8Value data(args[0]->ToString());
  Nan::Utf8String data(args[0]);
  std::string request(*data);
  LmiString requestSt;
  LmiString responseSt;
  LmiAllocator *alloc;

  alloc = LmiMallocAllocatorGetDefault();
  LmiStringConstructCStr(&requestSt, request.c_str(), alloc);
  LmiStringConstructDefault(&responseSt, alloc);
  VidyoClientElectronDispatch(&requestSt, &responseSt);


  args.GetReturnValue().Set(Nan::New(LmiStringCStr(&responseSt)).ToLocalChecked());
}

void init(v8::Local<v8::Object> exports) {
    v8::Local<v8::Context> context = exports->CreationContext();

    exports->Set(context,
        Nan::New("VidyoAddonInit").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(VidyoAddonInit)
        ->GetFunction(context)
        .ToLocalChecked()
    );

    exports->Set(context,
        Nan::New("VidyoAddonUninit").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(VidyoAddonUninit)
        ->GetFunction(context)
        .ToLocalChecked()
    );

    exports->Set(context,
        Nan::New("VidyoAddonDispatch").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(VidyoAddonDispatch)
        ->GetFunction(context)
        .ToLocalChecked()
    );

    // NODE_SET_METHOD(exports, "VidyoAddonInit", VidyoAddonInit);
    // NODE_SET_METHOD(exports, "VidyoAddonUninit", VidyoAddonUninit);
    // NODE_SET_METHOD(exports, "VidyoAddonDispatch", VidyoAddonDispatch);
}


NODE_MODULE(VidyoAddon, init)
