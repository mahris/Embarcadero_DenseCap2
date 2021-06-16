#pragma once

#include <comdef.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;

extern "C" {

  __declspec(dllexport) BSTR Densecap_ProcessFile(BSTR key, BSTR filename)
  {
    String^ skey = Marshal::PtrToStringBSTR(static_cast<IntPtr>(key));
    String^ sfilename = Marshal::PtrToStringBSTR(static_cast<IntPtr>(filename));
    String^ sresult = DeepAICsWrapper::Wrapper::Densecap_ProcessFile(skey, sfilename);
    const OLECHAR* chars = (const OLECHAR*)(Marshal::StringToHGlobalUni(sresult)).ToPointer();
    BSTR bresult = SysAllocString(chars);
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return bresult;
  }

  __declspec(dllexport) BSTR Densecap_ProcessUrl(BSTR key, BSTR url)
  {
    String^ skey = Marshal::PtrToStringBSTR(static_cast<IntPtr>(key));
    String^ surl = Marshal::PtrToStringBSTR(static_cast<IntPtr>(url));
    String^ sresult = DeepAICsWrapper::Wrapper::Densecap_ProcessUrl(skey, surl);
    const OLECHAR* chars = (const OLECHAR*)(Marshal::StringToHGlobalUni(sresult)).ToPointer();
    BSTR bresult = SysAllocString(chars);
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return bresult;
  }

}