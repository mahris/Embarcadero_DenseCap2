#pragma once

#include <comdef.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;

/*namespace DeepAIClrWrapper {
	public ref class Class1
	{
		// TODO: Add your methods for this class here.
	};
}*/

extern "C" {
  __declspec(dllexport) BSTR Densecap_ProcessFile(BSTR key, BSTR filename)
  {
    String^ skey = Marshal::PtrToStringBSTR(static_cast<IntPtr>(key));
    String^ sfilename = Marshal::PtrToStringBSTR(static_cast<IntPtr>(filename));
    Trace::WriteLine("clr");
    Trace::WriteLine(skey);
    Trace::WriteLine(sfilename);
    String^ sresult = DeepAICsWrapper::Wrapper::Densecap_ProcessFile(skey, sfilename);
    const OLECHAR* chars = (const OLECHAR*)(Marshal::StringToHGlobalUni(sresult)).ToPointer();
    BSTR bresult = SysAllocString(chars);
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return bresult;
  }
}